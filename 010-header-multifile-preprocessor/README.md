
# 010 — Header, Multi-file, Preprocessor

**Fase:** 3 · Fungsi & Modularitas Modern | **Prasyarat:** [009 — Function & Storage Classes](../009-function-dan-storage-classes/) | **Estimasi waktu:** 5-6 jam

---

## 🎯 Tujuan Belajar

- Bisa menulis dan menggunakan **`#define`** (object-like dan function-like macro)
- Memahami perbedaan **`#include <...>`** vs **`#include "..."`**
- Bisa menggunakan **conditional compilation** (`#ifdef`, `#ifndef`, `#endif`, `#if`, `#elif`)
- Menguasai pola **include guards** untuk mencegah double inclusion
- Bisa **split project** ke file `.h` (header) dan `.c` (source)
- Memahami proses **multi-file compilation** dan kenapa muncul error "undefined reference"
- Bisa menulis **Makefile** dasar untuk automasi build

---

## 📖 Konsep Inti

### 1. Preprocessor — Apa Itu?

> **Analogi:** Preprocessor itu kayak **editor naskah sebelum naik cetak**. Sebelum compiler baca kode lu, preprocessor masuk dulu — ganti semua `#define`, copy-paste isi `#include`, dan pilih mana kode yang di-compile berdasarkan `#ifdef`.

```
Source code (.c)
     │
     ▼
[Preprocessor]  ← #include, #define, #ifdef, dll
     │
     ▼
Preprocessed code (semua macro sudah di-expand)
     │
     ▼
[Compiler]      ← compile jadi object file (.o)
     │
     ▼
Object file (.o)
     │
     ▼
[Linker]        ← gabungin semua .o jadi executable
     │
     ▼
Executable (program)
```

Lihat hasil preprocessor:
```bash
gcc -E main.c | head -50    # Flag -E: hanya preprocess, tidak compile
```

### 2. `#define` — Object-like Macro

```c
/* Konstanta — konvensi: HURUF_BESAR */
#define MAX_SIZE 100
#define PI 3.14159265358979
#define APP_NAME "My Calculator"
#define NEWLINE '\n'

/* Dipakai seperti biasa */
int arr[MAX_SIZE];
double luas = PI * r * r;
printf("App: %s%c", APP_NAME, NEWLINE);
```

**`#define` vs `const`:**

| | `#define` | `const` |
|---|---|---|
| Tipe | Tidak ada (text replacement) | Ada tipe yang jelas |
| Scope | Global (dari titik define ke bawah) | Mengikuti scope C biasa |
| Debug | Tidak muncul di debugger | Muncul dengan nama & tipe |
| Kapan dipakai | Conditional compilation, header guards | Konstanta dalam kode |

> **Rekomendasi:** Untuk konstanta biasa, **prefer `const`**. Pakai `#define` hanya untuk hal yang butuh preprocessor (conditional compilation, header guards, macro functions).

### 3. `#define` — Function-like Macro

```c
/* Macro function — hati-hati dengan efek samping! */
#define SQUARE(x)    ((x) * (x))
#define MAX(a, b)    ((a) > (b) ? (a) : (b))
#define MIN(a, b)    ((a) < (b) ? (a) : (b))
#define ABS(x)       ((x) < 0 ? -(x) : (x))
#define SWAP(a, b)   do { typeof(a) _t = (a); (a) = (b); (b) = _t; } while(0)

printf("%d\n", SQUARE(5));    // 25
printf("%d\n", MAX(10, 20));  // 20
printf("%d\n", ABS(-42));     // 42
```

**⚠️ BAHAYA macro function — double evaluation:**

```c
#define SQUARE(x)  ((x) * (x))

int a = 5;
int result = SQUARE(a++);
// Preprocessor expand: ((a++) * (a++))
// a di-increment DUA KALI! Undefined behavior!

// ✅ Dengan function biasa, ini aman:
int square(int x) { return x * x; }
int result2 = square(a++);   // a++ hanya sekali
```

> **⚠️ SELALU pakai tanda kurung** di setiap parameter macro:
> ```c
> #define BAD(x)   x * x
> BAD(3 + 1)  // expand: 3 + 1 * 3 + 1 = 7 (SALAH! harusnya 16)
>
> #define GOOD(x)  ((x) * (x))
> GOOD(3 + 1) // expand: ((3 + 1) * (3 + 1)) = 16 ✅
> ```

### 4. Multi-line Macro

