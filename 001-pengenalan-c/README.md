# 001 — Pengenalan C

**Fase:** 1 · Fondasi | **Prasyarat:** Tidak ada | **Estimasi waktu:** 3-4 jam

---

## 🎯 Tujuan Belajar

- Bisa menjelaskan **apa itu bahasa C** dan kenapa masih relevan di 2025+
- Bisa membedakan **compiler vs interpreter** dan paham kenapa C pakai compiler
- Bisa meng-**install compiler** (`gcc`/`clang`) di macOS, Linux, atau Windows
- Bisa menulis, **meng-compile, dan menjalankan** program "Hello World" pertama
- Bisa menjelaskan **anatomi program C**: `#include`, `main()`, `return 0`, dan alur eksekusi

---

## 📖 Konsep Inti

### 1. Apa Itu Bahasa C?

C adalah bahasa pemrograman **prosedural** yang dibuat oleh **Dennis Ritchie** di Bell Labs pada tahun **1972**. Ya, bahasa ini lebih tua dari kebanyakan orang yang baca guide ini — dan masih dipakai di mana-mana.

**Kenapa C masih penting?**

| Alasan | Contoh Nyata |
|--------|-------------|
| **Sistem operasi ditulis pakai C** | Linux kernel, Windows kernel, macOS (Darwin kernel) |
| **Embedded systems** | Firmware Arduino, mikrokontroler, IoT devices |
| **Database** | MySQL, PostgreSQL, SQLite — semua ditulis pakai C |
| **Game engines** | Bagian low-level dari Unreal Engine, id Tech |
| **Bahasa lain dibangun dari C** | Python interpreter (CPython), Ruby, PHP, Node.js (V8 engine) |
| **Performance-critical software** | Nginx, Redis, Git |

> **Analogi:** Kalau programming languages itu gedung, C itu **fondasinya**. Banyak bahasa modern (C++, Java, Go, Rust) terinspirasi dari sintaks dan konsep C. Belajar C = belajar "bahasa ibu"-nya programming.

### 2. Compiler vs Interpreter

Sebelum kode lu bisa dijalankan komputer, kode itu harus diterjemahkan dari bahasa manusia ke bahasa mesin (0 dan 1).

Ada 2 cara menerjemahkan:

| | Compiler | Interpreter |
|---|----------|-------------|
| **Cara kerja** | Terjemahkan **seluruh kode** dulu, baru jalankan | Terjemahkan **baris per baris** sambil jalan |
| **Hasil** | File executable (binary) | Tidak ada file terpisah |
| **Kecepatan** | ⚡ Sangat cepat (sudah jadi bahasa mesin) | 🐢 Lebih lambat (terjemahkan terus-terusan) |
| **Error** | Ketahuan **sebelum** program jalan | Ketahuan **saat** program jalan |
| **Contoh bahasa** | C, C++, Rust, Go | Python, JavaScript, Ruby |

> **Analogi:** Compiler itu kayak penerjemah buku — dia terjemahin seluruh buku dulu, baru kamu baca. Interpreter itu kayak penerjemah simultan — dia terjemahin kalimat per kalimat sambil kamu dengerin.

**C pakai compiler.** Artinya:
1. Lu nulis kode (file `.c`)
2. Compiler terjemahkan ke bahasa mesin → menghasilkan file executable
3. Lu jalankan file executable tersebut

```
[main.c] ---(compiler)---> [program / program.exe] ---(run)---> Output
```

### 3. Setup Environment (Install Compiler)

#### macOS

Di macOS (termasuk Apple Silicon M1/M2/M3/M4), compiler default-nya adalah **Apple Clang** (bukan GCC murni). Tapi tenang — Clang 100% kompatibel dengan standar C, dan command `gcc` di macOS sebenarnya adalah alias ke Clang.

```bash
# Install Xcode Command Line Tools (includes clang)
xcode-select --install

# Verifikasi
gcc --version
# Output: Apple clang version 16.x.x ...
# Ini NORMAL — di macOS, 'gcc' = Apple Clang

# Kalau mau install GCC murni (opsional, via Homebrew):
brew install gcc
# Setelah install, GCC tersedia sebagai gcc-14 (atau versi terbaru)
```

> **Catatan penting untuk macOS:** Perintah `gcc` di macOS menjalankan Apple Clang, **bukan** GCC dari GNU. Untuk keperluan belajar C, ini **tidak masalah sama sekali** — keduanya mendukung standar C17. Perbedaannya hanya terasa di fitur-fitur sangat spesifik yang tidak akan kita pakai di kurikulum ini.

#### Linux (Ubuntu/Debian)

```bash
sudo apt update
sudo apt install gcc build-essential

# Verifikasi
gcc --version
```

#### Windows

Ada beberapa opsi:

