#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>

#define s21_NAN 0.0 / 0.0
#define s21_INF 1.0 / 0.0

#define s21_e 2.71828182845904523536
#define s21_PI 3.14159265359


long double s21_atan(double x);    // вычисляет арктангенс
long double s21_tan(double x) ;    // вычисляет тангенс
long double s21_ceil(double x);    // возвращает ближайшее целое число, не меньшее заданного значения
long double s21_exp(double x);     // возвращает значение e, возведенное в заданную степень
long double s21_floor(double x);   // возвращает ближайшее целое число, не превышающее заданное значение

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_fmod(double x, double y);
long double s21_asin(double x);
long double s21_acos(double x);

long double s21_log(double x);
long double ss21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sqrt(double x);

#endif  // SRC_S21_MATH_H_