# 003 — Operator

**Fase:** 1 · Fondasi | **Prasyarat:** [002 — Variabel & Tipe Data](../002-variabel-dan-tipe-data/) | **Estimasi waktu:** 4-5 jam

---

## 🎯 Tujuan Belajar

- Bisa menggunakan **semua jenis operator** di C: aritmatika, relasional, logika, bitwise, assignment
- Bisa membedakan **prefix vs postfix** increment/decrement dan paham dampaknya
- Bisa membaca dan menerapkan **operator precedence table** untuk memprediksi hasil ekspresi kompleks
- Bisa menjelaskan **operator bitwise** dan use-case-nya di dunia nyata (flags, permissions)
- Bisa menghindari **common bugs** terkait operator (assignment vs comparison, division by zero)

---

## 📖 Konsep Inti

### 1. Operator Aritmatika

Operator dasar untuk operasi matematika:

| Operator | Nama | Contoh | Hasil |
|----------|------|--------|-------|
| `+` | Penjumlahan | `5 + 3` | `8` |
| `-` | Pengurangan | `5 - 3` | `2` |
| `*` | Perkalian | `5 * 3` | `15` |
| `/` | Pembagian | `5 / 3` | `1` ⚠️ |
| `%` | Modulo (sisa bagi) | `5 % 3` | `2` |

> **⚠️ PERINGATAN: Integer Division!**
> Pembagian `int / int` menghasilkan `int` — bagian desimal **dibuang** (bukan dibulatkan):
> ```c
> printf("%d\n", 7 / 2);     // Output: 3 (bukan 3.5!)
> printf("%d\n", -7 / 2);    // Output: -3 (truncated toward zero)
> printf("%f\n", 7.0 / 2);   // Output: 3.500000 (salah satu float/double = OK)
> ```

> **Analogi modulo (`%`):** Bayangkan lu punya 17 permen dan mau bagi rata ke 5 anak. Setiap anak dapat `17 / 5 = 3` permen. Sisanya? `17 % 5 = 2` permen. Modulo = sisa pembagian.

**Real world use-case modulo:**
```c
// Cek genap/ganjil
if (angka % 2 == 0)  // Genap
if (angka % 2 != 0)  // Ganjil

// Wrap around (cycling): 0, 1, 2, 0, 1, 2, 0, ...
int index = counter % 3;

// Cek kelipatan: setiap 10 item, cetak progress
if (i % 10 == 0) printf("Progress: %d items...\n", i);
```

### 2. Operator Relasional (Perbandingan)

Mengembalikan `1` (true) atau `0` (false):

| Operator | Nama | Contoh | Hasil |
|----------|------|--------|-------|
| `==` | Sama dengan | `5 == 5` | `1` (true) |
| `!=` | Tidak sama dengan | `5 != 3` | `1` (true) |
| `>` | Lebih besar | `5 > 3` | `1` (true) |
| `<` | Lebih kecil | `5 < 3` | `0` (false) |
| `>=` | Lebih besar atau sama | `5 >= 5` | `1` (true) |
| `<=` | Lebih kecil atau sama | `3 <= 5` | `1` (true) |

> **PENTING:** Di C, **TIDAK ADA tipe `bool` bawaan** di C89. Di C99+, ada `<stdbool.h>` yang mendefinisikan `true` = 1 dan `false` = 0. Tapi secara internal, semua conditional di C bekerja dengan integer:
> - **0 = false** (termasuk `0.0`, `'\0'`, `NULL`)
> - **Semua nilai lain = true** (1, -1, 42, 0.5, dst.)

### 3. Operator Logika

Menggabungkan beberapa kondisi:

| Operator | Nama | Contoh | Hasil |
|----------|------|--------|-------|
| `&&` | AND (dan) | `1 && 1` | `1` |
| `\|\|` | OR (atau) | `0 \|\| 1` | `1` |
| `!` | NOT (negasi) | `!1` | `0` |

**Truth table:**

| A | B | A && B | A \|\| B | !A |
|---|---|--------|----------|----|
| 0 | 0 | 0 | 0 | 1 |
| 0 | 1 | 0 | 1 | 1 |
| 1 | 0 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 0 |

