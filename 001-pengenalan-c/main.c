/*
 * ============================================================
 *  001 — Pengenalan C: Contoh Kode Utama
 * ============================================================
 *  File ini mendemonstrasikan semua konsep inti dari modul 001.
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o program main.c
 *    ./program       (macOS/Linux)
 *    .\program.exe   (Windows)
 * ============================================================
 */

#include <stdio.h>  /* Library standar untuk fungsi Input/Output */

int main(void) {

    /* -------------------------------------------------------
     * 1. printf() dasar — mencetak teks ke terminal
     * ------------------------------------------------------- */
    printf("=== SELAMAT DATANG DI C-LEARNING ===\n");
    printf("Modul 001: Pengenalan C\n\n");

    /* -------------------------------------------------------
     * 2. Escape characters — karakter spesial dalam string
     *    \n = newline (pindah baris)
     *    \t = tab (indentasi)
     *    \\ = cetak karakter backslash
     *    \" = cetak tanda kutip di dalam string
     * ------------------------------------------------------- */
    printf("--- Escape Characters Demo ---\n");
    printf("Newline:\n");
    printf("  Baris pertama\n  Baris kedua\n  Baris ketiga\n\n");

    printf("Tab:\n");
    printf("\tNama\t: Admiral\n");
    printf("\tBahasa\t: C\n");
    printf("\tLevel\t: Pemula\n\n");

    printf("Backslash & Kutip:\n");
    printf("  Path Windows : C:\\Users\\Admiral\\Projects\n");
    printf("  Dennis Ritchie bilang: \"C is a sharp tool.\"\n\n");

    /* -------------------------------------------------------
     * 3. printf() multiple kali — teks saling menyambung
     *    Tanpa \n, teks berikutnya NEMPEL di baris yang sama.
     * ------------------------------------------------------- */
    printf("--- Concatenation Demo ---\n");
    printf("Ini ");
    printf("satu ");
    printf("baris ");
    printf("nyambung.\n\n");

    /* -------------------------------------------------------
     * 4. Komentar — catatan untuk manusia, diabaikan compiler
     *
     *    Dua jenis:
     *      // komentar satu baris (C99+)
     *      Komentar banyak baris: buka dengan garis-miring bintang, tutup bintang garis-miring
     *
     *    Best practice:
     *      - Jelaskan KENAPA, bukan APA
     *      - Jangan komentari hal yang sudah obvious
     * ------------------------------------------------------- */

    // Contoh komentar yang BAIK:
    // Cetak separator sebelum penutup agar output lebih mudah dibaca
    printf("========================================\n");

    /* Contoh komentar yang BURUK (terlalu obvious, jangan ditiru):
       printf mencetak teks "Program selesai" ke layar */
    printf("Program selesai. Return code: 0 (sukses)\n");

    /* -------------------------------------------------------
     * 5. return 0 — beri tahu OS bahwa program selesai sukses
     *
     *    Nilai 0 = EXIT_SUCCESS (tidak ada error)
     *    Nilai != 0 = ada error (misal return 1)
     *
     *    Lu bisa cek exit code di terminal:
     *      ./program
     *      echo $?     (macOS/Linux)
     *      echo %errorlevel%  (Windows CMD)
     * ------------------------------------------------------- */
    return 0;
}
