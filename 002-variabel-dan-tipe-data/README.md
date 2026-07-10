# 002 — Variabel & Tipe Data

**Fase:** 1 · Fondasi | **Prasyarat:** [001 — Pengenalan C](../001-pengenalan-c/) | **Estimasi waktu:** 4-5 jam

---

## 🎯 Tujuan Belajar

- Bisa menjelaskan **apa itu variabel** dan bagaimana data disimpan di memori
- Bisa menggunakan **semua tipe data primitif** C: `int`, `float`, `double`, `char`, `short`, `long`, `unsigned`
- Bisa menggunakan `sizeof()` untuk mengetahui ukuran setiap tipe data dalam byte
- Bisa membedakan **deklarasi vs inisialisasi** dan paham bahaya variabel yang belum diinisialisasi
- Bisa menggunakan **konstanta** (`const` dan `#define`) dan paham kapan pakai yang mana

---

## 📖 Konsep Inti

### 1. Apa Itu Variabel?

> **Analogi:** Variabel itu kayak **kotak penyimpanan berlabel** di gudang. Setiap kotak punya:
> 1. **Nama** (label kotak) — supaya lu bisa nemuin lagi
> 2. **Tipe** (ukuran kotak) — menentukan apa yang bisa disimpan dan seberapa besar
> 3. **Nilai** (isi kotak) — data yang sebenarnya disimpan
> 4. **Alamat** (lokasi rak di gudang) — di mana kotak itu berada di memori

Di level mesin, variabel itu cuma **sejumlah byte di RAM** yang dikasih nama supaya manusia bisa akses tanpa harus ingat alamat memori (misal `0x7ffd9a12bc40`).

```c
int umur = 25;
//  ^    ^   ^
//  |    |   └── Nilai (value): 25
//  |    └────── Nama: umur
//  └─────────── Tipe: int (integer, 4 byte di kebanyakan sistem)
```

### 2. Deklarasi vs Inisialisasi

Ini dua konsep yang sering dicampur pemula:

```c
// DEKLARASI — bikin kotak kosong, belum diisi
int umur;

// INISIALISASI — isi kotak untuk pertama kalinya
umur = 25;

// DEKLARASI + INISIALISASI sekaligus (RECOMMENDED!)
int umur = 25;
```

**Kenapa harus inisialisasi?**

Di C, variabel yang hanya dideklarasi tanpa diinisialisasi mengandung **garbage value** — nilai random yang sudah ada di memori dari program sebelumnya. Ini bukan nol, ini literal sampah.

```c
int x;           // x = ??? (bisa 0, bisa -184629, bisa apa aja)
printf("%d", x); // Undefined Behavior! Output-nya unpredictable
```

> **Best practice:** SELALU inisialisasi variabel saat deklarasi. Ini salah satu aturan paling penting di C.

### 3. Semua Tipe Data Primitif C

#### 3a. Integer Types (Bilangan Bulat)

| Tipe | Ukuran (typical) | Range | Kapan Pakai |
|------|-------------------|-------|-------------|
| `char` | 1 byte | -128 s.d. 127 | Karakter ASCII, flag kecil |
| `short` | 2 byte | -32,768 s.d. 32,767 | Jarang dipakai, hemat memori |
| `int` | 4 byte | -2,147,483,648 s.d. 2,147,483,647 | **Default untuk bilangan bulat** |
| `long` | 4-8 byte | Minimal sama dengan `int` | Bilangan besar |
| `long long` | 8 byte | ±9.2 × 10^18 | Bilangan SANGAT besar |

> **Catatan penting:** Ukuran `int`, `long`, dll. **tidak dijamin sama** di semua platform. Standar C hanya menjamin minimum:
> - `short` ≥ 16 bit
> - `int` ≥ 16 bit
> - `long` ≥ 32 bit
> - `long long` ≥ 64 bit
>
> Di kebanyakan sistem modern (64-bit), `int` = 4 byte dan `long` = 8 byte (Linux/macOS) atau 4 byte (Windows). Selalu pakai `sizeof()` kalau butuh kepastian.

#### 3b. `unsigned` — Bilangan Non-Negatif

Menambahkan `unsigned` di depan tipe integer membuat variabel hanya bisa menyimpan **bilangan >= 0**, tapi range positifnya jadi **2x lipat**:

```c
int            biasa  = -100;    // Range: -2.1M s.d. +2.1M
unsigned int   positif = 100;    // Range: 0 s.d. +4.2M (2x lipat!)
```

| Tipe | Range |
|------|-------|
| `unsigned char` | 0 s.d. 255 |
| `unsigned short` | 0 s.d. 65,535 |
| `unsigned int` | 0 s.d. 4,294,967,295 |
| `unsigned long long` | 0 s.d. 18,446,744,073,709,551,615 |

