/*
 * ============================================================
 *  004 — Input/Output: Jawaban Latihan
 * ============================================================
 *  SPOILER ALERT! Kerjakan exercise.c dulu.
 *
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o answer exercise_answer.c
 *    ./answer
 * ============================================================
 */

#include <stdio.h>
#include <string.h>

int main(void) {

    int c; /* Untuk pembersihan buffer */

    /* ============================================
     * LEVEL 1: EASY — Profil User
     * ============================================ */
    printf("=== LEVEL 1: Profil User ===\n\n");

    char nama_l1[50];
    int umur_l1;
    double tinggi_l1;

    /* Baca nama dulu (fgets) sebelum scanf, menghindari buffer issue */
    printf("  Nama lengkap: ");
    fgets(nama_l1, sizeof(nama_l1), stdin);
    nama_l1[strcspn(nama_l1, "\n")] = '\0';

    printf("  Umur: ");
    scanf("%d", &umur_l1);

    printf("  Tinggi (cm): ");
    scanf("%lf", &tinggi_l1);  /* %lf untuk double di scanf! */

    printf("\n");
    printf("  +---------------------------------+\n");
    printf("  |        PROFIL USER              |\n");
    printf("  +---------------------------------+\n");
    printf("  |  Nama    : %-20s |\n", nama_l1);
    printf("  |  Umur    : %-3d tahun             |\n", umur_l1);
    printf("  |  Tinggi  : %-6.2f cm             |\n", tinggi_l1);
    printf("  +---------------------------------+\n");
    printf("\n");

    /* Bersihkan buffer setelah scanf */
    while ((c = getchar()) != '\n' && c != EOF) { }

    /* ============================================
     * LEVEL 2: MEDIUM — Kartu Karakter Game
     * ============================================ */
    printf("=== LEVEL 2: Kartu Karakter Game ===\n\n");

    char char_name[50];
    char char_class[30];
    int level;
    int hp;
    double atk;
    double def;

    printf("  Nama karakter: ");
    fgets(char_name, sizeof(char_name), stdin);
    char_name[strcspn(char_name, "\n")] = '\0';

    printf("  Class (Warrior/Mage/Archer): ");
    fgets(char_class, sizeof(char_class), stdin);
    char_class[strcspn(char_class, "\n")] = '\0';

    printf("  Level: ");
    scanf("%d", &level);

    printf("  HP: ");
    scanf("%d", &hp);

    printf("  Attack Power: ");
    scanf("%lf", &atk);

    printf("  Defense: ");
    scanf("%lf", &def);

    double power_rating = atk + def;

    printf("\n");
    printf("  +========================================+\n");
    printf("  |        CHARACTER CARD                  |\n");
    printf("  +========================================+\n");
    printf("  |  Name    : %-27s|\n", char_name);
    printf("  |  Class   : %-27s|\n", char_class);
    printf("  |  Level   : %-27d|\n", level);
    printf("  +----------------------------------------+\n");
    printf("  |  HP      : %15d               |\n", hp);
    printf("  |  ATK     : %15.2f               |\n", atk);
    printf("  |  DEF     : %15.2f               |\n", def);
    printf("  +----------------------------------------+\n");
    printf("  |  Power Rating: %-23.2f|\n", power_rating);
    printf("  +========================================+\n");
    printf("\n");

    /* Bersihkan buffer */
    while ((c = getchar()) != '\n' && c != EOF) { }

    /* ============================================
     * LEVEL 3: HARD — Struk Belanja
     * ============================================ */
    printf("=== LEVEL 3: Struk Belanja ===\n\n");

    char nama_toko[50];
    char barang1[30], barang2[30], barang3[30];
    int qty1, qty2, qty3;
    double harga1, harga2, harga3;

    printf("  Nama toko: ");
    fgets(nama_toko, sizeof(nama_toko), stdin);
    nama_toko[strcspn(nama_toko, "\n")] = '\0';

    /* Barang 1 */
    printf("  Barang 1 (nama): ");
    fgets(barang1, sizeof(barang1), stdin);
    barang1[strcspn(barang1, "\n")] = '\0';
    printf("  Barang 1 (qty) : ");
    scanf("%d", &qty1);
    printf("  Barang 1 (harga): ");
    scanf("%lf", &harga1);
    while ((c = getchar()) != '\n' && c != EOF) { }

    /* Barang 2 */
    printf("  Barang 2 (nama): ");
    fgets(barang2, sizeof(barang2), stdin);
    barang2[strcspn(barang2, "\n")] = '\0';
    printf("  Barang 2 (qty) : ");
    scanf("%d", &qty2);
    printf("  Barang 2 (harga): ");
    scanf("%lf", &harga2);
    while ((c = getchar()) != '\n' && c != EOF) { }

    /* Barang 3 */
    printf("  Barang 3 (nama): ");
    fgets(barang3, sizeof(barang3), stdin);
    barang3[strcspn(barang3, "\n")] = '\0';
    printf("  Barang 3 (qty) : ");
    scanf("%d", &qty3);
    printf("  Barang 3 (harga): ");
    scanf("%lf", &harga3);

    /* Hitung */
    double sub1 = qty1 * harga1;
    double sub2 = qty2 * harga2;
    double sub3 = qty3 * harga3;
    double total = sub1 + sub2 + sub3;
    double pajak = total * 0.11;
    double grand_total = total + pajak;

    /* Header menggunakan snprintf */
    char header[60];
    snprintf(header, sizeof(header), "%s", nama_toko);

    /* Cetak struk */
    printf("\n");
    printf("  ============================================\n");
    printf("  %*s\n", (int)(22 + strlen(header) / 2), header);
    printf("  ============================================\n");
    printf("  %-4s %-16s %4s %9s %11s\n", "No", "Barang", "Qty", "Harga", "Subtotal");
    printf("  --------------------------------------------\n");
    printf("  %-4d %-16s %4d %9.0f %11.2f\n", 1, barang1, qty1, harga1, sub1);
    printf("  %-4d %-16s %4d %9.0f %11.2f\n", 2, barang2, qty2, harga2, sub2);
    printf("  %-4d %-16s %4d %9.0f %11.2f\n", 3, barang3, qty3, harga3, sub3);
    printf("  --------------------------------------------\n");
    printf("  %26s %15.2f\n", "Subtotal:", total);
    printf("  %26s %15.2f\n", "PPN 11% :", pajak);
    printf("  ============================================\n");
    printf("  %26s %15.2f\n", "TOTAL   :", grand_total);
    printf("  ============================================\n");
    printf("       Terima kasih sudah berbelanja!\n");

    return 0;
}
