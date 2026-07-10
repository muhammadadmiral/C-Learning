# 007 — Array

**Fase:** 2 · Kontrol & Struktur Data Dasar | **Prasyarat:** [006 — Perulangan](../006-perulangan/) | **Estimasi waktu:** 4-5 jam

---

## 🎯 Tujuan Belajar

- Bisa mendeklarasikan, menginisialisasi, dan mengakses elemen **array 1D**
- Bisa bekerja dengan **array 2D** (matrix) dan memahami pola nested loop-nya
- Mengerti apa itu **VLA (Variable Length Array)** dan kapan boleh/tidak boleh dipakai
- Bisa mengimplementasikan **Bubble Sort** dan menjelaskan kenapa O(n²)
- Bisa mengimplementasikan **Linear Search** dan **Binary Search** (beserta syaratnya)
- Mengenali **common pitfalls** array di C: out-of-bounds, sizeof trap, decay to pointer

---

## 📖 Konsep Inti

### 1. Array 1D — Kumpulan Data Satu Tipe

> **Analogi:** Array itu kayak **loker di sekolah** — deretan kotak berurutan, tiap kotak punya nomor (index), dan isinya harus sejenis (semua int, semua char, dll).

```c
// Deklarasi: tipe nama[UKURAN];
int nilai[5];           // 5 elemen int, isi belum tentu 0!

// Deklarasi + inisialisasi
int skor[5] = {90, 85, 78, 92, 88};

// Partial init — sisanya otomatis 0
int data[5] = {10, 20};    // → {10, 20, 0, 0, 0}

// Init semua 0
int kosong[100] = {0};     // Semua elemen = 0

// Ukuran otomatis dari initializer
int angka[] = {1, 2, 3, 4};   // Compiler tahu: ukuran = 4
```

**Akses elemen — index mulai dari 0:**

```c
int skor[5] = {90, 85, 78, 92, 88};
//  index:      0   1   2   3   4

printf("%d\n", skor[0]);    // 90 (elemen pertama)
printf("%d\n", skor[4]);    // 88 (elemen terakhir)
printf("%d\n", skor[5]);    // ❌ OUT OF BOUNDS! Undefined behavior!

skor[2] = 100;              // Ubah elemen ke-3 jadi 100
```

**Iterasi array — pattern paling dasar:**

```c
int arr[5] = {10, 20, 30, 40, 50};
int size = 5;

// Traverse: cetak semua elemen
for (int i = 0; i < size; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
}
```

**`sizeof` pada array:**

```c
int arr[5] = {1, 2, 3, 4, 5};

printf("Total bytes  : %zu\n", sizeof(arr));        // 20 (5 × 4 bytes)
printf("Per elemen   : %zu\n", sizeof(arr[0]));     // 4 bytes (int)
printf("Jumlah elemen: %zu\n", sizeof(arr) / sizeof(arr[0]));  // 5
```

> **⚠️ PENTING:** `sizeof(arr) / sizeof(arr[0])` hanya benar kalau `arr` masih berupa **array asli** (belum di-pass ke function). Begitu masuk function, array "decay" jadi pointer — sizeof-nya berubah! Ini dibahas di bagian Perangkap Umum.

### 2. Array 2D — Matrix / Tabel

> **Analogi:** Array 2D itu kayak **spreadsheet** — ada baris dan kolom. `matrix[baris][kolom]`.

```c
// Deklarasi: tipe nama[BARIS][KOLOM];
int matrix[3][4];   // 3 baris, 4 kolom

// Deklarasi + inisialisasi
int tabel[2][3] = {
    {1, 2, 3},      // Baris 0
    {4, 5, 6}       // Baris 1
};

// Akses
printf("%d\n", tabel[0][2]);   // 3 (baris 0, kolom 2)
printf("%d\n", tabel[1][0]);   // 4 (baris 1, kolom 0)
```

**Iterasi 2D — nested loop:**

```c
int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

for (int i = 0; i < 3; i++) {           // Baris
    for (int j = 0; j < 3; j++) {       // Kolom
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
}
```

**Layout di memori — array 2D itu sebenarnya 1D "flat":**

