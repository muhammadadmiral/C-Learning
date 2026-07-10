
/*
 * ============================================================
 *  010 — mathlib.h: Header untuk Math Library
 * ============================================================
 *  Contoh header file dengan include guards.
 *  Berisi DEKLARASI (prototype) saja, bukan implementasi.
 * ============================================================
 */

#ifndef MATHLIB_H
#define MATHLIB_H

/* -------------------------------------------------------
 * Konstanta
 * ------------------------------------------------------- */
#define MATHLIB_PI 3.14159265358979
#define MATHLIB_E 2.71828182845904
#define MATHLIB_VERSION "1.0.0"

/* -------------------------------------------------------
 * Function Prototypes
 * ------------------------------------------------------- */

/* Aritmatika dasar */
int math_add(int a, int b);
int math_subtract(int a, int b);
int math_multiply(int a, int b);
double math_divide(int a, int b);

/* Operasi lanjut */
long long math_power(int base, int exp);
int math_factorial(int n);
int math_gcd(int a, int b);
int math_lcm(int a, int b);

/* Utility */
int math_is_prime(int n);
int math_abs(int x);
int math_max(int a, int b);
int math_min(int a, int b);

#endif /* MATHLIB_H */
