# 008 — String

**Fase:** 2 · Kontrol & Struktur Data Dasar | **Prasyarat:** [007 — Array](../007-array/) | **Estimasi waktu:** 4-5 jam

---

## 🎯 Tujuan Belajar

- Memahami bahwa **string di C = array of `char`** yang diakhiri **null terminator `\0`**
- Bisa membedakan **string literal** (read-only) vs **char array** (mutable)
- Menguasai fungsi-fungsi **`string.h`**: `strlen`, `strcpy`/`strncpy`, `strcat`/`strncat`, `strcmp`, `strchr`/`strstr`, `strtok`, `snprintf`
- Bisa melakukan **manipulasi string manual** tanpa `string.h`
- Mengenali dan menghindari **buffer overflow** di operasi string
- Mengerti perbedaan `sizeof` vs `strlen`, dan kenapa `==` tidak bisa untuk membandingkan string

---

## 📖 Konsep Inti

### 1. String = Array of `char` + Null Terminator

> **Analogi:** String di C itu kayak **kereta api** — setiap gerbong adalah satu karakter, dan gerbong terakhir selalu **gerbong rem `\0`** yang menandai akhir kereta.

```c
// String literal — compiler otomatis tambah '\0'
char salam[] = "Halo";

// Di memori:
// Index:   0    1    2    3    4
// Isi  : ['H'] ['a'] ['l'] ['o'] ['\0']
// Size = 5 bytes (4 huruf + 1 null terminator)

printf("%s\n", salam);        // Halo
printf("%zu\n", sizeof(salam)); // 5 (termasuk '\0')
```

**Null terminator `\0`** (ASCII 0) adalah **penanda akhir string**. Semua fungsi string (`printf %s`, `strlen`, `strcpy`, dll) membaca karakter sampai ketemu `\0`.

```c
// Ini juga valid — inisialisasi manual per karakter
char manual[5] = {'H', 'a', 'l', 'o', '\0'};

// ❌ BAHAYA — tanpa '\0', bukan string yang valid!
char bukan_string[4] = {'H', 'a', 'l', 'o'};
printf("%s\n", bukan_string);   // Undefined behavior!
// printf terus baca memori sampai ketemu '\0' secara kebetulan
```

### 2. String Literal vs Char Array

```c
// Char array (MUTABLE) — isi bisa diubah
char arr[] = "Hello";
arr[0] = 'J';              // ✅ OK → "Jello"

// String literal via pointer (READ-ONLY)
char *ptr = "Hello";
ptr[0] = 'J';              // ❌ UNDEFINED BEHAVIOR! Crash!
```

**Kenapa?**
- `char arr[] = "Hello"` → compiler **copy** string ke stack (array), jadi bisa diubah
- `char *ptr = "Hello"` → `ptr` menunjuk ke **read-only memory** (biasanya segment `.rodata`)

> **Best practice:** Kalau tidak perlu diubah, pakai `const char *`:
> ```c
> const char *pesan = "Halo dunia";   // Jelas read-only
> ```

### 3. Input String — `scanf` vs `fgets`

```c
char nama[50];

/* scanf %s — BAHAYA: berhenti di whitespace, tidak cek buffer */
scanf("%s", nama);        // Input "John Doe" → nama = "John" saja!

/* scanf %49[^\n] — lebih baik, tapi masih ribet */
scanf("%49[^\n]", nama);  // Baca sampai newline, max 49 karakter

/* fgets — REKOMENDASI */
fgets(nama, sizeof(nama), stdin);
// ✅ Baca sampai newline ATAU sampai buffer penuh
// ⚠️ fgets MENYIMPAN '\n' di akhir (kalau muat)
```

**Menghapus newline dari `fgets`:**

```c
char input[100];
fgets(input, sizeof(input), stdin);

// Hapus trailing '\n' kalau ada
size_t len = strlen(input);
if (len > 0 && input[len - 1] == '\n') {
    input[len - 1] = '\0';
}
```

### 4. `string.h` — Fungsi String Standar

#### `strlen` — Hitung Panjang String

```c
#include <string.h>

char teks[] = "Hello";
size_t panjang = strlen(teks);     // 5 (TANPA hitung '\0')
printf("sizeof = %zu\n", sizeof(teks));  // 6 (DENGAN '\0')
printf("strlen = %zu\n", panjang);       // 5
```

