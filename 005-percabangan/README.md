# 005 — Percabangan

**Fase:** 1 · Fondasi | **Prasyarat:** [004 — Input/Output](../004-input-output/) | **Estimasi waktu:** 3-4 jam

---

## 🎯 Tujuan Belajar

- Bisa menggunakan **if, else if, else** untuk mengarahkan alur program berdasarkan kondisi
- Bisa menggunakan **switch-case** dan tahu kapan switch lebih tepat dari if-else
- Bisa menggunakan **ternary operator** (`? :`) untuk conditional one-liner
- Bisa menerapkan **guard clause / early return pattern** untuk mengurangi nesting
- Bisa menghindari **common bugs**: dangling else, missing break, assignment vs comparison

---

## 📖 Konsep Inti

### 1. `if` — Kondisi Paling Dasar

> **Analogi:** `if` itu kayak **rambu lalu lintas**. Kalau lampu hijau (kondisi true), jalan. Kalau merah (false), berhenti.

```c
int suhu = 38;

if (suhu > 37) {
    printf("Demam! Istirahat dulu.\n");
}
```

**Cara kerja:** Ekspresi di dalam `()` dievaluasi. Kalau hasilnya **non-zero (true)**, blok `{}` dijalankan. Kalau **zero (false)**, diskip.

Ingat dari modul 003: di C, **0 = false**, **semua nilai lain = true**.

```c
if (42)    { ... }   /* Dijalankan — 42 adalah true */
if (-1)    { ... }   /* Dijalankan — -1 adalah true */
if (0)     { ... }   /* TIDAK dijalankan — 0 adalah false */
if (0.0)   { ... }   /* TIDAK dijalankan — 0.0 adalah false */
if ('\0')  { ... }   /* TIDAK dijalankan — '\0' = 0 */
```

### 2. `if-else` — Dua Jalur

```c
int umur = 16;

if (umur >= 17) {
    printf("Boleh bikin SIM.\n");
} else {
    printf("Belum boleh bikin SIM.\n");
}
```

### 3. `if — else if — else` — Banyak Jalur

```c
int nilai = 85;

if (nilai >= 90) {
    printf("Grade: A\n");
} else if (nilai >= 80) {
    printf("Grade: B\n");
} else if (nilai >= 70) {
    printf("Grade: C\n");
} else if (nilai >= 60) {
    printf("Grade: D\n");
} else {
    printf("Grade: F (Tidak lulus)\n");
}
```

**Penting:** Eksekusi berhenti di kondisi pertama yang **true**. Jadi urutannya penting!

```c
/* ❌ SALAH — urutan terbalik */
if (nilai >= 60)       printf("D\n");
else if (nilai >= 70)  printf("C\n");   /* Tidak pernah tercapai! */
else if (nilai >= 80)  printf("B\n");   /* karena 80 >= 60 sudah true di atas */
```

### 4. Nested `if` — Dan Kenapa Harus Dihindari

```c
/* ❌ Nesting terlalu dalam — sulit dibaca */
if (is_logged_in) {
    if (has_permission) {
        if (is_valid_data) {
            if (is_not_expired) {
                process_request();
            } else {
                printf("Data expired!\n");
            }
        } else {
            printf("Data tidak valid!\n");
        }
    } else {
        printf("Tidak punya izin!\n");
    }
} else {
    printf("Belum login!\n");
}
```

Kode di atas punya masalah serius: **terlalu banyak nesting** (arrow code / pyramid of doom). Solusinya? **Guard clause**.

### 5. Guard Clause (Early Return Pattern) ⭐

> **Analogi:** Bayangkan lu penjaga pintu klub. Daripada ngecek satu per satu apakah tamu memenuhi SEMUA syarat, lebih baik **tolak yang tidak memenuhi satu syarat, satu per satu**, dari awal.

```c
/* ✅ Guard clause — jauh lebih mudah dibaca! */
/* Catatan: ini contoh di dalam fungsi, bukan main() */
/* Konsep function akan diajarkan di modul 009 */

void process_request(int is_logged_in, int has_permission,
                     int is_valid_data, int is_not_expired) {
    if (!is_logged_in) {
        printf("Belum login!\n");
        return;                     /* Keluar langsung */
    }

    if (!has_permission) {
        printf("Tidak punya izin!\n");
        return;
    }

    if (!is_valid_data) {
        printf("Data tidak valid!\n");
        return;
    }

    if (!is_not_expired) {
        printf("Data expired!\n");
        return;
    }

    /* Sampai sini = semua kondisi OK */
    /* process_request(); — logika utama di sini, tanpa nesting */
}
```

