/*
 * ============================================================
 *  003 — Operator: Latihan
 * ============================================================
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o exercise exercise.c
 *    ./exercise
 * ============================================================
 */

#include <stdio.h>

int main(void) {

    /* ============================================
     * LEVEL 1: EASY — Kalkulator Geometri
     * ============================================
     * Tugas:
     * 1. Deklarasi variabel panjang = 12 dan lebar = 5 (int)
     * 2. Hitung dan cetak:
     *    - Luas        = panjang * lebar
     *    - Keliling    = 2 * (panjang + lebar)
     *    - Diagonal    = (gunakan rumus: panjang^2 + lebar^2, hitung hasilnya saja,
     *                     belum perlu sqrt karena belum kenal math.h)
     *    - Sisa bagi   = panjang % lebar
     *
     * 3. Tunjukkan perbedaan integer vs float division:
     *    - panjang / lebar (integer)
     *    - (double)panjang / lebar (float)
     *
     * Output contoh:
     *   === Kalkulator Geometri ===
     *   Panjang  : 12
     *   Lebar    : 5
     *   Luas     : 60
     *   Keliling : 34
     *   p^2+l^2  : 169  (= diagonal^2, tanpa sqrt)
     *   p % l    : 2
     *   p / l    : 2    (integer)
     *   p / l    : 2.40 (float)
     */

    // TODO: Tulis kode lu di sini


    /* ============================================
     * LEVEL 2: MEDIUM — Bit Flags: Status Player
     * ============================================
     * Tugas: Implementasi status system untuk game character
     *
     * 1. Definisikan flag-flag berikut dengan #define dan bit shift:
     *    - STATUS_ALIVE     (bit 0) = 1
     *    - STATUS_POISONED  (bit 1) = 2
     *    - STATUS_SHIELDED  (bit 2) = 4
     *    - STATUS_ON_FIRE   (bit 3) = 8
     *
     * 2. Buat variabel unsigned int player_status = 0
     *
     * 3. Lakukan operasi berikut dan cetak status setiap langkah:
     *    a. SET player_status = ALIVE + SHIELDED
     *       → cetak: "Status: 5 | Alive: Ya, Poisoned: Tidak, Shielded: Ya, On Fire: Tidak"
     *    b. Player kena poison → SET STATUS_POISONED
     *    c. Player shield pecah → REMOVE STATUS_SHIELDED
     *    d. TOGGLE STATUS_ON_FIRE (nyalain api)
     *    e. TOGGLE STATUS_ON_FIRE lagi (matiin api)
     *    f. Cetak status final
     *
     * Gunakan: |= (set), &= ~ (remove), ^= (toggle), & (check)
     *
     * Bonus: buat fungsi-like macro atau helper printf untuk
     * mengecek dan mencetak "Ya"/"Tidak" dari setiap flag
     */

    // TODO: Tulis kode lu di sini


    /* ============================================
     * LEVEL 3: HARD / CHALLENGE — Precedence Puzzle
     * ============================================
     * Tugas (gabungan konsep modul 002 + 003):
     *
     * TANPA menjalankan kode, PREDIKSI output dari setiap ekspresi.
     * Tulis prediksi lu di komentar, lalu verifikasi dengan printf.
     *
     * 1.  int r1 = 2 + 3 * 4 - 1;
     *     Prediksi: ???
     *
     * 2.  int r2 = (2 + 3) * (4 - 1);
     *     Prediksi: ???
     *
     * 3.  int r3 = 10 % 3 + 10 / 3;
     *     Prediksi: ???
     *
     * 4.  int a = 5;
     *     int r4 = a++ + ++a;   // Catatan: ini sebenarnya UB!
     *     Prediksi: ???         // Tulis "UB" kalau lu paham ini UB
     *
     * 5.  int r5 = 1 << 4 | 1 << 2;
     *     Prediksi: ???
     *
     * 6.  int r6 = 15 & 0xF0;
     *     Prediksi: ???
     *     (Hint: 15 = 0x0F, 0xF0 = 240. Ingat & per bit)
     *
     * 7.  int val = 42;
     *     int r7 = (val > 40) && (val < 50) || (val == 100);
     *     Prediksi: ???
     *
     * Setelah menuliskan prediksi, cetak semua hasil dan bandingkan.
     * Untuk soal nomor 4, jelaskan kenapa hasilnya bisa berbeda
     * di compiler yang berbeda.
     */

    // TODO: Tulis prediksi di komentar, lalu verifikasi dengan printf


    return 0;
}
