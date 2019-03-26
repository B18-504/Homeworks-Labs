#ifndef Header_h
#define Header_h
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265

struct complex {
    float re; //действительная часть
    float im; //мнимая часть
    float arg; //аргумент
    float mod; //модуль числа
};

void complex_set (struct complex* num, float r, float i) { //задание комплексного числа по чего действительной и мнимой частям
    num->re = r;
    num->im = i;
    num->mod = sqrt(powf(num->re, 2) + powf(num->im, 2));
    if (num->re > 0) {
        num->arg = atanf(num->im/num->re);
    }
    else if ((num->re < 0) && (num->im > 0)) {
        num->arg = PI + atanf(num->im/num->re);
    }
    else {
        num->arg = -PI + atanf(num->im/num->re);
    }
}

void complex_print(struct complex* num) { //вывод комплексного числа в двух формах: алгебраической и тригонометрической
    if (num->im > 0) {
        printf("%f+%fi, ", num->re, num->im);
    }
    else {
        printf("%f%fi, ", num->re, num->im);
    }
    printf("%f(cos(%f rad)+isin(%f rad))\n", num->mod, num->arg, num->arg);
}

struct complex complex_math(struct complex* num1, char sign[1], struct complex* num2) { //алгебраические операции с комплексными числами
    struct complex mem;
    if (strncmp(sign, "+", 1) == 0) {
        mem.re = num1->re + num2->re;
        mem.im = num1->im + num2->im;
        mem.mod = sqrt(powf(mem.re, 2) + powf(mem.im, 2));
        if (mem.re > 0) {
            mem.arg = atanf(mem.im/mem.re);
        }
        else if ((mem.re < 0) && (mem.im > 0)) {
            mem.arg = PI + atanf(mem.im/mem.re);
        }
        else {
            mem.arg = -PI + atanf(mem.im/mem.re);
        }
    }
    else if (strncmp(sign, "-", 1) == 0) {
        mem.re = num1->re - num2->re;
        mem.im = num1->im - num2->im;
        mem.mod = sqrt(powf(mem.re, 2) + powf(mem.im, 2));
        if (mem.re > 0) {
            mem.arg = atanf(mem.im/mem.re);
        }
        else if ((mem.re < 0) && (mem.im > 0)) {
            mem.arg = PI + atanf(mem.im/mem.re);
        }
        else {
            mem.arg = -PI + atanf(mem.im/mem.re);
        }
    }
    else if (strncmp(sign, "*", 1) == 0) {
        mem.mod = num1->mod * num2->mod;
        mem.arg = num1->arg + num2->arg;
        mem.re = mem.mod*cosf(mem.arg);
        mem.im = mem.mod*sinf(mem.arg);
    }
    else if (strncmp(sign, "/", 1) == 0) {
        mem.mod = num1->mod / num2->mod;
        mem.arg = num1->arg - num2->arg;
        mem.re = mem.mod*cosf(mem.arg);
        mem.im = mem.mod*sinf(mem.arg);
    }
    else {
        printf("Complex_simple_math: operation is not executable\n");
        exit(228);
    }
    return mem;
}

struct complex complex_pow(struct complex* num, int pow) { //возведение комплексного числа в натуральную степень
    struct complex mem;
    if (pow < 0) {
        printf("Complex_pow: operation is not executable\n");
        exit(228);
    }
    else {
        mem.mod = powf(num->mod, pow);
        mem.arg = pow*num->arg;
        mem.re = mem.mod*cosf(mem.arg);
        mem.im = mem.mod*sinf(mem.arg);
    }
    return mem;
}

#endif
