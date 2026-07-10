# 004 — Input/Output

**Fase:** 1 · Fondasi | **Prasyarat:** [003 — Operator](../003-operator/) | **Estimasi waktu:** 4-5 jam

---

## 🎯 Tujuan Belajar

- Bisa menggunakan **semua format specifier** `printf()` termasuk width, precision, dan flags
- Bisa menggunakan `scanf()` dengan benar dan paham **cara kerjanya di level buffer**
- Bisa menjelaskan dan mengatasi **buffer/newline problem** klasik di C
- Bisa membedakan **`fgets()` vs `scanf()`** dan tahu kapan pakai yang mana
- Bisa menggunakan fungsi I/O lain: `getchar()`, `putchar()`, `puts()`

---

## 📖 Konsep Inti

### 1. `printf()` Deep Dive

`printf()` = **print formatted** — fungsi paling sering dipakai di C untuk menampilkan output ke terminal (stdout).

#### Syntax Format Specifier

```
%[flags][width][.precision][length]specifier
```

Setiap bagian:

| Komponen | Contoh | Penjelasan |
|----------|--------|------------|
| `%` | — | Penanda awal format specifier |
| flags | `-`, `+`, `0`, ` ` | Modifikasi tampilan |
| width | `10` | Lebar minimum field |
| .precision | `.2` | Jumlah digit desimal / max karakter |
| length | `l`, `ll`, `h` | Modifikasi ukuran tipe data |
| specifier | `d`, `f`, `s`, `c` | Tipe data yang dicetak |

#### Semua Specifier

| Specifier | Tipe | Contoh |
|-----------|------|--------|
| `%d` / `%i` | `int` (desimal) | `printf("%d", 42);` → `42` |
| `%u` | `unsigned int` | `printf("%u", 42U);` → `42` |
| `%o` | `unsigned int` (oktal) | `printf("%o", 255);` → `377` |
| `%x` / `%X` | `unsigned int` (hex) | `printf("%x", 255);` → `ff` |
| `%f` | `double` / `float` | `printf("%f", 3.14);` → `3.140000` |
| `%e` / `%E` | `double` (scientific) | `printf("%e", 3.14);` → `3.140000e+00` |
| `%g` / `%G` | `double` (auto) | Pilih `%f` atau `%e` yang lebih pendek |
| `%c` | `char` | `printf("%c", 'A');` → `A` |
| `%s` | `char*` (string) | `printf("%s", "Halo");` → `Halo` |
| `%p` | pointer (alamat) | `printf("%p", &x);` → `0x7ffd...` |
| `%zu` | `size_t` | `printf("%zu", sizeof(int));` → `4` |
| `%ld` | `long` | `printf("%ld", 3000000000L);` |
| `%lld` | `long long` | `printf("%lld", 9000000000000LL);` |
| `%Lf` | `long double` | `printf("%Lf", 3.14L);` |
| `%%` | literal `%` | `printf("100%%");` → `100%` |

#### Flags

| Flag | Efek | Contoh | Output |
|------|------|--------|--------|
| `-` | Rata kiri | `printf("%-10d!", 42);` | `42        !` |
| `+` | Selalu tampilkan tanda +/- | `printf("%+d", 42);` | `+42` |
| `0` | Pad dengan nol | `printf("%05d", 42);` | `00042` |
| ` ` (spasi) | Spasi di depan bilangan positif | `printf("% d", 42);` | ` 42` |
| `#` | Alternate form | `printf("%#x", 255);` | `0xff` |

#### Width & Precision

```c
/* Width: lebar minimum field */
printf("[%10d]\n", 42);       /* [        42] — rata kanan (default) */
printf("[%-10d]\n", 42);      /* [42        ] — rata kiri (flag -) */

/* Precision untuk float: jumlah digit setelah koma */
printf("[%.2f]\n", 3.14159);  /* [3.14] — 2 digit desimal */
printf("[%.0f]\n", 3.14159);  /* [3]    — tanpa desimal */
printf("[%8.2f]\n", 3.14);    /* [    3.14] — width 8, 2 desimal */

/* Precision untuk string: max karakter */
printf("[%.5s]\n", "Hello World");  /* [Hello] — potong 5 karakter */

/* Kombinasi width + precision */
printf("[%-10.3f]\n", 3.14);  /* [3.140     ] — rata kiri, 3 desimal, width 10 */
```