**Short-circuit evaluation:**

C mengevaluasi operator logika dari kiri ke kanan dan **berhenti segera setelah hasilnya pasti**:

```c
// && (AND): kalau yang kiri sudah false, yang kanan TIDAK dievaluasi
// Karena false && apapun = false
int x = 0;
if (x != 0 && 10 / x > 2) { ... }
// x = 0, jadi x != 0 = false
// 10 / x TIDAK dievaluasi — selamat dari division by zero!

// || (OR): kalau yang kiri sudah true, yang kanan TIDAK dievaluasi
// Karena true || apapun = true
```

> **Real world:** Short-circuit sering dipakai sebagai "safety check" sebelum operasi berbahaya. Ini bukan trik — ini **idiom standar** di C.

### 4. Operator Assignment (Penugasan)

| Operator | Contoh | Sama Dengan | Penjelasan |
|----------|--------|-------------|------------|
| `=` | `x = 5` | — | Assign nilai 5 ke x |
| `+=` | `x += 3` | `x = x + 3` | Tambah 3 |
| `-=` | `x -= 2` | `x = x - 2` | Kurang 2 |
| `*=` | `x *= 4` | `x = x * 4` | Kali 4 |
| `/=` | `x /= 2` | `x = x / 2` | Bagi 2 |
| `%=` | `x %= 3` | `x = x % 3` | Modulo 3 |
| `&=` | `x &= 0xF` | `x = x & 0xF` | Bitwise AND |
| `\|=` | `x \|= 0x4` | `x = x \| 0x4` | Bitwise OR |
| `^=` | `x ^= 0xFF` | `x = x ^ 0xFF` | Bitwise XOR |
| `<<=` | `x <<= 2` | `x = x << 2` | Shift left |
| `>>=` | `x >>= 1` | `x = x >> 1` | Shift right |

> **Best practice:** Pakai compound assignment (`+=`, `-=`, dll.) daripada bentuk panjangnya. Lebih ringkas, lebih jelas, dan compiler bisa mengoptimasi lebih baik.

### 5. Operator Increment & Decrement

| Operator | Nama | Efek |
|----------|------|------|
| `++x` | Prefix increment | Tambah 1 **dulu**, baru pakai nilainya |
| `x++` | Postfix increment | Pakai nilainya **dulu**, baru tambah 1 |
| `--x` | Prefix decrement | Kurang 1 **dulu**, baru pakai nilainya |
| `x--` | Postfix decrement | Pakai nilainya **dulu**, baru kurang 1 |

**Perbedaan prefix vs postfix — ini KRUSIAL:**

```c
int a = 5;
int b = ++a;   // a jadi 6 DULU, baru assign ke b
// a = 6, b = 6

int c = 5;
int d = c++;   // assign c (5) ke d DULU, baru c jadi 6
// c = 6, d = 5
```

> **Analogi:** 
> - `++x` = "Naikkan dulu, baru ambil" (kayak naik tangga dulu baru foto)
> - `x++` = "Ambil dulu, baru naikkan" (kayak foto dulu baru naik tangga)

> **Best practice:** Kalau lu cuma mau menambah 1 tanpa peduli "kapan" perubahannya (misal `i++` di akhir loop), keduanya menghasilkan hal yang sama. Tapi **JANGAN** campurkan `++`/`--` dengan operasi lain di ekspresi yang sama — itu bikin kode sulit dibaca dan bisa jadi **Undefined Behavior**.

```c
// ❌ JANGAN — hasilnya UNPREDICTABLE (UB)
int x = 5;
int y = x++ + ++x;  // UB! Jangan pernah bikin ekspresi kayak gini

// ✅ AMAN — pisahkan ke statement terpisah
int x = 5;
x++;
int y = x + 1;
```

### 6. Operator Bitwise

Operator yang bekerja di level **bit** (0 dan 1). Ini operator yang bikin C "dekat dengan hardware".

