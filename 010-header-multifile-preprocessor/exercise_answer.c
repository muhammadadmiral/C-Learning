/*
 * ============================================================
 *  010 — Header, Multi-file, Preprocessor: Jawaban Latihan
 * ============================================================
 *  SPOILER ALERT! Kerjakan exercise.c dulu.
 *
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o answer exercise_answer.c
 *    ./answer
 *
 *  Dengan debug logging:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -DLOG_LEVEL=3 -o answer exercise_answer.c
 * ============================================================
 */

#include <stdio.h>
#include <string.h>

/* ============================================================
 * LEVEL 1: MACRO COLLECTION
 * ============================================================ */

#define MAX(a, b)           ((a) > (b) ? (a) : (b))
#define MIN(a, b)           ((a) < (b) ? (a) : (b))
#define ABS(x)              ((x) < 0 ? -(x) : (x))
#define ARRAY_SIZE(arr)     (sizeof(arr) / sizeof((arr)[0]))
#define CLAMP(x, lo, hi)    (MIN(MAX((x), (lo)), (hi)))
#define IN_RANGE(x, lo, hi) ((x) >= (lo) && (x) <= (hi))

/* SWAP pakai do-while(0) dan variabel temp int.
 * Untuk tipe lain, buat macro terpisah atau pakai function.
 * Catatan: typeof(a) adalah GCC extension, tidak portable. */
#define SWAP_INT(a, b) \
    do { \
        int _swap_tmp = (a); \
        (a) = (b); \
        (b) = _swap_tmp; \
    } while(0)

/* Versi generic pakai XOR trick (hanya untuk integer!) */
#define SWAP(a, b) \
    do { \
        (a) ^= (b); \
        (b) ^= (a); \
        (a) ^= (b); \
    } while(0)

/* ============================================================
 * LEVEL 3: DEBUG LOGGING SYSTEM
 * ============================================================ */

/* Log levels */
#define LOG_LEVEL_NONE  0
#define LOG_LEVEL_ERROR 1
#define LOG_LEVEL_INFO  2
#define LOG_LEVEL_DEBUG 3

/* Default log level — bisa di-override dari command line (-DLOG_LEVEL=3) */
#ifndef LOG_LEVEL
#define LOG_LEVEL LOG_LEVEL_ERROR
#endif

/* Log macros — hanya aktif kalau level cukup tinggi */
#if LOG_LEVEL >= LOG_LEVEL_ERROR
#define LOG_ERROR(msg) \
    printf("[ERROR] %s:%d %s(): %s\n", __FILE__, __LINE__, __func__, msg)
#else
#define LOG_ERROR(msg) do {} while(0)
#endif

#if LOG_LEVEL >= LOG_LEVEL_INFO
#define LOG_INFO(msg) \
    printf("[INFO]  %s:%d %s(): %s\n", __FILE__, __LINE__, __func__, msg)
#else
#define LOG_INFO(msg) do {} while(0)
#endif

#if LOG_LEVEL >= LOG_LEVEL_DEBUG
#define LOG_DEBUG(msg) \
    printf("[DEBUG] %s:%d %s(): %s\n", __FILE__, __LINE__, __func__, msg)
#else
#define LOG_DEBUG(msg) do {} while(0)
#endif

/* LOG_ASSERT — print error kalau condition false */
#define LOG_ASSERT(condition, msg) \
    do { \
        if (!(condition)) { \
            printf("[ASSERT FAIL] %s:%d %s(): %s (condition: %s)\n", \
                   __FILE__, __LINE__, __func__, msg, #condition); \
        } \
    } while(0)

/* Demo function yang pakai logging */
int safe_divide(int a, int b) {
    LOG_DEBUG("safe_divide() called");

    if (b == 0) {
        LOG_ERROR("Division by zero!");
        return 0;
    }

    LOG_INFO("Division OK");
    return a / b;
}

int main(void) {

    /* ============================================
     * LEVEL 1: EASY — Macro Collection
     * ============================================ */
    printf("=== LEVEL 1: Macro Collection ===\n\n");

    printf("  MAX(10, 20)      = %d\n", MAX(10, 20));
    printf("  MAX(-5, -10)     = %d\n", MAX(-5, -10));
    printf("  MIN(10, 20)      = %d\n", MIN(10, 20));
    printf("  ABS(-42)         = %d\n", ABS(-42));
    printf("  ABS(42)          = %d\n", ABS(42));

    /* SWAP */
    int a = 100, b = 200;
    printf("\n  Sebelum SWAP: a=%d, b=%d\n", a, b);
    SWAP(a, b);
    printf("  Sesudah SWAP: a=%d, b=%d\n", a, b);

    /* ARRAY_SIZE */
    int arr[] = {10, 20, 30, 40, 50, 60};
    printf("\n  ARRAY_SIZE(arr) = %zu\n", ARRAY_SIZE(arr));

    /* CLAMP */
    printf("\n  CLAMP(15, 0, 10) = %d (capped at 10)\n", CLAMP(15, 0, 10));
    printf("  CLAMP(-5, 0, 10) = %d (raised to 0)\n", CLAMP(-5, 0, 10));
    printf("  CLAMP(5, 0, 10)  = %d (unchanged)\n", CLAMP(5, 0, 10));

    /* IN_RANGE */
    printf("\n  IN_RANGE(5, 0, 10)  = %d (true)\n", IN_RANGE(5, 0, 10));
    printf("  IN_RANGE(15, 0, 10) = %d (false)\n", IN_RANGE(15, 0, 10));
    printf("  IN_RANGE(0, 0, 10)  = %d (true, inclusive)\n", IN_RANGE(0, 0, 10));

    /* ============================================
     * LEVEL 2: MEDIUM — Multi-file Project
     * ============================================ */
    printf("\n=== LEVEL 2: Multi-file Project ===\n\n");
    printf("  Level 2 membutuhkan file terpisah.\n");
    printf("  Buat file: arrayutils.h, arrayutils.c, dan Makefile\n");
    printf("  Lihat README.md bagian 'Split .h / .c' untuk panduan.\n");
    printf("  Contoh sudah tersedia di: mathlib.h/.c dan strutils.h/.c\n");

    /* ============================================
     * LEVEL 3: HARD — Debug Logging System
     * ============================================ */
    printf("\n=== LEVEL 3: Debug Logging System ===\n\n");

    printf("  Current LOG_LEVEL = %d", LOG_LEVEL);
    if (LOG_LEVEL == LOG_LEVEL_NONE) printf(" (NONE)\n");
    else if (LOG_LEVEL == LOG_LEVEL_ERROR) printf(" (ERROR)\n");
    else if (LOG_LEVEL == LOG_LEVEL_INFO) printf(" (INFO)\n");
    else if (LOG_LEVEL == LOG_LEVEL_DEBUG) printf(" (DEBUG)\n");

    printf("  Compile with -DLOG_LEVEL=3 to see all logs\n\n");

    /* Demo logging */
    LOG_DEBUG("Program starting");
    LOG_INFO("Initializing...");

    int result = safe_divide(10, 3);
    printf("  10 / 3 = %d\n", result);

    result = safe_divide(10, 0);
    printf("  10 / 0 = %d (error handled)\n", result);

    /* LOG_ASSERT demo */
    int x = 5;
    LOG_ASSERT(x > 0, "x should be positive");
    LOG_ASSERT(x > 100, "x should be > 100");    /* This will fire */

    LOG_INFO("Program finished");

    return 0;
}