> **`sizeof` vs `strlen`:**
> - `sizeof` → ukuran **memory** (termasuk `\0`)
> - `strlen` → panjang **string** (tanpa `\0`)

#### `strcpy` / `strncpy` — Copy String

```c
char src[] = "Hello World";
char dst[20];

/* strcpy — copy semua (BAHAYA kalau dst terlalu kecil!) */
strcpy(dst, src);     // dst = "Hello World"

/* strncpy — copy max n karakter (LEBIH AMAN) */
char dst2[6];
strncpy(dst2, src, sizeof(dst2) - 1);   // Copy max 5 karakter
dst2[sizeof(dst2) - 1] = '\0';          // WAJIB! strncpy tidak selalu tambah '\0'
// dst2 = "Hello"
```

> **⚠️ Trap `strncpy`:** Kalau `src` lebih pendek dari `n`, sisanya di-pad `\0`. Tapi kalau `src` lebih panjang atau sama dengan `n`, **`\0` TIDAK ditambahkan!** Selalu set manual.

#### `strcat` / `strncat` — Gabung (Concatenate) String

```c
char greeting[50] = "Hello";

/* strcat — gabung (BAHAYA kalau buffer tidak cukup!) */
strcat(greeting, ", ");
strcat(greeting, "World!");     // greeting = "Hello, World!"

/* strncat — lebih aman */
char buf[15] = "Hi";
strncat(buf, " there everyone!", sizeof(buf) - strlen(buf) - 1);
// buf = "Hi there ever" (terpotong, tapi aman)
```

#### `strcmp` — Bandingkan String

```c
char a[] = "apple";
char b[] = "banana";
char c[] = "apple";

/* strcmp return:
 *   0  → sama
 *   <0 → a datang sebelum b (lexicographic)
 *   >0 → a datang sesudah b
 */
printf("%d\n", strcmp(a, c));    //  0 (sama)
printf("%d\n", strcmp(a, b));    // <0 (apple < banana)
printf("%d\n", strcmp(b, a));    // >0 (banana > apple)

/* ❌ SALAH — ini membandingkan ALAMAT pointer, bukan isi string! */
if (a == c) { ... }    // Hampir selalu false!

/* ✅ BENAR */
if (strcmp(a, c) == 0) {
    printf("String sama!\n");
}
```

#### `strchr` / `strstr` — Cari Karakter / Substring

```c
char kalimat[] = "Hello, World!";

/* strchr — cari karakter pertama */
char *pos = strchr(kalimat, 'W');
if (pos != NULL) {
    printf("'W' ditemukan di index %ld\n", pos - kalimat);  // 7
    printf("Dari 'W' ke akhir: %s\n", pos);  // "World!"
}

/* strrchr — cari karakter TERAKHIR */
char *last = strrchr(kalimat, 'l');
printf("'l' terakhir di index %ld\n", last - kalimat);  // 10

/* strstr — cari substring */
char *sub = strstr(kalimat, "World");
if (sub != NULL) {
    printf("\"World\" ditemukan di index %ld\n", sub - kalimat);  // 7
}
```

#### `strtok` — Pecah String Jadi Token

> **⚠️ Hati-hati:** `strtok` **memodifikasi** string asli! Dia replace delimiter dengan `\0`.

```c
char data[] = "apple,banana,cherry,date";
char *token = strtok(data, ",");

while (token != NULL) {
    printf("  Token: %s\n", token);
    token = strtok(NULL, ",");   // Panggil dengan NULL untuk token berikutnya
}
// Output:
//   Token: apple
//   Token: banana
//   Token: cherry
//   Token: date

// ⚠️ data sekarang RUSAK: "apple\0banana\0cherry\0date"
```

#### `snprintf` — Format String ke Buffer (AMAN)

```c
char buf[50];
int skor = 95;
char nama[] = "Budi";

/* snprintf — seperti printf, tapi ke buffer string */
snprintf(buf, sizeof(buf), "%s mendapat skor %d", nama, skor);
printf("%s\n", buf);   // "Budi mendapat skor 95"

/* Keunggulan snprintf vs sprintf:
 * - snprintf TIDAK akan menulis melebihi buffer
 * - Return value = jumlah karakter yang AKAN ditulis (berguna untuk cek truncation)
 */
int written = snprintf(buf, 10, "Hello, World!");
printf("buf = \"%s\"\n", buf);     // "Hello, Wo" (terpotong)
printf("Would need %d chars\n", written);  // 13
```

