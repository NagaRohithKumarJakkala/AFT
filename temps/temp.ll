; ModuleID = 'my_program'
source_filename = "my_program"

@0 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1

declare i32 @printf(ptr, ...)

define ptr @generate_sine_wave(double %frequency, double %sample_rate, double %duration) {
entry:
  %vec.lit = alloca [1 x i64], align 8
  %sample = alloca i64, align 8
  %t = alloca double, align 8
  %i = alloca i64, align 8
  %signal = alloca ptr, align 8
  %num_samples = alloca i32, align 4
  %duration3 = alloca double, align 8
  %sample_rate2 = alloca double, align 8
  %frequency1 = alloca double, align 8
  store double %frequency, ptr %frequency1, align 8
  store double %sample_rate, ptr %sample_rate2, align 8
  store double %duration, ptr %duration3, align 8
  %duration4 = load double, ptr %duration3, align 8
  %sample_rate5 = load double, ptr %sample_rate2, align 8
  %0 = fmul double %duration4, %sample_rate5
  %1 = fptosi double %0 to i32
  store i32 %1, ptr %num_samples, align 4
  store ptr null, ptr %signal, align 8
  %num_samples6 = load i32, ptr %num_samples, align 4
  %2 = sext i32 %num_samples6 to i64
  %3 = insertvalue { i64, i64, i1 } { i64 0, i64 undef, i1 undef }, i64 %2, 1
  %4 = insertvalue { i64, i64, i1 } %3, i1 false, 2
  %5 = extractvalue { i64, i64, i1 } %4, 0
  %6 = extractvalue { i64, i64, i1 } %4, 1
  %7 = extractvalue { i64, i64, i1 } %4, 2
  store i64 %5, ptr %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.step, %entry
  %8 = load i64, ptr %i, align 4
  %9 = icmp sle i64 %8, %6
  br i1 %9, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %i7 = load i64, ptr %i, align 4
  %10 = sitofp i64 %i7 to double
  %sample_rate8 = load double, ptr %sample_rate2, align 8
  %11 = fdiv double %10, %sample_rate8
  store double %11, ptr %t, align 8
  %signal9 = load ptr, ptr %signal, align 8
  %sample10 = load i64, ptr %sample, align 4
  %sample11 = load i64, ptr %sample, align 4
  %12 = getelementptr inbounds [1 x i64], ptr %vec.lit, i32 0, i32 0
  store i64 %sample11, ptr %12, align 4
  %13 = getelementptr inbounds [1 x i64], ptr %vec.lit, i32 0, i32 0
  %14 = add ptr %signal9, %13
  store ptr %14, ptr %signal, align 8
  br label %for.step

for.step:                                         ; preds = %for.body
  %15 = load i64, ptr %i, align 4
  %16 = add i64 %15, 1
  store i64 %16, ptr %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  %signal12 = load ptr, ptr %signal, align 8
  ret ptr %signal12
}

define void @main() {
entry:
  %sine_wave = alloca ptr, align 8
  %duration = alloca double, align 8
  %freq = alloca double, align 8
  %fs = alloca double, align 8
  store double 4.410000e+04, ptr %fs, align 8
  store double 4.400000e+02, ptr %freq, align 8
  store double 1.000000e+00, ptr %duration, align 8
  %freq1 = load double, ptr %freq, align 8
  %fs2 = load double, ptr %fs, align 8
  %duration3 = load double, ptr %duration, align 8
  %calltmp = call ptr @generate_sine_wave(double %freq1, double %fs2, double %duration3)
  store ptr %calltmp, ptr %sine_wave, align 8
  %sine_wave4 = load ptr, ptr %sine_wave, align 8
  %0 = call i32 (ptr, ...) @printf(ptr @0, ptr %sine_wave4)
  ret void
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
