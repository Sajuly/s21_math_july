#include <math.h>
#include <stdio.h>
#include "s21_math.h"
#include <stdlib.h>


int main() {

    long double atang_math, arc_tang_j;
    long double tan_math, tan_j;
    long double ceil_math, ceil_j;
    long double exp_math, exp_j;
    long double floor_math, floor_j;
    long double fabs_math, fabs_j;
    long double sin_math, sin_j;
    long double cos_math, cos_j;
    long double acos_math, acos_j;
    long double asin_math, asin_j;
    long double fmod_math, fmod_j;
    long double pow_math, pow_j;
    long double sqrt_math, sqrt_j;
    int abs_math, abs_j;


    int d = 123365;
    double y = -6.222222;
    double x = -7.712388980;
   
 
    printf("\n");

    // tan_math = tan(x);
    // tan_j = s21_tan(x);
    // printf("    tan = %Lf\n", tan_math);
    // printf("s21_tan = %Lf\n\n", tan_j);

    sin_math = sin(x);
    printf("sin_math = %Lf\n", sin_math);
    sin_j = s21_sin(x);
    printf("   sin_j = %Lf\n\n", sin_math);

    // atang_math = atan(y);
    // arc_tang_j = s21_atan(y);
    // printf("    atan = %Lf\n", atang_math);
    // printf("s21_atan = %Lf\n\n", arc_tang_j);

    // tang_math = ceil(x);
    // ceil_j = s21_ceil(x);
    // printf("ceil = %Lf\n", tang_math);
    // printf("s21_ceil = %Lf\n\n", ceil_j);

    // exp_math = exp(x);
    // printf("exp_math = %Lf\n", exp_math);
    // exp_j = s21_exp(x);
    // printf(" s21_exp = %Lf\n\n", exp_j);

    // floor_math = floor(x);
    // floor_j = s21_floor(x);
    // printf("floor_math = %Lf\n", floor_math);
    // printf(" s21_floor = %Lf\n", floor_j);

    // abs_math = abs(d);
    // abs_j = s21_abs(d);
    // printf("abs_math = %d\n", abs_math);
    // printf("   abs_j = %d\n\n", abs_j);

    // fabs_math = fabs(sin(x));
    // fabs_j = s21_fabs(x);
    // printf("fabs_math = %Lf\n", fabs_math);
    // printf("   fabs_j = %Lf\n\n", fabs_j);

    cos_math = cos(x);
    cos_j = s21_cos(x);
    printf("cos_math = %Lf\n", cos_math);
    printf("   cos_j = %Lf\n\n", cos_j);

    // asin_math = asin(x);
    // printf("asin_math = %Lf\n", asin_math);
    // asin_j = s21_asin(x);
    // printf("   asin_j = %Lf\n\n", asin_j);

    // acos_math = acos(x);
    // printf("acos_math = %Lf\n", acos_math);
    // acos_j = s21_acos(x);
    // printf("   acos_j = %Lf\n\n", acos_j);

    // fmod_math = fmod(x, y);
    // printf("fmod_math = %Lf\n", fmod_math);
    // fmod_j = s21_fmod(x, y);
    // printf("   fmod_j = %Lf\n\n", fmod_j);

    // pow_math = pow(x, y);
    // printf("pow_math = %Lf\n", pow_math);
    // pow_j = s21_pow(x, y);
    // printf("   pow_j = %Lf\n\n", pow_j);

    // sqrt_math = sqrt(x);
    // printf("sqrt_math = %Lf\n", sqrt_math);
    // sqrt_j = s21_sqrt(x);
    // printf("   sqrt_j = %Lf\n\n", sqrt_j);

    return 0;
}
