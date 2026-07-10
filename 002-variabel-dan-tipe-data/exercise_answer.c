/*
 * ============================================================
 *  002 — Variabel & Tipe Data: Jawaban Latihan
 * ============================================================
 *  SPOILER ALERT! Kerjakan exercise.c dulu.
 *
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o answer exercise_answer.c
 *    ./answer
 * ============================================================
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {

    /* ============================================
     * LEVEL 1: EASY — Semua Tipe Data & sizeof
     * ============================================ */
    printf("=== LEVEL 1: Semua Tipe Data & sizeof ===\n\n");

    char   inisial    = 'A';
    short  tahun_ring = 99;
    int    umur       = 25;
    long   populasi   = 275000000L;
    float  ipk        = 3.55f;
    double pi         = 3.14159265358979;

    printf("  char   : '%c'\t(sizeof: %zu byte)\n", inisial, sizeof(inisial));
    printf("  short  : %hd\t(sizeof: %zu byte)\n", tahun_ring, sizeof(tahun_ring));
    printf("  int    : %d\t(sizeof: %zu byte)\n", umur, sizeof(umur));
    printf("  long   : %ld\t(sizeof: %zu byte)\n", populasi, sizeof(populasi));
    printf("  float  : %.2f\t(sizeof: %zu byte)\n", ipk, sizeof(ipk));
    printf("  double : %.14f\t(sizeof: %zu byte)\n", pi, sizeof(pi));
    printf("\n");

    /* ============================================
     * LEVEL 2: MEDIUM — Kalkulator Konversi Suhu
     * ============================================ */
    printf("=== LEVEL 2: Konversi Suhu ===\n\n");

    double celsius = 36.5;

    /*
     * PENTING: pakai 9.0/5.0, BUKAN 9/5!
     * 9/5 = 1 (integer division, desimal dibuang)
     * 9.0/5.0 = 1.8 (floating-point division, benar)
     */
    double fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    double kelvin = celsius + 273.15;

    printf("  === Konversi Suhu ===\n");
    printf("  Celsius    : %.2f C\n", celsius);
    printf("  Fahrenheit : %.2f F\n", fahrenheit);
    printf("  Kelvin     : %.2f K\n\n", kelvin);

    /* Verifikasi dengan nilai yang dikenal */
    double c_didih = 100.0;
    double f_didih = (c_didih * 9.0 / 5.0) + 32.0;
    double k_didih = c_didih + 273.15;
    printf("  Verifikasi (titik didih air):\n");
    printf("  %.0f C = %.0f F = %.2f K\n\n", c_didih, f_didih, k_didih);

    double c_beku = 0.0;
    double f_beku = (c_beku * 9.0 / 5.0) + 32.0;
    double k_beku = c_beku + 273.15;
    printf("  Verifikasi (titik beku air):\n");
    printf("  %.0f C = %.0f F = %.2f K\n\n", c_beku, f_beku, k_beku);

    /* ============================================
     * LEVEL 3: HARD — Overflow Explorer
     * ============================================ */
    printf("=== LEVEL 3: Overflow Explorer ===\n\n");

    /* Bagian 1: Batas semua tipe integer */
    printf("  %-20s %-22s %s\n", "Tipe", "Min", "Max");
    printf("  ---------------------------------------------------------------\n");
    printf("  %-20s %-22d %d\n",   "char", CHAR_MIN, CHAR_MAX);
    printf("  %-20s %-22d %d\n",   "unsigned char", 0, UCHAR_MAX);
    printf("  %-20s %-22d %d\n",   "short", SHRT_MIN, SHRT_MAX);
    printf("  %-20s %-22d %d\n",   "unsigned short", 0, USHRT_MAX);
    printf("  %-20s %-22d %d\n",   "int", INT_MIN, INT_MAX);
    printf("  %-20s %-22u %u\n",   "unsigned int", 0U, UINT_MAX);
    printf("  %-20s %-22ld %ld\n", "long", LONG_MIN, LONG_MAX);
    printf("  %-20s %-22lu %lu\n", "unsigned long", 0UL, ULONG_MAX);
    printf("  %-20s %-22lld %lld\n", "long long", LLONG_MIN, LLONG_MAX);
    printf("  %-20s %-22llu %llu\n", "unsigned long long", 0ULL, ULLONG_MAX);
    printf("\n");

    /* Bagian 2: Unsigned overflow demo */
    printf("  === UNSIGNED OVERFLOW DEMO ===\n");

    unsigned char uc = 255;
    unsigned char uc_plus = uc + 1; /* 256 -> wrap ke 0 */
    printf("  unsigned char %u + 1 = %u (wrap around!)\n", uc, uc_plus);

    unsigned char uc2 = 0;
    unsigned char uc_minus = uc2 - 1; /* -1 -> wrap ke 255 */
    printf("  unsigned char %u - 1 = %u (wrap around!)\n\n", uc2, uc_minus);

    /* Bagian 3: Casting data loss */
    printf("  === CASTING DATA LOSS DEMO ===\n");

    int big_val = 100000;
    short small_val = (short)big_val;

    printf("  int   big_val   = %d\n", big_val);
    printf("  short small_val = (short)big_val = %hd\n", small_val);
    printf("\n");

    /*
     * Kenapa nilainya berubah?
     *
     * int 100000 dalam binary (32-bit):
     *   0000 0000 0000 0001 1000 0110 1010 0000
     *
     * Cast ke short (16-bit) — hanya ambil 16 bit terakhir:
     *   1000 0110 1010 0000
     *
     * Karena bit pertama = 1 (sign bit), angka ini diinterpretasikan
     * sebagai bilangan negatif di signed short.
     * Hasilnya: -31072 (atau nilai lain tergantung platform)
     *
     * Pelajaran: JANGAN cast ke tipe yang lebih kecil kalau nilainya
     * bisa melebihi kapasitas tipe tujuan!
     */
    printf("  Penjelasan: 100000 > SHRT_MAX (%d), sehingga\n", SHRT_MAX);
    printf("  16 bit terakhir diinterpretasikan ulang oleh short.\n");
    printf("  Ini disebut 'data truncation' atau 'narrowing conversion'.\n");

    return 0;
}
