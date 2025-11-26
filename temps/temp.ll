; ModuleID = 'my_program'
source_filename = "my_program"

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
  %c = alloca { double, double }, align 8
  %b = alloca { double, double }, align 8
  %a = alloca { double, double }, align 8
  store { double, double } { double 2.000000e+00, double 3.000000e+00 }, ptr %a, align 8
  store { double, double } { double 5.000000e+00, double 4.000000e+00 }, ptr %b, align 8
  %a1 = load { double, double }, ptr %a, align 8
  %b2 = load { double, double }, ptr %b, align 8
  %0 = extractvalue { double, double } %a1, 0
  %1 = extractvalue { double, double } %a1, 1
  %2 = extractvalue { double, double } %b2, 0
  %3 = extractvalue { double, double } %b2, 1
  %4 = fadd double %0, %2
  %5 = fadd double %1, %3
  %6 = insertvalue { double, double } undef, double %4, 0
  %7 = insertvalue { double, double } %6, double %5, 1
  store { double, double } %7, ptr %c, align 8
  ret void
}
