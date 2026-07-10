# 011 — Rekursi

**Fase:** 3 · Fungsi & Modularitas Modern | **Prasyarat:** [010 — Header & Multi-file](../010-header-multifile-preprocessor/) | **Estimasi waktu:** 4-5 jam

---

## 🎯 Tujuan Belajar

- Memahami konsep **rekursi**: fungsi yang memanggil dirinya sendiri
- Bisa mengidentifikasi **base case** dan **recursive case** yang benar
- Mengerti cara kerja **call stack** dan kenapa bisa terjadi **stack overflow**
- Memahami konsep **tail recursion** dan optimasi compiler
- Bisa mengimplementasikan studi kasus klasik: **factorial, fibonacci, power, tower of hanoi**
- Bisa membedakan kapan pakai **rekursi vs iterasi**
- Mengenal konsep **memoization** untuk optimasi rekursi

---

## 📖 Konsep Inti

### 1. Apa Itu Rekursi?

> **Analogi:** Rekursi itu kayak **cermin menghadap cermin** — bayangan di dalam bayangan, terus ke dalam, sampai terlalu kecil untuk dilihat (base case). Atau kayak **boneka matryoshka** — buka satu, ada yang lebih kecil di dalamnya, sampai habis.

```c
void hitung_mundur(int n) {
    if (n <= 0) {             // BASE CASE — kapan berhenti
        printf("GO!\n");
        return;
    }
    printf("%d... ", n);       // Lakukan sesuatu
    hitung_mundur(n - 1);     // RECURSIVE CASE — panggil diri sendiri
}

// hitung_mundur(3):
// 3... 2... 1... GO!
```

**Dua komponen WAJIB dalam rekursi:**

1. **Base case** — kondisi berhenti (tanpa ini → infinite recursion → stack overflow!)
2. **Recursive case** — panggil diri sendiri dengan input yang **LEBIH KECIL/SEDERHANA**

### 2. Call Stack — Bagaimana Rekursi Bekerja di Memori

> **Analogi:** Call stack itu kayak **tumpukan piring** — setiap kali function dipanggil, satu "piring" (stack frame) ditaruh di atas. Saat function selesai (return), piring diambil dari atas.

```c
int factorial(int n) {
    if (n <= 1) return 1;        // Base case
    return n * factorial(n - 1); // Recursive case
}

// factorial(4) — visualisasi call stack:
//
// PANGGIL                              RETURN
// ┌─────────────────┐
// │ factorial(4)     │                 4 * 6 = 24
// │  4 * factorial(3)│                    ↑
// ├─────────────────┤
// │ factorial(3)     │                 3 * 2 = 6
// │  3 * factorial(2)│                    ↑
// ├─────────────────┤
// │ factorial(2)     │                 2 * 1 = 2
// │  2 * factorial(1)│                    ↑
// ├─────────────────┤
// │ factorial(1)     │                 return 1  ← BASE CASE
// └─────────────────┘
```

Setiap pemanggilan function membuat **stack frame** baru yang berisi:
- Parameter function
- Variabel lokal
- Alamat kembali (return address)

### 3. Stack Overflow — Terlalu Dalam!

```c
/* ❌ TANPA base case — infinite recursion → CRASH! */
void infinite(void) {
    printf("Help! ");
    infinite();   // Tidak pernah berhenti → stack overflow
}

/* ❌ Base case ada tapi input tidak mengecil */
int broken(int n) {
    if (n == 0) return 0;
    return broken(n);       // n tidak berubah → infinite recursion!
}

/* ❌ Base case salah — beberapa input tidak pernah mencapainya */
int broken2(int n) {
    if (n == 1) return 1;
    return broken2(n - 2);  // Kalau n genap, tidak pernah == 1!
}
```

> **Stack overflow** terjadi karena setiap panggilan function memakan memori di stack. Stack punya batas (~1-8 MB tergantung OS). Kalau rekursi terlalu dalam, stack penuh → program crash.

### 4. Studi Kasus Klasik

#### Factorial: n!

```
5! = 5 × 4 × 3 × 2 × 1 = 120
n! = n × (n-1)!
0! = 1 (base case)
```

```c
int factorial(int n) {
    if (n <= 1) return 1;           // Base case: 0! = 1! = 1
    return n * factorial(n - 1);    // n! = n × (n-1)!
}
```

#### Fibonacci: F(n) = F(n-1) + F(n-2)

```
F(0) = 0, F(1) = 1
F(2) = 1, F(3) = 2, F(4) = 3, F(5) = 5, F(6) = 8, ...
```

```c
/* Versi naif — SANGAT LAMBAT! O(2^n) */
int fib_naive(int n) {
    if (n <= 0) return 0;       // Base case
    if (n == 1) return 1;       // Base case
    return fib_naive(n - 1) + fib_naive(n - 2);
}

// fib_naive(5) melakukan BANYAK pemanggilan berulang:
//                  fib(5)
//                /        \
//           fib(4)        fib(3)
//          /      \      /      \
//      fib(3)  fib(2)  fib(2)  fib(1)
//      /    \
//  fib(2)  fib(1)
//  ...
// fib(2) dihitung 3 KALI! Sangat tidak efisien.
```

#### Power: x^n

```c
/* Versi sederhana — O(n) */
long long power_simple(int base, int exp) {
    if (exp == 0) return 1;
    return base * power_simple(base, exp - 1);
}

/* Versi cepat — O(log n), fast exponentiation */
long long power_fast(int base, int exp) {
    if (exp == 0) return 1;

    if (exp % 2 == 0) {
        long long half = power_fast(base, exp / 2);
        return half * half;           // x^n = (x^(n/2))²
    } else {
        return base * power_fast(base, exp - 1);
    }
}
```

