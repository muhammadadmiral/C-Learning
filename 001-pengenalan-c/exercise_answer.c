/*
 * ============================================================
 *  001 — Pengenalan C: Jawaban Latihan
 * ============================================================
 *  SPOILER ALERT! Coba kerjakan exercise.c dulu sebelum
 *  melihat file ini.
 *
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o answer exercise_answer.c
 *    ./answer
 * ============================================================
 */

#include <stdio.h>

int main(void) {

    /* ============================================
     * LEVEL 1: EASY — Cetak Biodata
     * ============================================ */
    printf("=== BIODATA ===\n");
    printf("\tNama\t: Admiral\n");
    printf("\tUmur\t: 25\n");
    printf("\tHobi\t: Coding\n");
    printf("\tBahasa\t: C\n");
    printf("\n");

    /* ============================================
     * LEVEL 2: MEDIUM — Kartu Nama dengan Border
     * ============================================ */
    printf("+----------------------------------+\n");
    printf("|         KARTU NAMA               |\n");
    printf("+----------------------------------+\n");
    printf("|  Nama   : Admiral                |\n");
    printf("|  Email  : admiral@email.com      |\n");
    printf("|  GitHub : muhammadadmiral        |\n");
    printf("+----------------------------------+\n");
    printf("\n");

    /* ============================================
     * LEVEL 3: HARD / CHALLENGE — Menu Restoran
     * ============================================
     * Catatan: Karakter Unicode box-drawing (╔ ═ ╗ dll)
     * butuh terminal yang mendukung UTF-8. Hampir semua
     * terminal modern (macOS Terminal, Windows Terminal,
     * GNOME Terminal, iTerm2) sudah mendukung.
     */
    printf("╔══════════════════════════════════╗\n");
    printf("║       WARUNG MAKAN \"SEDAP\"       ║\n");
    printf("║       Jl. Coding No. 42          ║\n");
    printf("╠══════════════════════════════════╣\n");
    printf("║  No  Menu              Harga     ║\n");
    printf("╠══════════════════════════════════╣\n");
    printf("║  1.  Nasi Goreng       Rp 15K    ║\n");
    printf("║  2.  Mie Ayam          Rp 12K    ║\n");
    printf("║  3.  Es Teh Manis      Rp  5K    ║\n");
    printf("║  4.  Kopi Hitam        Rp  8K    ║\n");
    printf("║  5.  Sate Ayam (10pc)  Rp 20K    ║\n");
    printf("╠══════════════════════════════════╣\n");
    printf("║  \"Dijamin enak atau uang         ║\n");
    printf("║   kembali... ke dompet kami\"      ║\n");
    printf("╚══════════════════════════════════╝\n");

    return 0;
}
