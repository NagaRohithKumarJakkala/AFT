; ModuleID = 'my_program'
source_filename = "my_program"

@0 = private unnamed_addr constant [26 x i8] c"=== INTEGER ABS TESTS ===\00", align 1
@1 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@2 = private unnamed_addr constant [12 x i8] c"abs(i8)  = \00", align 1
@3 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@4 = private unnamed_addr constant [6 x i8] c"%lld\0A\00", align 1
@5 = private unnamed_addr constant [12 x i8] c"abs(i16) = \00", align 1
@6 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@7 = private unnamed_addr constant [6 x i8] c"%lld\0A\00", align 1
@8 = private unnamed_addr constant [12 x i8] c"abs(i32) = \00", align 1
@9 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@10 = private unnamed_addr constant [6 x i8] c"%lld\0A\00", align 1
@11 = private unnamed_addr constant [12 x i8] c"abs(i64) = \00", align 1
@12 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@13 = private unnamed_addr constant [6 x i8] c"%lld\0A\00", align 1
@14 = private unnamed_addr constant [24 x i8] c"=== FLOAT ABS TESTS ===\00", align 1
@15 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@16 = private unnamed_addr constant [12 x i8] c"abs(f32) = \00", align 1
@17 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@18 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@19 = private unnamed_addr constant [12 x i8] c"abs(f64) = \00", align 1
@20 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@21 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@22 = private unnamed_addr constant [19 x i8] c"=== SQRT TESTS ===\00", align 1
@23 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@24 = private unnamed_addr constant [12 x i8] c"sqrt(16) = \00", align 1
@25 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@26 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@27 = private unnamed_addr constant [13 x i8] c"sqrt(2.5) = \00", align 1
@28 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@29 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@30 = private unnamed_addr constant [29 x i8] c"=== EXP / LN / LOG TESTS ===\00", align 1
@31 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@32 = private unnamed_addr constant [10 x i8] c"exp(1) = \00", align 1
@33 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@34 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@35 = private unnamed_addr constant [15 x i8] c"ln(2.71828) = \00", align 1
@36 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@37 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@38 = private unnamed_addr constant [15 x i8] c"log10(1000) = \00", align 1
@39 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@40 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@41 = private unnamed_addr constant [14 x i8] c"log2(1024) = \00", align 1
@42 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@43 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@44 = private unnamed_addr constant [18 x i8] c"=== POW TESTS ===\00", align 1
@45 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@46 = private unnamed_addr constant [14 x i8] c"pow(2, 10) = \00", align 1
@47 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@48 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@49 = private unnamed_addr constant [15 x i8] c"pow(3.5, 3) = \00", align 1
@50 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@51 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@52 = private unnamed_addr constant [23 x i8] c"=== TRIG FUNCTIONS ===\00", align 1
@53 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@54 = private unnamed_addr constant [13 x i8] c"sin(PI/2) = \00", align 1
@55 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@56 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@57 = private unnamed_addr constant [10 x i8] c"cos(0) = \00", align 1
@58 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@59 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@60 = private unnamed_addr constant [12 x i8] c"tan(1.0) = \00", align 1
@61 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@62 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@63 = private unnamed_addr constant [13 x i8] c"arcsin(1) = \00", align 1
@64 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@65 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@66 = private unnamed_addr constant [13 x i8] c"arccos(1) = \00", align 1
@67 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@68 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@69 = private unnamed_addr constant [13 x i8] c"arctan(1) = \00", align 1
@70 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@71 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@72 = private unnamed_addr constant [10 x i8] c"sec(0) = \00", align 1
@73 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@74 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@75 = private unnamed_addr constant [15 x i8] c"cosec(PI/2) = \00", align 1
@76 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@77 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@78 = private unnamed_addr constant [12 x i8] c"cot(1.0) = \00", align 1
@79 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@80 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1

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

