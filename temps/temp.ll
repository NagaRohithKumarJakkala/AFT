; ModuleID = 'my_program'
source_filename = "my_program"

@0 = private unnamed_addr constant [29 x i8] c"=== COMPLEX NUMBER TESTS ===\00", align 1
@1 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@2 = private unnamed_addr constant [23 x i8] c"Test 1: Pure imaginary\00", align 1
@3 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@4 = private unnamed_addr constant [10 x i8] c"(%f, %f)\0A\00", align 1
@5 = private unnamed_addr constant [24 x i8] c"Test 2: Complex literal\00", align 1
@6 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@7 = private unnamed_addr constant [10 x i8] c"(%f, %f)\0A\00", align 1
@8 = private unnamed_addr constant [17 x i8] c"Test 3: Addition\00", align 1
@9 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@10 = private unnamed_addr constant [10 x i8] c"(%f, %f)\0A\00", align 1
@11 = private unnamed_addr constant [20 x i8] c"Test 4: Subtraction\00", align 1
@12 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@13 = private unnamed_addr constant [10 x i8] c"(%f, %f)\0A\00", align 1
@14 = private unnamed_addr constant [23 x i8] c"Test 5: Multiplication\00", align 1
@15 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@16 = private unnamed_addr constant [10 x i8] c"(%f, %f)\0A\00", align 1
@17 = private unnamed_addr constant [17 x i8] c"Test 6: Division\00", align 1
@18 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@19 = private unnamed_addr constant [10 x i8] c"(%f, %f)\0A\00", align 1
@20 = private unnamed_addr constant [25 x i8] c"Test 7: Scalar + complex\00", align 1
@21 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@22 = private unnamed_addr constant [10 x i8] c"(%f, %f)\0A\00", align 1
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
@34 = private unnamed_addr constant [10 x i8] c"(%f, %f)\0A\00", align 1
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
  %z1123 = alloca { double, double }, align 8
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
  %2 = extractvalue { double, double } %z11, 0
  %3 = extractvalue { double, double } %z11, 1
  %4 = call i32 (ptr, ...) @printf(ptr @4, double %2, double %3)
  %5 = call i32 (ptr, ...) @printf(ptr @6, ptr @5)
  store { double, double } { double 3.000000e+00, double 4.000000e+00 }, ptr %z2, align 8
  %z22 = load { double, double }, ptr %z2, align 8
  %6 = extractvalue { double, double } %z22, 0
  %7 = extractvalue { double, double } %z22, 1
  %8 = call i32 (ptr, ...) @printf(ptr @7, double %6, double %7)
  %9 = call i32 (ptr, ...) @printf(ptr @9, ptr @8)
  store { double, double } { double 1.000000e+00, double 2.000000e+00 }, ptr %z3, align 8
  store { double, double } { double 3.000000e+00, double 4.000000e+00 }, ptr %z4, align 8
  %z33 = load { double, double }, ptr %z3, align 8
  %z44 = load { double, double }, ptr %z4, align 8
  %10 = extractvalue { double, double } %z33, 0
  %11 = extractvalue { double, double } %z33, 1
  %12 = extractvalue { double, double } %z44, 0
  %13 = extractvalue { double, double } %z44, 1
  %14 = fadd double %10, %12
  %15 = fadd double %11, %13
  %16 = insertvalue { double, double } undef, double %14, 0
  %17 = insertvalue { double, double } %16, double %15, 1
  store { double, double } %17, ptr %sum, align 8
  %sum5 = load { double, double }, ptr %sum, align 8
  %18 = extractvalue { double, double } %sum5, 0
  %19 = extractvalue { double, double } %sum5, 1
  %20 = call i32 (ptr, ...) @printf(ptr @10, double %18, double %19)
  %21 = call i32 (ptr, ...) @printf(ptr @12, ptr @11)
  %z46 = load { double, double }, ptr %z4, align 8
  %z37 = load { double, double }, ptr %z3, align 8
  %22 = extractvalue { double, double } %z46, 0
  %23 = extractvalue { double, double } %z46, 1
  %24 = extractvalue { double, double } %z37, 0
  %25 = extractvalue { double, double } %z37, 1
  %26 = fsub double %22, %24
  %27 = fsub double %23, %25
  %28 = insertvalue { double, double } undef, double %26, 0
  %29 = insertvalue { double, double } %28, double %27, 1
  store { double, double } %29, ptr %diff, align 8
  %diff8 = load { double, double }, ptr %diff, align 8
  %30 = extractvalue { double, double } %diff8, 0
  %31 = extractvalue { double, double } %diff8, 1
  %32 = call i32 (ptr, ...) @printf(ptr @13, double %30, double %31)
  %33 = call i32 (ptr, ...) @printf(ptr @15, ptr @14)
  store { double, double } { double -5.000000e+00, double 1.000000e+01 }, ptr %prod, align 8
  %prod9 = load { double, double }, ptr %prod, align 8
  %34 = extractvalue { double, double } %prod9, 0
  %35 = extractvalue { double, double } %prod9, 1
  %36 = call i32 (ptr, ...) @printf(ptr @16, double %34, double %35)
  %37 = call i32 (ptr, ...) @printf(ptr @18, ptr @17)
  store { double, double } { double 2.200000e+00, double -4.000000e-01 }, ptr %quot, align 8
  %quot10 = load { double, double }, ptr %quot, align 8
  %38 = extractvalue { double, double } %quot10, 0
  %39 = extractvalue { double, double } %quot10, 1
  %40 = call i32 (ptr, ...) @printf(ptr @19, double %38, double %39)
  %41 = call i32 (ptr, ...) @printf(ptr @21, ptr @20)
  store { double, double } { double 8.000000e+00, double 4.000000e+00 }, ptr %z5, align 8
  %z511 = load { double, double }, ptr %z5, align 8
  %42 = extractvalue { double, double } %z511, 0
  %43 = extractvalue { double, double } %z511, 1
  %44 = call i32 (ptr, ...) @printf(ptr @22, double %42, double %43)
  %45 = call i32 (ptr, ...) @printf(ptr @24, ptr @23)
  store { double, double } { double 3.000000e+00, double 4.000000e+00 }, ptr %z6, align 8
  store { double, double } { double 3.000000e+00, double 4.000000e+00 }, ptr %z7, align 8
  store { double, double } { double 5.000000e+00, double 6.000000e+00 }, ptr %z8, align 8
  %z612 = load { double, double }, ptr %z6, align 8
  %z713 = load { double, double }, ptr %z7, align 8
  %46 = extractvalue { double, double } %z612, 0
  %47 = extractvalue { double, double } %z612, 1
  %48 = extractvalue { double, double } %z713, 0
  %49 = extractvalue { double, double } %z713, 1
  %50 = fcmp oeq double %46, %48
  %51 = fcmp oeq double %47, %49
  %52 = and i1 %50, %51
  br i1 %52, label %then, label %else

