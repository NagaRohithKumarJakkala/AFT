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
  %i = alloca i64, align 8
  %c = alloca ptr, align 8
  %0 = call ptr @vec_create(i32 5, i64 6)
  %1 = call ptr @vec_index_ptr(ptr %0, i64 0)
  store i64 1, ptr %1, align 4
  %2 = call ptr @vec_index_ptr(ptr %0, i64 1)
  store i64 2, ptr %2, align 4
  %3 = call ptr @vec_index_ptr(ptr %0, i64 2)
  store i64 3, ptr %3, align 4
  %4 = call ptr @vec_index_ptr(ptr %0, i64 3)
  store i64 4, ptr %4, align 4
  %5 = call ptr @vec_index_ptr(ptr %0, i64 4)
  store i64 5, ptr %5, align 4
  %6 = call ptr @vec_index_ptr(ptr %0, i64 5)
  store i64 6, ptr %6, align 4
  %vreverse = call ptr @vector_reverse(ptr %0)
  store ptr %vreverse, ptr %c, align 8
  store i64 0, ptr %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.step, %entry
  %7 = load i64, ptr %i, align 4
  %8 = icmp sle i64 %7, 5
  br i1 %8, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %c1 = load ptr, ptr %c, align 8
  %i2 = load i64, ptr %i, align 4
  %9 = getelementptr inbounds nuw %VecHeader, ptr %c1, i32 0, i32 0
  %10 = load ptr, ptr %9, align 8
  %11 = getelementptr inbounds nuw %VecHeader, ptr %c1, i32 0, i32 1
  %12 = load i64, ptr %11, align 4
  %13 = getelementptr inbounds nuw %VecHeader, ptr %c1, i32 0, i32 2
  %14 = load i64, ptr %13, align 4
  %15 = getelementptr inbounds nuw %VecHeader, ptr %c1, i32 0, i32 3
  %16 = load i32, ptr %15, align 4
  %17 = call ptr @vec_index_ptr(ptr %c1, i64 %i2)
  %18 = load i64, ptr %17, align 4
  %19 = call i32 (ptr, ...) @printf(ptr @0, i64 %18)
  br label %for.step

for.step:                                         ; preds = %for.body
  %20 = load i64, ptr %i, align 4
  %21 = add i64 %20, 1
  store i64 %21, ptr %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  ret void
}
