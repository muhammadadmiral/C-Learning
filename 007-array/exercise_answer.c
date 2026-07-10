/*
 * ============================================================
 *  007 — Array: Jawaban Latihan
 * ============================================================
 *  SPOILER ALERT! Kerjakan exercise.c dulu.
 *
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o answer exercise_answer.c
 *    ./answer
 * ============================================================
 */

#include <stdio.h>

/* Function prototypes */
void print_array(int arr[], int n);
void selection_sort(int arr[], int n);
int binary_search(int arr[], int n, int target);
void reverse(int arr[], int start, int end);
void rotate_left(int arr[], int n, int k);

int main(void) {

    /* ============================================
     * LEVEL 1: EASY — Min, Max, Rata-rata
     * ============================================ */
    printf("=== LEVEL 1: Min, Max, Rata-rata ===\n\n");

    int count;
    printf("  Jumlah elemen (max 100): ");
    scanf("%d", &count);

    if (count < 1 || count > 100) {
        printf("  Harus 1-100!\n");
        return 1;
    }

    int data[100];
    for (int i = 0; i < count; i++) {
        printf("  Elemen ke-%d: ", i + 1);
        scanf("%d", &data[i]);
    }

    /* Cari min, max, total */
    int min = data[0];
    int max = data[0];
    int min_idx = 0;
    int max_idx = 0;
    long total = 0;   /* long untuk menghindari overflow */

    for (int i = 0; i < count; i++) {
        total += data[i];
        if (data[i] < min) {
            min = data[i];
            min_idx = i;
        }
        if (data[i] > max) {
            max = data[i];
            max_idx = i;
        }
    }

    printf("\n  Data    : ");
    print_array(data, count);
    printf("  Min     : %d (index %d)\n", min, min_idx);
    printf("  Max     : %d (index %d)\n", max, max_idx);
    printf("  Rata²   : %.2f\n", (double)total / count);

    /* ============================================
     * LEVEL 2: MEDIUM — Selection Sort + Binary Search
     * ============================================ */
    printf("\n=== LEVEL 2: Selection Sort + Binary Search ===\n\n");

    int arr[] = {64, 25, 12, 22, 11, 90, 34};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("  Array awal   : ");
    print_array(arr, n);

    selection_sort(arr, n);

    printf("  Array sorted : ");
    print_array(arr, n);

    printf("\n  Cari angka: ");
    int target;
    scanf("%d", &target);

    int idx = binary_search(arr, n, target);
    if (idx != -1) {
        printf("  %d ditemukan di index %d\n", target, idx);
    } else {
        printf("  %d TIDAK ditemukan\n", target);
    }

    /* ============================================
     * LEVEL 3: HARD — Rotasi Array In-Place
     * ============================================ */
    printf("\n=== LEVEL 3: Rotasi Array In-Place ===\n\n");

    int rot[] = {1, 2, 3, 4, 5, 6, 7};
    int rot_size = sizeof(rot) / sizeof(rot[0]);
    int k = 3;

    printf("  Array awal : ");
    print_array(rot, rot_size);
    printf("  k = %d\n", k);

    rotate_left(rot, rot_size, k);

    printf("  Setelah rotasi kiri %d : ", k);
    print_array(rot, rot_size);

    /* Demo rotasi kanan (rotasi kiri sebanyak n-k) */
    int rot2[] = {1, 2, 3, 4, 5, 6, 7};
    int k_right = 2;

    printf("\n  Array awal : ");
    print_array(rot2, rot_size);
    printf("  Rotasi kanan k = %d\n", k_right);

    /* Rotasi kanan k = rotasi kiri (n - k) */
    rotate_left(rot2, rot_size, rot_size - k_right);

    printf("  Hasil      : ");
    print_array(rot2, rot_size);

    /* Edge case: k = 0 */
    int rot3[] = {10, 20, 30};
    printf("\n  Edge case k=0: ");
    rotate_left(rot3, 3, 0);
    print_array(rot3, 3);

    /* Edge case: k = n (kembali ke awal) */
    int rot4[] = {10, 20, 30};
    printf("  Edge case k=n: ");
    rotate_left(rot4, 3, 3);
    print_array(rot4, 3);

    /* Edge case: k > n */
    int rot5[] = {10, 20, 30};
    printf("  Edge case k=7 (n=3, efektif k=1): ");
    rotate_left(rot5, 3, 7);
    print_array(rot5, 3);

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

/*
 * Selection Sort — cari minimum, taruh di depan
 *
 * Untuk setiap posisi i:
 *   1. Cari elemen terkecil dari i sampai n-1
 *   2. Swap elemen terkecil dengan elemen di posisi i
 *
 * Kompleksitas: O(n²) — sama seperti bubble sort
 * Tapi jumlah swap-nya lebih sedikit (max n-1 swap)
 */
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        /* Cari index elemen terkecil dari i+1 sampai n-1 */
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        /* Swap jika min bukan di posisi i */
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }

        printf("  Pass %d      : ", i + 1);
        print_array(arr, n);
    }
}

/*
 * Binary Search — O(log n)
 * SYARAT: array harus sudah sorted ascending!
 */
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

/*
 * Reverse — balik urutan elemen dari index start sampai end
 * In-place: swap dari kedua ujung menuju tengah
 */
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

/*
 * Rotate Left — rotasi array ke kiri sebanyak k posisi
 *
 * Algoritma Reversal (juggling/reversal algorithm):
 *   1. Reverse bagian pertama [0..k-1]
 *   2. Reverse bagian kedua [k..n-1]
 *   3. Reverse seluruh array [0..n-1]
 *
 * Contoh: [1,2,3,4,5,6,7], k=3
 *   Step 1: reverse [1,2,3]       → [3,2,1,4,5,6,7]
 *   Step 2: reverse [4,5,6,7]     → [3,2,1,7,6,5,4]
 *   Step 3: reverse seluruh       → [4,5,6,7,1,2,3] ✅
 *
 * Kompleksitas: O(n) time, O(1) space — sangat efisien!
 */
void rotate_left(int arr[], int n, int k) {
    if (n <= 1) return;

    k = k % n;            /* Handle k >= n */
    if (k == 0) return;    /* Tidak perlu rotasi */

    reverse(arr, 0, k - 1);      /* Reverse bagian kiri */
    reverse(arr, k, n - 1);      /* Reverse bagian kanan */
    reverse(arr, 0, n - 1);      /* Reverse seluruh array */
}