**Opsi 1: MSYS2 + MinGW-w64 (Direkomendasikan)**
```powershell
# Install MSYS2
winget install -e --id MSYS2.MSYS2

# Buka MSYS2 UCRT64 terminal, lalu:
pacman -Syu
pacman -S mingw-w64-ucrt-x86_64-gcc

# Tambahkan ke PATH:
# C:\msys64\ucrt64\bin
```

**Opsi 2: WSL (Windows Subsystem for Linux)**
```powershell
# Install WSL
wsl --install

# Di dalam WSL (Ubuntu), install gcc:
sudo apt install gcc build-essential
```

**Verifikasi di semua OS:**
```bash
gcc --version
# Harus menampilkan versi gcc/clang — kalau muncul, berarti siap!
```

### 4. Anatomi Program C — "Hello World"

Ini adalah program C paling sederhana yang bisa lu tulis:

```c
#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
```

Mari kita bedah **setiap baris**:

#### Baris 1: `#include <stdio.h>`

```c
#include <stdio.h>
```

- `#include` = "sertakan file ini ke dalam program gua"
- `<stdio.h>` = **St**andar **I**nput **O**utput **H**eader — library bawaan C yang berisi fungsi-fungsi I/O seperti `printf()` dan `scanf()`
- Tanpa baris ini, compiler **tidak tahu** apa itu `printf`

> **Analogi:** Ini kayak `import` di Python atau `using` di C#. Lu ngasih tahu compiler: "Eh, gua mau pakai alat-alat dari kotak `stdio.h`."

**Kenapa pakai `<>` bukan `""`?**
- `<stdio.h>` → cari di folder **system/library** (bawaan compiler)
- `"myfile.h"` → cari di folder **project lu** dulu, baru ke system

Ini akan dibahas lebih dalam di modul 010 (Header & Multi-file).

#### Baris 3: `int main(void)`

```c
int main(void) {
```

- `main` = **entry point** — titik mulai program. Setiap program C **wajib** punya tepat satu fungsi `main()`
- `int` = tipe return value. `main()` mengembalikan integer ke operating system
- `void` = fungsi ini tidak menerima parameter (boleh juga ditulis `main()` tanpa `void`, tapi `main(void)` lebih eksplisit dan lebih "correct" menurut standar C)
- `{` = awal blok kode fungsi `main`

> **Analogi:** `main()` itu pintu masuk utama rumah lu. OS (sistem operasi) selalu masuk lewat pintu ini. Mau berapa pun ruangan (fungsi) di rumah lu, tamu (OS) selalu mulai dari `main()`.

**Kenapa `int main(void)` bukan `void main()`?**

`void main()` secara teknis **bukan standar C** (meskipun beberapa compiler mengizinkannya). Standar C (C11/C17) mendefinisikan dua bentuk valid:
1. `int main(void)` — tanpa argumen
2. `int main(int argc, char *argv[])` — dengan command-line arguments (dibahas nanti)

Selalu pakai `int main(void)` untuk kebiasaan yang benar.

#### Baris 4: `printf("Hello, World!\n");`

```c
    printf("Hello, World!\n");
```

- `printf()` = **print formatted** — fungsi untuk mencetak teks ke layar (terminal/console)
- `"Hello, World!\n"` = string yang ingin dicetak
- `\n` = **newline character** (pindah baris). Tanpa ini, teks berikutnya akan nempel di baris yang sama
- `;` = **setiap statement di C harus diakhiri titik koma** — ini bukan opsional, lupa taruh `;` = error

#### Baris 5: `return 0;`

```c
    return 0;
```

- `return` = kembalikan nilai ke pemanggil (dalam kasus `main()`, pemanggilnya adalah **OS**)
- `0` = artinya "program selesai **tanpa error**" (exit code 0 = sukses)
- Nilai selain 0 = ada error. Contoh: `return 1;` bisa berarti "file not found"

> **Analogi:** Ini kayak kode status HTTP. 200 = OK, 404 = Not Found. Di C, return 0 = "semua lancar, bos!"

Lu bisa cek exit code di terminal:
```bash
./program
echo $?    # macOS/Linux — tampilkan exit code program terakhir
# Output: 0
```

#### Baris 6: `}`

```c
}
```

Penutup blok `main()`. Setiap `{` harus punya pasangan `}`.

### 5. Cara Compile dan Run

```bash
# Compile
gcc -std=c17 -Wall -Wextra -Wpedantic -o program main.c

# Run (macOS/Linux)
./program

# Run (Windows)
.\program.exe
```

**Penjelasan flags:**