> **Kapan pakai `unsigned`?** Ketika nilainya **pasti tidak negatif**: jumlah barang, ukuran file, index array. Tapi hati-hati — `unsigned` bisa bikin bug halus (lihat Perangkap Umum).

#### 3c. Floating-Point Types (Bilangan Desimal)

| Tipe | Ukuran | Presisi | Kapan Pakai |
|------|--------|---------|-------------|
| `float` | 4 byte | ~6-7 digit | Jarang dipakai langsung (presisi rendah) |
| `double` | 8 byte | ~15-16 digit | **Default untuk bilangan desimal** |
| `long double` | 8-16 byte | ~18-21 digit | Komputasi ilmiah presisi tinggi |

```c
float  ipk_float  = 3.75f;    // 'f' suffix = literal float
double ipk_double = 3.75;     // Tanpa suffix = default double
long double pi_hd = 3.14159265358979323846L;  // 'L' suffix
```

> **Kenapa `double` bukan `float`?** Karena `float` cuma presisi 6-7 digit. Untuk kebanyakan aplikasi, `double` lebih aman. Dalam standar C, literal desimal seperti `3.14` itu tipenya `double`, bukan `float`.

> **Analogi floating-point:** Bayangkan kalkulator yang cuma bisa tampilkan 7 digit. Angka `1234567.89` akan dibulatkan jadi `1234568.0`. Itulah kenapa `float` bisa "kehilangan" angka di belakang koma.

#### 3d. `char` — Karakter

`char` sebenarnya adalah **integer kecil (1 byte)** yang merepresentasikan karakter ASCII:

```c
char huruf = 'A';          // Karakter literal (pakai single quotes)
char huruf_angka = 65;     // Sama saja! 65 = 'A' di tabel ASCII

printf("%c\n", huruf);     // Output: A (cetak sebagai karakter)
printf("%d\n", huruf);     // Output: 65 (cetak sebagai angka)
```

**Tabel ASCII penting:**
| Karakter | Kode ASCII | Catatan |
|----------|-----------|---------|
| `'0'` - `'9'` | 48 - 57 | Karakter digit (bukan angka!) |
| `'A'` - `'Z'` | 65 - 90 | Huruf besar |
| `'a'` - `'z'` | 97 - 122 | Huruf kecil |
| `' '` (spasi) | 32 | |
| `'\n'` | 10 | Newline |
| `'\0'` | 0 | Null terminator (akhir string) |

> **Trik:** Konversi huruf kecil → besar: `'a' - 32 = 'A'`. Ini karena selisih ASCII antara huruf kecil dan besar selalu 32.

#### 3e. String (Array of `char`) — Preview

String di C **bukan** tipe data primitif. String adalah **array (deretan) dari `char`** yang diakhiri null character `'\0'`:

```c
char nama[50] = "Admiral";
// Di memori: ['A']['d']['m']['i']['r']['a']['l']['\0']...
//             ^0   ^1   ^2   ^3   ^4   ^5   ^6   ^7

char greeting[] = "Halo";   // Compiler otomatis hitung ukuran (5 byte: H,a,l,o,\0)
```

String akan dibahas mendalam di **modul 008**. Di sini cukup tahu bahwa string = `char[]` + `'\0'`.

### 4. `sizeof()` — Ukuran Tipe Data

`sizeof()` mengembalikan **ukuran dalam byte** dari tipe data atau variabel:

```c
printf("sizeof(char)      = %zu byte\n", sizeof(char));       // 1
printf("sizeof(short)     = %zu byte\n", sizeof(short));      // 2
printf("sizeof(int)       = %zu byte\n", sizeof(int));        // 4
printf("sizeof(long)      = %zu byte\n", sizeof(long));       // 4 atau 8
printf("sizeof(long long) = %zu byte\n", sizeof(long long));  // 8
printf("sizeof(float)     = %zu byte\n", sizeof(float));      // 4
printf("sizeof(double)    = %zu byte\n", sizeof(double));     // 8
```

> **Format specifier `%zu`:** Ini khusus untuk tipe `size_t` (tipe return dari `sizeof`). Pakai `%zu`, bukan `%d` atau `%ld` — ini bisa bikin warning. Akan dibahas lebih lanjut di modul 004 (I/O).

### 5. Type Casting (Konversi Tipe)

#### 5a. Implicit Casting (Otomatis)

Compiler otomatis mengkonversi tipe data yang lebih kecil ke tipe yang lebih besar. Ini aman (tidak kehilangan data):