#### Tower of Hanoi

> **Puzzle:** Pindahkan n disk dari tiang A ke tiang C, menggunakan tiang B sebagai perantara. Aturan: hanya boleh pindah 1 disk, disk besar tidak boleh di atas disk kecil.

```c
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("  Pindahkan disk 1 dari %c ke %c\n", from, to);
        return;
    }

    // 1. Pindahkan n-1 disk dari 'from' ke 'aux' (via 'to')
    hanoi(n - 1, from, aux, to);

    // 2. Pindahkan disk terbesar dari 'from' ke 'to'
    printf("  Pindahkan disk %d dari %c ke %c\n", n, from, to);

    // 3. Pindahkan n-1 disk dari 'aux' ke 'to' (via 'from')
    hanoi(n - 1, aux, to, from);
}

// hanoi(3, 'A', 'C', 'B'):
// Total langkah = 2^n - 1 = 7
```

### 5. Tail Recursion

**Tail recursion** = recursive call adalah **hal TERAKHIR** yang dilakukan function (tidak ada operasi lagi setelah recursive call).

```c
/* ❌ BUKAN tail recursive — masih ada operasi 'n *' setelah recursive call */
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);   // Harus tunggu hasil, baru kalikan
}

/* ✅ Tail recursive — recursive call adalah HAL TERAKHIR */
int factorial_tail(int n, int acc) {
    if (n <= 1) return acc;
    return factorial_tail(n - 1, n * acc);   // Tidak ada operasi setelah ini
}

// Wrapper function untuk kemudahan
int factorial_tr(int n) {
    return factorial_tail(n, 1);
}
```

> **Kenapa penting?** Compiler bisa mengoptimasi tail recursion menjadi **iterasi** (tail call optimization / TCO), sehingga tidak menambah stack frame — tidak bisa stack overflow! Compile dengan `-O2` untuk enable TCO.

### 6. Rekursi vs Iterasi

| Aspek | Rekursi | Iterasi |
|-------|---------|---------|
| Readability | Lebih natural untuk masalah "divide & conquer" | Lebih straightforward untuk loop biasa |
| Memory | Pakai stack frame per call (bisa stack overflow) | Konstant memory (O(1)) |
| Performance | Overhead function call | Biasanya lebih cepat |
| Use-case | Tree traversal, divide & conquer, Tower of Hanoi | Counting, array traversal, simple loops |

**Rule of thumb:**
- Kalau masalah **secara natural rekursif** (tree, divide & conquer) → pakai rekursi
- Kalau bisa pakai **loop sederhana** → pakai iterasi (lebih efisien)
- Kalau rekursi terlalu lambat → pakai **memoization** atau ubah ke iterasi

### 7. Memoization — Caching Hasil Rekursi

> **Analogi:** Memoization itu kayak **catatan contekan** — kalau lu sudah pernah hitung sesuatu, tulis hasilnya. Kalau ditanya lagi, buka catatan, jangan hitung ulang.

```c
/* Fibonacci dengan memoization — O(n) bukan O(2^n)! */
#define MAX_N 100
long long memo[MAX_N] = {0};
int computed[MAX_N] = {0};

long long fib_memo(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    /* Cek cache dulu */
    if (computed[n]) return memo[n];

    /* Hitung dan simpan */
    memo[n] = fib_memo(n - 1) + fib_memo(n - 2);
    computed[n] = 1;

    return memo[n];
}
```

**Perbandingan:**

| n | fib_naive() calls | fib_memo() calls |
|---|---|---|
| 10 | 177 | 19 |
| 20 | 21,891 | 39 |
| 30 | 2,692,537 | 59 |
| 40 | 331,160,281 | 79 |
| 50 | ~40 miliar! | 99 |

---

## ⚠️ Perangkap Umum (Common Pitfalls)

### 1. Missing Base Case

```c
/* ❌ Lupa base case → infinite recursion → stack overflow! */
int sum(int n) {
    return n + sum(n - 1);   // Kapan berhenti?!
}

/* ✅ Selalu punya base case */
int sum_fix(int n) {
    if (n <= 0) return 0;       // BASE CASE!
    return n + sum_fix(n - 1);
}
```

### 2. Input Tidak Mengecil

```c
/* ❌ Input tidak menuju base case */
int bad(int n) {
    if (n == 0) return 0;
    return bad(n + 1);    // n BERTAMBAH, tidak pernah == 0 (kalau n > 0)
}
```

### 3. Exponential Complexity (Fibonacci Trap)

```c
/* ❌ Fibonacci naif → O(2^n) — terlalu lambat untuk n > 40 */
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);   // BANYAK pemanggilan berulang!
}

/* ✅ Solusi: memoization atau iterasi */
```

### 4. Stack Overflow untuk Input Besar

```c
/* ❌ factorial(1000000) → stack overflow (~1 juta stack frame!) */
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

/* ✅ Pakai iterasi untuk input besar */
long long factorial_iter(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
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
| 🟢 EASY | Implementasi rekursif: **sum of digits**, **reverse number**, dan **GCD** (Euclidean) |
| 🟡 MEDIUM | **Recursive binary search** + **recursive pattern printing** (segitiga bintang) |
| 🔴 HARD | **Permutasi string** — print semua kemungkinan urutan karakter dari string input (misal "ABC" → ABC, ACB, BAC, BCA, CAB, CBA) |

---

## 🔗 Lanjut ke

**[012 — Pointer Dasar →](../012-pointer-dasar/)**
