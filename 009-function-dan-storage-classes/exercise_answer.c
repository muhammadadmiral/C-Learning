/*
 * ============================================================
 *  009 — Function & Storage Classes: Jawaban Latihan
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
#include <ctype.h>

/* -------------------------------------------------------
 * Function Prototypes
 * ------------------------------------------------------- */

/* Level 1 */
int is_prime(int n);
int gcd(int a, int b);
int lcm(int a, int b);

/* Level 2 */
int arr_min(const int arr[], int n);
int arr_max(const int arr[], int n);
double arr_mean(const int arr[], int n);
double arr_median(int arr[], int n);
void bubble_sort(int arr[], int n);
void print_array(const int arr[], int n);

/* Level 3 */
void caesar_encrypt(char *text, int shift);
void caesar_decrypt(char *text, int shift);
int get_crypto_ops_count(void);
static int *crypto_counter_ptr(void);

int main(void) {

    /* ============================================
     * LEVEL 1: EASY — is_prime, gcd, lcm
     * ============================================ */
    printf("=== LEVEL 1: is_prime, gcd, lcm ===\n\n");

    /* Cetak bilangan prima 2-50 */
    printf("  Bilangan prima 2-50:\n  ");
    int prime_count = 0;
    for (int i = 2; i <= 50; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            prime_count++;
        }
    }
    printf("\n  Total: %d bilangan prima\n", prime_count);

    /* GCD test */
    printf("\n  gcd(48, 18) = %d\n", gcd(48, 18));     /* 6 */
    printf("  gcd(100, 75) = %d\n", gcd(100, 75));     /* 25 */
    printf("  gcd(17, 13) = %d\n", gcd(17, 13));       /* 1 (coprime) */

    /* LCM test */
    printf("\n  lcm(12, 8) = %d\n", lcm(12, 8));       /* 24 */
    printf("  lcm(5, 7) = %d\n", lcm(5, 7));           /* 35 */
    printf("  lcm(6, 4) = %d\n", lcm(6, 4));           /* 12 */

    /* ============================================
     * LEVEL 2: MEDIUM — Mini Library Statistik
     * ============================================ */
    printf("\n=== LEVEL 2: Mini Library Statistik ===\n\n");

    int data[] = {12, 5, 8, 3, 15, 7, 10};
    int n = sizeof(data) / sizeof(data[0]);

    printf("  Data   : ");
    print_array(data, n);

    printf("  Min    : %d\n", arr_min(data, n));
    printf("  Max    : %d\n", arr_max(data, n));
    printf("  Mean   : %.2f\n", arr_mean(data, n));
    printf("  Median : %.2f\n", arr_median(data, n));

    /* Test dengan jumlah genap */
    printf("\n");
    int data2[] = {4, 1, 7, 9, 2, 5};
    int n2 = sizeof(data2) / sizeof(data2[0]);

    printf("  Data   : ");
    print_array(data2, n2);

    printf("  Min    : %d\n", arr_min(data2, n2));
    printf("  Max    : %d\n", arr_max(data2, n2));
    printf("  Mean   : %.2f\n", arr_mean(data2, n2));
    printf("  Median : %.2f (rata-rata 2 tengah)\n", arr_median(data2, n2));

    /* ============================================
     * LEVEL 3: HARD — Caesar Cipher
     * ============================================ */
    printf("\n=== LEVEL 3: Caesar Cipher ===\n\n");

    char msg1[] = "Hello, World!";
    printf("  Original : \"%s\"\n", msg1);

    caesar_encrypt(msg1, 3);
    printf("  Encrypted: \"%s\" (shift=3)\n", msg1);

    caesar_decrypt(msg1, 3);
    printf("  Decrypted: \"%s\"\n", msg1);

    /* Test dengan shift besar */
    char msg2[] = "abcXYZ";
    printf("\n  Original : \"%s\"\n", msg2);

    caesar_encrypt(msg2, 25);
    printf("  Encrypted: \"%s\" (shift=25)\n", msg2);

    caesar_decrypt(msg2, 25);
    printf("  Decrypted: \"%s\"\n", msg2);

    /* Test wrap-around */
    char msg3[] = "Zoo Zebra!";
    printf("\n  Original : \"%s\"\n", msg3);

    caesar_encrypt(msg3, 5);
    printf("  Encrypted: \"%s\" (shift=5)\n", msg3);

    caesar_decrypt(msg3, 5);
    printf("  Decrypted: \"%s\"\n", msg3);

    printf("\n  Total crypto operations: %d\n", get_crypto_ops_count());

    return 0;
}