```c
int    bilangan_bulat = 42;
double bilangan_desimal = bilangan_bulat;  // int → double otomatis
// bilangan_desimal = 42.000000 ✅ aman

char   huruf = 'A';      // 'A' = 65
int    kode  = huruf;    // char → int otomatis
// kode = 65 ✅ aman
```

Urutan promosi (kecil → besar, aman):
```
char → short → int → long → long long → float → double → long double
```

#### 5b. Explicit Casting (Manual)

Konversi dari tipe besar ke kecil **bisa kehilangan data**. Compiler akan kasih warning kecuali lu secara eksplisit "memaksa" konversi:

```c
double pi = 3.14159;
int    pi_bulat = (int)pi;     // Explicit cast: double → int
// pi_bulat = 3 (bagian desimal HILANG, bukan dibulatkan!)

int besar = 300;
char kecil = (char)besar;      // int → char: OVERFLOW! 
// 300 > 127 (max signed char), hasilnya UNPREDICTABLE
```

> **Best practice:** Kalau lu butuh explicit cast, itu **warning sign** bahwa mungkin ada masalah logika di kode lu. Tanya diri sendiri: "Kenapa gua perlu konversi ini?"

### 6. Integer Overflow & Underflow

Apa yang terjadi kalau nilai melebihi kapasitas tipe data?

```c
#include <limits.h>   // Berisi konstanta batas tipe data

int max = INT_MAX;    // 2,147,483,647
printf("%d\n", max);      // Output: 2147483647
printf("%d\n", max + 1);  // Output: -2147483648 — OVERFLOW!
// Nilainya "wrap around" dari positif terbesar ke negatif terkecil
```

> **Analogi:** Bayangkan odometer mobil yang mentok di 999999. Kalau ditambah 1 lagi, dia balik ke 000000. Itulah overflow.

**BAHAYA:** Signed integer overflow adalah **Undefined Behavior** di C! Compiler boleh melakukan **APA PUN** — crash, diam-diam kasih hasil salah, atau bahkan menghapus kode lu (serius — compiler bisa mengoptimasi kode berdasarkan asumsi bahwa UB tidak terjadi).

```c
// Unsigned integer overflow TERDEFINISI (wrap around)
unsigned int u = UINT_MAX;   // 4,294,967,295
printf("%u\n", u + 1);       // Output: 0 (terdefinisi, aman)

// Signed integer overflow = UNDEFINED BEHAVIOR (UB)
int s = INT_MAX;
printf("%d\n", s + 1);       // UB! Compiler boleh kasih hasil apa saja
```

### 7. Konstanta — Nilai yang Tidak Boleh Berubah

#### 7a. `const` (Runtime Constant)

```c
const int MAX_SISWA = 40;
const double PI = 3.14159265358979;

MAX_SISWA = 50;  // ❌ COMPILE ERROR — const tidak bisa diubah
```

#### 7b. `#define` (Preprocessor Macro)

```c
#define MAX_BUFFER 1024
#define PI 3.14159265358979

// Sebelum compile, preprocessor MENGGANTI semua "MAX_BUFFER" dengan "1024"
// Jadi: int buffer[MAX_BUFFER]; → int buffer[1024];
int buffer[MAX_BUFFER];
```

#### Kapan pakai `const` vs `#define`?

| Aspek | `const` | `#define` |
|-------|---------|-----------|
| Tipe data | Punya tipe (type-safe) | Tidak punya tipe (text replacement) |
| Scope | Mengikuti scope `{}` | Global dari titik definisi sampai akhir file |
| Debugging | Muncul di debugger | Tidak muncul (sudah diganti saat preprocessing) |
| Rekomendasi | ✅ Lebih disarankan | Untuk ukuran array dan conditional compilation |

> **Best practice:** Pakai `const` untuk konstanta dengan tipe data jelas. Pakai `#define` untuk ukuran array (`#define MAX_BUFFER 1024`) dan conditional compilation (`#ifdef DEBUG`).

### 8. Scope Dasar (Cakupan Variabel)

Variabel di C hanya "hidup" di dalam blok `{}` tempat dia dideklarasi:

```c
int main(void) {
    int x = 10;        // x hidup di seluruh main()

    {
        int y = 20;    // y HANYA hidup di dalam blok ini
        printf("%d %d\n", x, y);  // ✅ OK: x dan y bisa diakses
    }

    printf("%d\n", x); // ✅ OK: x masih hidup
    printf("%d\n", y); // ❌ COMPILE ERROR: y sudah "mati"
}
```

> **Analogi:** Scope itu kayak ruangan di rumah. Variabel yang dideklarasi di ruang tamu bisa diakses dari seluruh rumah (outer scope). Tapi variabel di kamar mandi cuma bisa diakses di kamar mandi itu (inner scope).