```c
/* Backslash (\) untuk lanjut ke baris berikutnya */
#define PRINT_HEADER(title) \
    do { \
        printf("========================\n"); \
        printf("  %s\n", title); \
        printf("========================\n"); \
    } while(0)

/* Kenapa do { ... } while(0)?
 * Agar macro aman dipakai di if-else tanpa kurung kurawal:
 *
 * if (condition)
 *     PRINT_HEADER("test");    // Aman dengan do-while(0)
 * else
 *     something_else();
 */
```

### 5. `#include` — Copy-Paste File

```c
#include <stdio.h>      // Cari di SYSTEM include path (/usr/include, dll)
#include "mathlib.h"     // Cari di DIRECTORY SAAT INI dulu, baru system path
```

**Apa yang terjadi saat `#include`?**
Preprocessor secara harfiah **copy-paste** seluruh isi file yang di-include ke posisi `#include`.

```c
// Kalau mathlib.h berisi:
// int tambah(int a, int b);
// int kurang(int a, int b);

// Maka #include "mathlib.h" di main.c identik dengan:
int tambah(int a, int b);
int kurang(int a, int b);
```

### 6. Conditional Compilation

```c
/* #ifdef — "kalau macro ini SUDAH didefinisikan" */
#define DEBUG

#ifdef DEBUG
    printf("Debug mode ON\n");
    printf("x = %d\n", x);
#endif

/* #ifndef — "kalau macro ini BELUM didefinisikan" */
#ifndef RELEASE
    printf("Ini bukan build release\n");
#endif

/* #if, #elif, #else — kondisi lebih kompleks */
#define VERSION 3

#if VERSION == 1
    printf("Version 1\n");
#elif VERSION == 2
    printf("Version 2\n");
#elif VERSION >= 3
    printf("Version 3 or later\n");
#else
    printf("Unknown version\n");
#endif
```

**Define dari command line (tanpa ubah source code):**

```bash
# -D flag untuk define macro dari luar
gcc -DDEBUG -DVERSION=3 -o program main.c

# Sekarang di kode, DEBUG dan VERSION=3 terdefinisi
```

### 7. Include Guards — Mencegah Double Inclusion

**Masalah:**

```c
// a.h: #include "common.h"
// b.h: #include "common.h"
// main.c: #include "a.h" dan #include "b.h"
// → common.h di-include 2 KALI! → error: redefinition
```

**Solusi — Include guards:**

```c
/* mathlib.h */
#ifndef MATHLIB_H      // Kalau MATHLIB_H belum didefinisikan...
#define MATHLIB_H      // Definisikan sekarang

/* Isi header */
int tambah(int a, int b);
int kurang(int a, int b);

#endif /* MATHLIB_H */

/* Include kedua kali? MATHLIB_H sudah ada → seluruh isi di-skip */
```

**Konvensi penamaan guard:** `NAMAFILE_H` (huruf besar, ganti `.` dan `-` jadi `_`).

### 8. Split .h / .c — Apa Masuk Mana?

```
┌─────────────── Header (.h) ───────────────┐
│ ✅ Function prototypes (deklarasi)         │
│ ✅ #define konstanta & macro               │
│ ✅ typedef                                 │
│ ✅ struct/union/enum definition             │
│ ✅ extern variable declaration             │
│ ✅ Include guards                          │
│ ❌ Function BODY (definisi/implementasi)   │
│ ❌ Variable definition (int x = 5;)        │
└────────────────────────────────────────────┘

┌─────────────── Source (.c) ────────────────┐
│ ✅ #include header yang dibutuhkan         │
│ ✅ Function implementation (body)          │
│ ✅ Variable definition                     │
│ ✅ static function (internal helper)       │
└────────────────────────────────────────────┘
```

**Contoh project structure:**

```
project/
├── main.c          ← #include "mathlib.h", berisi main()
├── mathlib.h       ← Prototype: int tambah(int, int);
├── mathlib.c       ← Implementasi: int tambah(int a, int b) { return a+b; }
├── strutils.h      ← Prototype fungsi string utility
├── strutils.c      ← Implementasi string utility
└── Makefile        ← Automasi build
```

### 9. Multi-file Compilation

```bash
# Cara 1: Compile semua sekaligus
gcc -std=c17 -Wall -Wextra -o program main.c mathlib.c strutils.c

# Cara 2: Compile terpisah (lebih efisien untuk project besar)
gcc -std=c17 -Wall -Wextra -c main.c       # → main.o
gcc -std=c17 -Wall -Wextra -c mathlib.c     # → mathlib.o
gcc -std=c17 -Wall -Wextra -c strutils.c    # → strutils.o
gcc -o program main.o mathlib.o strutils.o   # Link semua .o
```

**Error "undefined reference":**