/* -------------------------------------------------------
 * LEVEL 1: IMPLEMENTASI
 * ------------------------------------------------------- */

/*
 * is_prime — cek apakah n bilangan prima
 * Optimasi: cek divisor hanya sampai sqrt(n)
 * Kenapa? Kalau n = a × b, minimal salah satu dari a atau b ≤ sqrt(n)
 */
int is_prime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;           /* 2 dan 3 prima */
    if (n % 2 == 0) return 0;      /* Genap > 2 bukan prima */

    for (int i = 3; i * i <= n; i += 2) {   /* Skip genap */
        if (n % i == 0) return 0;
    }
    return 1;
}

/*
 * gcd — Greatest Common Divisor (FPB)
 * Algoritma Euclidean: gcd(a, b) = gcd(b, a % b)
 * Contoh: gcd(48, 18) → gcd(18, 12) → gcd(12, 6) → gcd(6, 0) = 6
 */
int gcd(int a, int b) {
    /* Handle negatif */
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/*
 * lcm — Least Common Multiple (KPK)
 * Rumus: lcm(a,b) = |a × b| / gcd(a,b)
 * Pakai a / gcd * b untuk hindari overflow
 */
int lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;

    int abs_a = a < 0 ? -a : a;
    int abs_b = b < 0 ? -b : b;

    return abs_a / gcd(abs_a, abs_b) * abs_b;
}

/* -------------------------------------------------------
 * LEVEL 2: IMPLEMENTASI
 * ------------------------------------------------------- */

void print_array(const int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

int arr_min(const int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

int arr_max(const int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

double arr_mean(const int arr[], int n) {
    long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double)sum / n;
}

/*
 * arr_median — return nilai tengah dari array yang di-sort
 *
 * ⚠️ Harus sort dulu! Tapi kita tidak mau merusak array asli,
 * jadi kita copy dulu ke array lokal, baru sort copy-nya.
 */
double arr_median(int arr[], int n) {
    /* Copy array agar yang asli tidak berubah */
    int sorted[100];   /* Max 100 elemen */
    for (int i = 0; i < n && i < 100; i++) {
        sorted[i] = arr[i];
    }

    bubble_sort(sorted, n);

    if (n % 2 == 1) {
        /* Ganjil: ambil elemen tengah */
        return (double)sorted[n / 2];
    } else {
        /* Genap: rata-rata 2 elemen tengah */
        return (sorted[n / 2 - 1] + sorted[n / 2]) / 2.0;
    }
}

/* -------------------------------------------------------
 * LEVEL 3: IMPLEMENTASI
 * ------------------------------------------------------- */

/*
 * Shared static counter — diakses via pointer dari helper function.
 * Ini pattern untuk "share static variable" antar function.
 */
static int *crypto_counter_ptr(void) {
    static int ops = 0;
    return &ops;
}

void caesar_encrypt(char *text, int shift) {
    /* Normalize shift ke 0-25 */
    shift = ((shift % 26) + 26) % 26;

    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' + shift) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' + shift) % 26 + 'A';
        }
        /* Non-alpha: skip (tetap sama) */
    }

    (*crypto_counter_ptr())++;
}

void caesar_decrypt(char *text, int shift) {
    /* Decrypt = encrypt dengan shift terbalik */
    caesar_encrypt(text, 26 - (shift % 26));

    /* Counter sudah di-increment oleh caesar_encrypt,
     * tapi kita mau count ini sebagai operasi terpisah.
     * Karena caesar_encrypt sudah menambah 1, kita cukup
     * (tidak perlu increment lagi — sudah di-count di encrypt) */
}

int get_crypto_ops_count(void) {
    return *crypto_counter_ptr();
}
