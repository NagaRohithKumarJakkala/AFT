; ModuleID = 'my_program'
source_filename = "my_program"

@0 = private unnamed_addr constant [6 x i8] c"%lld\0A\00", align 1

declare i32 @printf(ptr, ...)

declare ptr @vec_create(i32, i64)

declare void @vec_resize(ptr, i64)

declare ptr @vec_index_ptr(ptr, i64)

declare void @vec_free(ptr)

declare void @vec_push(ptr, ptr)

declare ptr @vector_reverse(ptr)

define i64 @return_zero() {
entry:
  ret i64 0
}

define void @main() {
entry:
  %i = alloca i64, align 8
  store i64 0, ptr %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.step, %entry
  %0 = load i64, ptr %i, align 4
  %1 = icmp sle i64 %0, 6
  %2 = icmp slt i64 %0, 6
  %3 = select i1 false, i1 %1, i1 %2
  br i1 %3, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %i1 = load i64, ptr %i, align 4
  %4 = call i32 (ptr, ...) @printf(ptr @0, i64 %i1)
  br label %for.step

for.step:                                         ; preds = %for.body
  %5 = load i64, ptr %i, align 4
  %6 = add i64 %5, 1
  store i64 %6, ptr %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  ret void
}
