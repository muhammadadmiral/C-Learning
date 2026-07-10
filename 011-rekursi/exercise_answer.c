/*
 * ============================================================
 *  011 — Rekursi: Jawaban Latihan
 * ============================================================
 *  SPOILER ALERT! Kerjakan exercise.c dulu.
 *
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o answer exercise_answer.c
 *    ./answer
 * ============================================================
 */

#include <stdio.h>
#include <string.h>

/* -------------------------------------------------------
 * Function Prototypes
 * ------------------------------------------------------- */

/* Level 1 */
int sum_digits(int n);
int reverse_helper(int n, int acc);
int reverse_number(int n);
int gcd_recursive(int a, int b);

/* Level 2 */
int binary_search_rec(const int arr[], int low, int high, int target);
void print_triangle(int n);
void print_triangle_inv(int n);
void print_stars(int count);

/* Level 3 */
void permutations(char *str, int start, int end);
void swap_char(char *a, char *b);

int main(void) {

    /* ============================================
     * LEVEL 1: EASY — Sum of Digits, Reverse, GCD
     * ============================================ */
    printf("=== LEVEL 1: Sum of Digits, Reverse, GCD ===\n\n");

    /* Sum of digits */
    printf("  sum_digits(1234) = %d\n", sum_digits(1234));     /* 10 */
    printf("  sum_digits(9876) = %d\n", sum_digits(9876));     /* 30 */
    printf("  sum_digits(5)    = %d\n", sum_digits(5));        /* 5 */
    printf("  sum_digits(0)    = %d\n", sum_digits(0));        /* 0 */

    /* Reverse number */
    printf("\n  reverse_number(1234) = %d\n", reverse_number(1234));  /* 4321 */
    printf("  reverse_number(100)  = %d\n", reverse_number(100));    /* 1 */
    printf("  reverse_number(9)    = %d\n", reverse_number(9));      /* 9 */
    printf("  reverse_number(12300)= %d\n", reverse_number(12300));  /* 321 */

    /* GCD */
    printf("\n  gcd(48, 18)  = %d\n", gcd_recursive(48, 18));   /* 6 */
    printf("  gcd(100, 75) = %d\n", gcd_recursive(100, 75));   /* 25 */
    printf("  gcd(17, 13)  = %d\n", gcd_recursive(17, 13));    /* 1 */
    printf("  gcd(0, 5)    = %d\n", gcd_recursive(0, 5));      /* 5 */

    /* ============================================
     * LEVEL 2: MEDIUM — Binary Search & Pattern
     * ============================================ */
    printf("\n=== LEVEL 2: Recursive Binary Search & Pattern ===\n\n");

    /* Binary Search */
    int sorted[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};
    int size = sizeof(sorted) / sizeof(sorted[0]);

    printf("  Array: [");
    for (int i = 0; i < size; i++) {
        printf("%d%s", sorted[i], i < size - 1 ? ", " : "");
    }
    printf("]\n\n");

    int targets[] = {23, 72, 2, 99, 38};
    int t_count = sizeof(targets) / sizeof(targets[0]);

    for (int i = 0; i < t_count; i++) {
        int idx = binary_search_rec(sorted, 0, size - 1, targets[i]);
        if (idx != -1) {
            printf("  Cari %2d → ketemu di index %d\n", targets[i], idx);
        } else {
            printf("  Cari %2d → TIDAK KETEMU\n", targets[i]);
        }
    }

    /* Segitiga */
    printf("\n  Segitiga (n=5):\n");
    print_triangle(5);

    printf("\n  Segitiga terbalik (n=5):\n");
    print_triangle_inv(5);

    /* ============================================
     * LEVEL 3: HARD — Permutasi String
     * ============================================ */
    printf("\n=== LEVEL 3: Permutasi String ===\n\n");

    char str1[] = "ABC";
    int len1 = strlen(str1);
    printf("  Permutasi \"%s\" (%d! = %d):\n", str1, len1,
           len1 == 3 ? 6 : len1 == 4 ? 24 : 0);
    permutations(str1, 0, len1 - 1);

    char str2[] = "AB";
    int len2 = strlen(str2);
    printf("\n  Permutasi \"%s\" (%d! = %d):\n", str2, len2, 2);
    permutations(str2, 0, len2 - 1);

    char str3[] = "ABCD";
    int len3 = strlen(str3);
    printf("\n  Permutasi \"%s\" (%d! = %d):\n", str3, len3, 24);
    permutations(str3, 0, len3 - 1);

    return 0;
}

