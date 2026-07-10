/*
 * ============================================================
 *  011 — Rekursi: Latihan
 * ============================================================
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o exercise exercise.c
 *    ./exercise
 * ============================================================
 */

#include <stdio.h>
#include <string.h>

int main(void) {

  /* ============================================
   * LEVEL 1: EASY — Sum of Digits, Reverse Number, GCD
   * ============================================
   * Tugas:
   *
   * 1. int sum_digits(int n)
   *    Hitung jumlah digit dari n secara rekursif.
   *    Contoh: sum_digits(1234) → 1+2+3+4 = 10
   *    Base case: n < 10 → return n
   *    Recursive: return (n % 10) + sum_digits(n / 10)
   *
   * 2. int reverse_number(int n)
   *    Balik angka secara rekursif.
   *    Contoh: reverse_number(1234) → 4321
   *    Tips: gunakan helper dengan accumulator
   *    int reverse_helper(int n, int acc) {
   *        if (n == 0) return acc;
   *        return reverse_helper(n / 10, acc * 10 + n % 10);
   *    }
   *
   * 3. int gcd_recursive(int a, int b)
   *    GCD dengan Euclidean algorithm secara rekursif.
   *    Base case: b == 0 → return a
   *    Recursive: return gcd_recursive(b, a % b)
   *
   * Test:
   *   sum_digits(9876)     → 30
   *   sum_digits(5)        → 5
   *   reverse_number(1234) → 4321
   *   reverse_number(100)  → 1
   *   gcd_recursive(48,18) → 6
   */

  // TODO: Tulis kode lu di sini

  /* ============================================
   * LEVEL 2: MEDIUM — Recursive Binary Search & Pattern
   * ============================================
   * Tugas:
   *
   * 1. int binary_search_rec(int arr[], int low, int high, int target)
   *    Binary search versi rekursif.
   *    Base case: low > high → return -1
   *    Recursive: cek mid, lalu panggil kiri atau kanan
   *
   * 2. void print_triangle(int n)
   *    Cetak segitiga bintang secara REKURSIF (tanpa loop!)
   *    n = 5:
   *    *
   *    * *
   *    * * *
   *    * * * *
   *    * * * * *
   *
   *    Tips: print_triangle(n-1) dulu, baru cetak baris ke-n
   *
   * 3. void print_triangle_inv(int n)
   *    Cetak segitiga TERBALIK secara rekursif:
   *    * * * * *
   *    * * * *
   *    * * *
   *    * *
   *    *
   *
   *    Tips: cetak baris ke-n dulu, baru print_triangle_inv(n-1)
   *
   * Test binary search:
   *   arr = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72}
   *   Cari 23 → index 5
   *   Cari 99 → -1 (tidak ketemu)
   */

  // TODO: Tulis kode lu di sini

  /* ============================================
   * LEVEL 3: HARD — Permutasi String
   * ============================================
   * Tugas:
   * Cetak SEMUA permutasi (urutan berbeda) dari karakter string.
   *
   * void permutations(char *str, int start, int end)
   *
   * Contoh: permutations("ABC", 0, 2)
   * Output:
   *   ABC
   *   ACB
   *   BAC
   *   BCA
   *   CBA
   *   CAB
   *
   * Algoritma:
   * 1. Base case: start == end → cetak string
   * 2. Untuk setiap posisi i dari start sampai end:
   *    a. Swap str[start] dengan str[i]
   *    b. Rekursi: permutations(str, start + 1, end)
   *    c. Swap balik (backtrack) str[start] dengan str[i]
   *
   * Jumlah permutasi = n! (factorial)
   * "ABC" (3 huruf) → 3! = 6 permutasi
   * "ABCD" (4 huruf) → 4! = 24 permutasi
   *
   * Tips:
   *   - Swap dua karakter: temp = a; a = b; b = temp;
   *   - Backtracking penting! Swap balik agar string
   *     kembali ke keadaan semula sebelum iterasi berikutnya
   *   - Coba gambar tree of recursive calls untuk "ABC"
   */

  // TODO: Tulis kode lu di sini

  return 0;
}
