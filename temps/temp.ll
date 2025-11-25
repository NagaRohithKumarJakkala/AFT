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
  %vec_load_tmp24 = alloca i64, align 8
  %c = alloca { ptr, i64, i32, i64 }, align 8
  %vec_load_tmp15 = alloca i64, align 8
  %vec_load_tmp = alloca i64, align 8
  %b = alloca { ptr, i64, i32, i64 }, align 8
  %0 = call ptr @vec_create(i32 4, i64 3)
  %1 = call ptr @vec_index_ptr(ptr %0, i64 0)
  store i64 20, ptr %1, align 4
  %2 = call ptr @vec_index_ptr(ptr %0, i64 1)
  store i64 30, ptr %2, align 4
  %3 = call ptr @vec_index_ptr(ptr %0, i64 2)
  store i64 30, ptr %3, align 4
  %4 = insertvalue { ptr, i64, i32, i64 } undef, ptr %0, 0
  %5 = insertvalue { ptr, i64, i32, i64 } %4, i64 3, 1
  %6 = insertvalue { ptr, i64, i32, i64 } %5, i32 4, 2
  %7 = insertvalue { ptr, i64, i32, i64 } %6, i64 3, 3
  store { ptr, i64, i32, i64 } %7, ptr %b, align 8
  %b1 = load { ptr, i64, i32, i64 }, ptr %b, align 8
  %8 = extractvalue { ptr, i64, i32, i64 } %b1, 0
  %9 = extractvalue { ptr, i64, i32, i64 } %b1, 1
  %10 = extractvalue { ptr, i64, i32, i64 } %b1, 2
  %11 = extractvalue { ptr, i64, i32, i64 } %b1, 3
  %12 = call ptr @vec_index_ptr(ptr %8, i64 2)
  switch i32 %10, label %vec.load.merge [
    i32 1, label %vec.load
    i32 3, label %vec.load2
    i32 4, label %vec.load3
    i32 11, label %vec.load4
    i32 12, label %vec.load5
    i32 16, label %vec.load6
  ]

vec.load.merge:                                   ; preds = %vec.load6, %vec.load5, %vec.load4, %vec.load3, %vec.load2, %vec.load, %entry
  %13 = load i64, ptr %vec_load_tmp, align 4
  %14 = call i32 (ptr, ...) @printf(ptr @0, i64 %13)
  %b7 = load { ptr, i64, i32, i64 }, ptr %b, align 8
  %15 = extractvalue { ptr, i64, i32, i64 } %b7, 0
  %16 = extractvalue { ptr, i64, i32, i64 } %b7, 1
  %17 = extractvalue { ptr, i64, i32, i64 } %b7, 2
  %18 = extractvalue { ptr, i64, i32, i64 } %b7, 3
  %19 = call ptr @vec_index_ptr(ptr %15, i64 2)
  switch i32 %17, label %vec.store.merge [
    i32 1, label %vec.store
    i32 3, label %vec.store8
    i32 4, label %vec.store9
    i32 11, label %vec.store10
    i32 12, label %vec.store11
    i32 16, label %vec.store12
  ]

vec.load:                                         ; preds = %entry
  %20 = load i8, ptr %12, align 1
  %21 = sext i8 %20 to i64
  store i64 %21, ptr %vec_load_tmp, align 4
  br label %vec.load.merge

vec.load2:                                        ; preds = %entry
  %22 = load i32, ptr %12, align 4
  %23 = sext i32 %22 to i64
  store i64 %23, ptr %vec_load_tmp, align 4
  br label %vec.load.merge

vec.load3:                                        ; preds = %entry
  %24 = load i64, ptr %12, align 4
  store i64 %24, ptr %vec_load_tmp, align 4
  br label %vec.load.merge

vec.load4:                                        ; preds = %entry
  %25 = load float, ptr %12, align 4
  %26 = fptosi float %25 to i64
  store i64 %26, ptr %vec_load_tmp, align 4
  br label %vec.load.merge

vec.load5:                                        ; preds = %entry
  %27 = load double, ptr %12, align 8
  %28 = fptosi double %27 to i64
  store i64 %28, ptr %vec_load_tmp, align 4
  br label %vec.load.merge

vec.load6:                                        ; preds = %entry
  %29 = load ptr, ptr %12, align 8
  %30 = ptrtoint ptr %29 to i64
  store i64 %30, ptr %vec_load_tmp, align 4
  br label %vec.load.merge

vec.store.merge:                                  ; preds = %vec.store12, %vec.store11, %vec.store10, %vec.store9, %vec.store8, %vec.store, %vec.load.merge
  %b13 = load { ptr, i64, i32, i64 }, ptr %b, align 8
  %31 = extractvalue { ptr, i64, i32, i64 } %b13, 0
  %32 = extractvalue { ptr, i64, i32, i64 } %b13, 1
  %33 = extractvalue { ptr, i64, i32, i64 } %b13, 2
  %34 = extractvalue { ptr, i64, i32, i64 } %b13, 3
  %35 = call ptr @vec_index_ptr(ptr %31, i64 2)
  switch i32 %33, label %vec.load.merge14 [
    i32 1, label %vec.load16
    i32 3, label %vec.load17
    i32 4, label %vec.load18
    i32 11, label %vec.load19
    i32 12, label %vec.load20
    i32 16, label %vec.load21
  ]

vec.store:                                        ; preds = %vec.load.merge
  store i8 20, ptr %19, align 1
  br label %vec.store.merge

vec.store8:                                       ; preds = %vec.load.merge
  store i32 20, ptr %19, align 4
  br label %vec.store.merge

vec.store9:                                       ; preds = %vec.load.merge
  store i64 20, ptr %19, align 4
  br label %vec.store.merge

