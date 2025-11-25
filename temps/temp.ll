; ModuleID = 'my_program'
source_filename = "my_program"

declare i32 @printf(ptr, ...)

define i64 @main() {
entry:
  %z = alloca double, align 8
  %y = alloca double, align 8
  %x = alloca double, align 8
  store double 1.050000e+01, ptr %x, align 8
  store double 2.050000e+01, ptr %y, align 8
  %x1 = load double, ptr %x, align 8
  %y2 = load double, ptr %y, align 8
  %0 = and double %x1, %y2
  store double %0, ptr %z, align 8
  ret i64 0
}

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
