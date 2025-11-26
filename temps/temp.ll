; ModuleID = 'my_program'
source_filename = "my_program"

%VecHeader = type { ptr, i64, i64, i32 }

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
  %4 = getelementptr inbounds nuw %VecHeader, ptr %b1, i32 0, i32 0
  %5 = load ptr, ptr %4, align 8
  %6 = getelementptr inbounds nuw %VecHeader, ptr %b1, i32 0, i32 1
  %7 = load i64, ptr %6, align 4
  %8 = getelementptr inbounds nuw %VecHeader, ptr %b1, i32 0, i32 2
  %9 = load i64, ptr %8, align 4
  %10 = getelementptr inbounds nuw %VecHeader, ptr %b1, i32 0, i32 3
  %11 = load i32, ptr %10, align 4
  %12 = call ptr @vec_index_ptr(ptr %b1, i64 2)
  %13 = load i64, ptr %12, align 4
  %14 = call i32 (ptr, ...) @printf(ptr @0, i64 %13)
  %b2 = load ptr, ptr %b, align 8
  %15 = getelementptr inbounds nuw %VecHeader, ptr %b2, i32 0, i32 0
  %16 = load ptr, ptr %15, align 8
  %17 = getelementptr inbounds nuw %VecHeader, ptr %b2, i32 0, i32 1
  %18 = load i64, ptr %17, align 4
  %19 = getelementptr inbounds nuw %VecHeader, ptr %b2, i32 0, i32 2
  %20 = load i64, ptr %19, align 4
  %21 = getelementptr inbounds nuw %VecHeader, ptr %b2, i32 0, i32 3
  %22 = load i32, ptr %21, align 4
  %23 = call ptr @vec_index_ptr(ptr %b2, i64 2)
  store i64 20, ptr %23, align 4
  %b3 = load ptr, ptr %b, align 8
  %24 = getelementptr inbounds nuw %VecHeader, ptr %b3, i32 0, i32 0
  %25 = load ptr, ptr %24, align 8
  %26 = getelementptr inbounds nuw %VecHeader, ptr %b3, i32 0, i32 1
  %27 = load i64, ptr %26, align 4
  %28 = getelementptr inbounds nuw %VecHeader, ptr %b3, i32 0, i32 2
  %29 = load i64, ptr %28, align 4
  %30 = getelementptr inbounds nuw %VecHeader, ptr %b3, i32 0, i32 3
  %31 = load i32, ptr %30, align 4
  %32 = call ptr @vec_index_ptr(ptr %b3, i64 2)
  %33 = load i64, ptr %32, align 4
  %34 = call i32 (ptr, ...) @printf(ptr @1, i64 %33)
  %35 = call ptr @vec_create(i32 13, i64 3)
  %36 = call ptr @vec_index_ptr(ptr %35, i64 0)
  store double 3.000000e+01, ptr %36, align 8
  %37 = call ptr @vec_index_ptr(ptr %35, i64 1)
  store double 4.050000e+01, ptr %37, align 8
  %38 = call ptr @vec_index_ptr(ptr %35, i64 2)
  store double 5.000000e+01, ptr %38, align 8
  store ptr %35, ptr %c, align 8
  %c4 = load ptr, ptr %c, align 8
  %39 = getelementptr inbounds nuw %VecHeader, ptr %c4, i32 0, i32 0
  %40 = load ptr, ptr %39, align 8
  %41 = getelementptr inbounds nuw %VecHeader, ptr %c4, i32 0, i32 1
  %42 = load i64, ptr %41, align 4
  %43 = getelementptr inbounds nuw %VecHeader, ptr %c4, i32 0, i32 2
  %44 = load i64, ptr %43, align 4
  %45 = getelementptr inbounds nuw %VecHeader, ptr %c4, i32 0, i32 3
  %46 = load i32, ptr %45, align 4
  %47 = call ptr @vec_index_ptr(ptr %c4, i64 1)
  %48 = load i64, ptr %47, align 4
  %49 = call i32 (ptr, ...) @printf(ptr @2, i64 %48)
  ret void
}
