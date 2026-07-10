/*
 * ============================================================
 *  010 — mathlib.c: Implementasi Math Library
 * ============================================================
 *  File ini berisi IMPLEMENTASI (body) dari fungsi-fungsi
 *  yang dideklarasikan di mathlib.h
 * ============================================================
 */

#include "mathlib.h"

/* -------------------------------------------------------
 * Aritmatika Dasar
 * ------------------------------------------------------- */

int math_add(int a, int b) {
    return a + b;
}

int math_subtract(int a, int b) {
    return a - b;
}

int math_multiply(int a, int b) {
    return a * b;
}

double math_divide(int a, int b) {
    if (b == 0) return 0.0;   /* Avoid division by zero */
    return (double)a / b;
}

/* -------------------------------------------------------
 * Operasi Lanjut
 * ------------------------------------------------------- */

long long math_power(int base, int exp) {
    if (exp < 0) return 0;

    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int math_factorial(int n) {
    if (n < 0) return -1;   /* Error: negatif */
    if (n <= 1) return 1;

    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int math_gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int math_lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    int abs_a = math_abs(a);
    int abs_b = math_abs(b);
    return abs_a / math_gcd(abs_a, abs_b) * abs_b;
}

/* -------------------------------------------------------
 * Utility
 * ------------------------------------------------------- */

int math_is_prime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0) return 0;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int math_abs(int x) {
    return x < 0 ? -x : x;
}

int math_max(int a, int b) {
    return a > b ? a : b;
}

int math_min(int a, int b) {
    return a < b ? a : b;
}