```
Logis:     [1][2][3]
           [4][5][6]

Di memori: [1][2][3][4][5][6]   ← row-major order
```

Ini penting untuk performa (cache-friendly) dan nanti saat belajar pointer arithmetic.

### 3. Multidimensional Array (3D+)

```c
// 3D: bayangkan "beberapa layer matrix 2D"
int cube[2][3][3] = {
    {   // Layer 0
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    },
    {   // Layer 1
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    }
};

printf("%d\n", cube[1][2][0]);  // 16 (layer 1, baris 2, kolom 0)
```

> **Praktisnya:** 3D array jarang dipakai langsung. Biasanya pakai array of pointer (dibahas di modul pointer). Untuk sekarang, fokus di 1D dan 2D.

### 4. VLA (Variable Length Array)

VLA = array yang ukurannya ditentukan saat **runtime** (dari variabel), bukan compile time.

```c
int n;
printf("Berapa elemen? ");
scanf("%d", &n);

int arr[n];   // VLA — ukuran ditentukan saat runtime

for (int i = 0; i < n; i++) {
    arr[i] = i * 10;
}
```

**Pro & Kontra VLA:**

| Pro | Kontra |
|-----|--------|
| Simpel, tidak perlu `malloc` | Dialokasi di **stack** — bisa stack overflow kalau `n` besar |
| Standar C99 & C11 | Di C11 jadi **opsional** (compiler boleh tidak support) |
| Otomatis di-free saat keluar scope | Tidak bisa dipakai di file scope (global) |
| | MSVC (Windows) **tidak support** VLA |

> **Rekomendasi:** Pakai VLA untuk ukuran kecil yang pasti (misal `n < 1000`). Untuk ukuran besar atau tidak pasti, nanti pakai `malloc` (modul 017).

### 5. Sorting: Bubble Sort

> **Analogi:** Bayangkan **gelembung udara di air** — elemen terbesar "naik" ke atas (akhir array) satu per satu setiap iterasi.

**Algoritma:**
1. Bandingkan elemen bersebelahan dari awal
2. Kalau urutan salah → tukar (swap)
3. Ulangi untuk seluruh array
4. Setiap iterasi, elemen terbesar "terbubble" ke posisi akhir
5. Ulangi sampai tidak ada swap lagi

```c
/* Bubble Sort — Ascending */
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;   // Optimasi: early exit

        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped) break;   // Sudah sorted → keluar
    }
}
```

**Visualisasi pass pertama:**

```
[5, 3, 8, 1, 2]
 ^  ^
 5>3 → swap → [3, 5, 8, 1, 2]
    ^  ^
    5<8 → OK  → [3, 5, 8, 1, 2]
       ^  ^
       8>1 → swap → [3, 5, 1, 8, 2]
          ^  ^
          8>2 → swap → [3, 5, 1, 2, 8]  ← 8 sudah di posisi akhir!
```

**Kompleksitas:**
- **Best case:** O(n) — array sudah sorted (dengan optimasi `swapped`)
- **Worst case:** O(n²) — array terbalik
- **Average:** O(n²)

> Bubble sort **tidak efisien** untuk data besar, tapi bagus untuk belajar konsep sorting. Nanti di mata kuliah Algoritma, lu akan belajar sorting yang lebih cepat (merge sort, quick sort → O(n log n)).

### 6. Searching: Linear Search & Binary Search

#### Linear Search — Cari Satu per Satu

```c
/* Return index kalau ketemu, -1 kalau tidak */
int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;   // Ketemu di index i
        }
    }
    return -1;          // Tidak ketemu
}
```

- **Kompleksitas:** O(n) — worst case harus cek semua elemen
- **Syarat:** Tidak ada — array boleh tidak sorted

#### Binary Search — Bagi Dua (Divide & Conquer)

> **Analogi:** Kayak cari kata di **kamus** — lu buka halaman tengah, kalau kata yang dicari ada sebelumnya → cari di bagian kiri, kalau sesudahnya → cari di bagian kanan.

```c
/* SYARAT: array HARUS sudah sorted ascending! */
int binary_search(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;   // Hindari overflow

        if (arr[mid] == target) {
            return mid;          // Ketemu!
        } else if (arr[mid] < target) {
            low = mid + 1;       // Target di kanan
        } else {
            high = mid - 1;      // Target di kiri
        }
    }

    return -1;   // Tidak ketemu
}
```

