/*
 * ============================================================
 *  008 — String: Contoh Kode Utama
 * ============================================================
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o program main.c
 *    ./program
 * ============================================================
 */

#include <stdio.h>
#include <string.h>

/* Function prototypes */
int my_strlen(const char *s);
void my_strcpy(char *dst, const char *src);

int main(void) {

    printf("╔══════════════════════════════════════════╗\n");
    printf("║  008 — String                            ║\n");
    printf("╚══════════════════════════════════════════╝\n\n");

    /* -------------------------------------------------------
     * 1. STRING BASICS — char array + '\0'
     * ------------------------------------------------------- */
    printf("--- 1. String Basics ---\n\n");

    char salam[] = "Halo, Dunia!";
    printf("  String  : \"%s\"\n", salam);
    printf("  sizeof  : %zu (termasuk '\\0')\n", sizeof(salam));
    printf("  strlen  : %zu (tanpa '\\0')\n", strlen(salam));

    /* Lihat isi per karakter */
    printf("  Karakter: ");
    for (int i = 0; salam[i] != '\0'; i++) {
        printf("'%c' ", salam[i]);
    }
    printf("'\\0'\n");

    /* Modifikasi karakter */
    salam[0] = 'W';
    salam[1] = 'o';
    salam[2] = 'w';
    salam[3] = '!';
    salam[4] = '\0';   /* Potong string */
    printf("\n  Setelah modifikasi: \"%s\" (len=%zu)\n", salam, strlen(salam));

    /* -------------------------------------------------------
     * 2. INISIALISASI STRING
     * ------------------------------------------------------- */
    printf("\n--- 2. Inisialisasi String ---\n\n");

    /* Cara 1: String literal */
    char cara1[] = "Hello";
    printf("  cara1 = \"%s\" (sizeof=%zu)\n", cara1, sizeof(cara1));

    /* Cara 2: Char array manual */
    char cara2[] = {'W', 'o', 'r', 'l', 'd', '\0'};
    printf("  cara2 = \"%s\" (sizeof=%zu)\n", cara2, sizeof(cara2));

    /* Cara 3: Buffer kosong untuk diisi nanti */
    char cara3[50] = "";   /* String kosong — cara3[0] = '\0' */
    printf("  cara3 = \"%s\" (sizeof=%zu, strlen=%zu)\n",
           cara3, sizeof(cara3), strlen(cara3));

    /* Cara 4: Pointer ke string literal (READ-ONLY!) */
    const char *cara4 = "Read Only";
    printf("  cara4 = \"%s\" (ini read-only, jangan diubah!)\n", cara4);

    /* -------------------------------------------------------
     * 3. strlen — panjang string
     * ------------------------------------------------------- */
    printf("\n--- 3. strlen ---\n\n");

    char teks[] = "Belajar C";
    printf("  \"%s\"\n", teks);
    printf("  strlen  = %zu\n", strlen(teks));         /* 9 */
    printf("  sizeof  = %zu\n", sizeof(teks));         /* 10 */
    printf("  Manual  = %d\n", my_strlen(teks));       /* 9 */

    /* -------------------------------------------------------
     * 4. strcpy / strncpy — copy string
     * ------------------------------------------------------- */
    printf("\n--- 4. strcpy / strncpy ---\n\n");

    char src[] = "Hello World";
    char dst1[20];
    char dst2[8];

    /* strcpy — copy semua */
    strcpy(dst1, src);
    printf("  strcpy  : \"%s\"\n", dst1);

    /* strncpy — copy max n karakter */
    strncpy(dst2, src, sizeof(dst2) - 1);
    dst2[sizeof(dst2) - 1] = '\0';
    printf("  strncpy : \"%s\" (buffer 8, dipotong)\n", dst2);

    /* Manual strcpy */
    char dst3[20];
    my_strcpy(dst3, src);
    printf("  manual  : \"%s\"\n", dst3);

    /* -------------------------------------------------------
     * 5. strcat / strncat — gabungkan string
     * ------------------------------------------------------- */
    printf("\n--- 5. strcat / strncat ---\n\n");

    char greeting[50] = "Selamat ";
    printf("  Awal    : \"%s\"\n", greeting);

    strcat(greeting, "Pagi, ");
    printf("  +Pagi   : \"%s\"\n", greeting);

    strncat(greeting, "Indonesia Raya!", sizeof(greeting) - strlen(greeting) - 1);
    printf("  +Indo   : \"%s\"\n", greeting);

    /* -------------------------------------------------------
     * 6. strcmp — bandingkan string
     * ------------------------------------------------------- */
    printf("\n--- 6. strcmp ---\n\n");

    const char *s1 = "apple";
    const char *s2 = "banana";
    const char *s3 = "apple";

    printf("  strcmp(\"%s\", \"%s\") = %d", s1, s3, strcmp(s1, s3));
    printf("  → %s\n", strcmp(s1, s3) == 0 ? "SAMA" : "BEDA");

    printf("  strcmp(\"%s\", \"%s\") = %d", s1, s2, strcmp(s1, s2));
    printf("  → %s\n", strcmp(s1, s2) < 0 ? "s1 < s2" : "s1 > s2");

    printf("  strcmp(\"%s\", \"%s\") = %d", s2, s1, strcmp(s2, s1));
    printf("  → %s\n", strcmp(s2, s1) > 0 ? "s2 > s1" : "s2 < s1");

    /* Case-insensitive? C standar tidak punya, tapi bisa manual */
    printf("\n  Tip: C tidak punya strcasecmp() di standar\n");
    printf("  Tapi tersedia di POSIX (Linux/macOS) via <strings.h>\n");

    /* -------------------------------------------------------
     * 7. strchr / strstr — cari karakter/substring
     * ------------------------------------------------------- */
    printf("\n--- 7. strchr / strstr ---\n\n");

    char kalimat[] = "Halo, apa kabar dunia?";
    printf("  Kalimat: \"%s\"\n\n", kalimat);

    /* strchr — cari karakter */
    char *pos = strchr(kalimat, 'k');
    if (pos) {
        printf("  strchr 'k'  → index %ld, sisa: \"%s\"\n",
               pos - kalimat, pos);
    }

    /* strrchr — cari karakter terakhir */
    char *last = strrchr(kalimat, 'a');
    if (last) {
        printf("  strrchr 'a' → index %ld, sisa: \"%s\"\n",
               last - kalimat, last);
    }

    /* strstr — cari substring */
    char *sub = strstr(kalimat, "kabar");
    if (sub) {
        printf("  strstr \"kabar\" → index %ld\n", sub - kalimat);
    }

    char *notfound = strstr(kalimat, "xyz");
    printf("  strstr \"xyz\" → %s\n", notfound ? "ketemu" : "TIDAK KETEMU");

    /* -------------------------------------------------------
     * 8. strtok — pecah string jadi token
     * ------------------------------------------------------- */
    printf("\n--- 8. strtok ---\n\n");

    char csv[] = "merah,hijau,biru,kuning,ungu";
    printf("  Data CSV: \"%s\"\n", csv);
    printf("  Token:\n");

    int token_num = 0;
    char *token = strtok(csv, ",");
    while (token != NULL) {
        token_num++;
        printf("    %d. \"%s\"\n", token_num, token);
        token = strtok(NULL, ",");
    }

    printf("  ⚠️  csv sekarang rusak: \"%s\" (hanya token pertama)\n", csv);

    /* -------------------------------------------------------
     * 9. snprintf — format ke buffer (AMAN)
     * ------------------------------------------------------- */
    printf("\n--- 9. snprintf ---\n\n");

    char buffer[50];
    int umur = 21;
    double ipk = 3.85;

    snprintf(buffer, sizeof(buffer), "Umur: %d, IPK: %.2f", umur, ipk);
    printf("  buffer = \"%s\"\n", buffer);

    /* Cek truncation */
    char small[15];
    int needed = snprintf(small, sizeof(small), "String yang sangat panjang");
    printf("  small  = \"%s\"\n", small);
    printf("  Butuh %d chars, buffer hanya %zu → %s\n",
           needed, sizeof(small),
           (size_t)needed >= sizeof(small) ? "TERPOTONG" : "OK");

    /* -------------------------------------------------------
     * 10. STRCSPN — cara elegan hapus newline
     * ------------------------------------------------------- */
    printf("\n--- 10. strcspn trick ---\n\n");

    char with_newline[] = "Hello World\n";
    printf("  Sebelum: \"%s\"  (ada newline di akhir)\n", with_newline);

    with_newline[strcspn(with_newline, "\n")] = '\0';
    printf("  Sesudah: \"%s\"\n", with_newline);

    printf("  strcspn mencari index PERTAMA dari karakter di set.\n");
    printf("  Kalau '\\n' tidak ada, return strlen → aman, tidak rusak.\n");

    printf("\n========================================\n");
    printf("Selesai! Lanjut ke modul 009 (Function).\n");

    return 0;
}

/* -------------------------------------------------------
 * IMPLEMENTASI FUNCTION
 * ------------------------------------------------------- */

int my_strlen(const char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

void my_strcpy(char *dst, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}
