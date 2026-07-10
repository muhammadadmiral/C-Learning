/*
 * ============================================================
 *  011 — Rekursi: Contoh Kode Utama
 * ============================================================
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o program main.c
 *    ./program
 * ============================================================
 */

#include <stdio.h>
#include <string.h>

/* -------------------------------------------------------
 * Function Prototypes
 * ------------------------------------------------------- */

/* Basics */
void hitung_mundur(int n);
int factorial(int n);
int factorial_tail(int n, int acc);

/* Fibonacci */
int fib_naive(int n);
long long fib_memo(int n);

/* Power */
long long power_simple(int base, int exp);
long long power_fast(int base, int exp);

/* Classic */
void hanoi(int n, char from, char to, char aux);

/* Utility */
int sum_recursive(int n);
int sum_array(const int arr[], int n);

/* Memoization storage */
#define MAX_FIB 100
static long long memo[MAX_FIB];
static int computed[MAX_FIB];

int main(void) {

    printf("╔══════════════════════════════════════════╗\n");
    printf("║  011 — Rekursi                           ║\n");
    printf("╚══════════════════════════════════════════╝\n\n");

    /* -------------------------------------------------------
     * 1. REKURSI DASAR — Hitung Mundur
     * ------------------------------------------------------- */
    printf("--- 1. Hitung Mundur (Rekursif) ---\n\n  ");
    hitung_mundur(5);
    printf("\n");

    /* -------------------------------------------------------
     * 2. FACTORIAL
     * ------------------------------------------------------- */
    printf("\n--- 2. Factorial ---\n\n");

    for (int i = 0; i <= 10; i++) {
        printf("  %2d! = %d\n", i, factorial(i));
    }

    /* Tail recursive version */
    printf("\n  Tail recursive: 12! = %d\n", factorial_tail(12, 1));

    /* -------------------------------------------------------
     * 3. SUM REKURSIF
     * ------------------------------------------------------- */
    printf("\n--- 3. Sum Rekursif ---\n\n");

    printf("  sum(1..10)  = %d\n", sum_recursive(10));
    printf("  sum(1..100) = %d\n", sum_recursive(100));

    int arr[] = {3, 7, 1, 9, 4};
    printf("  sum([3,7,1,9,4]) = %d\n", sum_array(arr, 5));

    /* -------------------------------------------------------
     * 4. FIBONACCI — Naif vs Memoized
     * ------------------------------------------------------- */
    printf("\n--- 4. Fibonacci ---\n\n");

    printf("  Fibonacci (naif): ");
    for (int i = 0; i <= 15; i++) {
        printf("%d ", fib_naive(i));
    }
    printf("\n");

    /* Memoized — bisa hitung jauh lebih besar */
    memset(computed, 0, sizeof(computed));
    memset(memo, 0, sizeof(memo));

    printf("  Fibonacci (memo): ");
    for (int i = 0; i <= 15; i++) {
        printf("%lld ", fib_memo(i));
    }
    printf("\n");

    /* Benchmark: fib(40) */
    memset(computed, 0, sizeof(computed));
    memset(memo, 0, sizeof(memo));
    printf("\n  fib_memo(40) = %lld (instant!)\n", fib_memo(40));
    printf("  fib_memo(50) = %lld\n", fib_memo(50));
    printf("  (fib_naive(40) would take ~40 seconds...)\n");

    /* -------------------------------------------------------
     * 5. POWER — Simple vs Fast
     * ------------------------------------------------------- */
    printf("\n--- 5. Power ---\n\n");

    printf("  power_simple(2, 10) = %lld\n", power_simple(2, 10));
    printf("  power_fast(2, 10)   = %lld\n", power_fast(2, 10));
    printf("  power_fast(3, 20)   = %lld\n", power_fast(3, 20));
    printf("  power_fast(2, 0)    = %lld\n", power_fast(2, 0));
    printf("  power_fast(5, 1)    = %lld\n", power_fast(5, 1));

    /* -------------------------------------------------------
     * 6. TOWER OF HANOI
     * ------------------------------------------------------- */
    printf("\n--- 6. Tower of Hanoi (3 disks) ---\n\n");

    hanoi(3, 'A', 'C', 'B');
    printf("  Total langkah: %d (2^n - 1 = 7)\n", (1 << 3) - 1);

    printf("\n  Tower of Hanoi (4 disks):\n\n");
    hanoi(4, 'A', 'C', 'B');
    printf("  Total langkah: %d\n", (1 << 4) - 1);

    /* -------------------------------------------------------
     * 7. REKURSI vs ITERASI — Perbandingan
     * ------------------------------------------------------- */
    printf("\n--- 7. Rekursi vs Iterasi ---\n\n");

    /* Factorial iteratif */
    long long fact_iter = 1;
    int n = 10;
    for (int i = 2; i <= n; i++) {
        fact_iter *= i;
    }
    printf("  Factorial %d:\n", n);
    printf("    Rekursif : %d\n", factorial(n));
    printf("    Iteratif : %lld\n", fact_iter);
    printf("    Keduanya benar — iteratif lebih hemat memori\n");

    printf("\n========================================\n");
    printf("Selesai! Lanjut ke modul 012 (Pointer Dasar).\n");

    return 0;
}

/* -------------------------------------------------------
 * IMPLEMENTASI FUNCTION
 * ------------------------------------------------------- */

void hitung_mundur(int n) {
    if (n <= 0) {
        printf("GO!");
        return;
    }
    printf("%d... ", n);
    hitung_mundur(n - 1);
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int factorial_tail(int n, int acc) {
    if (n <= 1) return acc;
    return factorial_tail(n - 1, n * acc);
}

int sum_recursive(int n) {
    if (n <= 0) return 0;
    return n + sum_recursive(n - 1);
}

int sum_array(const int arr[], int n) {
    if (n <= 0) return 0;
    return arr[n - 1] + sum_array(arr, n - 1);
}

/* Fibonacci naif — O(2^n), sangat lambat untuk n besar */
int fib_naive(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fib_naive(n - 1) + fib_naive(n - 2);
}

/* Fibonacci memoized — O(n) */
long long fib_memo(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n < MAX_FIB && computed[n]) return memo[n];

    long long result = fib_memo(n - 1) + fib_memo(n - 2);

    if (n < MAX_FIB) {
        memo[n] = result;
        computed[n] = 1;
    }

    return result;
}

/* Power simple — O(n) */
long long power_simple(int base, int exp) {
    if (exp == 0) return 1;
    return base * power_simple(base, exp - 1);
}

/* Power fast — O(log n), fast exponentiation */
long long power_fast(int base, int exp) {
    if (exp == 0) return 1;

    if (exp % 2 == 0) {
        long long half = power_fast(base, exp / 2);
        return half * half;
    } else {
        return base * power_fast(base, exp - 1);
    }
}

/* Tower of Hanoi */
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("  Disk 1: %c → %c\n", from, to);
        return;
    }

    hanoi(n - 1, from, aux, to);
    printf("  Disk %d: %c → %c\n", n, from, to);
    hanoi(n - 1, aux, to, from);
}
