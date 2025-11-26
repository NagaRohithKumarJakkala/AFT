; ModuleID = 'my_program'
source_filename = "my_program"

@0 = private unnamed_addr constant [6 x i8] c"%lld\0A\00", align 1
@1 = private unnamed_addr constant [6 x i8] c"%lld\0A\00", align 1
@2 = private unnamed_addr constant [6 x i8] c"%lld\0A\00", align 1

declare i32 @printf(ptr, ...)

declare ptr @vec_create(i32, i64)

declare void @vec_resize(ptr, i64)

declare ptr @vec_index_ptr(ptr, i64)

declare void @vec_free(ptr)

declare void @vec_push(ptr, ptr)

define i64 @abs(i64 %a) {
entry:
  %a1 = alloca i64, align 8
  store i64 %a, ptr %a1, align 4
  %a2 = load i64, ptr %a1, align 4
  %0 = icmp slt i64 %a2, 0
  br i1 %0, label %then, label %else

then:                                             ; preds = %entry
  %a3 = load i64, ptr %a1, align 4
  %1 = sub i64 0, %a3
  ret i64 %1

else:                                             ; preds = %entry
  br label %ifend

ifend:                                            ; preds = %else
  %a4 = load i64, ptr %a1, align 4
  ret i64 %a4
}

define void @main() {
entry:
  %c = alloca ptr, align 8
  %b = alloca ptr, align 8
  %0 = call ptr @vec_create(i32 5, i64 3)
  %1 = call ptr @vec_index_ptr(ptr %0, i64 0)
  store i64 20, ptr %1, align 4
  %2 = call ptr @vec_index_ptr(ptr %0, i64 1)
  store i64 30, ptr %2, align 4
  %3 = call ptr @vec_index_ptr(ptr %0, i64 2)
  store i64 30, ptr %3, align 4
  store ptr %0, ptr %b, align 8
  %b1 = load ptr, ptr %b, align 8
  %4 = call ptr @vec_index_ptr(ptr %b1, i64 2)
  %5 = load i64, ptr %4, align 4
  %6 = call i32 (ptr, ...) @printf(ptr @0, i64 %5)
  %b2 = load ptr, ptr %b, align 8
  %7 = getelementptr inbounds nuw { ptr, i64, i64, i32 }, ptr %b2, i32 0, i32 0
  %8 = load ptr, ptr %7, align 8
  %9 = getelementptr inbounds nuw { ptr, i64, i64, i32 }, ptr %b2, i32 0, i32 1
  %10 = load i64, ptr %9, align 4
  %11 = getelementptr inbounds nuw { ptr, i64, i64, i32 }, ptr %b2, i32 0, i32 2
  %12 = load i64, ptr %11, align 4
  %13 = getelementptr inbounds nuw { ptr, i64, i64, i32 }, ptr %b2, i32 0, i32 3
  %14 = load i32, ptr %13, align 4
  %15 = call ptr @vec_index_ptr(ptr %b2, i64 2)
  switch i32 %14, label %vec.store.merge [
    i32 2, label %vec.store
    i32 4, label %vec.store3
    i32 5, label %vec.store4
    i32 12, label %vec.store5
    i32 13, label %vec.store6
    i32 16, label %vec.store7
  ]

vec.store.merge:                                  ; preds = %vec.store7, %vec.store6, %vec.store5, %vec.store4, %vec.store3, %vec.store, %entry
  %b8 = load ptr, ptr %b, align 8
  %16 = call ptr @vec_index_ptr(ptr %b8, i64 2)
  %17 = load i64, ptr %16, align 4
  %18 = call i32 (ptr, ...) @printf(ptr @1, i64 %17)
  %19 = call ptr @vec_create(i32 13, i64 3)
  %20 = call ptr @vec_index_ptr(ptr %19, i64 0)
  store double 3.000000e+01, ptr %20, align 8
  %21 = call ptr @vec_index_ptr(ptr %19, i64 1)
  store double 4.000000e+01, ptr %21, align 8
  %22 = call ptr @vec_index_ptr(ptr %19, i64 2)
  store double 5.000000e+01, ptr %22, align 8
  store ptr %19, ptr %c, align 8
  %c9 = load ptr, ptr %c, align 8
  %23 = call ptr @vec_index_ptr(ptr %c9, i64 1)
  %24 = load i64, ptr %23, align 4
  %25 = call i32 (ptr, ...) @printf(ptr @2, i64 %24)
  ret void

vec.store:                                        ; preds = %entry
  store i8 20, ptr %15, align 1
  br label %vec.store.merge

vec.store3:                                       ; preds = %entry
  store i32 20, ptr %15, align 4
  br label %vec.store.merge

vec.store4:                                       ; preds = %entry
  store i64 20, ptr %15, align 4
  br label %vec.store.merge

vec.store5:                                       ; preds = %entry
  store float 2.000000e+01, ptr %15, align 4
  br label %vec.store.merge

vec.store6:                                       ; preds = %entry
  store double 2.000000e+01, ptr %15, align 8
  br label %vec.store.merge

vec.store7:                                       ; preds = %entry
  store ptr inttoptr (i64 20 to ptr), ptr %15, align 8
  br label %vec.store.merge
}