| Operator | Nama | Contoh (binary) | Hasil |
|----------|------|-----------------|-------|
| `&` | AND | `0b1010 & 0b1100` | `0b1000` (8) |
| `\|` | OR | `0b1010 \| 0b1100` | `0b1110` (14) |
| `^` | XOR | `0b1010 ^ 0b1100` | `0b0110` (6) |
| `~` | NOT (complement) | `~0b1010` | `0b...0101` |
| `<<` | Left shift | `0b0001 << 3` | `0b1000` (8) |
| `>>` | Right shift | `0b1000 >> 2` | `0b0010` (2) |

> **Analogi:**
> - `&` (AND) = "Lampu nyala HANYA kalau KEDUA switch ON"
> - `|` (OR) = "Lampu nyala kalau SALAH SATU switch ON"
> - `^` (XOR) = "Lampu nyala kalau switch-nya BEDA"
> - `~` (NOT) = "Balik semua switch"
> - `<<` (Left shift) = "Geser semua digit ke kiri, isi 0 di kanan" (= kali 2^n)
> - `>>` (Right shift) = "Geser semua digit ke kanan" (= bagi 2^n)

**Detail bitwise AND (`&`):**
```
   1010  (10 dalam desimal)
&  1100  (12 dalam desimal)
------
   1000  (8 dalam desimal)
```
Setiap posisi bit: hanya 1 & 1 = 1. Semua kombinasi lain = 0.

**Detail bitwise OR (`|`):**
```
   1010  (10)
|  1100  (12)
------
   1110  (14)
```
Setiap posisi bit: kalau salah satu 1, hasilnya 1.

**Detail bitwise XOR (`^`):**
```
   1010  (10)
^  1100  (12)
------
   0110  (6)
```
Setiap posisi bit: kalau BERBEDA = 1, kalau SAMA = 0.

**Left shift (`<<`) dan Right shift (`>>`):**
```c
int x = 1;          // binary: 0001
x = x << 3;         // binary: 1000 = 8 (= 1 * 2^3)
// Left shift n = kalikan dengan 2^n

int y = 16;          // binary: 10000
y = y >> 2;          // binary: 00100 = 4 (= 16 / 2^2)
// Right shift n = bagi dengan 2^n (integer division)
```

**Real world use-case bitwise:**

```c
/* Permission system (seperti Linux file permissions) */
#define PERM_READ    (1 << 0)   /* 001 = 1 */
#define PERM_WRITE   (1 << 1)   /* 010 = 2 */
#define PERM_EXECUTE (1 << 2)   /* 100 = 4 */

int user_perm = 0;

/* SET permission: pakai OR */
user_perm |= PERM_READ;          /* Kasih izin baca */
user_perm |= PERM_WRITE;         /* Kasih izin tulis */
/* user_perm sekarang = 011 (3) = READ + WRITE */

/* CHECK permission: pakai AND */
if (user_perm & PERM_READ) {     /* Apakah punya izin baca? */
    printf("Boleh baca!\n");
}

/* REMOVE permission: pakai AND NOT */
user_perm &= ~PERM_WRITE;        /* Cabut izin tulis */
/* user_perm sekarang = 001 (1) = hanya READ */

/* TOGGLE permission: pakai XOR */
user_perm ^= PERM_EXECUTE;       /* Flip izin eksekusi */
```

> Ini bukan teori — **Linux file permissions** (`chmod 755`) bekerja persis seperti ini. Bit flags juga dipakai di game development (status effects), networking (protocol headers), dan embedded systems.

### 7. Operator Precedence Table

Urutan prioritas operator (dari **tertinggi** ke **terendah**):

