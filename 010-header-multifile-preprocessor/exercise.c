/*
 * ============================================================
 *  010 — Header, Multi-file, Preprocessor: Latihan
 * ============================================================
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o exercise exercise.c
 *    ./exercise
 *
 *  Untuk Level 3 (debug logging), coba:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -DDEBUG -o exercise exercise.c
 * ============================================================
 */

#include <stdio.h>
#include <string.h>

int main(void) {

    /* ============================================
     * LEVEL 1: EASY — Macro Collection
     * ============================================
     * Tugas:
     * 1. Buat macro berikut (di atas main):
     *
     *    #define MAX(a, b)         → return yang lebih besar
     *    #define MIN(a, b)         → return yang lebih kecil
     *    #define ABS(x)            → return nilai absolut
     *    #define SWAP(a, b)        → tukar nilai a dan b
     *    #define ARRAY_SIZE(arr)   → return jumlah elemen array
     *    #define CLAMP(x, lo, hi)  → batasi x di range [lo, hi]
     *    #define IN_RANGE(x, lo, hi) → cek apakah lo <= x <= hi
     *
     * 2. JANGAN LUPA kurung di setiap parameter!
     *
     * 3. Test semua macro:
     *    MAX(10, 20) → 20
     *    MIN(10, 20) → 10
     *    ABS(-42) → 42
     *    SWAP(a, b) → tukar a dan b
     *    ARRAY_SIZE(arr) → jumlah elemen
     *    CLAMP(15, 0, 10) → 10 (dibatasi max 10)
     *    CLAMP(-5, 0, 10) → 0 (dibatasi min 0)
     *    IN_RANGE(5, 0, 10) → 1 (true)
     *    IN_RANGE(15, 0, 10) → 0 (false)
     */

    // TODO: Define macro di atas main, test di sini


    /* ============================================
     * LEVEL 2: MEDIUM — Multi-file Project
     * ============================================
     * Tugas:
     * Buat mini project multi-file:
     *
     * 1. File: arrayutils.h
     *    - Include guards
     *    - Prototype:
     *      void arr_print(const int arr[], int n);
     *      void arr_bubble_sort(int arr[], int n);
     *      int arr_binary_search(const int arr[], int n, int target);
     *      int arr_sum(const int arr[], int n);
     *      void arr_reverse(int arr[], int n);
     *
     * 2. File: arrayutils.c
     *    - #include "arrayutils.h"
     *    - Implementasi semua fungsi
     *
     * 3. File: exercise_multifile.c (rename dari main ini)
     *    - #include "arrayutils.h"
     *    - Test semua fungsi
     *
     * 4. File: Makefile
     *    - Target: exercise_multifile
     *    - Dependencies: exercise_multifile.o arrayutils.o
     *    - Target clean
     *
     * Compile:
     *    make -f Makefile_exercise
     *    atau
     *    gcc -std=c17 -Wall -Wextra -o test exercise_multifile.c arrayutils.c
     */

    // TODO: Buat file-file terpisah


    /* ============================================
     * LEVEL 3: HARD — Debug Logging System
     * ============================================
     * Tugas:
     * Buat system logging dengan macro & conditional compilation:
     *
     * 1. Define log level macro:
     *    #define LOG_LEVEL_NONE  0
     *    #define LOG_LEVEL_ERROR 1
     *    #define LOG_LEVEL_INFO  2
     *    #define LOG_LEVEL_DEBUG 3
     *
     * 2. Set default log level:
     *    #ifndef LOG_LEVEL
     *    #define LOG_LEVEL LOG_LEVEL_ERROR
     *    #endif
     *
     * 3. Buat macro:
     *    LOG_ERROR(msg) → "[ERROR] file:line func(): msg"
     *    LOG_INFO(msg)  → "[INFO]  file:line func(): msg"
     *    LOG_DEBUG(msg) → "[DEBUG] file:line func(): msg"
     *
     *    Masing-masing hanya print kalau LOG_LEVEL cukup tinggi
     *
     * 4. Buat macro LOG_ASSERT(condition, msg):
     *    Kalau condition false, print error dan return
     *
     * 5. Test dengan berbagai compile flag:
     *    gcc ... -DLOG_LEVEL=0 ...   → tidak ada log
     *    gcc ... -DLOG_LEVEL=1 ...   → hanya ERROR
     *    gcc ... -DLOG_LEVEL=2 ...   → ERROR + INFO
     *    gcc ... -DLOG_LEVEL=3 ...   → semua log
     *
     * Tips:
     *    - Macro yang "do nothing" bisa pakai: do {} while(0)
     *    - Pakai __FILE__, __LINE__, __func__ untuk info lokasi
     */

    // TODO: Define logging macros di atas main, test di sini


    return 0;
}
