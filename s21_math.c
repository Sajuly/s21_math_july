#include "s21_math.h"

long double s21_log(double x) {
    int i = 2;
    long double result = x - 1, st = x - 1, a = x;
    if (x < 0) {
        result = s21_NAN;
    } else if (x == 0.0) {
        result = -s21_INF;
    } else if (x < 2.0 + 1e-16) {
        x = x - 1;
        while (s21_fabs((double)st / i) > 1e-16) {
            st *= -1 * x;
            result += st / i;
            ++i;
        }
    } else {
        int count = 0;
        while (a > 1.0) {
            a /= 10;
            count++;
        }
        result = s21_log(a) + count * 2.302585092994;
    }
    return result;
}

long double s21_pow(double base, double exp) {
    long double result = 1;
    if (exp == (long int)exp) {
        if (exp >= 0) {
            for (int i = 1; i <= exp; i++)
                result *= base;
        } else {
            base = 1/base;
            exp *= -1;
            for (int i = 1; i <= exp; i++)
                result *= base;
        }
    } else {
        if (base == 0) {
            result = 0;
            if (exp < 0)
                result = s21_INF;
        } else if (base < 0) {
            result = s21_NAN;
        } else {
            result = s21_exp(exp * s21_log(base));
        }
    }
    return result;
}

long double s21_sqrt(double x) {
    double del = 1;
    long double r = 0;
    double i = 0;
    if (x > 0) {
        for (int j = 0; j < 20; j++) {
            i = 0;
            for (; (r+i)*(r+i) < x; i += del) {}
            i -= del;
            r += i;
            del /= 10;
        }
    } else if (x < 0) {
        r = s21_NAN;
    }
    long double result = r;
    return result;
}

long double s21_tan(double x) {
    long double a = s21_sin(x);
    long double b = s21_cos(x);
    long double tang = a / b;
    return tang;
}

long double s21_ceil(double x) {
    long int cei = (long int)x;
    if (cei < x) {
        cei++;
    }
    return x == 0 ? 0: cei;
}

long double s21_exp(double x) {
    long double r = 1, y = 1;
    long double i = 1;
    int z = 0;
    if (x < 0) {
        x *= -1;
        z = 1;
    }
    while (s21_fabs(r) > 1e-17) {
    r *= x / i;
        i++;
        y += r;
        if (y > 1.7976931348623157e308) {
            y = s21_INF;
            break;
        }
    }
    if (z == 1) {
        if (y > 1.7976931348623157e308)
            y = 0;
        else
            y = 1. / y;
    }
    if (y > 1.7976931348623157e308)
        y = s21_INF;
    return y;
}

long double s21_floor(double x) {
    long int cei = (long int)x;
    if (x < 0) {
        if (cei > x) {
            cei--;
        }
    }
    return x == 0 ? 0: cei;
}

int s21_abs(int x) {
    return x > 0 ? x : -x;
}

long double s21_fabs(double x) {
    return x > 0 ? x : -x;
}

long double s21_sin(double x) {
    while (x - s21_PI > s21_PI/2) {
        x -= 2*s21_PI;
    }
    while (x + s21_PI < s21_PI/2) {
        x += 2*s21_PI;
    }
    double n = x;
    double sum = 0.0;
    int i = 1;
    sum += n;
    n *= -1.0 * x * x / ((2 * i) * (2 * i + 1));
    i++;
    while ((n > 0.0 ? n : -n) > 1E-16) {
        sum += n;
        n *= -1.0 * x * x / ((2 * i) * (2 * i + 1));
        i++;
    }
    return sum;
}

long double s21_cos(double x) {
    while (x - s21_PI > s21_PI/2) {
        x -= 2*s21_PI;
    }
    while (x + s21_PI < s21_PI/2) {
        x += 2*s21_PI;
    }
    long double f_cos = s21_sqrt(1-s21_pow(s21_sin(x), 2));
    if (x < s21_PI / 2 && x > -s21_PI / 2) {
        x = f_cos;
    } else {
        x = -f_cos;
    }
    return  x;
}

long double s21_fmod(double x, double y) {
    long double res = s21_fabs(x);
    y = s21_fabs(y);
    if (y == 0)
        x = s21_NAN;
    int i = 1;
    while (res >= y) {
        res = s21_fabs(x) - y * i;
        i++;
    }
return (x < 0) ? -res : res;
}

long double s21_asin(double x) {
    long double tmp = x, result = x;
    long double i = 1;
    while (s21_fabs(tmp) > 1e-16) {
        if (x < -1 || x > 1) {
            result = s21_NAN;
            break;
        }
        if (x == 1 || x == -1) {
            result = s21_PI / 2 * x;
            break;
        }
        tmp *= x * x * (2 * i - 1) * (2 * i) * (2 * i - 1) / ((2 * i + 1) * 4 * i * i);
        i += 1;
        result += tmp;
    }
  return result;
}

long double s21_acos(double x) {
    long double result = s21_PI / 2 - s21_fabs(s21_asin(x));
    return (x < 0) ? (s21_PI - (result)) : (result);
}

long double s21_atan(double x) {
    long double atang = s21_acos(1 / s21_sqrt(1 + x * x));
    return x < 0 ? -atang: atang;
}