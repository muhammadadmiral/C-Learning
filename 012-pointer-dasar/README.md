# 012 — Pointer Dasar & Const Correctness

**Fase:** 4 · Pointer & Level Memori | **Prasyarat:** [011 — Rekursi](../011-rekursi/) | **Estimasi waktu:** 5-6 jam

---

## 🎯 Tujuan Belajar

- Memahami apa itu **pointer** dan kenapa ia fundamental di C
- Bisa menggunakan operator **address-of `&`** dan **dereference `*`**
- Mengerti apa itu **NULL pointer** dan kapan menggunakannya
- Memahami **void pointer** (`void *`) dan kapan dibutuhkan
- Menguasai **`const` dengan pointer** — perbedaan `const int *`, `int * const`, dan `const int * const`
- Mengenali dan menghindari **dangling pointer** dan **wild pointer**
- Bisa menggunakan pointer untuk **pass by reference** di function

---

## 📖 Konsep Inti

### 1. Apa Itu Pointer?

> **Analogi:** Kalau variabel biasa itu kayak **rumah** (menyimpan isinya langsung), maka pointer itu kayak **kartu alamat** — dia tidak menyimpan barang, tapi menyimpan **alamat rumah** di mana barang disimpan.

```c
int angka = 42;        // Variabel biasa — menyimpan nilai 42
int *ptr = &angka;     // Pointer — menyimpan ALAMAT dari angka

// Visualisasi memori:
//
// Alamat    Nama       Nilai
// 0x1000    angka      42
// 0x2000    ptr        0x1000  ← menyimpan alamat angka
```

**Dua operator kunci:**

| Operator | Nama | Artinya |
|----------|------|---------|
| `&` | Address-of | Ambil alamat variabel |
| `*` | Dereference | Akses nilai di alamat yang ditunjuk |

```c
int x = 10;
int *p = &x;        // p menyimpan alamat x

printf("%d\n", x);   // 10 (nilai x)
printf("%p\n", (void *)&x);  // 0x7fff... (alamat x)
printf("%p\n", (void *)p);   // 0x7fff... (sama — p menyimpan alamat x)
printf("%d\n", *p);  // 10 (dereference — "buka" alamat, ambil nilainya)

*p = 99;             // Ubah nilai di alamat yang ditunjuk p
printf("%d\n", x);   // 99 — x berubah lewat pointer!
```

### 2. Deklarasi Pointer

```c
int *p1;         // p1 adalah pointer ke int
double *p2;      // p2 adalah pointer ke double
char *p3;        // p3 adalah pointer ke char

// HATI-HATI! * menempel ke variabel, bukan tipe:
int *a, b;       // a = pointer ke int, b = int BIASA!
int *a, *b;      // Keduanya pointer ke int ✅

// Tipe pointer HARUS cocok dengan tipe data yang ditunjuk
int x = 42;
int *pi = &x;       // ✅ pointer int menunjuk ke int
// double *pd = &x;  // ❌ WARNING: type mismatch
```

### 3. Pass by Reference dengan Pointer

Ini alasan utama pointer penting — bisa memodifikasi variabel dari function lain.

```c
/* ❌ Pass by value — tidak bisa ubah variabel asli */
void swap_fail(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    // a dan b lokal → tidak ada efek ke luar
}

/* ✅ Pass by reference via pointer */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    // Mengubah nilai di ALAMAT asli
}

int main(void) {
    int x = 10, y = 20;

    swap_fail(x, y);
    printf("x=%d, y=%d\n", x, y);   // x=10, y=20 (GAGAL!)

    swap(&x, &y);
    printf("x=%d, y=%d\n", x, y);   // x=20, y=10 (BERHASIL!)

    return 0;
}
```

**Use-case penting lainnya:**

```c
/* Function yang "return" lebih dari satu nilai */
void divide(int a, int b, int *quotient, int *remainder) {
    *quotient = a / b;
    *remainder = a % b;
}

int q, r;
divide(17, 5, &q, &r);
printf("17 / 5 = %d sisa %d\n", q, r);   // 3 sisa 2
```

### 4. NULL Pointer

```c
int *ptr = NULL;   // Pointer yang SENGAJA tidak menunjuk ke mana-mana

// SELALU cek NULL sebelum dereference!
if (ptr != NULL) {
    printf("%d\n", *ptr);   // Aman
} else {
    printf("Pointer is NULL!\n");
}

// ❌ Dereference NULL → CRASH! (Segmentation Fault)
// printf("%d\n", *ptr);   // KABOOM!
```

**Kapan pakai NULL?**
- Saat pointer belum/tidak valid
- Sebagai return value untuk indikasi "tidak ada" atau "gagal"
- Sebagai sentinel (penanda akhir)

```c
/* Function yang bisa gagal */
int *find_element(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return &arr[i];   // Return pointer ke elemen
        }
    }
    return NULL;   // Tidak ketemu
}

int data[] = {10, 20, 30, 40};
int *found = find_element(data, 4, 30);
if (found != NULL) {
    printf("Ketemu: %d\n", *found);   // 30
}
```

### 5. Void Pointer (`void *`)

> **Analogi:** `void *` itu kayak **amplop tertutup** — lu tahu ada sesuatu di dalamnya, tapi lu harus tahu sendiri apa isinya sebelum buka.

```c
int x = 42;
double y = 3.14;

void *generic = &x;      // ✅ void * bisa menunjuk ke tipe apa saja

// Tapi TIDAK bisa langsung dereference!
// printf("%d\n", *generic);   // ❌ ERROR: deref void *

// Harus CAST dulu ke tipe yang tepat:
printf("%d\n", *(int *)generic);      // ✅ 42

generic = &y;
printf("%.2f\n", *(double *)generic); // ✅ 3.14
```

