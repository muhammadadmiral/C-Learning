/*
 * ============================================================
 *  006 — Perulangan: Jawaban Latihan
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

int main(void) {

    /* ============================================
     * LEVEL 1: EASY — FizzBuzz
     * ============================================ */
    printf("=== LEVEL 1: FizzBuzz (1-30) ===\n\n  ");

    for (int i = 1; i <= 30; i++) {
        /*
         * Cek kelipatan 15 DULU, karena kelipatan 15 juga kelipatan 3
         * dan kelipatan 5. Kalau cek 3 duluan, "FizzBuzz" tidak pernah
         * tercetak — sudah ditangkap "Fizz" lebih dulu.
         */
        if (i % 15 == 0) {
            printf("FizzBuzz ");
        } else if (i % 3 == 0) {
            printf("Fizz ");
        } else if (i % 5 == 0) {
            printf("Buzz ");
        } else {
            printf("%d ", i);
        }
    }
    printf("\n\n");

    /* ============================================
     * LEVEL 2: MEDIUM — Pattern Printer
     * ============================================ */
    printf("=== LEVEL 2: Pattern Printer ===\n\n");

    int tinggi;
    do {
        printf("  Masukkan tinggi (1-15): ");
        scanf("%d", &tinggi);
        if (tinggi < 1 || tinggi > 15) {
            printf("  Harus 1-15! Coba lagi.\n");
        }
    } while (tinggi < 1 || tinggi > 15);

    /* Pattern A: Segitiga terbalik */
    printf("\n  Pattern A: Segitiga Terbalik\n");
    for (int i = tinggi; i >= 1; i--) {
        printf("    ");
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    /* Pattern B: Diamond */
    printf("\n  Pattern B: Diamond\n");
    /* Bagian atas (termasuk baris tengah) */
    for (int i = 1; i <= tinggi; i++) {
        printf("    ");
        for (int s = i; s < tinggi; s++) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
    /* Bagian bawah */
    for (int i = tinggi - 1; i >= 1; i--) {
        printf("    ");
        for (int s = i; s < tinggi; s++) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    /* Pattern C: Hollow rectangle */
    printf("\n  Pattern C: Hollow Rectangle\n");
    for (int i = 1; i <= tinggi; i++) {
        printf("    ");
        for (int j = 1; j <= tinggi; j++) {
            if (i == 1 || i == tinggi || j == 1 || j == tinggi) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    /* ============================================
     * LEVEL 3: HARD — Kalkulator Interaktif
     * ============================================ */
    printf("\n=== LEVEL 3: Kalkulator Interaktif ===\n");

    /* History: 5 variabel terpisah (belum belajar array) */
    char hist1[60] = "(kosong)";
    char hist2[60] = "(kosong)";
    char hist3[60] = "(kosong)";
    char hist4[60] = "(kosong)";
    char hist5[60] = "(kosong)";
    int total_ops = 0;

    int c;
    while ((c = getchar()) != '\n' && c != EOF) { } /* Bersihkan buffer */

    int running = 1;
    while (running) {
        printf("\n  ╔═══════════════════════╗\n");
        printf("  ║   KALKULATOR v1.0     ║\n");
        printf("  ╠═══════════════════════╣\n");
        printf("  ║ [1] Penjumlahan       ║\n");
        printf("  ║ [2] Pengurangan       ║\n");
        printf("  ║ [3] Perkalian         ║\n");
        printf("  ║ [4] Pembagian         ║\n");
        printf("  ║ [5] Modulo            ║\n");
        printf("  ║ [6] Pangkat (x^n)     ║\n");
        printf("  ║ [7] Lihat History     ║\n");
        printf("  ║ [0] Keluar            ║\n");
        printf("  ╚═══════════════════════╝\n");
        printf("  Pilih: ");

        int menu;
        if (scanf("%d", &menu) != 1) {
            while ((c = getchar()) != '\n' && c != EOF) { }
            printf("  Input tidak valid!\n");
            continue;
        }

        if (menu == 0) {
            printf("  Total operasi: %d\n", total_ops);
            printf("  Terima kasih!\n");
            running = 0;
            continue;
        }

        if (menu == 7) {
            printf("\n  === HISTORY (5 terakhir) ===\n");
            printf("  1. %s\n", hist1);
            printf("  2. %s\n", hist2);
            printf("  3. %s\n", hist3);
            printf("  4. %s\n", hist4);
            printf("  5. %s\n", hist5);
            continue;
        }

        if (menu < 1 || menu > 6) {
            printf("  Menu tidak valid!\n");
            continue;
        }

        if (menu == 6) {
            /* Pangkat: x^n pakai loop */
            int base, exp;
            printf("  Base: ");
            scanf("%d", &base);
            printf("  Exponent (>= 0): ");
            scanf("%d", &exp);

            if (exp < 0) {
                printf("  ERROR: Exponent harus >= 0!\n");
                continue;
            }

            long long result = 1;
            for (int i = 0; i < exp; i++) {
                result *= base;
            }
            printf("  %d ^ %d = %lld\n", base, exp, result);

            /* Shift history */
            snprintf(hist5, sizeof(hist5), "%s", hist4);
            snprintf(hist4, sizeof(hist4), "%s", hist3);
            snprintf(hist3, sizeof(hist3), "%s", hist2);
            snprintf(hist2, sizeof(hist2), "%s", hist1);
            snprintf(hist1, sizeof(hist1), "%d ^ %d = %lld", base, exp, result);
            total_ops++;
            continue;
        }

        /* Menu 1-5: dua operand */
        double a, b, result;
        char op;
        printf("  Angka pertama : ");
        scanf("%lf", &a);
        printf("  Angka kedua   : ");
        scanf("%lf", &b);

        int valid = 1;

        switch (menu) {
            case 1: result = a + b; op = '+'; break;
            case 2: result = a - b; op = '-'; break;
            case 3: result = a * b; op = '*'; break;
            case 4:
                if (b == 0) {
                    printf("  ERROR: Pembagian oleh 0!\n");
                    valid = 0;
                } else {
                    result = a / b;
                    op = '/';
                }
                break;
            case 5:
                if (b == 0) {
                    printf("  ERROR: Modulo oleh 0!\n");
                    valid = 0;
                } else {
                    result = (int)a % (int)b;
                    op = '%';
                }
                break;
            default:
                valid = 0;
                result = 0;
                op = '?';
                break;
        }

        if (valid) {
            printf("  %.2f %c %.2f = %.2f\n", a, op, b, result);

            /* Shift history */
            snprintf(hist5, sizeof(hist5), "%s", hist4);
            snprintf(hist4, sizeof(hist4), "%s", hist3);
            snprintf(hist3, sizeof(hist3), "%s", hist2);
            snprintf(hist2, sizeof(hist2), "%s", hist1);
            snprintf(hist1, sizeof(hist1), "%.2f %c %.2f = %.2f", a, op, b, result);
            total_ops++;
        }
    }

    return 0;
}
