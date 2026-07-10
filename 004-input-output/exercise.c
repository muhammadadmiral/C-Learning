/*
 * ============================================================
 *  004 — Input/Output: Latihan
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
     * LEVEL 1: EASY — Profil User
     * ============================================
     * Tugas:
     * 1. Minta user memasukkan:
     *    - Nama lengkap (bisa pakai spasi → gunakan fgets)
     *    - Umur (int → gunakan scanf)
     *    - Tinggi badan dalam cm (double, misal 175.5 → gunakan scanf)
     *
     * 2. Cetak data dalam format tabel:
     *
     *    ╔═══════════════════════════════╗
     *    ║       PROFIL USER             ║
     *    ╠═══════════════════════════════╣
     *    ║  Nama    : Admiral            ║
     *    ║  Umur    : 25 tahun           ║
     *    ║  Tinggi  : 175.50 cm          ║
     *    ╚═══════════════════════════════╝
     *
     * PENTING:
     *   - Perhatikan urutan scanf dan fgets (buffer problem!)
     *   - Hapus newline dari fgets
     *   - Gunakan %lf untuk scanf double, %f untuk printf double
     */

    // TODO: Tulis kode lu di sini


    /* ============================================
     * LEVEL 2: MEDIUM — Kartu Karakter Game
     * ============================================
     * Tugas:
     * 1. Minta user memasukkan data karakter RPG:
     *    - Nama karakter (string, bisa pakai spasi)
     *    - Class (Warrior/Mage/Archer — string)
     *    - Level (int)
     *    - HP (int)
     *    - Attack Power (double)
     *    - Defense (double)
     *
     * 2. Cetak "kartu karakter" dengan format:
     *
     *    +========================================+
     *    |        ⚔️  CHARACTER CARD  ⚔️          |
     *    +========================================+
     *    |  Name    : Dark Knight                 |
     *    |  Class   : Warrior                     |
     *    |  Level   : 42                          |
     *    +----------------------------------------+
     *    |  HP      :          1500               |
     *    |  ATK     :           85.50             |
     *    |  DEF     :           62.30             |
     *    +----------------------------------------+
     *    |  Power Rating: 147.80                  |
     *    +========================================+
     *
     * 3. Hitung "Power Rating" = ATK + DEF (double, 2 desimal)
     *
     * Challenge:
     *   - Handle SEMUA buffer transition (scanf → fgets) dengan benar
     *   - Gunakan width specifier untuk alignment
     *   - HP rata kanan dengan width 15
     *   - ATK dan DEF dengan presisi 2 desimal dan width 15
     */

    // TODO: Tulis kode lu di sini


    /* ============================================
     * LEVEL 3: HARD / CHALLENGE — Struk Belanja
     * ============================================
     * Tugas (gabungan konsep modul 002 + 003 + 004):
     *
     * 1. Buat program "struk belanja" sederhana:
     *    - Minta nama toko (fgets)
     *    - Minta 3 barang beserta harganya:
     *      * Nama barang (fgets — bisa pakai spasi)
     *      * Qty (int — scanf)
     *      * Harga satuan (double — scanf)
     *
     * 2. Hitung:
     *    - Subtotal per barang = qty * harga
     *    - Total semua barang
     *    - Pajak 11% (PPN)
     *    - Grand total (total + pajak)
     *
     * 3. Cetak struk dengan format SANGAT rapi:
     *
     *    ==========================================
     *            TOKO CODING JAYA
     *    ==========================================
     *    No  Barang          Qty    Harga  Subtotal
     *    ------------------------------------------
     *     1  Keyboard          1  250000   250000.00
     *     2  Mouse             2   75000   150000.00
     *     3  Monitor           1 3500000  3500000.00
     *    ------------------------------------------
     *                         Subtotal:  3900000.00
     *                         PPN 11% :   429000.00
     *    ==========================================
     *                         TOTAL   :  4329000.00
     *    ==========================================
     *         Terima kasih sudah berbelanja!
     *
     * Challenge:
     *   - Semua angka rata kanan
     *   - Nama barang rata kiri dengan width
     *   - Harga dengan 2 desimal
     *   - Handle SEMUA buffer problem
     *   - Gunakan snprintf untuk membangun string header
     */

    // TODO: Tulis kode lu di sini


    return 0;
}
