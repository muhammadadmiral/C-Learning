/*
 * ============================================================
 *  007 — Array: Latihan
 * ============================================================
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o exercise exercise.c
 *    ./exercise
 * ============================================================
 */

#include <stdio.h>

int main(void) {

    /* ============================================
     * LEVEL 1: EASY — Min, Max, Rata-rata
     * ============================================
     * Tugas:
     * 1. Minta user input jumlah elemen (max 100)
     * 2. Minta user input tiap elemen
     * 3. Cari dan tampilkan:
     *    - Nilai minimum
     *    - Nilai maksimum
     *    - Rata-rata (tampilkan 2 desimal)
     *    - Index dari min dan max
     *
     * Contoh output:
     *   Jumlah elemen: 5
     *   Elemen ke-1: 42
     *   Elemen ke-2: 17
     *   Elemen ke-3: 85
     *   Elemen ke-4: 3
     *   Elemen ke-5: 56
     *
     *   Data    : [42, 17, 85, 3, 56]
     *   Min     : 3 (index 3)
     *   Max     : 85 (index 2)
     *   Rata²   : 40.60
     *
     * Tips: inisialisasi min/max dengan elemen pertama
     */

    // TODO: Tulis kode lu di sini


    /* ============================================
     * LEVEL 2: MEDIUM — Selection Sort + Binary Search
     * ============================================
     * Tugas:
     * 1. Pakai array dari LEVEL 1 (atau hardcode array baru)
     * 2. Implementasi SELECTION SORT:
     *    - Untuk setiap posisi i (0 sampai n-2):
     *      a. Cari elemen terkecil dari index i sampai n-1
     *      b. Swap elemen terkecil itu dengan elemen di posisi i
     *    - Cetak array setelah setiap pass
     * 3. Setelah sorted, minta user input angka yang dicari
     * 4. Pakai BINARY SEARCH untuk mencari angka tersebut
     * 5. Tampilkan hasilnya (ketemu di index berapa, atau tidak ketemu)
     *
     * Contoh output:
     *   Array awal   : [64, 25, 12, 22, 11]
     *   Pass 1       : [11, 25, 12, 22, 64]
     *   Pass 2       : [11, 12, 25, 22, 64]
     *   Pass 3       : [11, 12, 22, 25, 64]
     *   Pass 4       : [11, 12, 22, 25, 64]
     *   Array sorted : [11, 12, 22, 25, 64]
     *
     *   Cari angka: 22
     *   22 ditemukan di index 2
     *
     * Tips:
     *   - Selection sort = "cari minimum, taruh di depan"
     *   - Jangan lupa binary search HARUS di array yang sudah sorted
     */

    // TODO: Tulis kode lu di sini


    /* ============================================
     * LEVEL 3: HARD — Rotasi Array In-Place
     * ============================================
     * Tugas:
     * Rotasi array ke KIRI sebanyak k posisi, tanpa array tambahan.
     *
     * Contoh:
     *   Array  : [1, 2, 3, 4, 5, 6, 7]
     *   k = 3
     *   Hasil  : [4, 5, 6, 7, 1, 2, 3]
     *
     * Algoritma Reversal (3 langkah):
     *   1. Reverse bagian pertama (0 sampai k-1)
     *      [1, 2, 3, 4, 5, 6, 7] → [3, 2, 1, 4, 5, 6, 7]
     *   2. Reverse bagian kedua (k sampai n-1)
     *      [3, 2, 1, 4, 5, 6, 7] → [3, 2, 1, 7, 6, 5, 4]
     *   3. Reverse seluruh array (0 sampai n-1)
     *      [3, 2, 1, 7, 6, 5, 4] → [4, 5, 6, 7, 1, 2, 3] ✅
     *
     * Langkah-langkah:
     * 1. Buat fungsi reverse(int arr[], int start, int end)
     *    yang membalik elemen dari index start sampai end
     * 2. Buat fungsi rotate_left(int arr[], int n, int k)
     *    yang memanggil reverse 3 kali
     * 3. Handle edge case: k = 0, k >= n (pakai k = k % n)
     * 4. Tampilkan array sebelum dan sesudah rotasi
     *
     * Bonus: buat juga rotate_right!
     *
     * Tips:
     *   - Reverse in-place: swap arr[start] dengan arr[end],
     *     lalu start++, end--, sampai start >= end
     *   - k % n untuk handle k yang lebih besar dari n
     */

    // TODO: Tulis kode lu di sini


    return 0;
}
