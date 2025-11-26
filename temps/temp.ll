; ModuleID = 'my_program'
source_filename = "my_program"

%VecHeader = type { ptr, i64, i64, i32 }

@0 = private unnamed_addr constant [6 x i8] c"%lld\0A\00", align 1

declare i32 @printf(ptr, ...)

declare ptr @vec_create(i32, i64)

declare void @vec_resize(ptr, i64)

declare ptr @vec_index_ptr(ptr, i64)

declare void @vec_free(ptr)

declare void @vec_push(ptr, ptr)

declare ptr @vector_reverse(ptr)

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
  %ys = alloca ptr, align 8
  %0 = call ptr @vec_create(i32 13, i64 3)
  %1 = call ptr @vec_index_ptr(ptr %0, i64 0)
  store double 1.000000e+01, ptr %1, align 8
  %2 = call ptr @vec_index_ptr(ptr %0, i64 1)
  store double 2.000000e+01, ptr %2, align 8
  %3 = call ptr @vec_index_ptr(ptr %0, i64 2)
  store double 3.000000e+01, ptr %3, align 8
  store ptr %0, ptr %ys, align 8
  %ys1 = load ptr, ptr %ys, align 8
  %4 = getelementptr inbounds nuw %VecHeader, ptr %ys1, i32 0, i32 0
  %5 = load ptr, ptr %4, align 8
  %6 = getelementptr inbounds nuw %VecHeader, ptr %ys1, i32 0, i32 1
  %7 = load i64, ptr %6, align 4
  %8 = getelementptr inbounds nuw %VecHeader, ptr %ys1, i32 0, i32 2
  %9 = load i64, ptr %8, align 4
  %10 = getelementptr inbounds nuw %VecHeader, ptr %ys1, i32 0, i32 3
  %11 = load i32, ptr %10, align 4
  %12 = call ptr @vec_index_ptr(ptr %ys1, i64 2)
  %13 = load i64, ptr %12, align 4
  %14 = call i32 (ptr, ...) @printf(ptr @0, i64 %13)
  ret void
}