> **Best practice:** Kalau bisa, **tolak/return/skip kasus error dulu**, baru proses kasus normal di akhir. Ini mengurangi nesting dan membuat kode lebih linear.
>
> *Catatan: Di `main()`, kita belum bisa pakai `return` di tengah (selain `return 0` di akhir) untuk guard clause. Konsep `return` dari fungsi akan dibahas di modul 009. Untuk sekarang, fokus pada memahami pattern-nya.*

### 6. `switch-case` — Percabangan Berdasarkan Nilai

```c
int pilihan = 2;

switch (pilihan) {
    case 1:
        printf("Menu 1: Nasi Goreng\n");
        break;
    case 2:
        printf("Menu 2: Mie Ayam\n");
        break;
    case 3:
        printf("Menu 3: Sate Ayam\n");
        break;
    default:
        printf("Menu tidak tersedia.\n");
        break;
}
```

**Aturan penting `switch`:**

1. **Ekspresi harus integer atau char** — TIDAK bisa pakai `float`, `double`, atau `string`
2. **`break` WAJIB** — tanpa `break`, eksekusi "jatuh" ke case berikutnya (**fall-through**)
3. **`default`** — untuk menangkap semua nilai yang tidak di-cover case lain (seperti `else`)

#### Fall-through — Fitur atau Bug?

```c
int hari = 3;

switch (hari) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        printf("Hari kerja\n");  /* Case 1-5 "jatuh" ke sini */
        break;
    case 6:
    case 7:
        printf("Weekend!\n");
        break;
    default:
        printf("Hari tidak valid\n");
        break;
}
```

Fall-through bisa jadi **fitur** kalau dipakai dengan sengaja (seperti di atas). Tapi kalau tidak sengaja lupa `break`, itu **bug**.

```c
/* ❌ BUG — lupa break! */
switch (grade) {
    case 'A':
        printf("Excellent!\n");
        /* LUPA BREAK — jatuh ke case B! */
    case 'B':
        printf("Good!\n");
        break;
}
/* Kalau grade = 'A', output: "Excellent!" DAN "Good!" */
```

### 7. `switch` vs `if-else` — Kapan Pakai Yang Mana?

| Aspek | `switch` | `if-else` |
|-------|----------|-----------|
| Tipe ekspresi | Hanya `int` / `char` | Apapun (int, float, string, complex condition) |
| Kondisi | Hanya `== nilai` | Bisa `>`, `<`, `>=`, `&&`, `||`, dll. |
| Readability | ✅ Lebih rapi untuk banyak nilai | Bisa panjang untuk banyak nilai |
| Performance | ⚡ Bisa dioptimasi compiler (jump table) | Dievaluasi satu per satu |
| Use-case | Menu, state machine, opcode | Range checking, complex conditions |

```c
/* ✅ Cocok untuk switch: nilai diskrit terbatas */
switch (menu_choice) { ... }

/* ✅ Cocok untuk if-else: range atau kondisi kompleks */
if (nilai >= 90) { ... }
else if (nilai >= 80 && kehadiran > 75) { ... }
```

### 8. Ternary Operator (`? :`)

One-liner conditional — pengganti `if-else` sederhana:

```c
/* Syntax: kondisi ? nilai_jika_true : nilai_jika_false */

int umur = 20;
char *status = (umur >= 17) ? "Dewasa" : "Anak-anak";
printf("%s\n", status);   /* Output: Dewasa */

/* Sama dengan: */
char *status;
if (umur >= 17) {
    status = "Dewasa";
} else {
    status = "Anak-anak";
}
```

**Kapan pakai ternary?**

```c
/* ✅ BAGUS — sederhana, satu baris */
int max = (a > b) ? a : b;
printf("Status: %s\n", (online) ? "Online" : "Offline");

/* ❌ BURUK — terlalu kompleks, pindah ke if-else */
int result = (a > b) ? ((c > d) ? c : d) : ((e > f) ? e : f);
/* Siapa yang paham ini? Tidak ada. */
```

> **Best practice:** Ternary hanya untuk ekspresi sederhana (1 kondisi, 2 nilai). Kalau nested ternary, **JANGAN** — pakai if-else biasa.

### 9. Boolean di C — `<stdbool.h>`

C99 memperkenalkan `<stdbool.h>` untuk tipe boolean yang lebih ekspresif:

