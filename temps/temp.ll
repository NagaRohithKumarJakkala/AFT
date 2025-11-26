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
@18 = private unnamed_addr constant [6 x i8] c"%lld\0A\00", align 1
@19 = private unnamed_addr constant [12 x i8] c"abs(f64) = \00", align 1
@20 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@21 = private unnamed_addr constant [6 x i8] c"%lld\0A\00", align 1
@22 = private unnamed_addr constant [19 x i8] c"=== SQRT TESTS ===\00", align 1
@23 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@24 = private unnamed_addr constant [12 x i8] c"sqrt(16) = \00", align 1
@25 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@26 = private unnamed_addr constant [13 x i8] c"sqrt(2.5) = \00", align 1
@27 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@28 = private unnamed_addr constant [29 x i8] c"=== EXP / LN / LOG TESTS ===\00", align 1
@29 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@30 = private unnamed_addr constant [10 x i8] c"exp(1) = \00", align 1
@31 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@32 = private unnamed_addr constant [15 x i8] c"ln(2.71828) = \00", align 1
@33 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@34 = private unnamed_addr constant [15 x i8] c"log10(1000) = \00", align 1
@35 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@36 = private unnamed_addr constant [14 x i8] c"log2(1024) = \00", align 1
@37 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@38 = private unnamed_addr constant [18 x i8] c"=== POW TESTS ===\00", align 1
@39 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@40 = private unnamed_addr constant [14 x i8] c"pow(2, 10) = \00", align 1
@41 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@42 = private unnamed_addr constant [15 x i8] c"pow(3.5, 3) = \00", align 1
@43 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@44 = private unnamed_addr constant [23 x i8] c"=== TRIG FUNCTIONS ===\00", align 1
@45 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@46 = private unnamed_addr constant [13 x i8] c"sin(PI/2) = \00", align 1
@47 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@48 = private unnamed_addr constant [10 x i8] c"cos(0) = \00", align 1
@49 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@50 = private unnamed_addr constant [12 x i8] c"tan(1.0) = \00", align 1
@51 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@52 = private unnamed_addr constant [13 x i8] c"arcsin(1) = \00", align 1
@53 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@54 = private unnamed_addr constant [13 x i8] c"arccos(1) = \00", align 1
@55 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@56 = private unnamed_addr constant [13 x i8] c"arctan(1) = \00", align 1
@57 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@58 = private unnamed_addr constant [10 x i8] c"sec(0) = \00", align 1
@59 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@60 = private unnamed_addr constant [15 x i8] c"cosec(PI/2) = \00", align 1
@61 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@62 = private unnamed_addr constant [12 x i8] c"cot(1.0) = \00", align 1
@63 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1

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
  %calltmp = call i64 @abs(i8 %a11)
  %2 = call i32 (ptr, ...) @printf(ptr @4, i64 %calltmp)
  %3 = call i32 (ptr, ...) @printf(ptr @6, ptr @5)
  %a22 = load i16, ptr %a2, align 2
  %calltmp3 = call i64 @abs(i16 %a22)
  %4 = call i32 (ptr, ...) @printf(ptr @7, i64 %calltmp3)
  %5 = call i32 (ptr, ...) @printf(ptr @9, ptr @8)
  %a34 = load i32, ptr %a3, align 4
  %calltmp5 = call i64 @abs(i32 %a34)
  %6 = call i32 (ptr, ...) @printf(ptr @10, i64 %calltmp5)
  %7 = call i32 (ptr, ...) @printf(ptr @12, ptr @11)
  %a46 = load i64, ptr %a4, align 4
  %calltmp7 = call i64 @abs(i64 %a46)
  %8 = call i32 (ptr, ...) @printf(ptr @13, i64 %calltmp7)
  %9 = call i32 (ptr, ...) @printf(ptr @15, ptr @14)
  store float -3.500000e+00, ptr %f1, align 4
  store double -9.987600e+01, ptr %f2, align 8
  %10 = call i32 (ptr, ...) @printf(ptr @17, ptr @16)
  %f18 = load float, ptr %f1, align 4
  %calltmp9 = call i64 @abs(float %f18)
  %11 = call i32 (ptr, ...) @printf(ptr @18, i64 %calltmp9)
  %12 = call i32 (ptr, ...) @printf(ptr @20, ptr @19)
  %f210 = load double, ptr %f2, align 8
  %calltmp11 = call i64 @abs(double %f210)
  %13 = call i32 (ptr, ...) @printf(ptr @21, i64 %calltmp11)
  %14 = call i32 (ptr, ...) @printf(ptr @23, ptr @22)
  %15 = call i32 (ptr, ...) @printf(ptr @25, ptr @24)
  %16 = call i32 (ptr, ...) @printf(ptr @27, ptr @26)
  %17 = call i32 (ptr, ...) @printf(ptr @29, ptr @28)
  %18 = call i32 (ptr, ...) @printf(ptr @31, ptr @30)
  %19 = call i32 (ptr, ...) @printf(ptr @33, ptr @32)
  %20 = call i32 (ptr, ...) @printf(ptr @35, ptr @34)
  %21 = call i32 (ptr, ...) @printf(ptr @37, ptr @36)
  %22 = call i32 (ptr, ...) @printf(ptr @39, ptr @38)
  %23 = call i32 (ptr, ...) @printf(ptr @41, ptr @40)
  %24 = call i32 (ptr, ...) @printf(ptr @43, ptr @42)
  %25 = call i32 (ptr, ...) @printf(ptr @45, ptr @44)
  %26 = call i32 (ptr, ...) @printf(ptr @47, ptr @46)
  %27 = call i32 (ptr, ...) @printf(ptr @49, ptr @48)
  %28 = call i32 (ptr, ...) @printf(ptr @51, ptr @50)
  %29 = call i32 (ptr, ...) @printf(ptr @53, ptr @52)
  %30 = call i32 (ptr, ...) @printf(ptr @55, ptr @54)
  %31 = call i32 (ptr, ...) @printf(ptr @57, ptr @56)
  %32 = call i32 (ptr, ...) @printf(ptr @59, ptr @58)
  %33 = call i32 (ptr, ...) @printf(ptr @61, ptr @60)
  %34 = call i32 (ptr, ...) @printf(ptr @63, ptr @62)
  ret i32 0
}