then:                                             ; preds = %entry
  %53 = call i32 (ptr, ...) @printf(ptr @26, ptr @25)
  br label %ifend

else:                                             ; preds = %entry
  br label %ifend

ifend:                                            ; preds = %else, %then
  %z614 = load { double, double }, ptr %z6, align 8
  %z815 = load { double, double }, ptr %z8, align 8
  %54 = extractvalue { double, double } %z614, 0
  %55 = extractvalue { double, double } %z614, 1
  %56 = extractvalue { double, double } %z815, 0
  %57 = extractvalue { double, double } %z815, 1
  br <null operand!>, label %then16, label %else17

then16:                                           ; preds = %ifend
  %58 = call i32 (ptr, ...) @printf(ptr @28, ptr @27)
  br label %ifend18

else17:                                           ; preds = %ifend
  br label %ifend18

ifend18:                                          ; preds = %else17, %then16
  %59 = call i32 (ptr, ...) @printf(ptr @30, ptr @29)
  store { double, double } { double 3.000000e+00, double 4.000000e+00 }, ptr %z9, align 8
  %z919 = load { double, double }, ptr %z9, align 8
  %60 = call double @aft_mag_c64({ double, double } %z919)
  store double %60, ptr %mag, align 8
  %mag20 = load double, ptr %mag, align 8
  %61 = call i32 (ptr, ...) @printf(ptr @31, double %mag20)
  %62 = call i32 (ptr, ...) @printf(ptr @33, ptr @32)
  store { double, double } { double 3.000000e+00, double 4.000000e+00 }, ptr %z10, align 8
  %z1021 = load { double, double }, ptr %z10, align 8
  %63 = call { double, double } @aft_conj_c64({ double, double } %z1021)
  store { double, double } %63, ptr %conj_z, align 8
  %conj_z22 = load { double, double }, ptr %conj_z, align 8
  %64 = extractvalue { double, double } %conj_z22, 0
  %65 = extractvalue { double, double } %conj_z22, 1
  %66 = call i32 (ptr, ...) @printf(ptr @34, double %64, double %65)
  %67 = call i32 (ptr, ...) @printf(ptr @36, ptr @35)
  store { double, double } { double 1.000000e+00, double 1.000000e+00 }, ptr %z1123, align 8
  %z1124 = load { double, double }, ptr %z1123, align 8
  %68 = call double @aft_arg_c64({ double, double } %z1124)
  store double %68, ptr %arg_z, align 8
  %arg_z25 = load double, ptr %arg_z, align 8
  %69 = call i32 (ptr, ...) @printf(ptr @37, double %arg_z25)
  %70 = call i32 (ptr, ...) @printf(ptr @39, ptr @38)
  ret void
}

declare double @aft_mag_c64({ double, double })

declare { double, double } @aft_conj_c64({ double, double })

declare double @aft_arg_c64({ double, double })
