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

#ifdef __cplusplus
}
#endif

