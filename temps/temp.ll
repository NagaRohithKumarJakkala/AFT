; ModuleID = 'my_program'
source_filename = "my_program"

@0 = private unnamed_addr constant [29 x i8] c"=== COMPLEX NUMBER TESTS ===\00", align 1
@1 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@2 = private unnamed_addr constant [23 x i8] c"Test 1: Pure imaginary\00", align 1
@3 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@4 = private unnamed_addr constant [12 x i8] c"(%f + %fj)\0A\00", align 1
@5 = private unnamed_addr constant [24 x i8] c"Test 2: Complex literal\00", align 1
@6 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@7 = private unnamed_addr constant [12 x i8] c"(%f + %fj)\0A\00", align 1
@8 = private unnamed_addr constant [17 x i8] c"Test 3: Addition\00", align 1
@9 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@10 = private unnamed_addr constant [12 x i8] c"(%f + %fj)\0A\00", align 1
@11 = private unnamed_addr constant [20 x i8] c"Test 4: Subtraction\00", align 1
@12 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@13 = private unnamed_addr constant [12 x i8] c"(%f + %fj)\0A\00", align 1
@14 = private unnamed_addr constant [23 x i8] c"Test 5: Multiplication\00", align 1
@15 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@16 = private unnamed_addr constant [12 x i8] c"(%f + %fj)\0A\00", align 1
@17 = private unnamed_addr constant [17 x i8] c"Test 6: Division\00", align 1
@18 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@19 = private unnamed_addr constant [12 x i8] c"(%f + %fj)\0A\00", align 1
@20 = private unnamed_addr constant [25 x i8] c"Test 7: Scalar + complex\00", align 1
@21 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@22 = private unnamed_addr constant [12 x i8] c"(%f + %fj)\0A\00", align 1
@23 = private unnamed_addr constant [17 x i8] c"Test 8: Equality\00", align 1
@24 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@25 = private unnamed_addr constant [15 x i8] c"z6 == z7: true\00", align 1
@26 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@27 = private unnamed_addr constant [15 x i8] c"z6 != z8: true\00", align 1
@28 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@29 = private unnamed_addr constant [18 x i8] c"Test 9: Magnitude\00", align 1
@30 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@31 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@32 = private unnamed_addr constant [19 x i8] c"Test 10: Conjugate\00", align 1
@33 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@34 = private unnamed_addr constant [12 x i8] c"(%f + %fj)\0A\00", align 1
@35 = private unnamed_addr constant [18 x i8] c"Test 11: Argument\00", align 1
@36 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@37 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@38 = private unnamed_addr constant [27 x i8] c"=== ALL TESTS COMPLETE ===\00", align 1
@39 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1

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
  %arg_z = alloca double, align 8
  %z1149 = alloca { double, double }, align 8
  %conj_z = alloca { double, double }, align 8
  %z10 = alloca { double, double }, align 8
  %mag = alloca double, align 8
  %z9 = alloca { double, double }, align 8
  %z8 = alloca { double, double }, align 8
  %z7 = alloca { double, double }, align 8
  %z6 = alloca { double, double }, align 8
  %z5 = alloca { double, double }, align 8
  %quot = alloca { double, double }, align 8
  %prod = alloca { double, double }, align 8
  %diff = alloca { double, double }, align 8
  %sum = alloca { double, double }, align 8
  %z4 = alloca { double, double }, align 8
  %z3 = alloca { double, double }, align 8
  %z2 = alloca { double, double }, align 8
  %z1 = alloca { double, double }, align 8
  %0 = call i32 (ptr, ...) @printf(ptr @1, ptr @0)
  %1 = call i32 (ptr, ...) @printf(ptr @3, ptr @2)
  store { double, double } { double 0.000000e+00, double 5.000000e+00 }, ptr %z1, align 8
  %z11 = load { double, double }, ptr %z1, align 8
  %re = extractvalue { double, double } %z11, 0
  %im = extractvalue { double, double } %z11, 1
  %2 = call i32 (ptr, ...) @printf(ptr @4, double %re, double %im)
  %3 = call i32 (ptr, ...) @printf(ptr @6, ptr @5)
  store { double, double } { double 3.000000e+00, double 4.000000e+00 }, ptr %z2, align 8
  %z22 = load { double, double }, ptr %z2, align 8
  %re3 = extractvalue { double, double } %z22, 0
  %im4 = extractvalue { double, double } %z22, 1
  %4 = call i32 (ptr, ...) @printf(ptr @7, double %re3, double %im4)
  %5 = call i32 (ptr, ...) @printf(ptr @9, ptr @8)
  store { double, double } { double 1.000000e+00, double 2.000000e+00 }, ptr %z3, align 8
  store { double, double } { double 3.000000e+00, double 4.000000e+00 }, ptr %z4, align 8
  %z35 = load { double, double }, ptr %z3, align 8
  %z46 = load { double, double }, ptr %z4, align 8
  %L.re = extractvalue { double, double } %z35, 0
  %L.im = extractvalue { double, double } %z35, 1
  %R.re = extractvalue { double, double } %z46, 0
  %R.im = extractvalue { double, double } %z46, 1
  %add.re = fadd double %L.re, %R.re
  %add.im = fadd double %L.im, %R.im
  %6 = insertvalue { double, double } undef, double %add.re, 0
  %7 = insertvalue { double, double } %6, double %add.im, 1
  store { double, double } %7, ptr %sum, align 8
  %sum7 = load { double, double }, ptr %sum, align 8
  %re8 = extractvalue { double, double } %sum7, 0
  %im9 = extractvalue { double, double } %sum7, 1
  %8 = call i32 (ptr, ...) @printf(ptr @10, double %re8, double %im9)
  %9 = call i32 (ptr, ...) @printf(ptr @12, ptr @11)
  %z410 = load { double, double }, ptr %z4, align 8
  %z311 = load { double, double }, ptr %z3, align 8
  %L.re12 = extractvalue { double, double } %z410, 0
  %L.im13 = extractvalue { double, double } %z410, 1
  %R.re14 = extractvalue { double, double } %z311, 0
  %R.im15 = extractvalue { double, double } %z311, 1
  %sub.re = fsub double %L.re12, %R.re14
  %sub.im = fsub double %L.im13, %R.im15
  %10 = insertvalue { double, double } undef, double %sub.re, 0
  %11 = insertvalue { double, double } %10, double %sub.im, 1
  store { double, double } %11, ptr %diff, align 8
  %diff16 = load { double, double }, ptr %diff, align 8
  %re17 = extractvalue { double, double } %diff16, 0
  %im18 = extractvalue { double, double } %diff16, 1
  %12 = call i32 (ptr, ...) @printf(ptr @13, double %re17, double %im18)
  %13 = call i32 (ptr, ...) @printf(ptr @15, ptr @14)
  store { double, double } { double -5.000000e+00, double 1.000000e+01 }, ptr %prod, align 8
  %prod19 = load { double, double }, ptr %prod, align 8
  %re20 = extractvalue { double, double } %prod19, 0
  %im21 = extractvalue { double, double } %prod19, 1
  %14 = call i32 (ptr, ...) @printf(ptr @16, double %re20, double %im21)
  %15 = call i32 (ptr, ...) @printf(ptr @18, ptr @17)
  store { double, double } { double 2.200000e+00, double -4.000000e-01 }, ptr %quot, align 8
  %quot22 = load { double, double }, ptr %quot, align 8
  %re23 = extractvalue { double, double } %quot22, 0
  %im24 = extractvalue { double, double } %quot22, 1
  %16 = call i32 (ptr, ...) @printf(ptr @19, double %re23, double %im24)
  %17 = call i32 (ptr, ...) @printf(ptr @21, ptr @20)
  store { double, double } { double 8.000000e+00, double 4.000000e+00 }, ptr %z5, align 8
  %z525 = load { double, double }, ptr %z5, align 8
  %re26 = extractvalue { double, double } %z525, 0
  %im27 = extractvalue { double, double } %z525, 1
  %18 = call i32 (ptr, ...) @printf(ptr @22, double %re26, double %im27)
  %19 = call i32 (ptr, ...) @printf(ptr @24, ptr @23)
  store { double, double } { double 3.000000e+00, double 4.000000e+00 }, ptr %z6, align 8
  store { double, double } { double 3.000000e+00, double 4.000000e+00 }, ptr %z7, align 8
  store { double, double } { double 5.000000e+00, double 6.000000e+00 }, ptr %z8, align 8
  %z628 = load { double, double }, ptr %z6, align 8
  %z729 = load { double, double }, ptr %z7, align 8
  %L.re30 = extractvalue { double, double } %z628, 0
  %L.im31 = extractvalue { double, double } %z628, 1
  %R.re32 = extractvalue { double, double } %z729, 0
  %R.im33 = extractvalue { double, double } %z729, 1
  %re.eq = fcmp oeq double %L.re30, %R.re32
  %im.eq = fcmp oeq double %L.im31, %R.im33
  %complex.eq = and i1 %re.eq, %im.eq
  br i1 %complex.eq, label %then, label %else