```
/usr/bin/ld: main.o: undefined reference to `tambah'
```

Artinya: linker tidak menemukan **implementasi** (body) fungsi `tambah`. Penyebab:
1. Lupa compile file `.c` yang berisi implementasi
2. Typo nama fungsi antara `.h` dan `.c`
3. Lupa `#include` header-nya

### 10. Makefile Dasar

> **Analogi:** Makefile itu kayak **resep masak otomatis** — lu tulis sekali langkah-langkahnya, tinggal ketik `make` dan semua di-compile otomatis. Kalau ada file yang berubah, cuma file itu yang di-compile ulang.

```makefile
# Variabel
CC      = gcc
CFLAGS  = -std=c17 -Wall -Wextra -Wpedantic
TARGET  = program

# Source files
SRCS    = main.c mathlib.c strutils.c
OBJS    = $(SRCS:.c=.o)     # Ganti .c jadi .o

# Target utama
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Pattern rule: compile .c jadi .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Dependency header
main.o: main.c mathlib.h strutils.h
mathlib.o: mathlib.c mathlib.h
strutils.o: strutils.c strutils.h

# Clean
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
```

**Variabel otomatis Makefile:**

| Variabel | Artinya |
|----------|---------|
| `$@` | Target (yang di-build) |
| `$<` | Dependency pertama |
| `$^` | Semua dependencies |

```bash
make            # Build project
make clean      # Hapus file hasil compile
```

### 11. Predefined Macros

```c
printf("File    : %s\n", __FILE__);     // Nama file source
printf("Line    : %d\n", __LINE__);     // Nomor baris saat ini
printf("Date    : %s\n", __DATE__);     // Tanggal compile
printf("Time    : %s\n", __TIME__);     // Jam compile
printf("Function: %s\n", __func__);     // Nama function saat ini

/* Berguna untuk debug logging */
#define LOG(msg) \
    printf("[%s:%d] %s(): %s\n", __FILE__, __LINE__, __func__, msg)

LOG("Starting initialization");
// Output: [main.c:42] main(): Starting initialization
```

---

## ⚠️ Perangkap Umum (Common Pitfalls)

### 1. Lupa Include Guards

```c
/* ❌ Tanpa include guard → error kalau di-include 2 kali */
// mathlib.h
int tambah(int a, int b);

/* ✅ Dengan include guard */
#ifndef MATHLIB_H
#define MATHLIB_H
int tambah(int a, int b);
#endif
```

### 2. Definisi Function di Header

```c
/* ❌ Function body di header → "multiple definition" error saat link */
// mathlib.h
int tambah(int a, int b) {    // SALAH! Ini DEFINISI, bukan deklarasi
    return a + b;
}

/* ✅ Header: hanya deklarasi. Body di .c */
// mathlib.h
int tambah(int a, int b);     // Deklarasi (prototype)

// mathlib.c
int tambah(int a, int b) {    // Definisi (implementasi)
    return a + b;
}
```

### 3. Macro Tanpa Kurung

```c
/* ❌ Tanpa kurung → precedence error */
#define DOUBLE(x)  x + x
int r = DOUBLE(3) * 2;   // expand: 3 + 3 * 2 = 9 (SALAH! harusnya 12)

/* ✅ Selalu pakai kurung */
#define DOUBLE(x)  ((x) + (x))
int r2 = DOUBLE(3) * 2;  // expand: ((3) + (3)) * 2 = 12 ✅
```

### 4. Circular Include

```c
/* ❌ a.h include b.h, b.h include a.h → infinite loop */
// a.h: #include "b.h"
// b.h: #include "a.h"

/* ✅ Solusi: restructure, gunakan forward declaration jika perlu */
```

---

## 💻 Cara Menjalankan

```bash
# Cara 1: Compile semua file sekaligus
gcc -std=c17 -Wall -Wextra -Wpedantic -o program main.c mathlib.c strutils.c
./program

# Cara 2: Pakai Makefile (recommended)
make
./program

# Clean up
make clean
```

---

## 📝 Latihan

| Level | Deskripsi |
|-------|-----------|
| 🟢 EASY | Buat macro `MAX()`, `MIN()`, `ABS()`, `SWAP()`, `ARRAY_SIZE()` dan test semuanya |
| 🟡 MEDIUM | Split project jadi multi-file: buat `arrayutils.h/.c` dengan fungsi array (sort, search, print) + Makefile |
| 🔴 HARD | Buat **debug logging system** dengan conditional compilation: `LOG_DEBUG()`, `LOG_INFO()`, `LOG_ERROR()` yang bisa di-enable/disable via `-DDEBUG` flag |

---

## 🔗 Lanjut ke

**[011 — Rekursi →](../011-rekursi/)**
