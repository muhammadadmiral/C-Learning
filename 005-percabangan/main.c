/*
 * ============================================================
 *  005 — Percabangan: Contoh Kode Utama
 * ============================================================
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o program main.c
 *    ./program
 * ============================================================
 */

#include <stdio.h>
#include <stdbool.h>   /* Untuk tipe bool, true, false (C99+) */
#include <string.h>    /* Untuk strcspn */

int main(void) {

    printf("╔══════════════════════════════════════════╗\n");
    printf("║  005 — Percabangan                       ║\n");
    printf("╚══════════════════════════════════════════╝\n\n");

    /* -------------------------------------------------------
     * 1. IF — ELSE IF — ELSE
     * ------------------------------------------------------- */
    printf("--- 1. if — else if — else ---\n\n");

    int nilai;
    printf("  Masukkan nilai (0-100): ");
    scanf("%d", &nilai);

    printf("  Nilai: %d -> ", nilai);

    if (nilai >= 90) {
        printf("Grade A (Excellent!)\n");
    } else if (nilai >= 80) {
        printf("Grade B (Good!)\n");
    } else if (nilai >= 70) {
        printf("Grade C (Average)\n");
    } else if (nilai >= 60) {
        printf("Grade D (Below Average)\n");
    } else {
        printf("Grade F (Tidak Lulus)\n");
    }

    /* -------------------------------------------------------
     * 2. NESTED IF — dan kenapa harus dihindari
     * ------------------------------------------------------- */
    printf("\n--- 2. Nested if (contoh buruk vs baik) ---\n\n");

    int umur = 20;
    bool punya_ktp = true;
    bool sudah_daftar = true;

    /* Cara buruk: terlalu banyak nesting */
    printf("  [Cara Nested — kurang rapi]\n");
    if (umur >= 17) {
        if (punya_ktp) {
            if (sudah_daftar) {
                printf("  Boleh ikut pemilu!\n");
            } else {
                printf("  Belum daftar!\n");
            }
        } else {
            printf("  Belum punya KTP!\n");
        }
    } else {
        printf("  Belum cukup umur!\n");
    }

    /* Cara baik: linear flow (guard clause style) */
    printf("\n  [Cara Guard Clause — lebih rapi]\n");
    /*
     * Catatan: Di main() kita tidak bisa pakai return di tengah
     * seperti di fungsi terpisah. Tapi kita bisa pakai variabel
     * boolean untuk mengontrol flow:
     */
    bool boleh = true;

    if (umur < 17) {
        printf("  Belum cukup umur!\n");
        boleh = false;
    }
    if (boleh && !punya_ktp) {
        printf("  Belum punya KTP!\n");
        boleh = false;
    }
    if (boleh && !sudah_daftar) {
        printf("  Belum daftar!\n");
        boleh = false;
    }
    if (boleh) {
        printf("  Boleh ikut pemilu!\n");
    }

    /* -------------------------------------------------------
     * 3. SWITCH-CASE
     * ------------------------------------------------------- */
    printf("\n--- 3. switch-case ---\n\n");

    /* Bersihkan buffer dari scanf sebelumnya */
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    printf("  === MENU KANTIN ===\n");
    printf("  1. Nasi Goreng  (Rp 15.000)\n");
    printf("  2. Mie Ayam     (Rp 12.000)\n");
    printf("  3. Sate Ayam    (Rp 20.000)\n");
    printf("  4. Es Teh       (Rp  5.000)\n");
    printf("  Pilih menu (1-4): ");

    int pilihan;
    scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
            printf("  -> Nasi Goreng, siap!\n");
            break;
        case 2:
            printf("  -> Mie Ayam, siap!\n");
            break;
        case 3:
            printf("  -> Sate Ayam, siap!\n");
            break;
        case 4:
            printf("  -> Es Teh, siap!\n");
            break;
        default:
            printf("  -> Menu tidak tersedia!\n");
            break;
    }

    /* -------------------------------------------------------
     * 4. FALL-THROUGH (disengaja)
     * ------------------------------------------------------- */
    printf("\n--- 4. Fall-through (disengaja) ---\n\n");

    /* Bersihkan buffer */
    while ((c = getchar()) != '\n' && c != EOF) { }

    printf("  Masukkan hari (1=Senin, ..., 7=Minggu): ");
    int hari;
    scanf("%d", &hari);

    printf("  Hari %d = ", hari);
    switch (hari) {
        case 1: case 2: case 3: case 4: case 5:
            printf("Hari Kerja\n");
            break;
        case 6: case 7:
            printf("Weekend! Santai~\n");
            break;
        default:
            printf("Hari tidak valid!\n");
            break;
    }

    /* -------------------------------------------------------
     * 5. TERNARY OPERATOR (? :)
     * ------------------------------------------------------- */
    printf("\n--- 5. Ternary Operator ---\n\n");

    int skor = 75;

    /* One-liner conditional */
    const char *status = (skor >= 60) ? "LULUS" : "TIDAK LULUS";
    printf("  Skor: %d -> %s\n", skor, status);

    /* Ternary di dalam printf */
    int suhu = 38;
    printf("  Suhu: %d C -> %s\n", suhu,
           (suhu > 37) ? "DEMAM!" : "Normal");

    /* Min/Max menggunakan ternary */
    int p = 42, q = 17;
    int max_val = (p > q) ? p : q;
    int min_val = (p < q) ? p : q;
    printf("  p=%d, q=%d -> max=%d, min=%d\n", p, q, max_val, min_val);

    /* -------------------------------------------------------
     * 6. BOOLEAN dengan <stdbool.h>
     * ------------------------------------------------------- */
    printf("\n--- 6. Boolean (<stdbool.h>) ---\n\n");

    bool is_online = true;
    bool is_admin = false;
    bool is_verified = true;

    printf("  is_online   : %s (%d)\n", is_online ? "true" : "false", is_online);
    printf("  is_admin    : %s (%d)\n", is_admin ? "true" : "false", is_admin);
    printf("  is_verified : %s (%d)\n", is_verified ? "true" : "false", is_verified);

    /* Operator logika dengan boolean */
    bool can_post = is_online && is_verified;
    bool can_delete = is_online && is_admin;

    printf("\n  can_post (online && verified)  : %s\n",
           can_post ? "Ya" : "Tidak");
    printf("  can_delete (online && admin)  : %s\n",
           can_delete ? "Ya" : "Tidak");

    /* -------------------------------------------------------
     * 7. REAL WORLD: Validasi Input
     *    Pattern yang sangat sering dipakai di program nyata
     * ------------------------------------------------------- */
    printf("\n--- 7. Real World: Validasi Input ---\n\n");

    /* Bersihkan buffer */
    while ((c = getchar()) != '\n' && c != EOF) { }

    printf("  Masukkan umur (1-150): ");
    int input_umur;
    int items = scanf("%d", &input_umur);

    /* Validasi bertingkat */
    if (items != 1) {
        printf("  ERROR: Input bukan angka!\n");
    } else if (input_umur < 1 || input_umur > 150) {
        printf("  ERROR: Umur harus antara 1-150! (input: %d)\n", input_umur);
    } else {
        /* Input valid — proses */
        printf("  OK! Umur: %d tahun\n", input_umur);

        /* Kategorisasi menggunakan ternary chain (tapi jangan terlalu panjang!) */
        const char *kategori =
            (input_umur < 5)  ? "Balita" :
            (input_umur < 12) ? "Anak-anak" :
            (input_umur < 18) ? "Remaja" :
            (input_umur < 60) ? "Dewasa" :
                                "Lansia";
        printf("  Kategori: %s\n", kategori);
    }

    /* -------------------------------------------------------
     * 8. COMMON BUG DEMO: Floating-point comparison
     * ------------------------------------------------------- */
    printf("\n--- 8. Float Comparison Bug ---\n\n");

    double result = 0.1 + 0.2;
    printf("  0.1 + 0.2 = %.20f\n", result);
    printf("  0.3       = %.20f\n", 0.3);

    /* ❌ Direct comparison mungkin GAGAL */
    if (result == 0.3) {
        printf("  result == 0.3 : true\n");
    } else {
        printf("  result == 0.3 : false (floating-point imprecision!)\n");
    }

    /* ✅ Comparison dengan epsilon */
    double epsilon = 1e-9;
    if (result - 0.3 < epsilon && 0.3 - result < epsilon) {
        printf("  fabs(result - 0.3) < epsilon : true (safe comparison)\n");
    }

    printf("\n========================================\n");
    printf("Fase 1 SELESAI! Lanjut ke modul 006 (Perulangan).\n");

    return 0;
}