> **Real world:** Format specifier dipakai untuk bikin tabel/laporan di terminal. Contoh: `printf("%-20s %10.2f\n", nama, harga);` untuk membuat tabel produk yang rapi.

### 2. `scanf()` Deep Dive

`scanf()` = **scan formatted** — membaca input dari keyboard (stdin).

#### Syntax Dasar

```c
int umur;
printf("Umur: ");
scanf("%d", &umur);    /* WAJIB pakai & (address-of) untuk tipe primitif */

char nama[50];
printf("Nama: ");
scanf("%s", nama);     /* String (char[]) TIDAK pakai & */
```

#### Kenapa `&` di `scanf()`?

> **Analogi:** `scanf()` itu kurir yang mau antar paket ke rumah lu. Dia butuh **ALAMAT rumah** lu, bukan isi rumah lu. Simbol `&` artinya "alamat dari".
>
> - `&umur` = "alamat kotak `umur` di memori" → kurir tahu mau naruh di mana
> - `umur` (tanpa &) = "ISI kotak `umur`" → kurir bingung, ini bukan alamat!
>
> Khusus `char[]` (array): nama array **sudah otomatis jadi alamat** elemen pertamanya (ini fitur spesial array di C), jadi tidak perlu `&`.

#### Return Value `scanf()`

`scanf()` mengembalikan **jumlah item yang berhasil dibaca**. Ini berguna untuk validasi:

```c
int x;
int result = scanf("%d", &x);
if (result == 1) {
    printf("Berhasil baca: %d\n", x);
} else {
    printf("Input tidak valid! (bukan angka)\n");
}

/* Membaca multiple value */
int a, b;
result = scanf("%d %d", &a, &b);
if (result == 2) {
    printf("Berhasil baca 2 angka: %d dan %d\n", a, b);
} else {
    printf("Gagal baca! Hanya berhasil %d item.\n", result);
}
```

#### `scanf()` dan Whitespace

`scanf("%d", ...)` otomatis **skip whitespace** (spasi, tab, newline) sebelum angka. Tapi ada gotcha untuk `%c`:

```c
int angka;
char huruf;

printf("Angka: ");
scanf("%d", &angka);    /* User ketik: 42↵ (enter) */
/* Buffer stdin sekarang: '\n' (sisa enter) */

printf("Huruf: ");
scanf("%c", &huruf);    /* ❌ Langsung "makan" '\n' dari buffer! */
/* huruf = '\n', BUKAN input user! */
```

**Solusi: taruh spasi sebelum `%c`:**
```c
scanf(" %c", &huruf);   /* Spasi sebelum %c = skip whitespace dulu */
/* Sekarang huruf = input user yang benar ✅ */
```

### 3. Buffer Problem — Masalah Klasik C

#### Apa itu Buffer (stdin)?

> **Analogi:** Buffer itu kayak **antrian di kasir**. Setiap kali lu ngetik di keyboard lalu tekan Enter, semua karakter (termasuk Enter/newline) masuk ke antrian. `scanf()` ambil dari depan antrian sesuai format yang diminta. Kalau ada sisa di antrian (misal karakter Enter), fungsi berikutnya yang baca input bisa "kebagian" sisa itu.

#### Skenario Bermasalah

```c
int umur;
char nama[50];

printf("Umur: ");
scanf("%d", &umur);     /* User ketik: 25↵ */
/* scanf ambil "25", tapi '\n' (Enter) MASIH di buffer */

printf("Nama: ");
fgets(nama, 50, stdin); /* ❌ Langsung ambil '\n' dari buffer! */
/* nama = "\n" — user tidak sempat mengetik! */
```

