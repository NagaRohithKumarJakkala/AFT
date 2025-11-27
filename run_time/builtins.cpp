#include <cmath>
#include <complex>

extern "C" {


// |x| for double
double aft_abs_f64(double x) {
    return std::fabs(x);
}

// |x| for signed 64-bit integer
long long aft_abs_i64(long long x) {
    return x < 0 ? -x : x;
}

double aft_sqrt_f64(double x) { return std::sqrt(x); }

double aft_pow_f64(double x, double y) { return std::pow(x, y); }

double aft_exp_f64(double x) { return std::exp(x); }

double aft_ln_f64(double x) { return std::log(x); }

double aft_log10_f64(double x) { return std::log10(x); }

double aft_log2_f64(double x) { return std::log2(x); }


double aft_sin_f64(double x) { return std::sin(x); }
double aft_cos_f64(double x) { return std::cos(x); }
double aft_tan_f64(double x) { return std::tan(x); }

double aft_asin_f64(double x) { return std::asin(x); }
double aft_acos_f64(double x) { return std::acos(x); }
double aft_atan_f64(double x) { return std::atan(x); }

// sec(x) = 1 / cos(x)
double aft_sec_f64(double x) {
    return 1.0 / std::cos(x);
}

// cosec(x) = 1 / sin(x)
double aft_cosec_f64(double x) {
    return 1.0 / std::sin(x);
}

// cot(x) = cos(x) / sin(x)
double aft_cot_f64(double x) {
    return std::cos(x) / std::sin(x);
}


struct aft_c64 {
    double re;
    double im;
};

// conj(z)
aft_c64 aft_conj_c64(aft_c64 z) {
    std::complex<double> c(z.re, z.im);
    std::complex<double> r = std::conj(c);
    aft_c64 out { std::real(r), std::imag(r) };
    return out;
}

// |z| (magnitude)
double aft_mag_c64(aft_c64 z) {
    std::complex<double> c(z.re, z.im);
    return std::abs(c);
}

// arg(z) (argument)
double aft_arg_c64(aft_c64 z) {
    std::complex<double> c(z.re, z.im);
    return std::arg(c);
}

} // extern "C"