/* -------------------------------------------------------
 * LEVEL 1: IMPLEMENTASI
 * ------------------------------------------------------- */

/*
 * sum_digits — jumlah semua digit
 * 1234 → 4 + sum_digits(123) → 4 + 3 + sum_digits(12) → ...
 */
int sum_digits(int n) {
    if (n < 0) n = -n;         /* Handle negatif */
    if (n < 10) return n;      /* Base case: satu digit */
    return (n % 10) + sum_digits(n / 10);
}

/*
 * reverse_number — balik angka
 * Pakai accumulator untuk build hasil dari kiri ke kanan
 * 1234, acc=0 → 123, acc=4 → 12, acc=43 → 1, acc=432 → 0, acc=4321
 */
int reverse_helper(int n, int acc) {
    if (n == 0) return acc;
    return reverse_helper(n / 10, acc * 10 + n % 10);
}

int reverse_number(int n) {
    if (n < 0) return -reverse_helper(-n, 0);
    if (n == 0) return 0;
    return reverse_helper(n, 0);
}

/*
 * gcd_recursive — Euclidean algorithm
 * gcd(48, 18) → gcd(18, 12) → gcd(12, 6) → gcd(6, 0) = 6
 */
int gcd_recursive(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    if (b == 0) return a;         /* Base case */
    return gcd_recursive(b, a % b);
}

/* -------------------------------------------------------
 * LEVEL 2: IMPLEMENTASI
 * ------------------------------------------------------- */

/*
 * binary_search_rec — binary search rekursif
 * Sama logikanya dengan iteratif, tapi pakai recursive call
 */
int binary_search_rec(const int arr[], int low, int high, int target) {
    if (low > high) return -1;    /* Base case: tidak ketemu */

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        return mid;                /* Ketemu! */
    } else if (arr[mid] < target) {
        return binary_search_rec(arr, mid + 1, high, target);
    } else {
        return binary_search_rec(arr, low, mid - 1, target);
    }
}

/* Helper: cetak n bintang + newline */
void print_stars(int count) {
    for (int i = 0; i < count; i++) {
        printf("* ");
    }
    printf("\n");
}

/*
 * print_triangle — segitiga bintang rekursif (membesar)
 * Cetak baris 1..n:
 *   1. Cetak segitiga ukuran n-1 dulu (baris 1 sampai n-1)
 *   2. Baru cetak baris ke-n
 */
void print_triangle(int n) {
    if (n <= 0) return;            /* Base case */
    print_triangle(n - 1);        /* Cetak baris 1..n-1 */
    printf("    ");
    print_stars(n);                /* Cetak baris ke-n */
}

/*
 * print_triangle_inv — segitiga terbalik rekursif (mengecil)
 * Cetak baris n..1:
 *   1. Cetak baris ke-n dulu
 *   2. Baru cetak segitiga terbalik ukuran n-1
 */
void print_triangle_inv(int n) {
    if (n <= 0) return;            /* Base case */
    printf("    ");
    print_stars(n);                /* Cetak baris ke-n */
    print_triangle_inv(n - 1);    /* Cetak baris n-1..1 */
}

/* -------------------------------------------------------
 * LEVEL 3: IMPLEMENTASI
 * ------------------------------------------------------- */

void swap_char(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * permutations — cetak semua permutasi string
 *
 * Algoritma backtracking:
 *   Untuk setiap posisi 'start', coba semua karakter yang mungkin
 *   di posisi itu (swap dengan setiap karakter dari start sampai end),
 *   lalu rekursi untuk posisi berikutnya, dan swap balik (backtrack).
 *
 * Contoh untuk "ABC":
 *
 *              "ABC"
 *            /   |   \
 *     swap(0,0) swap(0,1) swap(0,2)
 *        |        |         |
 *      "ABC"    "BAC"     "CBA"
 *      / \      / \       / \
 *   "ABC" "ACB" "BAC" "BCA" "CBA" "CAB"
 *
 * Setiap leaf = satu permutasi yang dicetak
 */
void permutations(char *str, int start, int end) {
    /* Base case: sudah di posisi terakhir → cetak */
    if (start == end) {
        printf("    %s\n", str);
        return;
    }

    for (int i = start; i <= end; i++) {
        /* 1. Swap: coba karakter ke-i di posisi 'start' */
        swap_char(&str[start], &str[i]);

        /* 2. Rekursi: proses posisi berikutnya */
        permutations(str, start + 1, end);

        /* 3. Backtrack: kembalikan ke keadaan semula */
        swap_char(&str[start], &str[i]);
    }
}