### 9. Format Specifier untuk printf()

Setiap tipe data punya format specifier sendiri untuk `printf()`:

| Tipe | Format | Contoh |
|------|--------|--------|
| `int` | `%d` atau `%i` | `printf("%d", umur);` |
| `unsigned int` | `%u` | `printf("%u", count);` |
| `long` | `%ld` | `printf("%ld", big);` |
| `long long` | `%lld` | `printf("%lld", huge);` |
| `float` | `%f` | `printf("%f", ipk);` |
| `double` | `%f` atau `%lf` | `printf("%f", pi);` |
| `char` | `%c` | `printf("%c", huruf);` |
| `char[]` (string) | `%s` | `printf("%s", nama);` |
| `size_t` | `%zu` | `printf("%zu", sizeof(int));` |

> Detail format specifier akan dibahas mendalam di modul 004 (Input/Output).

### 10. Naming Convention

Di C, ada beberapa konvensi penamaan:

```c
// snake_case — STANDAR di C (dipakai di repo ini)
int total_siswa = 40;
float rata_rata_nilai = 85.5;

// camelCase — lebih umum di Java/JavaScript, JARANG di C
int totalSiswa = 40;

// SCREAMING_SNAKE_CASE — untuk konstanta dan macro
#define MAX_BUFFER_SIZE 1024
const int MAX_RETRY_COUNT = 3;
```

**Aturan penamaan variabel di C:**
- ✅ Boleh: huruf, angka, underscore (`_`)
- ✅ Harus diawali huruf atau underscore (bukan angka)
- ❌ Tidak boleh pakai spasi, tanda baca, atau karakter spesial
- ❌ Tidak boleh sama dengan keyword C (`int`, `return`, `if`, dll.)
- ❌ Hindari awalan `_` (konvensi reserved untuk compiler/system)

```c
int umur_user;     // ✅ Bagus — deskriptif
int u;             // ❌ Buruk — terlalu pendek, tidak jelas
int x1;            // ⚠️ OK untuk loop/math, buruk untuk data bisnis
int 2ndPlace;      // ❌ ERROR — diawali angka
int long;          // ❌ ERROR — 'long' adalah keyword C
```

---

## ⚠️ Perangkap Umum (Common Pitfalls)

### 1. Variabel Tidak Diinisialisasi

```c
// ❌ BAHAYA — garbage value!
int harga;
printf("Harga: %d\n", harga);   // Output: -1839462 (atau apapun)

// ✅ AMAN — selalu inisialisasi
int harga = 0;
printf("Harga: %d\n", harga);   // Output: 0
```

### 2. Integer Division (Pembagian Bulat)

```c
// ❌ Hasil yang tidak diharapkan
int a = 7;
int b = 2;
printf("%d\n", a / b);     // Output: 3 (bukan 3.5!)
// Pembagian int / int = int (bagian desimal DIBUANG)

// ✅ Solusi: cast salah satu ke double
printf("%f\n", (double)a / b);  // Output: 3.500000
```

### 3. Bug Halus `unsigned`

```c
unsigned int stok = 0;
stok = stok - 1;           // Harusnya -1, tapi unsigned tidak bisa negatif!
printf("%u\n", stok);       // Output: 4294967295 — WRAP AROUND ke max!

// Ini sering bikin bug di loop:
for (unsigned int i = 10; i >= 0; i--) {  
    // Loop TIDAK PERNAH BERHENTI!
    // Saat i = 0, i-- = 4294967295 (bukan -1), jadi i >= 0 selalu true
}
```

### 4. Salah Format Specifier

```c
int angka = 42;
printf("%f\n", angka);     // ❌ UB! %f untuk float/double, bukan int
printf("%d\n", angka);     // ✅ Benar

double pi = 3.14;
printf("%d\n", pi);        // ❌ UB! %d untuk int, bukan double
printf("%f\n", pi);        // ✅ Benar
```

Salah pakai format specifier adalah **Undefined Behavior** — bisa crash, bisa tampil angka aneh, bisa diam-diam "jalan" tapi hasilnya salah.

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
| 🟢 EASY | Deklarasi variabel berbagai tipe data, cetak nilainya, cetak sizeof-nya |
| 🟡 MEDIUM | Kalkulator konversi suhu (Celsius ↔ Fahrenheit) dengan casting yang benar |
| 🔴 HARD | Eksplorasi batas tipe data: demonstrasikan overflow, cetak batas dari `<limits.h>`, dan tunjukkan perbedaan signed vs unsigned |

---

## 🔗 Lanjut ke

**[003 — Operator →](../003-operator/)**