| Flag | Fungsi |
|------|--------|
| `-std=c17` | Gunakan standar C17 (versi terbaru yang stabil) |
| `-Wall` | Tampilkan **semua warning** umum |
| `-Wextra` | Tampilkan warning **tambahan** yang tidak tercover `-Wall` |
| `-Wpedantic` | Warning untuk kode yang tidak 100% sesuai standar |
| `-o program` | Nama file output (executable) |

> **Best practice:** SELALU compile dengan `-Wall -Wextra -Wpedantic`. Warning itu bukan error, tapi sering jadi **petunjuk bug** yang belum meledak. Programmer profesional memperlakukan warning sebagai error.

### 6. Escape Characters

Karakter spesial yang diawali backslash (`\`) di dalam string:

| Escape | Fungsi | Contoh |
|--------|--------|--------|
| `\n` | Newline (pindah baris) | `printf("Baris 1\nBaris 2");` |
| `\t` | Tab (indentasi) | `printf("Nama\t: Admiral");` |
| `\\` | Cetak backslash literal | `printf("Path: C:\\Users");` |
| `\"` | Cetak tanda kutip | `printf("Dia bilang \"Halo\"");` |
| `\0` | Null character (akhir string) | Dibahas di modul String |
| `\a` | Bell/alert (bunyi beep) | `printf("\a");` |
| `\r` | Carriage return | Untuk progress bar di terminal |

### 7. Komentar (Comments)

Komentar = catatan di kode yang **diabaikan oleh compiler**. Ini buat manusia, bukan mesin.

```c
// Ini komentar satu baris (C99+)

/*
   Ini komentar
   banyak baris (C89+)
*/

/* Ini juga valid untuk satu baris */
```

**Best practice komentar:**
- ✅ Jelaskan **KENAPA**, bukan APA: `// Tambah 1 karena array dimulai dari index 0`
- ❌ Jangan narasi ulang kode: `// Tambahkan i dengan 1` ← ini redundant, kodenya sudah jelas
- ✅ Komentari keputusan desain yang tidak obvious
- ❌ Jangan komentar setiap baris — kode yang baik itu **self-documenting**

### 8. Real World: Di Mana C Dipakai?

| Industri | Contoh Penggunaan |
|----------|-------------------|
| **Operating Systems** | Linux kernel (~28 juta baris C), Windows kernel, macOS Darwin |
| **Embedded/IoT** | Arduino, ESP32, firmware mobil, mesin cuci pintar |
| **Database** | SQLite (single-file database yang ada di SETIAP smartphone) |
| **Networking** | Nginx, curl, OpenSSL |
| **Game Development** | Doom (1993), Quake engine |
| **Bahasa Pemrograman** | CPython (Python), Ruby MRI, PHP Zend Engine, Lua |
| **Tools** | Git, VLC media player, GIMP |

**Fakta menarik:** Bahasa Python yang kamu pakai sehari-hari... interpreter-nya ditulis pakai C (CPython). Jadi secara teknis, setiap kali lu jalankan Python, lu sebenarnya menjalankan program C.

---

## ⚠️ Perangkap Umum (Common Pitfalls)

### 1. Lupa titik koma (`;`)

```c
// ❌ SALAH — compiler error
printf("Hello")

// ✅ BENAR
printf("Hello");
```

Error message-nya sering **menyesatkan** — compiler mungkin bilang error di baris BERIKUTNYA, padahal masalahnya di baris yang lupa `;`. Kalau lihat error aneh, cek baris di atasnya.

### 2. Pakai `void main()` bukan `int main(void)`

```c
// ❌ Non-standard (meskipun kadang jalan)
void main() {
    printf("Hello\n");
}

// ✅ Standar C yang benar
int main(void) {
    printf("Hello\n");
    return 0;
}
```

Beberapa compiler (terutama di Windows/Turbo C) mengizinkan `void main()`, tapi ini **bukan standar C**. Biasakan pakai `int main(void)`.

### 3. Lupa `#include <stdio.h>`

```c
// ❌ Compiler warning: implicit declaration of function 'printf'
int main(void) {
    printf("Hello\n");
    return 0;
}
```

Tanpa `#include <stdio.h>`, compiler tidak tahu definisi `printf()`. Di C89 ini mungkin "jalan" tapi dengan warning; di C99+ ini bisa jadi error.

### 4. Nulis `\n` di luar string

```c
// ❌ SALAH
printf("Hello")\n;

// ✅ BENAR — \n harus DI DALAM tanda kutip
printf("Hello\n");
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
| 🟢 EASY | Cetak biodata sederhana (nama, umur, hobi) dengan format rapi |
| 🟡 MEDIUM | Buat tampilan "kartu nama" dengan border menggunakan escape characters |
| 🔴 HARD | Buat tampilan menu restoran multi-baris dengan alignment rapi |

---

## 🔗 Lanjut ke

**[002 — Variabel & Tipe Data →](../002-variabel-dan-tipe-data/)**
