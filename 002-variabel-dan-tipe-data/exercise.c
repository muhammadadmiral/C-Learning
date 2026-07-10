/*
 * ============================================================
 *  002 — Variabel & Tipe Data: Latihan
 * ============================================================
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o exercise exercise.c
 *    ./exercise
 * ============================================================
 */

#include <stdio.h>
#include <limits.h>

int main(void) {

    /* ============================================
     * LEVEL 1: EASY — Semua Tipe Data & sizeof
     * ============================================
     * Tugas:
     * 1. Deklarasi + inisialisasi variabel untuk SETIAP tipe data:
     *    - char   (karakter inisial nama lu)
     *    - short  (tahun lahir lu disingkat, misal 99)
     *    - int    (umur lu)
     *    - long   (populasi Indonesia ~275000000)
     *    - float  (IPK lu, misal 3.55)
     *    - double (nilai PI 3.14159265358979)
     *
     * 2. Cetak SEMUA nilainya dengan format specifier yang benar
     *
     * 3. Cetak sizeof() dari setiap tipe data
     *
     * Output yang diharapkan (contoh):
     *   char   : A (sizeof: 1 byte)
     *   short  : 99 (sizeof: 2 byte)
     *   int    : 25 (sizeof: 4 byte)
     *   ...dst
     */

    // TODO: Tulis kode lu di sini


    /* ============================================
     * LEVEL 2: MEDIUM — Kalkulator Konversi Suhu
     * ============================================
     * Tugas:
     * 1. Deklarasi variabel celsius bertipe double, isi dengan 36.5
     * 2. Hitung konversi ke Fahrenheit: F = (C * 9.0/5.0) + 32.0
     * 3. Hitung konversi ke Kelvin: K = C + 273.15
     * 4. Cetak ketiga nilai dengan 2 angka di belakang koma
     *
     * PENTING:
     *   - Hati-hati integer division! 9/5 = 1 (bukan 1.8)
     *   - Pakai 9.0/5.0 atau cast ke double
     *
     * Output yang diharapkan:
     *   === Konversi Suhu ===
     *   Celsius    : 36.50 °C
     *   Fahrenheit : 97.70 °F
     *   Kelvin     : 309.65 K
     *
     * Bonus: coba ganti celsius ke 100.0 dan 0.0, pastikan hasilnya benar
     *   100°C = 212°F = 373.15K (titik didih air)
     *   0°C   = 32°F  = 273.15K (titik beku air)
     */

    // TODO: Tulis kode lu di sini


    /* ============================================
     * LEVEL 3: HARD / CHALLENGE — Overflow Explorer
     * ============================================
     * Tugas (gabungan konsep modul 001 + 002):
     *
     * 1. Cetak batas semua tipe integer dari <limits.h>:
     *    - CHAR_MIN, CHAR_MAX
     *    - SHRT_MIN, SHRT_MAX
     *    - INT_MIN, INT_MAX
     *    - LONG_MIN, LONG_MAX
     *    - LLONG_MIN, LLONG_MAX
     *    - UCHAR_MAX, USHRT_MAX, UINT_MAX, ULONG_MAX, ULLONG_MAX
     *
     * 2. Demonstrasikan UNSIGNED overflow:
     *    - Buat unsigned char uc = 255
     *    - Cetak uc, lalu uc + 1 (harus wrap ke 0)
     *    - Buat unsigned char uc2 = 0
     *    - Cetak uc2, lalu uc2 - 1 (harus wrap ke 255)
     *
     * 3. Demonstrasikan casting data loss:
     *    - Buat int big = 100000
     *    - Cast ke short: short s = (short)big
     *    - Cetak keduanya — tunjukkan bahwa nilainya berubah
     *    - Jelaskan di komentar KENAPA nilainya berubah
     *
     * 4. Buat tampilan tabel rapi (pakai escape character \t
     *    dari modul 001) yang menampilkan semua hasil di atas
     *
     * Output contoh:
     *   === OVERFLOW EXPLORER ===
     *   Tipe            Min                  Max
     *   -----------------------------------------------
     *   char            -128                 127
     *   unsigned char   0                    255
     *   ...dst
     *
     *   === OVERFLOW DEMO ===
     *   unsigned char 255 + 1 = 0 (wrap around!)
     *   ...dst
     */

    // TODO: Tulis kode lu di sini


    return 0;
}