then:                                             ; preds = %entry
  %20 = call i32 (ptr, ...) @printf(ptr @26, ptr @25)
  br label %ifend

else:                                             ; preds = %entry
  br label %ifend

ifend:                                            ; preds = %else, %then
  %z634 = load { double, double }, ptr %z6, align 8
  %z835 = load { double, double }, ptr %z8, align 8
  %L.re36 = extractvalue { double, double } %z634, 0
  %L.im37 = extractvalue { double, double } %z634, 1
  %R.re38 = extractvalue { double, double } %z835, 0
  %R.im39 = extractvalue { double, double } %z835, 1
  %re.ne = fcmp one double %L.re36, %R.re38
  %im.ne = fcmp one double %L.im37, %R.im39
  %complex.ne = or i1 %re.ne, %im.ne
  br i1 %complex.ne, label %then40, label %else41

then40:                                           ; preds = %ifend
  %21 = call i32 (ptr, ...) @printf(ptr @28, ptr @27)
  br label %ifend42

else41:                                           ; preds = %ifend
  br label %ifend42

ifend42:                                          ; preds = %else41, %then40
  %22 = call i32 (ptr, ...) @printf(ptr @30, ptr @29)
  store { double, double } { double 3.000000e+00, double 4.000000e+00 }, ptr %z9, align 8
  %z943 = load { double, double }, ptr %z9, align 8
  %23 = call double @aft_mag_c64({ double, double } %z943)
  store double %23, ptr %mag, align 8
  %mag44 = load double, ptr %mag, align 8
  %24 = call i32 (ptr, ...) @printf(ptr @31, double %mag44)
  %25 = call i32 (ptr, ...) @printf(ptr @33, ptr @32)
  store { double, double } { double 3.000000e+00, double 4.000000e+00 }, ptr %z10, align 8
  %z1045 = load { double, double }, ptr %z10, align 8
  %26 = call { double, double } @aft_conj_c64({ double, double } %z1045)
  store { double, double } %26, ptr %conj_z, align 8
  %conj_z46 = load { double, double }, ptr %conj_z, align 8
  %re47 = extractvalue { double, double } %conj_z46, 0
  %im48 = extractvalue { double, double } %conj_z46, 1
  %27 = call i32 (ptr, ...) @printf(ptr @34, double %re47, double %im48)
  %28 = call i32 (ptr, ...) @printf(ptr @36, ptr @35)
  store { double, double } { double 1.000000e+00, double 1.000000e+00 }, ptr %z1149, align 8
  %z1150 = load { double, double }, ptr %z1149, align 8
  %29 = call double @aft_arg_c64({ double, double } %z1150)
  store double %29, ptr %arg_z, align 8
  %arg_z51 = load double, ptr %arg_z, align 8
  %30 = call i32 (ptr, ...) @printf(ptr @37, double %arg_z51)
  %31 = call i32 (ptr, ...) @printf(ptr @39, ptr @38)
  ret void
}

declare double @aft_mag_c64({ double, double })

declare { double, double } @aft_conj_c64({ double, double })

declare double @aft_arg_c64({ double, double })