#### Solusi: Bersihkan Buffer

**Cara 1: `scanf(" %c", ...)` dengan spasi**
```c
scanf(" %c", &ch);  /* Spasi = skip semua whitespace sebelum baca */
```

**Cara 2: Loop pembersihan (paling robust)**
```c
/* Bersihkan semua karakter tersisa di buffer sampai newline */
int c;
while ((c = getchar()) != '\n' && c != EOF) {
    /* Kosongkan buffer */
}
```

**Cara 3: Letakkan `getchar()` setelah `scanf()`**
```c
scanf("%d", &umur);
getchar();              /* "Makan" newline sisa */
fgets(nama, 50, stdin); /* Sekarang bisa baca input user ✅ */
```

> **Best practice:** Untuk input teks (string), lebih baik selalu pakai `fgets()` dari awal dan hindari `scanf("%s", ...)`. Kenapa? Lihat poin berikutnya.

### 4. `fgets()` vs `scanf("%s")` — Kapan Pakai Yang Mana?

| Aspek | `scanf("%s", buf)` | `fgets(buf, size, stdin)` |
|-------|-------------------|---------------------------|
| Membaca spasi | ❌ Berhenti di spasi | ✅ Baca sampai Enter |
| Buffer overflow | ⚠️ Rawan (kalau tidak pakai width) | ✅ Aman (ada limit `size`) |
| Menyimpan `\n` | ❌ Tidak | ✅ Ya (perlu dihapus manual) |
| Keamanan | ⚠️ Butuh `%49s` (width limit) | ✅ Lebih aman by default |

```c
char input[50];

/* scanf BERHENTI di spasi! */
printf("Nama lengkap: ");
scanf("%s", input);           /* User ketik: "John Doe" */
printf("Hasil: [%s]\n", input);  /* Output: [John] — "Doe" hilang! */

/* fgets membaca SELURUH baris termasuk spasi */
printf("Nama lengkap: ");
fgets(input, sizeof(input), stdin);  /* User ketik: "John Doe" */
/* input = "John Doe\n" — ada newline di akhir! */
```

**Menghapus newline dari `fgets()`:**
```c
#include <string.h>

fgets(input, sizeof(input), stdin);
/* Hapus '\n' di akhir (kalau ada) */
input[strcspn(input, "\n")] = '\0';
/* strcspn() mencari posisi pertama '\n' di string */
```

> **Rekomendasi:** Untuk baca teks, **SELALU pakai `fgets()`**. Untuk baca angka, `scanf("%d", ...)` masih OK.

### 5. `scanf("%s")` — Bahaya Buffer Overflow

```c
char buf[10];
scanf("%s", buf);   /* User ketik 50 karakter → OVERFLOW! */
/* Menulis melewati batas buf → Undefined Behavior, bisa crash */

/* Solusi: batasi dengan width */
scanf("%9s", buf);  /* Maksimal baca 9 karakter (sisakan 1 untuk '\0') */
```

> **JANGAN PERNAH** pakai `gets()`:
> ```c
> gets(buf);   /* ⛔ DILARANG! Tidak ada batas baca → buffer overflow guaranteed */
> ```
> `gets()` sudah di-**remove** dari standar C11 karena tidak bisa dibuat aman. Tidak ada cara untuk membatasi jumlah karakter yang dibaca. Pakai `fgets()` saja.

### 6. Fungsi I/O Lainnya

#### `getchar()` dan `putchar()`

```c
/* getchar() — baca SATU karakter dari stdin */
printf("Tekan sembarang tombol: ");
int ch = getchar();         /* Return type int, bukan char! (untuk EOF) */
printf("Lu tekan: ");
putchar(ch);                /* putchar() — cetak SATU karakter ke stdout */
putchar('\n');
```

> **Kenapa `getchar()` return `int`?** Karena `getchar()` harus bisa membedakan antara karakter valid (0-255) dan **EOF** (End Of File, biasanya -1). Kalau return `char`, tidak bisa membedakan `EOF` dari karakter `'\xff'`.