```c
#include <stdbool.h>

bool is_active = true;    /* true = 1 */
bool is_admin = false;    /* false = 0 */

if (is_active && is_admin) {
    printf("Admin aktif!\n");
}
```

Tanpa `<stdbool.h>`, programmer C biasanya pakai:
```c
/* Konvensi lama (masih sering ditemui) */
#define TRUE  1
#define FALSE 0
int is_active = TRUE;
```

> `<stdbool.h>` lebih disarankan karena lebih readable dan standar.

### 10. Conditional Compilation Preview

Ini preview — akan dibahas mendalam di modul 010 (Preprocessor):

```c
#define DEBUG 1

#if DEBUG
    printf("[DEBUG] nilai x = %d\n", x);
#endif
```

Ini bukan if-else biasa — ini **preprocessor directive** yang menentukan kode mana yang **masuk ke compiler**. Kode di dalam `#if 0 ... #endif` bahkan tidak di-compile.

---

## ⚠️ Perangkap Umum (Common Pitfalls)

### 1. Assignment vs Comparison (Lagi!)

```c
int x = 5;

/* ❌ BUG KLASIK — assignment, bukan comparison! */
if (x = 10) {     /* x DIUBAH jadi 10, lalu 10 = true → selalu masuk */
    printf("Ini selalu dicetak!\n");
}

/* ✅ BENAR */
if (x == 10) {
    printf("x adalah 10\n");
}
```

### 2. Lupa Kurung Kurawal `{}`

```c
int x = 5;

/* ❌ BERBAHAYA — tanpa {}, hanya statement PERTAMA yang masuk if */
if (x > 10)
    printf("x lebih dari 10\n");
    printf("Ini SELALU dicetak!\n");   /* Ini BUKAN bagian dari if! */

/* ✅ SELALU pakai {} walaupun cuma 1 statement */
if (x > 10) {
    printf("x lebih dari 10\n");
    printf("Ini juga hanya dicetak kalau x > 10\n");
}
```

> **Best practice:** SELALU pakai `{}` bahkan untuk if satu baris. Ini mencegah bug saat menambahkan statement baru.

### 3. Dangling Else

```c
/* ❌ Ambigu — else milik if yang mana? */
if (a > 0)
    if (b > 0)
        printf("Keduanya positif\n");
else
    printf("a negatif? Atau b negatif?\n");

/* 
 * Jawaban: else milik if TERDEKAT (if (b > 0)), bukan if (a > 0)!
 * Compiler menafsirkan:
 */
if (a > 0) {
    if (b > 0)
        printf("Keduanya positif\n");
    else                                /* Milik if (b > 0) */
        printf("a positif, b negatif\n");
}

/* ✅ Selalu pakai {} untuk menghindari ambiguitas */
```

### 4. Lupa `break` di Switch

```c
/* ❌ Fall-through tidak disengaja */
char grade = 'A';
switch (grade) {
    case 'A':
        printf("Excellent!\n");
        /* LUPA break! */
    case 'B':
        printf("Good!\n");
        break;
}
/* Output: "Excellent!" DAN "Good!" — bukan yang diinginkan */
```

### 5. Membandingkan Float dengan `==`

```c
double a = 0.1 + 0.2;

/* ❌ Mungkin false! Floating-point tidak presisi */
if (a == 0.3) {
    printf("Sama!\n");
}
/* 0.1 + 0.2 sebenarnya = 0.30000000000000004 (IEEE 754 rounding) */

/* ✅ Bandingkan dengan epsilon (toleransi kecil) */
double epsilon = 0.0001;
if (a - 0.3 < epsilon && 0.3 - a < epsilon) {
    printf("Kira-kira sama!\n");
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

Lihat file `exercise.c` untuk 3 latihan:

| Level | Deskripsi |
|-------|-----------|
| 🟢 EASY | Kalkulator grade: input nilai (0-100), output grade (A/B/C/D/F) dengan if-else |
| 🟡 MEDIUM | Menu ATM interaktif: pilih menu (cek saldo/tarik/setor) dengan switch-case |
| 🔴 HARD | Sistem tiket bioskop: hitung harga berdasarkan umur, hari, tipe kursi, membership |

---

## 🔗 Lanjut ke

**[006 — Perulangan →](../006-perulangan/)**

🎉 **Selamat! Lu sudah menyelesaikan Fase 1: Fondasi.** Dari sini lu sudah bisa bikin program C sederhana yang menerima input, memproses data, dan menghasilkan output berdasarkan kondisi. Lanjut ke Fase 2 untuk belajar loop, array, dan string!