### 5. Manipulasi String Manual (Tanpa string.h)

Memahami cara kerja string secara manual itu penting — ini dasar dari semua fungsi string.h.

```c
/* strlen manual */
int my_strlen(const char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

/* strcpy manual */
void my_strcpy(char *dst, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';   // Jangan lupa null terminator!
}

/* strcmp manual */
int my_strcmp(const char *a, const char *b) {
    while (*a && *a == *b) {
        a++;
        b++;
    }
    return *(unsigned char *)a - *(unsigned char *)b;
}
```

### 6. `sprintf` / `snprintf` untuk Konversi

```c
/* int ke string */
int angka = 42;
char str[20];
snprintf(str, sizeof(str), "%d", angka);   // str = "42"

/* Gabungin berbagai tipe */
char result[100];
snprintf(result, sizeof(result), "Nama: %s, Umur: %d, IPK: %.2f",
         "Andi", 21, 3.75);
// result = "Nama: Andi, Umur: 21, IPK: 3.75"
```

---

## ⚠️ Perangkap Umum (Common Pitfalls)

### 1. Lupa Null Terminator

```c
char buf[5];
buf[0] = 'H';
buf[1] = 'i';
// ❌ Lupa buf[2] = '\0'
printf("%s\n", buf);   // "Hi" + garbage sampai ketemu '\0' random

// ✅ Selalu akhiri dengan '\0'
buf[2] = '\0';
```

### 2. Buffer Overflow — Musuh #1 String di C

```c
char small[5];

/* ❌ "Hello World" = 11 karakter + '\0' = 12 bytes, tapi buffer cuma 5! */
strcpy(small, "Hello World");   // Buffer overflow! Menimpa memori lain!

/* ✅ Pakai strncpy atau snprintf */
strncpy(small, "Hello World", sizeof(small) - 1);
small[sizeof(small) - 1] = '\0';

/* ✅ Atau lebih simpel */
snprintf(small, sizeof(small), "Hello World");   // Otomatis truncate
```

> **Fun fact:** Buffer overflow di string C adalah salah satu vulnerability paling umum di sejarah software security (Morris Worm 1988, Heartbleed, dll).

### 3. `==` untuk Bandingkan String

```c
char a[] = "test";
char b[] = "test";

/* ❌ Ini bandingkan ALAMAT memori, bukan isi! */
if (a == b) { ... }     // Hampir selalu false

/* ✅ Pakai strcmp */
if (strcmp(a, b) == 0) {
    printf("Sama!\n");
}
```

### 4. `sizeof` vs `strlen` di Function Parameter

```c
void proses(char str[]) {
    // str sudah decay jadi pointer!
    printf("sizeof = %zu\n", sizeof(str));    // 8 (pointer size)
    printf("strlen = %zu\n", strlen(str));    // Panjang string sebenarnya
}

int main(void) {
    char teks[] = "Hello";
    printf("sizeof = %zu\n", sizeof(teks));   // 6
    proses(teks);                             // sizeof = 8!
    return 0;
}
```

### 5. `fgets` Menyimpan Newline

```c
char nama[50];
printf("Nama: ");
fgets(nama, sizeof(nama), stdin);

// Input: "Budi\n" → nama = "Budi\n\0"
// '\n' ikut tersimpan!

// ✅ Hapus newline
nama[strcspn(nama, "\n")] = '\0';   // Cara elegan pakai strcspn
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
| 🟢 EASY | Hitung jumlah **vowel, consonant, digit, dan spasi** dalam string input user |
| 🟡 MEDIUM | Implementasi **`my_strrev()`** (reverse string in-place) dan fungsi cek **palindrome** |
| 🔴 HARD | **Word counter**: pecah kalimat jadi kata-kata, hitung jumlah kata, dan tampilkan setiap kata unik beserta frekuensinya |

---

## 🔗 Lanjut ke

**[009 — Function & Storage Classes →](../009-function-dan-storage-classes/)**
