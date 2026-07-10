/*
 * ============================================================
 *  005 — Percabangan: Latihan
 * ============================================================
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o exercise exercise.c
 *    ./exercise
 * ============================================================
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void) {

    /* ============================================
     * LEVEL 1: EASY — Kalkulator Grade
     * ============================================
     * Tugas:
     * 1. Minta user input nilai (0-100) pakai scanf
     * 2. Validasi: jika < 0 atau > 100, cetak error
     * 3. Tentukan grade:
     *    A  = 90-100
     *    B+ = 85-89
     *    B  = 80-84
     *    C+ = 75-79
     *    C  = 70-74
     *    D  = 60-69
     *    F  = 0-59
     * 4. Cetak: "Nilai: XX -> Grade: X"
     * 5. Bonus: Cetak "LULUS" (grade C ke atas) atau "TIDAK LULUS"
     *    menggunakan ternary operator
     *
     * Contoh output:
     *   Masukkan nilai: 87
     *   Nilai: 87 -> Grade: B+
     *   Status: LULUS
     */

    // TODO: Tulis kode lu di sini


    /* ============================================
     * LEVEL 2: MEDIUM — Menu ATM
     * ============================================
     * Tugas:
     * 1. Definisikan saldo awal: 1000000 (satu juta)
     * 2. Tampilkan menu:
     *    [1] Cek Saldo
     *    [2] Tarik Tunai
     *    [3] Setor Tunai
     *    [4] Keluar
     * 3. Minta user pilih menu (pakai switch-case)
     * 4. Implementasi:
     *    - Cek Saldo: tampilkan saldo
     *    - Tarik Tunai:
     *      a. Minta jumlah penarikan
     *      b. Validasi: tidak boleh > saldo
     *      c. Validasi: harus kelipatan 50000
     *      d. Kurangi saldo, tampilkan saldo baru
     *    - Setor Tunai:
     *      a. Minta jumlah setoran
     *      b. Validasi: harus > 0
     *      c. Tambah saldo, tampilkan saldo baru
     *    - Keluar: cetak "Terima kasih!"
     *    - Default: cetak "Menu tidak valid!"
     *
     * 5. Format saldo: rata kanan, misal "Rp  1.000.000"
     *    (boleh tanpa titik pemisah ribuan, fokus ke logika)
     *
     * Contoh output:
     *   === ATM BANK CODING ===
     *   [1] Cek Saldo
     *   [2] Tarik Tunai
     *   [3] Setor Tunai
     *   [4] Keluar
     *   Pilih menu: 2
     *   Jumlah tarik: 250000
     *   Penarikan berhasil!
     *   Saldo sekarang: Rp 750000
     */

    // TODO: Tulis kode lu di sini


    /* ============================================
     * LEVEL 3: HARD / CHALLENGE — Sistem Tiket Bioskop
     * ============================================
     * Tugas (gabungan konsep modul 002, 003, 004, 005):
     *
     * Buat sistem pembelian tiket bioskop yang menghitung
     * harga berdasarkan beberapa faktor:
     *
     * 1. Input:
     *    - Nama penonton (fgets, bisa pakai spasi)
     *    - Umur (int)
     *    - Hari (1=Senin..7=Minggu, pakai switch)
     *    - Tipe kursi: R=Regular, P=Premium, V=VIP (char)
     *    - Punya membership? (y/n, pakai char)
     *
     * 2. Harga dasar:
     *    - Regular  : 35000
     *    - Premium  : 50000
     *    - VIP      : 75000
     *
     * 3. Modifikasi harga:
     *    - Hari Selasa ("Tues-day promo"): diskon 30%
     *    - Weekend (Sab-Min): markup +20%
     *    - Anak-anak (umur < 12): diskon 50%
     *    - Lansia (umur >= 60): diskon 40%
     *    - Member: diskon tambahan 10% (dari harga setelah modifikasi di atas)
     *
     * 4. Output: cetak struk tiket:
     *
     *    ╔══════════════════════════════╗
     *    ║     TIKET BIOSKOP XXI       ║
     *    ╠══════════════════════════════╣
     *    ║  Nama     : John Doe        ║
     *    ║  Umur     : 25 tahun        ║
     *    ║  Hari     : Selasa          ║
     *    ║  Kursi    : Premium         ║
     *    ║  Member   : Ya              ║
     *    ╠══════════════════════════════╣
     *    ║  Harga dasar : Rp  50000    ║
     *    ║  Diskon hari : -  15000     ║
     *    ║  Diskon member: - 3500      ║
     *    ╠══════════════════════════════╣
     *    ║  TOTAL       : Rp  31500    ║
     *    ╚══════════════════════════════╝
     *
     * 5. Validasi SEMUA input (umur valid, hari 1-7,
     *    kursi R/P/V, member y/n)
     *
     * Tips:
     *   - Hitung diskon secara bertahap (layer by layer)
     *   - Pakai switch untuk hari (nama hari) dan tipe kursi (harga dasar)
     *   - Pakai if-else untuk umur dan membership
     *   - Pakai ternary untuk cetak "Ya"/"Tidak"
     *   - Handle buffer antara scanf dan fgets!
     */

    // TODO: Tulis kode lu di sini


    return 0;
}