define i32 @main() {
entry:
  %f2 = alloca double, align 8
  %f1 = alloca float, align 4
  %a4 = alloca i64, align 8
  %a3 = alloca i32, align 4
  %a2 = alloca i16, align 2
  %a1 = alloca i8, align 1
  %0 = call i32 (ptr, ...) @printf(ptr @1, ptr @0)
  store i8 -5, ptr %a1, align 1
  store i16 -123, ptr %a2, align 2
  store i32 -99999, ptr %a3, align 4
  store i64 -12345678, ptr %a4, align 4
  %1 = call i32 (ptr, ...) @printf(ptr @3, ptr @2)
  %a11 = load i8, ptr %a1, align 1
  %2 = sext i8 %a11 to i64
  %3 = call i64 @aft_abs_i64(i64 %2)
  %4 = trunc i64 %3 to i8
  %5 = sext i8 %4 to i64
  %6 = call i32 (ptr, ...) @printf(ptr @4, i64 %5)
  %7 = call i32 (ptr, ...) @printf(ptr @6, ptr @5)
  %a22 = load i16, ptr %a2, align 2
  %8 = sext i16 %a22 to i64
  %9 = call i64 @aft_abs_i64(i64 %8)
  %10 = trunc i64 %9 to i16
  %11 = sext i16 %10 to i64
  %12 = call i32 (ptr, ...) @printf(ptr @7, i64 %11)
  %13 = call i32 (ptr, ...) @printf(ptr @9, ptr @8)
  %a33 = load i32, ptr %a3, align 4
  %14 = sext i32 %a33 to i64
  %15 = call i64 @aft_abs_i64(i64 %14)
  %16 = trunc i64 %15 to i32
  %17 = sext i32 %16 to i64
  %18 = call i32 (ptr, ...) @printf(ptr @10, i64 %17)
  %19 = call i32 (ptr, ...) @printf(ptr @12, ptr @11)
  %a44 = load i64, ptr %a4, align 4
  %20 = call i64 @aft_abs_i64(i64 %a44)
  %21 = call i32 (ptr, ...) @printf(ptr @13, i64 %20)
  %22 = call i32 (ptr, ...) @printf(ptr @15, ptr @14)
  store float -3.500000e+00, ptr %f1, align 4
  store double -9.987600e+01, ptr %f2, align 8
  %23 = call i32 (ptr, ...) @printf(ptr @17, ptr @16)
  %f15 = load float, ptr %f1, align 4
  %24 = fpext float %f15 to double
  %25 = call double @aft_abs_f64(double %24)
  %26 = fptrunc double %25 to float
  %27 = fpext float %26 to double
  %28 = call i32 (ptr, ...) @printf(ptr @18, double %27)
  %29 = call i32 (ptr, ...) @printf(ptr @20, ptr @19)
  %f26 = load double, ptr %f2, align 8
  %30 = call double @aft_abs_f64(double %f26)
  %31 = call i32 (ptr, ...) @printf(ptr @21, double %30)
  %32 = call i32 (ptr, ...) @printf(ptr @23, ptr @22)
  %33 = call i32 (ptr, ...) @printf(ptr @25, ptr @24)
  %34 = call double @aft_sqrt_f64(double 1.600000e+01)
  %35 = call i32 (ptr, ...) @printf(ptr @26, double %34)
  %36 = call i32 (ptr, ...) @printf(ptr @28, ptr @27)
  %37 = call double @aft_sqrt_f64(double 2.500000e+00)
  %38 = call i32 (ptr, ...) @printf(ptr @29, double %37)
  %39 = call i32 (ptr, ...) @printf(ptr @31, ptr @30)
  %40 = call i32 (ptr, ...) @printf(ptr @33, ptr @32)
  %41 = call double @aft_exp_f64(double 1.000000e+00)
  %42 = call i32 (ptr, ...) @printf(ptr @34, double %41)
  %43 = call i32 (ptr, ...) @printf(ptr @36, ptr @35)
  %44 = call double @aft_ln_f64(double 2.718280e+00)
  %45 = call i32 (ptr, ...) @printf(ptr @37, double %44)
  %46 = call i32 (ptr, ...) @printf(ptr @39, ptr @38)
  %47 = call double @aft_log10_f64(double 1.000000e+03)
  %48 = call i32 (ptr, ...) @printf(ptr @40, double %47)
  %49 = call i32 (ptr, ...) @printf(ptr @42, ptr @41)
  %50 = call double @aft_log2_f64(double 1.024000e+03)
  %51 = call i32 (ptr, ...) @printf(ptr @43, double %50)
  %52 = call i32 (ptr, ...) @printf(ptr @45, ptr @44)
  %53 = call i32 (ptr, ...) @printf(ptr @47, ptr @46)
  %54 = call double @aft_pow_f64(double 2.000000e+00, double 1.000000e+01)
  %55 = call i32 (ptr, ...) @printf(ptr @48, double %54)
  %56 = call i32 (ptr, ...) @printf(ptr @50, ptr @49)
  %57 = call double @aft_pow_f64(double 3.500000e+00, double 3.000000e+00)
  %58 = call i32 (ptr, ...) @printf(ptr @51, double %57)
  %59 = call i32 (ptr, ...) @printf(ptr @53, ptr @52)
  %60 = call i32 (ptr, ...) @printf(ptr @55, ptr @54)
  %61 = call double @aft_sin_f64(double 0x3FF921FB54442D18)
  %62 = call i32 (ptr, ...) @printf(ptr @56, double %61)
  %63 = call i32 (ptr, ...) @printf(ptr @58, ptr @57)
  %64 = call double @aft_cos_f64(double 0.000000e+00)
  %65 = call i32 (ptr, ...) @printf(ptr @59, double %64)
  %66 = call i32 (ptr, ...) @printf(ptr @61, ptr @60)
  %67 = call double @aft_tan_f64(double 1.000000e+00)
  %68 = call i32 (ptr, ...) @printf(ptr @62, double %67)
  %69 = call i32 (ptr, ...) @printf(ptr @64, ptr @63)
  %70 = call double @aft_asin_f64(double 1.000000e+00)
  %71 = call i32 (ptr, ...) @printf(ptr @65, double %70)
  %72 = call i32 (ptr, ...) @printf(ptr @67, ptr @66)
  %73 = call double @aft_acos_f64(double 1.000000e+00)
  %74 = call i32 (ptr, ...) @printf(ptr @68, double %73)
  %75 = call i32 (ptr, ...) @printf(ptr @70, ptr @69)
  %76 = call double @aft_atan_f64(double 1.000000e+00)
  %77 = call i32 (ptr, ...) @printf(ptr @71, double %76)
  %78 = call i32 (ptr, ...) @printf(ptr @73, ptr @72)
  %79 = call double @aft_sec_f64(double 0.000000e+00)
  %80 = call i32 (ptr, ...) @printf(ptr @74, double %79)
  %81 = call i32 (ptr, ...) @printf(ptr @76, ptr @75)
  %82 = call double @aft_cosec_f64(double 0x3FF921FB54442D18)
  %83 = call i32 (ptr, ...) @printf(ptr @77, double %82)
  %84 = call i32 (ptr, ...) @printf(ptr @79, ptr @78)
  %85 = call double @aft_cot_f64(double 1.000000e+00)
  %86 = call i32 (ptr, ...) @printf(ptr @80, double %85)
  ret i32 0
}

declare i64 @aft_abs_i64(i64)

declare double @aft_abs_f64(double)

declare double @aft_sqrt_f64(double)

declare double @aft_exp_f64(double)

declare double @aft_ln_f64(double)

declare double @aft_log10_f64(double)

declare double @aft_log2_f64(double)

declare double @aft_pow_f64(double, double)

declare double @aft_sin_f64(double)

declare double @aft_cos_f64(double)

declare double @aft_tan_f64(double)

declare double @aft_asin_f64(double)

declare double @aft_acos_f64(double)

declare double @aft_atan_f64(double)

declare double @aft_sec_f64(double)

declare double @aft_cosec_f64(double)

declare double @aft_cot_f64(double)