**Kapan pakai `void *`?**
- Function yang bekerja dengan **tipe apa saja** (generic)
- `malloc()` return `void *` (modul 017)
- Callback yang generik (modul 014)

### 6. Const dengan Pointer — 4 Kombinasi

Ini salah satu topik paling penting untuk **const correctness**:

```c
int x = 10, y = 20;

/* 1. Pointer ke const int — NILAI tidak bisa diubah lewat pointer */
const int *p1 = &x;
// *p1 = 99;       // ❌ ERROR: nilai yang ditunjuk const
p1 = &y;           // ✅ OK: pointer sendiri bisa pindah

/* 2. Const pointer ke int — POINTER tidak bisa pindah */
int *const p2 = &x;
*p2 = 99;          // ✅ OK: nilai bisa diubah
// p2 = &y;        // ❌ ERROR: pointer const, tidak bisa pindah

/* 3. Const pointer ke const int — KEDUA-DUANYA const */
const int *const p3 = &x;
// *p3 = 99;       // ❌ ERROR
// p3 = &y;        // ❌ ERROR

/* 4. Pointer biasa — semua bisa berubah */
int *p4 = &x;
*p4 = 99;          // ✅ OK
p4 = &y;           // ✅ OK
```

**Trik baca: baca dari KANAN ke KIRI!**

```
const int *p     → p is a pointer to int that is const
                   "pointer ke const int" — NILAI const

int *const p     → p is a const pointer to int
                   "const pointer ke int" — POINTER const

const int *const p → keduanya const
```

**Best practice: selalu pakai `const` kalau tidak perlu modifikasi:**

```c
/* ✅ Fungsi yang hanya BACA array — parameter const */
void print_array(const int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        // arr[i] = 99;   // ❌ Compiler cegah — const!
    }
    printf("\n");
}
```

### 7. Dangling Pointer & Wild Pointer

#### Dangling Pointer — Menunjuk ke Memori yang Sudah Tidak Valid

```c
int *dangling(void) {
    int local = 42;
    return &local;     // ⚠️ local mati setelah function return!
}

int *p = dangling();
printf("%d\n", *p);    // ❌ Undefined behavior! Bisa apa aja!
```

```c
int *ptr;
{
    int temp = 100;
    ptr = &temp;       // ptr menunjuk ke temp
}
// temp sudah mati (keluar scope)
// ptr sekarang = DANGLING POINTER!
printf("%d\n", *ptr);  // ❌ UB!
```

#### Wild Pointer — Pointer yang Belum Diinisialisasi

```c
int *wild;             // Belum diinisialisasi — berisi alamat RANDOM!
// printf("%d\n", *wild);  // ❌ CRASH atau UB!

// ✅ Selalu inisialisasi pointer
int *safe = NULL;      // Aman — bisa dicek sebelum dipakai
```

**Tips menghindari masalah pointer:**
1. **Selalu inisialisasi** pointer (`NULL` atau alamat valid)
2. **Set ke NULL** setelah pointer tidak diperlukan lagi
3. **Jangan return alamat local variable** dari function
4. **Cek NULL** sebelum dereference

### 8. Pointer ke Pointer (`int **`)

```c
int x = 42;
int *p = &x;       // Pointer ke int
int **pp = &p;     // Pointer ke pointer ke int

printf("%d\n", x);      // 42
printf("%d\n", *p);     // 42
printf("%d\n", **pp);   // 42 (double dereference)

**pp = 99;              // Mengubah x lewat 2 level indirection
printf("%d\n", x);      // 99
```

> Pointer ke pointer banyak dipakai di modul selanjutnya (dynamic 2D array, fungsi yang mengubah pointer itu sendiri).

---

## ⚠️ Perangkap Umum (Common Pitfalls)

### 1. Lupa `&` Saat Pass ke Function

```c
int x = 10;
// scanf("%d", x);     // ❌ CRASH! scanf butuh ALAMAT, bukan NILAI!
scanf("%d", &x);       // ✅ Pass alamat x
```

### 2. Dereference NULL

```c
int *p = NULL;
// *p = 42;   // ❌ Segmentation fault!

// ✅ Selalu cek dulu
if (p != NULL) {
    *p = 42;
}
```

### 3. Type Mismatch

```c
double d = 3.14;
int *p = (int *)&d;   // ⚠️ Cast paksa — hasilnya SAMPAH!
printf("%d\n", *p);    // Bukan 3, bukan 3.14 — nilai random!
```

### 4. Uninitialized Pointer

```c
int *p;            // WILD POINTER — alamat random!
*p = 42;           // ❌ Menulis ke alamat random → CRASH atau corrupt memory!
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
| 🟢 EASY | Buat fungsi `swap()`, `min_max()` (return min & max via pointer), dan `is_sorted()` yang menerima array via pointer |
| 🟡 MEDIUM | Buat fungsi `array_stats()` yang return min, max, sum, mean via 4 pointer parameter — plus fungsi `find()` yang return pointer ke elemen atau NULL |
| 🔴 HARD | Buat **simple string builder**: fungsi-fungsi `str_append()`, `str_prepend()`, `str_insert_at()` yang memodifikasi char buffer via pointer, dengan tracking panjang via `int *len` |

---

## 🔗 Lanjut ke

**[013 — Pointer Arithmetic, Array, & String Safety →](../013-pointer-arithmetic-array/)**
