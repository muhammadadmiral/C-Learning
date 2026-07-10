/*
 * ============================================================
 *  005 — Percabangan: Jawaban Latihan
 * ============================================================
 *  SPOILER ALERT! Kerjakan exercise.c dulu.
 *
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o answer exercise_answer.c
 *    ./answer
 * ============================================================
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void) {

    int c; /* Untuk pembersihan buffer */

    /* ============================================
     * LEVEL 1: EASY — Kalkulator Grade
     * ============================================ */
    printf("=== LEVEL 1: Kalkulator Grade ===\n\n");

    int nilai;
    printf("  Masukkan nilai (0-100): ");
    int items = scanf("%d", &nilai);

    if (items != 1) {
        printf("  ERROR: Input bukan angka!\n");
    } else if (nilai < 0 || nilai > 100) {
        printf("  ERROR: Nilai harus 0-100! (input: %d)\n", nilai);
    } else {
        const char *grade;

        if (nilai >= 90)      grade = "A";
        else if (nilai >= 85) grade = "B+";
        else if (nilai >= 80) grade = "B";
        else if (nilai >= 75) grade = "C+";
        else if (nilai >= 70) grade = "C";
        else if (nilai >= 60) grade = "D";
        else                  grade = "F";

        printf("  Nilai: %d -> Grade: %s\n", nilai, grade);

        /* Ternary: lulus jika grade C ke atas (nilai >= 70) */
        printf("  Status: %s\n", (nilai >= 70) ? "LULUS" : "TIDAK LULUS");
    }

    /* Bersihkan buffer */
    while ((c = getchar()) != '\n' && c != EOF) { }

    /* ============================================
     * LEVEL 2: MEDIUM — Menu ATM
     * ============================================ */
    printf("\n=== LEVEL 2: Menu ATM ===\n\n");

    int saldo = 1000000;

    printf("  === ATM BANK CODING ===\n");
    printf("  [1] Cek Saldo\n");
    printf("  [2] Tarik Tunai\n");
    printf("  [3] Setor Tunai\n");
    printf("  [4] Keluar\n");
    printf("  Pilih menu: ");

    int menu;
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            printf("  Saldo Anda: Rp %d\n", saldo);
            break;

        case 2: {
            printf("  Jumlah tarik: ");
            int tarik;
            scanf("%d", &tarik);

            if (tarik <= 0) {
                printf("  ERROR: Jumlah harus > 0!\n");
            } else if (tarik > saldo) {
                printf("  ERROR: Saldo tidak cukup! (saldo: Rp %d)\n", saldo);
            } else if (tarik % 50000 != 0) {
                printf("  ERROR: Jumlah harus kelipatan Rp 50.000!\n");
            } else {
                saldo -= tarik;
                printf("  Penarikan berhasil!\n");
                printf("  Saldo sekarang: Rp %d\n", saldo);
            }
            break;
        }

        case 3: {
            printf("  Jumlah setor: ");
            int setor;
            scanf("%d", &setor);

            if (setor <= 0) {
                printf("  ERROR: Jumlah harus > 0!\n");
            } else {
                saldo += setor;
                printf("  Setoran berhasil!\n");
                printf("  Saldo sekarang: Rp %d\n", saldo);
            }
            break;
        }

        case 4:
            printf("  Terima kasih telah menggunakan ATM Bank Coding!\n");
            break;

        default:
            printf("  Menu tidak valid!\n");
            break;
    }

    /* Bersihkan buffer */
    while ((c = getchar()) != '\n' && c != EOF) { }

    /* ============================================
     * LEVEL 3: HARD — Sistem Tiket Bioskop
     * ============================================ */
    printf("\n=== LEVEL 3: Sistem Tiket Bioskop ===\n\n");

    /* Input */
    char nama_penonton[50];
    printf("  Nama penonton: ");
    fgets(nama_penonton, sizeof(nama_penonton), stdin);
    nama_penonton[strcspn(nama_penonton, "\n")] = '\0';

    int umur_penonton;
    printf("  Umur: ");
    scanf("%d", &umur_penonton);

    int hari_num;
    printf("  Hari (1=Senin..7=Minggu): ");
    scanf("%d", &hari_num);

    printf("  Tipe kursi (R=Regular, P=Premium, V=VIP): ");
    char tipe_kursi;
    scanf(" %c", &tipe_kursi);  /* Spasi sebelum %c untuk skip whitespace */

    printf("  Punya membership? (y/n): ");
    char member_input;
    scanf(" %c", &member_input);

    /* Validasi input */
    bool valid = true;

    if (umur_penonton < 1 || umur_penonton > 120) {
        printf("  ERROR: Umur tidak valid!\n");
        valid = false;
    }
    if (valid && (hari_num < 1 || hari_num > 7)) {
        printf("  ERROR: Hari harus 1-7!\n");
        valid = false;
    }
    if (valid && tipe_kursi != 'R' && tipe_kursi != 'P' && tipe_kursi != 'V'
             && tipe_kursi != 'r' && tipe_kursi != 'p' && tipe_kursi != 'v') {
        printf("  ERROR: Tipe kursi harus R, P, atau V!\n");
        valid = false;
    }
    if (valid && member_input != 'y' && member_input != 'Y'
             && member_input != 'n' && member_input != 'N') {
        printf("  ERROR: Input membership harus y atau n!\n");
        valid = false;
    }

    if (valid) {
        bool is_member = (member_input == 'y' || member_input == 'Y');

        /* Harga dasar berdasarkan tipe kursi (switch) */
        double harga_dasar = 0;
        const char *nama_kursi = "";
        switch (tipe_kursi) {
            case 'R': case 'r':
                harga_dasar = 35000;
                nama_kursi = "Regular";
                break;
            case 'P': case 'p':
                harga_dasar = 50000;
                nama_kursi = "Premium";
                break;
            case 'V': case 'v':
                harga_dasar = 75000;
                nama_kursi = "VIP";
                break;
            default:
                break;
        }

        /* Nama hari (switch) */
        const char *nama_hari = "";
        switch (hari_num) {
            case 1: nama_hari = "Senin"; break;
            case 2: nama_hari = "Selasa"; break;
            case 3: nama_hari = "Rabu"; break;
            case 4: nama_hari = "Kamis"; break;
            case 5: nama_hari = "Jumat"; break;
            case 6: nama_hari = "Sabtu"; break;
            case 7: nama_hari = "Minggu"; break;
            default: break;
        }

        /* Hitung diskon/markup */
        double harga = harga_dasar;
        double diskon_hari = 0;
        double diskon_umur = 0;
        double diskon_member = 0;
        const char *ket_hari = "";
        const char *ket_umur = "";

        /* Diskon hari */
        if (hari_num == 2) {
            diskon_hari = harga * 0.30;
            harga -= diskon_hari;
            ket_hari = "Tuesday Promo -30%";
        } else if (hari_num == 6 || hari_num == 7) {
            diskon_hari = -(harga * 0.20); /* Negatif = markup */
            harga += harga * 0.20;
            ket_hari = "Weekend Markup +20%";
        }

        /* Diskon umur */
        if (umur_penonton < 12) {
            diskon_umur = harga * 0.50;
            harga -= diskon_umur;
            ket_umur = "Anak-anak -50%";
        } else if (umur_penonton >= 60) {
            diskon_umur = harga * 0.40;
            harga -= diskon_umur;
            ket_umur = "Lansia -40%";
        }

        /* Diskon member (dari harga setelah modifikasi) */
        if (is_member) {
            diskon_member = harga * 0.10;
            harga -= diskon_member;
        }

        /* Cetak struk */
        printf("\n");
        printf("  +================================+\n");
        printf("  |      TIKET BIOSKOP XXI         |\n");
        printf("  +================================+\n");
        printf("  |  Nama     : %-18s|\n", nama_penonton);
        printf("  |  Umur     : %-3d tahun          |\n", umur_penonton);
        printf("  |  Hari     : %-18s|\n", nama_hari);
        printf("  |  Kursi    : %-18s|\n", nama_kursi);
        printf("  |  Member   : %-18s|\n", is_member ? "Ya" : "Tidak");
        printf("  +--------------------------------+\n");
        printf("  |  Harga dasar  : Rp %9.0f  |\n", harga_dasar);

        if (diskon_hari > 0) {
            printf("  |  %-14s: -  %9.0f  |\n", ket_hari, diskon_hari);
        } else if (diskon_hari < 0) {
            printf("  |  %-14s: +  %9.0f  |\n", ket_hari, -diskon_hari);
        }

        if (diskon_umur > 0) {
            printf("  |  %-14s: -  %9.0f  |\n", ket_umur, diskon_umur);
        }

        if (diskon_member > 0) {
            printf("  |  Member -10%%   : -  %9.0f  |\n", diskon_member);
        }

        printf("  +================================+\n");
        printf("  |  TOTAL        : Rp %9.0f  |\n", harga);
        printf("  +================================+\n");
    }

    return 0;
}
