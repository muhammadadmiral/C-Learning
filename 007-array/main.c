/*
 * ============================================================
 *  007 — Array: Contoh Kode Utama
 * ============================================================
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o program main.c
 *    ./program
 * ============================================================
 */

#include <stdio.h>

/* -------------------------------------------------------
 * Function prototypes (preview — detail di modul 009)
 * ------------------------------------------------------- */
void bubble_sort(int arr[], int n);
int linear_search(int arr[], int n, int target);
int binary_search(int arr[], int n, int target);
void print_array(int arr[], int n);

int main(void) {

    printf("╔══════════════════════════════════════════╗\n");
    printf("║  007 — Array                             ║\n");
    printf("╚══════════════════════════════════════════╝\n\n");

    /* -------------------------------------------------------
     * 1. ARRAY 1D — deklarasi & inisialisasi
     * ------------------------------------------------------- */
    printf("--- 1. Array 1D Basics ---\n\n");

    /* Berbagai cara inisialisasi */
    int skor[5] = {90, 85, 78, 92, 88};
    int partial[5] = {10, 20};              /* sisanya 0 */
    int zeros[5] = {0};                     /* semua 0 */
    int auto_size[] = {1, 2, 3, 4};         /* ukuran = 4 */

    printf("  skor    : ");
    print_array(skor, 5);

    printf("  partial : ");
    print_array(partial, 5);

    printf("  zeros   : ");
    print_array(zeros, 5);

    printf("  auto    : ");
    print_array(auto_size, 4);

    /* sizeof trick */
    printf("\n  sizeof(skor)          = %zu bytes\n", sizeof(skor));
    printf("  sizeof(skor[0])       = %zu bytes\n", sizeof(skor[0]));
    printf("  Jumlah elemen         = %zu\n",
           sizeof(skor) / sizeof(skor[0]));

    /* Modifikasi elemen */
    skor[2] = 100;
    printf("\n  Setelah skor[2] = 100 : ");
    print_array(skor, 5);

    /* -------------------------------------------------------
     * 2. ITERASI & OPERASI DASAR
     * ------------------------------------------------------- */
    printf("\n--- 2. Iterasi & Operasi Dasar ---\n\n");

    int data[] = {42, 17, 85, 3, 56, 91, 28, 64, 10, 73};
    int n = sizeof(data) / sizeof(data[0]);

    /* Cari total, min, max */
    int total = 0;
    int min = data[0];
    int max = data[0];

    for (int i = 0; i < n; i++) {
        total += data[i];
        if (data[i] < min) min = data[i];
        if (data[i] > max) max = data[i];
    }

    printf("  Data    : ");
    print_array(data, n);
    printf("  Total   : %d\n", total);
    printf("  Rata²   : %.2f\n", (double)total / n);
    printf("  Min     : %d\n", min);
    printf("  Max     : %d\n", max);

    /* -------------------------------------------------------
     * 3. ARRAY 2D — matrix
     * ------------------------------------------------------- */
    printf("\n--- 3. Array 2D (Matrix) ---\n\n");

    int matrix[3][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };

    printf("  Matrix 3x4:\n");
    for (int i = 0; i < 3; i++) {
        printf("    ");
        for (int j = 0; j < 4; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    /* Transpose (simpan ke matrix baru) */
    int transpose[4][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("\n  Transpose 4x3:\n");
    for (int i = 0; i < 4; i++) {
        printf("    ");
        for (int j = 0; j < 3; j++) {
            printf("%4d", transpose[i][j]);
        }
        printf("\n");
    }

    /* -------------------------------------------------------
     * 4. VLA (Variable Length Array)
     * ------------------------------------------------------- */
    printf("\n--- 4. VLA (Variable Length Array) ---\n\n");

    int vla_size = 7;   /* Dalam real code, ini bisa dari scanf */
    int vla[vla_size];

    for (int i = 0; i < vla_size; i++) {
        vla[i] = (i + 1) * (i + 1);   /* Kuadrat */
    }

    printf("  VLA (size=%d): ", vla_size);
    print_array(vla, vla_size);

    /* -------------------------------------------------------
     * 5. BUBBLE SORT
     * ------------------------------------------------------- */
    printf("\n--- 5. Bubble Sort ---\n\n");

    int unsorted[] = {64, 34, 25, 12, 22, 11, 90};
    int un_size = sizeof(unsorted) / sizeof(unsorted[0]);

    printf("  Sebelum : ");
    print_array(unsorted, un_size);

    bubble_sort(unsorted, un_size);

    printf("  Sesudah : ");
    print_array(unsorted, un_size);

    /* -------------------------------------------------------
     * 6. LINEAR SEARCH
     * ------------------------------------------------------- */
    printf("\n--- 6. Linear Search ---\n\n");

    int haystack[] = {42, 17, 85, 3, 56, 91, 28};
    int hay_size = sizeof(haystack) / sizeof(haystack[0]);

    printf("  Array: ");
    print_array(haystack, hay_size);

    int target1 = 56;
    int target2 = 99;

    int idx1 = linear_search(haystack, hay_size, target1);
    int idx2 = linear_search(haystack, hay_size, target2);

    printf("  Cari %d → %s",
           target1, idx1 != -1 ? "" : "TIDAK KETEMU\n");
    if (idx1 != -1) printf("ketemu di index %d\n", idx1);

    printf("  Cari %d → %s",
           target2, idx2 != -1 ? "" : "TIDAK KETEMU\n");
    if (idx2 != -1) printf("ketemu di index %d\n", idx2);

    /* -------------------------------------------------------
     * 7. BINARY SEARCH (harus sorted dulu!)
     * ------------------------------------------------------- */
    printf("\n--- 7. Binary Search ---\n\n");

    int sorted[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};
    int s_size = sizeof(sorted) / sizeof(sorted[0]);

    printf("  Array (sorted): ");
    print_array(sorted, s_size);

    int targets[] = {23, 72, 2, 50};
    int t_count = sizeof(targets) / sizeof(targets[0]);

    for (int i = 0; i < t_count; i++) {
        int idx = binary_search(sorted, s_size, targets[i]);
        if (idx != -1) {
            printf("  Cari %2d → ketemu di index %d\n", targets[i], idx);
        } else {
            printf("  Cari %2d → TIDAK KETEMU\n", targets[i]);
        }
    }

    /* -------------------------------------------------------
     * 8. SIZEOF TRAP DEMO
     * ------------------------------------------------------- */
    printf("\n--- 8. sizeof Trap ---\n\n");

    int demo[10] = {0};
    printf("  Di main():\n");
    printf("    sizeof(demo)    = %zu bytes\n", sizeof(demo));
    printf("    Jumlah elemen   = %zu\n", sizeof(demo) / sizeof(demo[0]));

    /* Kalau di-pass ke function, sizeof jadi pointer size (8 bytes) */
    /* Ini didemonstrasikan secara konsep — nanti detail di modul pointer */
    printf("\n  ⚠️  Begitu array di-pass ke function, sizeof = %zu (pointer size)\n",
           sizeof(int *));
    printf("  → Selalu pass ukuran array sebagai parameter terpisah!\n");

    printf("\n========================================\n");
    printf("Selesai! Lanjut ke modul 008 (String).\n");

    return 0;
}

/* -------------------------------------------------------
 * IMPLEMENTASI FUNCTION
 * ------------------------------------------------------- */

void print_array(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;

        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped) break;
    }
}

int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binary_search(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}