| Prioritas | Operator | Arah Evaluasi |
|-----------|----------|---------------|
| 1 (tertinggi) | `()` (grouping) | Kiri → Kanan |
| 2 | `++` `--` (postfix), `()` (function call) | Kiri → Kanan |
| 3 | `++` `--` (prefix), `!` `~` `+` `-` (unary), `(type)`, `sizeof` | Kanan → Kiri |
| 4 | `*` `/` `%` | Kiri → Kanan |
| 5 | `+` `-` | Kiri → Kanan |
| 6 | `<<` `>>` | Kiri → Kanan |
| 7 | `<` `<=` `>` `>=` | Kiri → Kanan |
| 8 | `==` `!=` | Kiri → Kanan |
| 9 | `&` (bitwise AND) | Kiri → Kanan |
| 10 | `^` (bitwise XOR) | Kiri → Kanan |
| 11 | `\|` (bitwise OR) | Kiri → Kanan |
| 12 | `&&` (logical AND) | Kiri → Kanan |
| 13 | `\|\|` (logical OR) | Kiri → Kanan |
| 14 | `? :` (ternary) | Kanan → Kiri |
| 15 | `=` `+=` `-=` dll. (assignment) | Kanan → Kiri |
| 16 (terendah) | `,` (comma) | Kiri → Kanan |

> **Best practice:** Jangan hafalkan tabel ini. **PAKAI TANDA KURUNG `()`** untuk mempertegas urutan. Kode yang jelas > kode yang pintar.

```c
// ❌ Siapa yang paham ini?
int result = a + b * c >> d & e;

// ✅ Jauh lebih jelas
int result = ((a + (b * c)) >> d) & e;
```

### 8. Operator Comma (`,`)

Operator yang paling jarang dibahas tapi ada di C:

```c
int a, b;          // Ini BUKAN comma operator — ini deklarasi multiple variabel

int x = (1, 2, 3); // Ini comma operator — evaluasi semua, ambil yang terakhir
// x = 3

// Biasanya muncul di for loop:
for (int i = 0, j = 10; i < j; i++, j--) {
    // i naik, j turun secara bersamaan
}
```

---

## ⚠️ Perangkap Umum (Common Pitfalls)

### 1. `=` vs `==` — Assignment vs Comparison

Ini bug **PALING KLASIK** di C:

```c
int x = 5;

// ❌ BUG — ini ASSIGNMENT, bukan comparison!
if (x = 3) {           // x DIUBAH jadi 3, lalu 3 dianggap true
    printf("Selalu masuk sini!\n");   // Selalu dieksekusi!
}

// ✅ BENAR — pakai == untuk membandingkan
if (x == 3) {
    printf("x adalah 3\n");
}

// TIP: Tulis konstanta di kiri (Yoda condition) untuk menghindari typo
if (3 == x) {   // Kalau typo jadi 3 = x, compiler ERROR (bagus!)
    printf("x adalah 3\n");
}
```

### 2. Division by Zero

```c
int a = 10;
int b = 0;
int c = a / b;     // ❌ CRASH! Division by zero = Undefined Behavior
// Pada kebanyakan sistem: program langsung crash (SIGFPE)

// ✅ Selalu cek pembagi sebelum membagi
if (b != 0) {
    int c = a / b;
} else {
    printf("Error: pembagi tidak boleh nol!\n");
}
```

### 3. Bitwise vs Logical — `&` vs `&&`

```c
int a = 1, b = 2;

// & (bitwise AND) — operasi per bit
printf("%d\n", a & b);    // 01 & 10 = 00 = 0

// && (logical AND) — true/false
printf("%d\n", a && b);   // 1 (true) && 2 (true) = 1 (true)

// Ini BEDA HASILNYA! Jangan tertukar!
```

### 4. Modulo dengan Bilangan Negatif

```c
printf("%d\n", -7 % 3);    // Hasil: -1 (di C99+)
// Bukan 2! Di C, tanda hasil modulo mengikuti tanda pembilang (dividend)
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

Lihat file `exercise.c` untuk 3 latihan:

| Level | Deskripsi |
|-------|-----------|
| 🟢 EASY | Kalkulator sederhana: hitung luas & keliling dari panjang dan lebar yang sudah di-hardcode |
| 🟡 MEDIUM | Bit flags permission system: implementasi SET, CHECK, REMOVE, TOGGLE permission |
| 🔴 HARD | Precedence puzzle: prediksi output dari ekspresi kompleks, lalu verifikasi dengan printf |

---

## 🔗 Lanjut ke

**[004 — Input/Output →](../004-input-output/)**
