/*
 * ============================================================
 *  010 — Header, Multi-file, Preprocessor: Contoh Kode Utama
 * ============================================================
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o program main.c mathlib.c strutils.c
 *    ./program
 *
 *  Atau pakai Makefile:
 *    make
 *    ./program
 * ============================================================
 */

#include <stdio.h>
#include <string.h>
#include "mathlib.h"
#include "strutils.h"

/* -------------------------------------------------------
 * Macro Definitions (demo)
 * ------------------------------------------------------- */
#define APP_NAME    "Multi-file Demo"
#define APP_VERSION "1.0"

/* Function-like macros */
#define SQUARE(x)      ((x) * (x))
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/* Debug logging macro */
#define LOG(msg) \
    printf("[%s:%d] %s(): %s\n", __FILE__, __LINE__, __func__, msg)

/* Multi-line macro */
#define PRINT_SECTION(title) \
    do { \
        printf("\n--- %s ---\n\n", title); \
    } while(0)

int main(void) {

    printf("╔══════════════════════════════════════════╗\n");
    printf("║  010 — Header, Multi-file, Preprocessor  ║\n");
    printf("╚══════════════════════════════════════════╝\n");
    printf("  App: %s v%s\n", APP_NAME, APP_VERSION);

    /* -------------------------------------------------------
     * 1. MENGGUNAKAN MATHLIB (dari mathlib.h / mathlib.c)
     * ------------------------------------------------------- */
    PRINT_SECTION("1. mathlib.h — Math Library");

    printf("  math_add(15, 27)       = %d\n", math_add(15, 27));
    printf("  math_subtract(50, 18)  = %d\n", math_subtract(50, 18));
    printf("  math_multiply(6, 7)    = %d\n", math_multiply(6, 7));
    printf("  math_divide(22, 7)     = %.4f\n", math_divide(22, 7));
    printf("  math_power(2, 10)      = %lld\n", math_power(2, 10));
    printf("  math_factorial(10)     = %d\n", math_factorial(10));
    printf("  math_gcd(48, 18)       = %d\n", math_gcd(48, 18));
    printf("  math_lcm(12, 8)        = %d\n", math_lcm(12, 8));
    printf("  math_is_prime(17)      = %s\n",
           math_is_prime(17) ? "true" : "false");
    printf("  math_abs(-42)          = %d\n", math_abs(-42));
    printf("  PI (from mathlib.h)    = %.10f\n", MATHLIB_PI);
    printf("  mathlib version        = %s\n", MATHLIB_VERSION);

    /* -------------------------------------------------------
     * 2. MENGGUNAKAN STRUTILS (dari strutils.h / strutils.c)
     * ------------------------------------------------------- */
    PRINT_SECTION("2. strutils.h — String Utilities");

    char sentence[] = "Hello, World! This is C programming.";
    printf("  Kalimat: \"%s\"\n", sentence);
    printf("  Jumlah kata   : %d\n", str_count_words(sentence));
    printf("  Jumlah 'l'    : %d\n", str_count_char(sentence, 'l'));
    printf("  Starts 'Hello': %s\n",
           str_starts_with(sentence, "Hello") ? "true" : "false");
    printf("  Ends '.'      : %s\n",
           str_ends_with(sentence, ".") ? "true" : "false");

    /* Transform */
    char upper_test[] = "Hello World";
    str_to_upper(upper_test);
    printf("\n  to_upper: \"%s\"\n", upper_test);

    char lower_test[] = "Hello World";
    str_to_lower(lower_test);
    printf("  to_lower: \"%s\"\n", lower_test);

    char rev_test[] = "Hello";
    str_reverse(rev_test);
    printf("  reverse : \"%s\"\n", rev_test);

    /* Palindrome */
    printf("\n  Palindrome checks:\n");
    printf("    \"racecar\" → %s\n",
           str_is_palindrome("racecar") ? "✅ Yes" : "❌ No");
    printf("    \"hello\"   → %s\n",
           str_is_palindrome("hello") ? "✅ Yes" : "❌ No");
    printf("    \"Katak\"   → %s\n",
           str_is_palindrome("Katak") ? "✅ Yes" : "❌ No");

    /* -------------------------------------------------------
     * 3. MACRO DEMO
     * ------------------------------------------------------- */
    PRINT_SECTION("3. Macro Demo");

    printf("  SQUARE(7)    = %d\n", SQUARE(7));
    printf("  SQUARE(3+1)  = %d (kurung penting!)\n", SQUARE(3 + 1));

    int demo_arr[] = {10, 20, 30, 40, 50};
    printf("  ARRAY_SIZE   = %zu\n", ARRAY_SIZE(demo_arr));

    /* LOG macro */
    LOG("Demo log message");

    /* -------------------------------------------------------
     * 4. CONDITIONAL COMPILATION
     * ------------------------------------------------------- */
    PRINT_SECTION("4. Conditional Compilation");

#ifdef DEBUG
    printf("  🐛 DEBUG mode is ON\n");
    printf("  Compile with: gcc -DDEBUG ...\n");
#else
    printf("  DEBUG mode is OFF\n");
    printf("  Compile with -DDEBUG to enable debug output\n");
#endif

    /* -------------------------------------------------------
     * 5. PREDEFINED MACROS
     * ------------------------------------------------------- */
    PRINT_SECTION("5. Predefined Macros");

    printf("  __FILE__  = %s\n", __FILE__);
    printf("  __LINE__  = %d\n", __LINE__);
    printf("  __DATE__  = %s\n", __DATE__);
    printf("  __TIME__  = %s\n", __TIME__);
    printf("  __func__  = %s\n", __func__);

#ifdef __STDC_VERSION__
    printf("  __STDC_VERSION__ = %ld", __STDC_VERSION__);
    if (__STDC_VERSION__ >= 201710L) printf(" (C17)");
    else if (__STDC_VERSION__ >= 201112L) printf(" (C11)");
    else if (__STDC_VERSION__ >= 199901L) printf(" (C99)");
    printf("\n");
#endif

    printf("\n========================================\n");
    printf("Selesai! Lanjut ke modul 011 (Rekursi).\n");

    return 0;
}