#### `puts()`

```c
puts("Hello World");    /* Otomatis tambah newline di akhir */
/* Sama dengan: printf("Hello World\n"); */
/* Tapi puts() TIDAK bisa format specifier (%d, %s, dll.) */
```

### 7. Hexadecimal dan Octal Output

```c
int nilai = 255;

printf("Desimal : %d\n", nilai);    /* 255 */
printf("Oktal   : %o\n", nilai);    /* 377 */
printf("Hex     : %x\n", nilai);    /* ff */
printf("HEX     : %X\n", nilai);    /* FF */
printf("Hex 0x  : %#x\n", nilai);   /* 0xff (dengan prefix) */
printf("Oktal 0 : %#o\n", nilai);   /* 0377 (dengan prefix) */
```

### 8. `sprintf()` dan `snprintf()` — Print ke String

Bukan ke layar, tapi ke variabel string:

```c
char pesan[100];

/* sprintf — HATI-HATI buffer overflow! */
sprintf(pesan, "Halo, %s! Umur: %d", "Admiral", 25);
printf("%s\n", pesan);   /* Output: Halo, Admiral! Umur: 25 */

/* snprintf — LEBIH AMAN, ada batas size */
snprintf(pesan, sizeof(pesan), "Skor: %d/%d (%.1f%%)", 85, 100, 85.0);
printf("%s\n", pesan);   /* Output: Skor: 85/100 (85.0%) */
```

> **Best practice:** Selalu pakai `snprintf()` daripada `sprintf()` untuk menghindari buffer overflow. Kebiasaan ini akan berguna saat masuk ke programming yang lebih serius.

---

## ⚠️ Perangkap Umum (Common Pitfalls)

### 1. Lupa `&` di `scanf()` untuk Tipe Primitif

```c
int x;
scanf("%d", x);     /* ❌ CRASH atau UB! x berisi garbage, bukan alamat */
scanf("%d", &x);    /* ✅ Benar — kirim ALAMAT x ke scanf */
```

Compiler modern biasanya kasih warning untuk ini, tapi bisa jadi **tidak crash langsung** — hasilnya diam-diam salah.

### 2. Pakai `%d` untuk `double`

```c
double pi = 3.14;
printf("%d\n", pi);    /* ❌ UB! %d untuk int, bukan double */
printf("%f\n", pi);    /* ✅ Benar */

/* Di scanf, double HARUS pakai %lf (bukan %f!) */
double x;
scanf("%f", &x);       /* ❌ %f untuk float di scanf! */
scanf("%lf", &x);      /* ✅ %lf untuk double di scanf */
```

> **Catatan perbedaan `printf` vs `scanf`:**
> - `printf`: `float` otomatis dipromosi ke `double`, jadi `%f` bekerja untuk keduanya
> - `scanf`: `float` dan `double` **BERBEDA** — `%f` untuk `float*`, `%lf` untuk `double*`

### 3. `fgets()` Menyimpan Newline

```c
char nama[50];
fgets(nama, 50, stdin);   /* User ketik "Admiral" lalu Enter */
printf("Halo, %s!\n", nama);
/* Output:
   Halo, Admiral
   !
   (ada baris kosong karena \n di dalam nama!)
*/

/* Fix: hapus newline */
nama[strcspn(nama, "\n")] = '\0';
printf("Halo, %s!\n", nama);   /* Output: Halo, Admiral! ✅ */
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
| 🟢 EASY | Baca nama, umur, tinggi dari user dan cetak dengan format rapi (tabel) |
| 🟡 MEDIUM | Mini program "profil karakter game" — baca multiple input, handle buffer, cetak kartu karakter |
| 🔴 HARD | Buat receipt/struk belanja: baca nama barang & harga, cetak struk dengan format rapi (alignment, total, pajak) |

---

## 🔗 Lanjut ke

**[005 — Percabangan →](../005-percabangan/)**
