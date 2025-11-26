// vector_runtime.c
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "elem_ids.h"   // e.g. defines E_I8, E_I16, E_U8, E_F32, E_F64, E_BOOL, etc.

#ifdef __cplusplus
extern "C" {
#endif

typedef struct VecHeader {
    void   *data;      // pointer to element storage
    int64_t length;    // number of elements logically in the vector
    int64_t capacity;  // number of elements allocated
    int32_t elemType;  // E_I64, E_F32, etc.
} VecHeader;

static size_t elem_size(int32_t elemType) {
    switch (elemType) {
        case E_BOOL: return sizeof(uint8_t);  // stored as 1 byte
        case E_I8:   return sizeof(int8_t);
        case E_I16:  return sizeof(int16_t);
        case E_I32:  return sizeof(int32_t);
        case E_I64:  return sizeof(int64_t);
        case E_I128: return 16;

        case E_U8:   return sizeof(uint8_t);
        case E_U16:  return sizeof(uint16_t);
        case E_U32:  return sizeof(uint32_t);
        case E_U64:  return sizeof(uint64_t);
        case E_U128: return 16;

        case E_F32:  return sizeof(float);
        case E_F64:  return sizeof(double);

        // Complex numbers: (re, im)
        case E_C32:  return sizeof(float) * 2;
        case E_C64:  return sizeof(double) * 2;

        case E_STR:  return sizeof(char*);  // store string pointers

        default:
            fprintf(stderr, "vec_runtime: unknown elemType=%d\n", elemType);
            abort();
    }
}

void* vec_create(int32_t elemType, int64_t capacity) {
    if (capacity < 0) {
        fprintf(stderr, "vec_create: negative capacity %lld\n",
                (long long)capacity);
        capacity = 0;
    }

    size_t esz = elem_size(elemType);

    VecHeader *vh = (VecHeader*)malloc(sizeof(VecHeader));
    if (!vh) {
        fprintf(stderr, "vec_create: out of memory (header)\n");
        abort();
    }

    vh->elemType = elemType;
    vh->length   = capacity;   
    vh->capacity = capacity;
    vh->data     = NULL;

    if (capacity > 0) {
        vh->data = malloc(esz * (size_t)capacity);
        if (!vh->data) {
            fprintf(stderr, "vec_create: out of memory (data)\n");
            free(vh);
            abort();
        }
        memset(vh->data, 0, esz * (size_t)capacity);
    }

    return (void*)vh;
}

void vec_resize(void *vec, int64_t newSize) {
    VecHeader *vh = (VecHeader*)vec;
    if (!vh) return;

    if (newSize < 0) {
        fprintf(stderr, "vec_resize: negative size %lld\n",
                (long long)newSize);
        return;
    }

    size_t esz = elem_size(vh->elemType);

    if (newSize <= vh->capacity) {
        vh->length = newSize;
        return;
    }

    int64_t newCap = vh->capacity > 0 ? vh->capacity : 1;
    while (newCap < newSize) {
        newCap *= 2;
    }

    void *newData = realloc(vh->data, esz * (size_t)newCap);
    if (!newData) {
        fprintf(stderr, "vec_resize: out of memory realloc to %lld\n",
                (long long)newCap);
        abort();
    }

    if (newSize > vh->length) {
        size_t oldBytes = (size_t)vh->length * esz;
        size_t newBytes = (size_t)newSize * esz;
        memset((char*)newData + oldBytes, 0, newBytes - oldBytes);
    }

    vh->data     = newData;
    vh->capacity = newCap;
    vh->length   = newSize;
}

void* vec_index_ptr(void *vec, int64_t index) {
    VecHeader *vh = (VecHeader*)vec;
    if (!vh) {
        fprintf(stderr, "vec_index_ptr: null vec\n");
        return NULL;
    }

    if (index < 0 || index >= vh->length) {
        fprintf(stderr, "vec_index_ptr: index %lld out of bounds [0,%lld)\n",
                (long long)index, (long long)vh->length);
        // You can abort() instead if you want hard failure:
        // abort();
        return NULL;
    }

    size_t esz = elem_size(vh->elemType);
    return (void*)((char*)vh->data + esz * (size_t)index);
}

void vec_push(void *vec, void *valuePtr) {
    VecHeader *vh = (VecHeader*)vec;
    if (!vh) {
        fprintf(stderr, "vec_push: null vec\n");
        return;
    }
    if (!valuePtr) {
        fprintf(stderr, "vec_push: null valuePtr\n");
        return;
    }

    int64_t oldLen = vh->length;
    vec_resize(vh, oldLen + 1);

    size_t esz   = elem_size(vh->elemType);
    void *dest   = (char*)vh->data + esz * (size_t)oldLen;

    memcpy(dest, valuePtr, esz);
}

void vec_free(void *vec) {
    VecHeader *vh = (VecHeader*)vec;
    if (!vh) return;

    if (vh->data) {
        free(vh->data);
        vh->data = NULL;
    }
    free(vh);
}

void* vector_concat(void *aPtr, void *bPtr) {
    VecHeader *a = (VecHeader*)aPtr;
    VecHeader *b = (VecHeader*)bPtr;
    if (!a || !b) return NULL;

    if (a->elemType != b->elemType) {
        fprintf(stderr, "vector_concat: type mismatch %d vs %d\n",
                a->elemType, b->elemType);
        return NULL;
    }

    size_t esz = elem_size(a->elemType);
    int64_t newLen = a->length + b->length;

    // Allocate new vector with full capacity
    VecHeader *out = (VecHeader*)vec_create(a->elemType, newLen);

    // Copy A’s data
    memcpy((char*)out->data,
           (char*)a->data,
           (size_t)a->length * esz);

    // Copy B’s data after A
    memcpy((char*)out->data + (size_t)a->length * esz,
           (char*)b->data,
           (size_t)b->length * esz);

    return out;
}



void* vector_convolution(void *aPtr, void *bPtr) {
    VecHeader *a = (VecHeader*)aPtr;
    VecHeader *b = (VecHeader*)bPtr;
    if (!a || !b) return NULL;

    if (a->elemType != b->elemType) {
        fprintf(stderr, "vector_convolution: type mismatch %d vs %d\n",
                a->elemType, b->elemType);
        return NULL;
    }

    if (!(a->elemType == E_I64 || a->elemType == E_F64)) {
        fprintf(stderr, "vector_convolution: only I64/F64 supported\n");
        return NULL;
    }

    int64_t n = a->length;
    int64_t m = b->length;
    int64_t outLen = n + m - 1;

    VecHeader *out = vec_create(a->elemType, outLen);

    size_t esz = elem_size(a->elemType);

    if (a->elemType == E_I64) {
        int64_t *A = (int64_t*)a->data;
        int64_t *B = (int64_t*)b->data;
        int64_t *O = (int64_t*)out->data;

        for (int64_t k = 0; k < outLen; k++) {
            long long sum = 0;
            for (int64_t i = 0; i < n; i++) {
                int64_t j = k - i;
                if (j >= 0 && j < m)
                    sum += A[i] * B[j];
            }
            O[k] = sum;
        }
    }
    else if (a->elemType == E_F64) {
        double *A = (double*)a->data;
        double *B = (double*)b->data;
        double *O = (double*)out->data;

        for (int64_t k = 0; k < outLen; k++) {
            double sum = 0.0;
            for (int64_t i = 0; i < n; i++) {
                int64_t j = k - i;
                if (j >= 0 && j < m)
                    sum += A[i] * B[j];
            }
            O[k] = sum;
        }
    }

    return out;
}

void* vector_reverse(void *vecPtr) {
    VecHeader *v = (VecHeader*)vecPtr;
    if (!v) return NULL;

    VecHeader *out = vec_create(v->elemType, v->length);
    size_t esz = elem_size(v->elemType);

    for (int64_t i = 0; i < v->length; i++) {
        memcpy((char*)out->data + (v->length - 1 - i) * esz,
               (char*)v->data + i * esz,
               esz);
    }

    return out;
}

int64_t vector_len(void *vecPtr) {
    VecHeader *v = (VecHeader*)vecPtr;
    if (!v) return 0;
    return v->length;
}

int64_t vector_size(void *vecPtr) {
    VecHeader *v = (VecHeader*)vecPtr;
    if (!v) return 0;
    return v->length * elem_size(v->elemType);
}





#ifdef __cplusplus
}
#endif