**Visualisasi:**

```
Array sorted: [2, 5, 8, 12, 16, 23, 38, 45, 56, 72]
Target: 23

Iterasi 1: low=0, high=9, mid=4 → arr[4]=16 < 23 → low=5
Iterasi 2: low=5, high=9, mid=7 → arr[7]=45 > 23 → high=6
Iterasi 3: low=5, high=6, mid=5 → arr[5]=23 == 23 → KETEMU! index 5
```

- **Kompleksitas:** O(log n) — jauh lebih cepat dari linear search
- **Syarat:** Array **HARUS sorted!**

**Perbandingan:**

| | Linear Search | Binary Search |
|---|---|---|
| Kompleksitas | O(n) | O(log n) |
| Syarat | Tidak ada | Array harus sorted |
| 1.000.000 elemen | Max 1.000.000 cek | Max ~20 cek! |

> **Kenapa `mid = low + (high - low) / 2` bukan `(low + high) / 2`?**
> Karena `low + high` bisa **integer overflow** kalau keduanya besar. Rumus `low + (high - low) / 2` aman secara matematis identik tapi tidak overflow.

---

## ⚠️ Perangkap Umum (Common Pitfalls)

### 1. Out-of-Bounds Access

```c
int arr[5] = {1, 2, 3, 4, 5};

/* ❌ Index 5 tidak ada! Valid index: 0-4 */
printf("%d\n", arr[5]);     // Undefined behavior!
arr[-1] = 10;               // Undefined behavior!

/* C TIDAK cek bounds! Tidak ada error, tapi hasilnya unpredictable */
```

### 2. sizeof Trap — Array Decay to Pointer

```c
void print_size(int arr[]) {
    // arr di sini BUKAN array — sudah "decay" jadi pointer!
    printf("Dalam function: %zu\n", sizeof(arr));   // 8 (pointer size)
}

int main(void) {
    int arr[5] = {1, 2, 3, 4, 5};
    printf("Di main: %zu\n", sizeof(arr));          // 20 (5 × 4)
    print_size(arr);                                 // 8! Bukan 20!
    return 0;
}
```

> **Solusi:** Selalu pass **ukuran array** sebagai parameter terpisah:

```c
void proses(int arr[], int n) {   // n = jumlah elemen
    for (int i = 0; i < n; i++) { ... }
}
```

### 3. Array Tidak Bisa Di-assign Langsung

```c
int a[3] = {1, 2, 3};
int b[3];

b = a;   // ❌ COMPILE ERROR! Array bukan assignable

// ✅ Copy manual per elemen
for (int i = 0; i < 3; i++) {
    b[i] = a[i];
}

// ✅ Atau pakai memcpy (dari string.h)
#include <string.h>
memcpy(b, a, sizeof(a));
```

### 4. Uninitialized Array

```c
int arr[5];   // TANPA inisialisasi

// arr berisi GARBAGE values — bukan 0!
for (int i = 0; i < 5; i++) {
    printf("%d ", arr[i]);   // Output: random junk
}

// ✅ Selalu inisialisasi
int arr2[5] = {0};   // Semua 0
```

---

## 💻 Cara Menjalankan

```bash
# macOS / Linux
gcc -std=c17 -Wall -Wextra -Wpedantic -o program main.c
./program

# Windows (MinGW / MSYS2)
gcc -std=c17 -Wall -Wextra -Wpedantic -o program.exe main.c
.\program.exe
```

---

## 📝 Latihan

| Level | Deskripsi |
|-------|-----------|
| 🟢 EASY | Cari **min, max, dan rata-rata** dari array integer yang di-input user |
| 🟡 MEDIUM | Implementasi **Selection Sort** (cari terkecil, taruh di depan) + **Binary Search** pada hasil sort |
| 🔴 HARD | **Rotasi array** ke kiri sebanyak k posisi secara **in-place** (tanpa array tambahan) — pakai algoritma reversal |

---

## 🔗 Lanjut ke

**[008 — String →](../008-string/)**
