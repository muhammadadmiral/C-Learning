/*
 * ============================================================
 *  006 — Perulangan: Contoh Kode Utama
 * ============================================================
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o program main.c
 *    ./program
 * ============================================================
 */

#include <stdio.h>

int main(void) {

    printf("╔══════════════════════════════════════════╗\n");
    printf("║  006 — Perulangan                        ║\n");
    printf("╚══════════════════════════════════════════╝\n\n");

    /* -------------------------------------------------------
     * 1. FOR LOOP — loop dengan counter
     * ------------------------------------------------------- */
    printf("--- 1. for loop ---\n");

    /* Hitung 1 sampai 5 */
    for (int i = 1; i <= 5; i++) {
        printf("  i = %d\n", i);
    }

    /* Hitung mundur */
    printf("\n  Countdown: ");
    for (int i = 5; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("GO!\n");

    /* Step 2 — angka genap */
    printf("  Genap 0-10: ");
    for (int i = 0; i <= 10; i += 2) {
        printf("%d ", i);
    }
    printf("\n");

    /* Multiple variabel */
    printf("\n  Multiple var:\n");
    for (int lo = 0, hi = 10; lo < hi; lo++, hi--) {
        printf("    lo=%d, hi=%d\n", lo, hi);
    }

    /* -------------------------------------------------------
     * 2. WHILE LOOP — loop dengan kondisi
     * ------------------------------------------------------- */
    printf("\n--- 2. while loop ---\n");

    /* Hitung digit dari sebuah angka */
    int angka = 123456;
    int temp = angka;
    int digit_count = 0;

    while (temp > 0) {
        temp /= 10;          /* Hapus digit terakhir */
        digit_count++;
    }
    printf("  Angka %d punya %d digit\n", angka, digit_count);

    /* Sum sampai melebihi target */
    int sum = 0;
    int n = 0;
    while (sum < 100) {
        n++;
        sum += n;
    }
    printf("  Jumlah 1+2+...+%d = %d (>= 100)\n", n, sum);

    /* -------------------------------------------------------
     * 3. DO-WHILE LOOP — minimal sekali jalan
     * ------------------------------------------------------- */
    printf("\n--- 3. do-while loop ---\n");

    /* Validasi input */
    int pilihan;
    printf("  Pilih angka 1-3: ");
    do {
        scanf("%d", &pilihan);
        if (pilihan < 1 || pilihan > 3) {
            printf("  Salah! Coba lagi (1-3): ");
        }
    } while (pilihan < 1 || pilihan > 3);
    printf("  Pilihan valid: %d\n", pilihan);

    /* -------------------------------------------------------
     * 4. NESTED LOOP — loop di dalam loop
     * ------------------------------------------------------- */
    printf("\n--- 4. Nested loop ---\n\n");

    /* Tabel perkalian 1-5 */
    printf("  Tabel Perkalian 1-5:\n");
    printf("    ");
    for (int j = 1; j <= 5; j++) {
        printf("%4d", j);
    }
    printf("\n    --------------------\n");

    for (int i = 1; i <= 5; i++) {
        printf("  %d|", i);
        for (int j = 1; j <= 5; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }

    /* Segitiga bintang */
    printf("\n  Segitiga:\n");
    for (int i = 1; i <= 5; i++) {
        printf("    ");
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    /* Piramida */
    printf("\n  Piramida:\n");
    int tinggi = 5;
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

    /* -------------------------------------------------------
     * 5. BREAK — keluar dari loop seketika
     * ------------------------------------------------------- */
    printf("\n--- 5. break ---\n");

    /* Cari bilangan prima pertama > 20 */
    for (int num = 21; ; num++) {
        int is_prime = 1;
        for (int d = 2; d * d <= num; d++) {
            if (num % d == 0) {
                is_prime = 0;
                break;    /* Keluar inner loop */
            }
        }
        if (is_prime) {
            printf("  Prima pertama > 20: %d\n", num);
            break;        /* Keluar outer loop */
        }
    }

    /* -------------------------------------------------------
     * 6. CONTINUE — skip iterasi saat ini
     * ------------------------------------------------------- */
    printf("\n--- 6. continue ---\n");

    /* Cetak 1-15, skip kelipatan 3 */
    printf("  1-15 (skip kelipatan 3): ");
    for (int i = 1; i <= 15; i++) {
        if (i % 3 == 0) {
            continue;     /* Skip printf, langsung ke i++ */
        }
        printf("%d ", i);
    }
    printf("\n");

    /* -------------------------------------------------------
     * 7. INFINITE LOOP + BREAK — menu interaktif
     * ------------------------------------------------------- */
    printf("\n--- 7. Infinite loop (menu demo) ---\n");

    /* Bersihkan buffer */
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    int running = 1;
    while (running) {
        printf("\n  [1] Sapa  [2] Hitung  [0] Keluar\n");
        printf("  Pilih: ");

        int menu;
        if (scanf("%d", &menu) != 1) {
            /* Input bukan angka — bersihkan dan skip */
            while ((c = getchar()) != '\n' && c != EOF) { }
            printf("  Input tidak valid!\n");
            continue;
        }

        switch (menu) {
            case 1:
                printf("  Halo! Semangat belajar C!\n");
                break;
            case 2: {
                int a, b;
                printf("  Masukkan 2 angka: ");
                scanf("%d %d", &a, &b);
                printf("  %d + %d = %d\n", a, b, a + b);
                break;
            }
            case 0:
                printf("  Bye! Sampai jumpa!\n");
                running = 0;    /* Keluar loop */
                break;
            default:
                printf("  Menu tidak ada!\n");
                break;
        }
    }

    printf("\n========================================\n");
    printf("Selesai! Lanjut ke modul 007 (Array).\n");

    return 0;
}
