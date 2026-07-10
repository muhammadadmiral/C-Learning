/*
 * ============================================================
 *  004 — Input/Output: Contoh Kode Utama
 * ============================================================
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o program main.c
 *    ./program
 * ============================================================
 */

#include <stdio.h>
#include <string.h>   /* Untuk strcspn() — menghapus newline dari fgets */

int main(void) {

    printf("╔══════════════════════════════════════════╗\n");
    printf("║  004 — Input/Output                      ║\n");
    printf("╚══════════════════════════════════════════╝\n\n");

    /* -------------------------------------------------------
     * 1. printf() FORMAT SPECIFIERS
     * ------------------------------------------------------- */
    printf("--- 1. printf() Format Specifiers ---\n\n");

    int angka = 42;
    double pi = 3.14159265358979;
    char huruf = 'Z';
    char nama[] = "Admiral";

    /* Specifier dasar */
    printf("  %%d  (int)       : %d\n", angka);
    printf("  %%u  (unsigned)  : %u\n", (unsigned int)angka);
    printf("  %%o  (oktal)     : %o\n", angka);
    printf("  %%x  (hex lower) : %x\n", angka);
    printf("  %%X  (hex upper) : %X\n", angka);
    printf("  %%#x (hex+prefix): %#x\n", angka);
    printf("  %%f  (double)    : %f\n", pi);
    printf("  %%e  (scientific): %e\n", pi);
    printf("  %%g  (auto)      : %g\n", pi);
    printf("  %%c  (char)      : %c\n", huruf);
    printf("  %%s  (string)    : %s\n", nama);
    printf("  %%%%  (literal %%) : 100%%\n\n");

    /* -------------------------------------------------------
     * 2. WIDTH, PRECISION, FLAGS
     * ------------------------------------------------------- */
    printf("--- 2. Width, Precision, Flags ---\n\n");

    /* Width: lebar minimum field */
    printf("  Width 10 (rata kanan) : [%10d]\n", angka);
    printf("  Width 10 (rata kiri)  : [%-10d]\n", angka);
    printf("  Width 10 (pad zero)   : [%010d]\n", angka);

    /* Precision untuk float */
    printf("  Default               : [%f]\n", pi);
    printf("  .2 precision          : [%.2f]\n", pi);
    printf("  .0 precision          : [%.0f]\n", pi);
    printf("  10.4 (width.precision): [%10.4f]\n", pi);

    /* Precision untuk string */
    printf("  String full           : [%s]\n", "Hello World");
    printf("  String .5             : [%.5s]\n", "Hello World");

    /* Flag + (selalu tampilkan tanda) */
    printf("  Positif (+flag)       : [%+d]\n", 42);
    printf("  Negatif (+flag)       : [%+d]\n", -42);
    printf("\n");

    /* -------------------------------------------------------
     * 3. TABEL RAPI dengan printf()
     *    Real world: buat laporan di terminal
     * ------------------------------------------------------- */
    printf("--- 3. Tabel Rapi ---\n\n");

    printf("  %-15s %8s %10s\n", "Barang", "Qty", "Harga");
    printf("  %-15s %8s %10s\n", "---------------", "--------", "----------");
    printf("  %-15s %8d %10.2f\n", "Nasi Goreng", 2, 15000.0);
    printf("  %-15s %8d %10.2f\n", "Es Teh Manis", 3, 5000.0);
    printf("  %-15s %8d %10.2f\n", "Sate Ayam", 1, 20000.0);
    printf("  %-15s %8s %10s\n", "---------------", "--------", "----------");
    printf("  %-15s %8s %10.2f\n", "TOTAL", "", 50000.0);
    printf("\n");

    /* -------------------------------------------------------
     * 4. scanf() — membaca input dari user
     * ------------------------------------------------------- */
    printf("--- 4. scanf() Demo ---\n\n");

    int umur;
    printf("  Masukkan umur lu: ");
    int items_read = scanf("%d", &umur);

    if (items_read == 1) {
        printf("  Umur lu: %d tahun\n", umur);
    } else {
        printf("  Input tidak valid!\n");
    }

    /* -------------------------------------------------------
     * 5. BUFFER PROBLEM & SOLUSI
     *    Setelah scanf("%d"), ada '\n' sisa di buffer.
     *    Kita harus membersihkannya sebelum fgets().
     * ------------------------------------------------------- */
    printf("\n--- 5. Buffer Problem & Solusi ---\n\n");

    /* Bersihkan buffer setelah scanf("%d") */
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* Buang semua karakter sampai newline */
    }

    /* Sekarang fgets() bisa bekerja dengan benar */
    char nama_lengkap[50];
    printf("  Masukkan nama lengkap: ");
    fgets(nama_lengkap, sizeof(nama_lengkap), stdin);

    /* Hapus newline di akhir fgets() */
    nama_lengkap[strcspn(nama_lengkap, "\n")] = '\0';

    printf("  Nama: %s\n", nama_lengkap);
    printf("  Umur: %d\n", umur);

    /* -------------------------------------------------------
     * 6. scanf() vs fgets() — PERBANDINGAN
     * ------------------------------------------------------- */
    printf("\n--- 6. scanf() vs fgets() ---\n\n");

    char kota[50];
    printf("  Masukkan kota (bisa pakai spasi): ");
    fgets(kota, sizeof(kota), stdin);
    kota[strcspn(kota, "\n")] = '\0';

    printf("  Kota: [%s]\n", kota);
    printf("  (fgets membaca seluruh baris termasuk spasi!)\n");

    /* -------------------------------------------------------
     * 7. snprintf() — print ke string (bukan ke layar)
     * ------------------------------------------------------- */
    printf("\n--- 7. snprintf() ---\n\n");

    char buffer[100];

    /* Bangun string secara dinamis */
    snprintf(buffer, sizeof(buffer),
             "Profil: %s, %d tahun, dari %s",
             nama_lengkap, umur, kota);

    printf("  Hasil snprintf: %s\n", buffer);

    /* snprintf return jumlah karakter yang SEHARUSNYA ditulis */
    int written = snprintf(buffer, sizeof(buffer),
                           "Teks yang sangat panjang: %d", 12345);
    printf("  snprintf return: %d (karakter yang ditulis)\n", written);

    /* -------------------------------------------------------
     * 8. getchar() dan putchar()
     * ------------------------------------------------------- */
    printf("\n--- 8. getchar() & putchar() ---\n\n");

    printf("  Tekan sembarang tombol lalu Enter: ");
    int key = getchar();
    printf("  Lu tekan: ");
    putchar(key);
    putchar('\n');
    printf("  ASCII code: %d\n", key);

    /* Bersihkan buffer */
    while ((c = getchar()) != '\n' && c != EOF) { }

    /* -------------------------------------------------------
     * 9. puts() — sederhana, otomatis newline
     * ------------------------------------------------------- */
    printf("\n--- 9. puts() ---\n\n");

    puts("  puts() otomatis menambahkan newline di akhir.");
    puts("  Tidak bisa pakai format specifier (%d, %s, dll).");
    puts("  Cocok untuk cetak string statis sederhana.");

    printf("\n========================================\n");
    printf("Selesai! Lanjut ke modul 005 (Percabangan).\n");

    return 0;
}
