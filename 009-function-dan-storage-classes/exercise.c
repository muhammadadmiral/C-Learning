/*
 * ============================================================
 *  009 — Function & Storage Classes: Latihan
 * ============================================================
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o exercise exercise.c
 *    ./exercise
 * ============================================================
 */

#include <stdio.h>

int main(void) {

    /* ============================================
     * LEVEL 1: EASY — is_prime, gcd, lcm
     * ============================================
     * Tugas:
     * 1. Buat fungsi int is_prime(int n)
     *    - Return 1 kalau n prima, 0 kalau bukan
     *    - Handle edge case: n <= 1 → bukan prima
     *    - Optimasi: cukup cek divisor sampai sqrt(n)
     *      → for (int i = 2; i * i <= n; i++)
     *
     * 2. Buat fungsi int gcd(int a, int b)
     *    - Hitung Greatest Common Divisor (FPB)
     *    - Pakai algoritma Euclidean:
     *      while (b != 0) { int t = b; b = a % b; a = t; }
     *      return a;
     *
     * 3. Buat fungsi int lcm(int a, int b)
     *    - Hitung Least Common Multiple (KPK)
     *    - Rumus: lcm(a,b) = |a * b| / gcd(a,b)
     *    - Gunakan fungsi gcd() yang sudah dibuat
     *
     * 4. Test semua dari main:
     *    - Cetak bilangan prima dari 2 sampai 50
     *    - gcd(48, 18) = 6
     *    - lcm(12, 8) = 24
     */

    // TODO: Tulis kode lu di sini


    /* ============================================
     * LEVEL 2: MEDIUM — Mini Library Statistik
     * ============================================
     * Tugas:
     * Buat 4 fungsi yang bekerja dengan array:
     *
     * 1. int arr_min(const int arr[], int n)
     *    → return nilai minimum
     *
     * 2. int arr_max(const int arr[], int n)
     *    → return nilai maksimum
     *
     * 3. double arr_mean(const int arr[], int n)
     *    → return rata-rata (double)
     *
     * 4. double arr_median(int arr[], int n)
     *    → return median (nilai tengah)
     *    ⚠️ PERLU SORT dulu! (pakai bubble sort dari modul 007)
     *    - Kalau n ganjil: median = arr[n/2]
     *    - Kalau n genap: median = (arr[n/2-1] + arr[n/2]) / 2.0
     *    ⚠️ Karena sort mengubah array, pertimbangkan copy dulu
     *
     * Test:
     *   int data[] = {12, 5, 8, 3, 15, 7, 10};
     *   Min    : 3
     *   Max    : 15
     *   Mean   : 8.57
     *   Median : 8.00 (sorted: 3 5 7 [8] 10 12 15)
     */

    // TODO: Tulis kode lu di sini


    /* ============================================
     * LEVEL 3: HARD — Caesar Cipher + Static Counter
     * ============================================
     * Tugas:
     * 1. Buat fungsi void caesar_encrypt(char *text, int shift)
     *    - Geser setiap huruf sebanyak 'shift' posisi ke kanan
     *    - Hanya huruf a-z dan A-Z yang digeser, lainnya tetap
     *    - Wrap around: 'z' + 1 = 'a', 'Z' + 1 = 'A'
     *    - Contoh: "Hello" shift=3 → "Khoor"
     *
     * 2. Buat fungsi void caesar_decrypt(char *text, int shift)
     *    - Kebalikan dari encrypt (geser ke kiri)
     *    - Atau: encrypt dengan shift = 26 - shift
     *
     * 3. Kedua fungsi harus punya STATIC COUNTER internal
     *    yang menghitung total operasi (encrypt/decrypt)
     *
     * 4. Buat fungsi int get_crypto_ops_count(void)
     *    yang return total operasi (enkripsi + dekripsi)
     *    → Pakai static variable yang di-share
     *
     * Test:
     *   caesar_encrypt("Hello, World!", 3)  → "Khoor, Zruog!"
     *   caesar_decrypt("Khoor, Zruog!", 3)  → "Hello, World!"
     *   get_crypto_ops_count() → 2
     *
     * Tips:
     *   - Untuk huruf kecil: encrypted = (c - 'a' + shift) % 26 + 'a'
     *   - Untuk decrypt: decrypted = (c - 'a' - shift + 26) % 26 + 'a'
     *   - +26 sebelum modulo agar tidak negatif
     */

    // TODO: Tulis kode lu di sini


    return 0;
}
