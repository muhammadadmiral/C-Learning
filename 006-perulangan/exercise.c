/*
 * ============================================================
 *  006 — Perulangan: Latihan
 * ============================================================
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o exercise exercise.c
 *    ./exercise
 * ============================================================
 */

#include <stdio.h>

int main(void) {

    /* ============================================
     * LEVEL 1: EASY — FizzBuzz
     * ============================================
     * Tugas:
     * Cetak angka 1 sampai 30, tapi:
     *   - Kalau kelipatan 3 → cetak "Fizz"
     *   - Kalau kelipatan 5 → cetak "Buzz"
     *   - Kalau kelipatan 3 DAN 5 → cetak "FizzBuzz"
     *   - Selain itu → cetak angkanya
     *
     * Output contoh:
     *   1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz 16 ...
     *
     * Tips: cek kelipatan 15 DULU sebelum 3 dan 5 (kenapa?)
     */

    // TODO: Tulis kode lu di sini


    /* ============================================
     * LEVEL 2: MEDIUM — Pattern Printer
     * ============================================
     * Tugas:
     * 1. Minta user input tinggi (1-15)
     * 2. Validasi input dengan do-while
     * 3. Cetak 3 pattern:
     *
     * Pattern A: Segitiga terbalik
     *   * * * * *
     *   * * * *
     *   * * *
     *   * *
     *   *
     *
     * Pattern B: Diamond (belah ketupat)
     *       *
     *      ***
     *     *****
     *    *******
     *   *********
     *    *******
     *     *****
     *      ***
     *       *
     *
     * Pattern C: Hollow rectangle (kotak berlubang)
     *   * * * * *
     *   *       *
     *   *       *
     *   *       *
     *   * * * * *
     *
     * Tips:
     *   - Diamond = piramida atas + piramida terbalik bawah
     *   - Hollow rectangle: cetak bintang hanya di baris pertama,
     *     baris terakhir, kolom pertama, atau kolom terakhir
     */

    // TODO: Tulis kode lu di sini


    /* ============================================
     * LEVEL 3: HARD / CHALLENGE — Kalkulator Interaktif
     * ============================================
     * Tugas (gabungan konsep modul 003 + 005 + 006):
     *
     * 1. Buat kalkulator interaktif dengan infinite loop menu
     * 2. Menu:
     *    [1] Penjumlahan
     *    [2] Pengurangan
     *    [3] Perkalian
     *    [4] Pembagian
     *    [5] Modulo
     *    [6] Pangkat (x^n, pakai loop, BUKAN math.h)
     *    [7] Lihat history
     *    [0] Keluar
     *
     * 3. Untuk menu 1-5: minta 2 angka, hitung, tampilkan hasil
     * 4. Untuk menu 6: minta base dan exponent, hitung pakai loop
     * 5. Simpan 5 operasi terakhir (tanpa array — pakai 5 variabel
     *    terpisah, shift manual: hist5=hist4, hist4=hist3, ...)
     *    Format history: "10 + 5 = 15"
     * 6. Validasi: pembagian/modulo oleh 0, exponent negatif
     * 7. Loop sampai user pilih [0]
     *
     * Bonus: hitung berapa total operasi yang sudah dilakukan
     */

    // TODO: Tulis kode lu di sini


    return 0;
}
