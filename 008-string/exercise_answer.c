/*
 * ============================================================
 *  008 — String: Jawaban Latihan
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
#include <ctype.h>

/* Function prototypes */
void my_strrev(char *str);
int is_palindrome(const char *str);
void to_lowercase(char *dst, const char *src);

int main(void) {

    /* ============================================
     * LEVEL 1: EASY — Hitung Karakter
     * ============================================ */
    printf("=== LEVEL 1: Hitung Karakter ===\n\n");

    char input[200];
    printf("  Masukkan kalimat: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';   /* Hapus newline */

    int vowels = 0, consonants = 0, digits = 0, spaces = 0, others = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];

        if (c == ' ') {
            spaces++;
        } else if (c >= '0' && c <= '9') {
            digits++;
        } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            /* Huruf — cek vowel atau consonant */
            char lower = tolower(c);
            if (lower == 'a' || lower == 'e' || lower == 'i' ||
                lower == 'o' || lower == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        } else {
            others++;
        }
    }

    printf("\n  Input     : \"%s\"\n", input);
    printf("  Vowel     : %d\n", vowels);
    printf("  Consonant : %d\n", consonants);
    printf("  Digit     : %d\n", digits);
    printf("  Spasi     : %d\n", spaces);
    printf("  Lainnya   : %d\n", others);

    /* ============================================
     * LEVEL 2: MEDIUM — Reverse & Palindrome
     * ============================================ */
    printf("\n=== LEVEL 2: Reverse & Palindrome ===\n\n");

    /* Demo reverse */
    char rev_test[] = "Hello World";
    printf("  Sebelum reverse: \"%s\"\n", rev_test);
    my_strrev(rev_test);
    printf("  Sesudah reverse: \"%s\"\n", rev_test);

    /* Demo palindrome */
    const char *test_cases[] = {
        "racecar", "Katak", "hello", "madam", "A", "",
        "Kasur rusak", "level"
    };
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    printf("\n  Palindrome check:\n");
    for (int i = 0; i < num_tests; i++) {
        int result = is_palindrome(test_cases[i]);
        printf("    \"%s\" → %s\n",
               test_cases[i],
               result ? "✅ Palindrome" : "❌ Bukan palindrome");
    }

    /* ============================================
     * LEVEL 3: HARD — Word Counter & Frequency
     * ============================================ */
    printf("\n=== LEVEL 3: Word Counter & Frequency ===\n\n");

    char kalimat[500];
    printf("  Masukkan kalimat: ");
    fgets(kalimat, sizeof(kalimat), stdin);
    kalimat[strcspn(kalimat, "\n")] = '\0';

    /* Copy kalimat karena strtok akan merusaknya */
    char kalimat_copy[500];
    strncpy(kalimat_copy, kalimat, sizeof(kalimat_copy) - 1);
    kalimat_copy[sizeof(kalimat_copy) - 1] = '\0';

    /* Array untuk menyimpan kata unik (max 100 kata, max 50 char per kata) */
    char words[100][50];
    int freq[100];
    int unique_count = 0;
    int total_words = 0;

    /* Pecah kalimat jadi token */
    char *token = strtok(kalimat_copy, " \t");
    while (token != NULL) {
        total_words++;

        /* Convert token ke lowercase untuk perbandingan */
        char lower_token[50];
        to_lowercase(lower_token, token);

        /* Cek apakah kata sudah ada di daftar */
        int found = 0;
        for (int i = 0; i < unique_count; i++) {
            if (strcmp(words[i], lower_token) == 0) {
                freq[i]++;
                found = 1;
                break;
            }
        }

        /* Kalau belum ada, tambahkan */
        if (!found && unique_count < 100) {
            strncpy(words[unique_count], lower_token, 49);
            words[unique_count][49] = '\0';
            freq[unique_count] = 1;
            unique_count++;
        }

        token = strtok(NULL, " \t");
    }

    printf("\n  Input      : \"%s\"\n", kalimat);
    printf("  Total kata : %d\n", total_words);
    printf("  Kata unik  : %d\n", unique_count);
    printf("\n  Frekuensi:\n");

    for (int i = 0; i < unique_count; i++) {
        printf("    %-15s : %d\n", words[i], freq[i]);
    }

    return 0;
}

/* -------------------------------------------------------
 * IMPLEMENTASI FUNCTION
 * ------------------------------------------------------- */

/*
 * my_strrev — reverse string in-place
 * Swap karakter dari kedua ujung menuju tengah
 */
void my_strrev(char *str) {
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

/*
 * is_palindrome — cek apakah string palindrome (case insensitive)
 *
 * PENTING: Kita TIDAK mengubah string asli (const char *).
 * Kita hanya bandingkan karakter dari kedua ujung tanpa reverse.
 * Skip karakter non-alfabet untuk handle kasus "Kasur rusak".
 */
int is_palindrome(const char *str) {
    int len = strlen(str);
    if (len <= 1) return 1;   /* String kosong atau 1 char = palindrome */

    int left = 0;
    int right = len - 1;

    while (left < right) {
        /* Skip non-alpha dari kiri */
        while (left < right && !isalpha(str[left])) left++;
        /* Skip non-alpha dari kanan */
        while (left < right && !isalpha(str[right])) right--;

        if (tolower(str[left]) != tolower(str[right])) {
            return 0;   /* Bukan palindrome */
        }
        left++;
        right--;
    }

    return 1;   /* Palindrome */
}

/*
 * to_lowercase — convert string ke lowercase, simpan di dst
 */
void to_lowercase(char *dst, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = tolower(src[i]);
        i++;
    }
    dst[i] = '\0';
}