vec.store10:                                      ; preds = %vec.load.merge
  store float 2.000000e+01, ptr %19, align 4
  br label %vec.store.merge

vec.store11:                                      ; preds = %vec.load.merge
  store double 2.000000e+01, ptr %19, align 8
  br label %vec.store.merge

vec.store12:                                      ; preds = %vec.load.merge
  store ptr inttoptr (i64 20 to ptr), ptr %19, align 8
  br label %vec.store.merge

vec.load.merge14:                                 ; preds = %vec.load21, %vec.load20, %vec.load19, %vec.load18, %vec.load17, %vec.load16, %vec.store.merge
  %36 = load i64, ptr %vec_load_tmp15, align 4
  %37 = call i32 (ptr, ...) @printf(ptr @1, i64 %36)
  %38 = call ptr @vec_create(i32 12, i64 3)
  %39 = call ptr @vec_index_ptr(ptr %38, i64 0)
  store double 3.000000e+01, ptr %39, align 8
  %40 = call ptr @vec_index_ptr(ptr %38, i64 1)
  store double 4.000000e+01, ptr %40, align 8
  %41 = call ptr @vec_index_ptr(ptr %38, i64 2)
  store double 5.000000e+01, ptr %41, align 8
  %42 = insertvalue { ptr, i64, i32, i64 } undef, ptr %38, 0
  %43 = insertvalue { ptr, i64, i32, i64 } %42, i64 3, 1
  %44 = insertvalue { ptr, i64, i32, i64 } %43, i32 12, 2
  %45 = insertvalue { ptr, i64, i32, i64 } %44, i64 3, 3
  store { ptr, i64, i32, i64 } %45, ptr %c, align 8
  %c22 = load { ptr, i64, i32, i64 }, ptr %c, align 8
  %46 = extractvalue { ptr, i64, i32, i64 } %c22, 0
  %47 = extractvalue { ptr, i64, i32, i64 } %c22, 1
  %48 = extractvalue { ptr, i64, i32, i64 } %c22, 2
  %49 = extractvalue { ptr, i64, i32, i64 } %c22, 3
  %50 = call ptr @vec_index_ptr(ptr %46, i64 1)
  switch i32 %48, label %vec.load.merge23 [
    i32 1, label %vec.load25
    i32 3, label %vec.load26
    i32 4, label %vec.load27
    i32 11, label %vec.load28
    i32 12, label %vec.load29
    i32 16, label %vec.load30
  ]

vec.load16:                                       ; preds = %vec.store.merge
  %51 = load i8, ptr %35, align 1
  %52 = sext i8 %51 to i64
  store i64 %52, ptr %vec_load_tmp15, align 4
  br label %vec.load.merge14

vec.load17:                                       ; preds = %vec.store.merge
  %53 = load i32, ptr %35, align 4
  %54 = sext i32 %53 to i64
  store i64 %54, ptr %vec_load_tmp15, align 4
  br label %vec.load.merge14

vec.load18:                                       ; preds = %vec.store.merge
  %55 = load i64, ptr %35, align 4
  store i64 %55, ptr %vec_load_tmp15, align 4
  br label %vec.load.merge14

vec.load19:                                       ; preds = %vec.store.merge
  %56 = load float, ptr %35, align 4
  %57 = fptosi float %56 to i64
  store i64 %57, ptr %vec_load_tmp15, align 4
  br label %vec.load.merge14

vec.load20:                                       ; preds = %vec.store.merge
  %58 = load double, ptr %35, align 8
  %59 = fptosi double %58 to i64
  store i64 %59, ptr %vec_load_tmp15, align 4
  br label %vec.load.merge14

vec.load21:                                       ; preds = %vec.store.merge
  %60 = load ptr, ptr %35, align 8
  %61 = ptrtoint ptr %60 to i64
  store i64 %61, ptr %vec_load_tmp15, align 4
  br label %vec.load.merge14

vec.load.merge23:                                 ; preds = %vec.load30, %vec.load29, %vec.load28, %vec.load27, %vec.load26, %vec.load25, %vec.load.merge14
  %62 = load i64, ptr %vec_load_tmp24, align 4
  %63 = call i32 (ptr, ...) @printf(ptr @2, i64 %62)
  ret void

vec.load25:                                       ; preds = %vec.load.merge14
  %64 = load i8, ptr %50, align 1
  %65 = sext i8 %64 to i64
  store i64 %65, ptr %vec_load_tmp24, align 4
  br label %vec.load.merge23

vec.load26:                                       ; preds = %vec.load.merge14
  %66 = load i32, ptr %50, align 4
  %67 = sext i32 %66 to i64
  store i64 %67, ptr %vec_load_tmp24, align 4
  br label %vec.load.merge23

vec.load27:                                       ; preds = %vec.load.merge14
  %68 = load i64, ptr %50, align 4
  store i64 %68, ptr %vec_load_tmp24, align 4
  br label %vec.load.merge23

vec.load28:                                       ; preds = %vec.load.merge14
  %69 = load float, ptr %50, align 4
  %70 = fptosi float %69 to i64
  store i64 %70, ptr %vec_load_tmp24, align 4
  br label %vec.load.merge23

vec.load29:                                       ; preds = %vec.load.merge14
  %71 = load double, ptr %50, align 8
  %72 = fptosi double %71 to i64
  store i64 %72, ptr %vec_load_tmp24, align 4
  br label %vec.load.merge23

vec.load30:                                       ; preds = %vec.load.merge14
  %73 = load ptr, ptr %50, align 8
  %74 = ptrtoint ptr %73 to i64
  store i64 %74, ptr %vec_load_tmp24, align 4
  br label %vec.load.merge23
}
