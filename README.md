# 🚀 C-Learning: Kurikulum Lengkap Bahasa C

> **Tujuan:** Menguasai bahasa C secara menyeluruh — dari fundamental hingga advanced — sebagai fondasi kuat untuk programming career dan transisi ke C++.
> **Platform:** Cross-platform (macOS Terminal / Windows CMD-PowerShell / Linux Terminal)
> **Standar Bahasa:** C17 (ISO/IEC 9899:2018)
> **Untuk siapa:** Siapa aja yang mau belajar C dari nol — nggak perlu background CS, cukup modal niat dan terminal

---

## 👋 Tentang Repo Ini

Repo ini adalah kurikulum belajar C yang disusun berurutan dari nol sampai bisa bikin project modular sendiri. Cocok buat:

- Pemula total yang belum pernah nulis kode C sama sekali
- Yang udah bisa bahasa lain (Python/JS/dll) dan mau paham C sebagai jembatan ke systems programming / C++
- Mahasiswa yang butuh materi pendamping mata kuliah Algoritma/Struktur Data/Sistem Operasi
- Siapapun yang mau serius belajar pointer & memory management, bukan cuma hafal sintaks

Setiap folder = satu modul, isinya penjelasan konsep + kode contoh + latihan + jawaban. Ikutin urutannya dari 001, jangan loncat-loncat kecuali udah yakin paham prasyaratnya.

---

## 🤖 Panduan Khusus untuk AI Agent (Content Generator)

> Bagian ini **wajib dibaca dan dipatuhi** setiap kali agent diminta men-generate materi untuk salah satu modul di roadmap. Tujuannya: memastikan semua modul, walau digenerate di sesi terpisah, tetap konsisten satu sama lain.

### 1. Struktur folder & file wajib per modul

```
0XX-nama-modul/
├── README.md              # Penjelasan konsep (lihat template di bawah)
├── main.c                  # Kode contoh, siap compile & run, well-commented
├── exercise.c               # Soal latihan (skeleton + TODO), TANPA jawaban
├── exercise_answer.c         # Jawaban lengkap dari exercise.c
├── Makefile                 # Mulai wajib ada dari modul 010 (Header & Modular)
└── notes.md                  # (opsional) catatan tambahan / FAQ / gotcha
```

- Folder pakai format `0XX-kebab-case-nama-modul`, contoh: `001-pengenalan-c`, `013-struct-dasar`.
- Semua nama file, variabel, fungsi pakai `snake_case`. Nama tipe custom (struct/typedef) pakai `PascalCase` atau `snake_case_t` — **pilih satu, konsisten di seluruh repo** (rekomendasi: `snake_case_t`, contoh `point_t`, `node_t`).

### 2. Template `README.md` per modul

Setiap modul **wajib** punya README dengan struktur berikut (agent mengisi, bukan mengubah urutan):

```markdown
# 0XX — [Judul Modul]

**Fase:** [nomor & nama fase] | **Prasyarat:** [modul sebelumnya] | **Estimasi waktu:** [X jam]

## 🎯 Tujuan Belajar
- Bullet list, 3-5 poin, actionable ("Bisa menjelaskan...", "Bisa menulis...", "Bisa membedakan...")

## 📖 Konsep Inti
- Daftar sub-topik yang dibahas (jadi outline buat main.c)

## ⚠️ Perangkap Umum (Common Pitfalls)
- Minimal 2-3 kesalahan klasik pemula terkait topik ini, disertai contoh singkat kenapa itu salah

## 💻 Cara Menjalankan
(snippet compile command sesuai OS, konsisten dengan bagian "Cara Compile & Run" di root README)

## 📝 Latihan
- Ringkasan level exercise (lihat poin 3 di bawah)

## 🔗 Lanjut ke
- Link ke modul berikutnya
```

### 3. Standar exercise.c (WAJIB 3 tingkat kesulitan)

Setiap `exercise.c` harus punya minimal **3 soal** dengan tingkat berbeda, ditandai jelas dalam komentar:

```c
// ============================================
// LEVEL 1: EASY — [deskripsi singkat]
// ============================================
// TODO: ...

// ============================================
// LEVEL 2: MEDIUM — [deskripsi singkat]
// ============================================
// TODO: ...

// ============================================
// LEVEL 3: HARD / CHALLENGE — [deskripsi singkat, boleh gabungin konsep modul sebelumnya]
// ============================================
// TODO: ...
```

Level 3 idealnya **menggabungkan** konsep modul ini dengan minimal satu konsep dari modul sebelumnya (reinforcement, bukan topik lepas-lepas).

### 4. Standar kode & komentar

- **Compiler flags wajib** disebutkan di setiap README: `gcc -std=c17 -Wall -Wextra -Wpedantic -o program main.c`
- Mulai modul **017 (Dynamic Memory)** ke atas, wajib sebutkan cara pakai **sanitizer**: `gcc -std=c17 -fsanitize=address,undefined -g -o program main.c` dan/atau `valgrind --leak-check=full ./program`
- Komentar kode: **Bahasa Indonesia untuk penjelasan konsep**, tapi istilah teknis tetap bahasa Inggris asli (jangan diterjemahkan paksa: "pointer", "heap", "stack", "buffer overflow", dst tetap disebut aslinya).
- Setiap konsep baru **wajib** disertai analogi dunia nyata sebelum masuk ke sintaks (gaya penjelasan "kenapa", bukan cuma "bagaimana").
- Semua contoh kode di `main.c` harus benar-benar bisa di-compile tanpa warning dengan flags di atas — agent harus "mental-compile" sebelum menganggap modul selesai.
- Dilarang pakai fungsi *deprecated/unsafe* tanpa penjelasan eksplisit (contoh: kalau kepaksa pakai `gets()` untuk demo kenapa itu bahaya, harus dijelaskan dan langsung dikontraskan dengan alternatif aman seperti `fgets()`).

### 5. Aturan urutan dependensi (PENTING)

Agent **dilarang** memperkenalkan konsep yang belum diajarkan di modul sebelumnya. Contoh: jangan pakai `struct` di modul 009 (Function) kalau struct baru diajarkan di modul 013. Kalau butuh, cek daftar "Konsep Inti" modul-modul sebelumnya dulu sebagai referensi dependensi.

### 6. Bahasa & tone

Tone penjelasan: santai tapi teknikal presisi, seperti mentor senior ngobrol sama mentee — boleh pakai "lu/lo", hindari terlalu formal/kaku ala textbook terjemahan.

---

## 📋 Cara Belajar

1. **Baca README.md** di setiap folder materi — ini adalah "buku pelajaran" lu
2. **Baca & jalankan main.c** — contoh kode yang bisa langsung di-compile dan di-run
3. **Kerjakan exercise.c** — latihan mandiri (3 level: easy/medium/hard), JANGAN langsung lihat jawaban
4. **Cek exercise_answer.c** — kalau stuck, baru boleh intip
5. **Ulangi tanpa lihat catatan** — kalau masih bisa ngerjain exercise dari modul 3 minggu lalu tanpa buka README, baru lanjut ke modul berikutnya

### Cara Compile & Run

#### macOS / Linux (Terminal)
```bash
# Install compiler (macOS)
xcode-select --install

# Install compiler (Linux/Ubuntu)
sudo apt install gcc

# Compile (standar wajib dipakai di seluruh repo)
gcc -std=c17 -Wall -Wextra -Wpedantic -o program main.c

# Run
./program
```

#### Windows (CMD / PowerShell)
```powershell
# Install MinGW-w64 dari https://www.mingw-w64.org/ atau via MSYS2
winget install -e --id MSYS2.MSYS2

# Compile (sama persis)
gcc -std=c17 -Wall -Wextra -Wpedantic -o program.exe main.c

# Run
.\program.exe
```

> **Flag `-Wall -Wextra -Wpedantic`** wajib dipakai di semua modul. Mulai modul Dynamic Memory, tambahkan `-fsanitize=address,undefined -g` untuk deteksi memory bug secara otomatis.

---

## 🗺️ ROADMAP

### 📦 Fase 1: Fondasi (001 - 005)
> *Tujuan: Bisa nulis program C sederhana yang menerima input dan menghasilkan output*

- [ ] **001 — Pengenalan C** → Sejarah, setup environment, Hello World, cara compile, anatomi program C, apa itu compiler vs interpreter
- [ ] **002 — Variabel & Tipe Data** → Semua tipe data primitif, sizeof, casting (implicit/explicit), integer overflow, konstanta (`const`, `#define`), scope dasar
- [ ] **003 — Operator** → Aritmatika, relasional, logika, **bitwise (`& | ^ ~ << >>`)**, assignment, operator precedence table, dampak bitwise ke Bit Fields (modul 014)
- [ ] **004 — Input/Output** → printf format specifier lengkap, scanf deep dive & pitfalls, buffer/newline problem, `fgets` vs `scanf`, `getchar`
- [ ] **005 — Percabangan** → if-else, switch-case, ternary, nested if, guard clause, best practice readability

### 🔁 Fase 2: Kontrol & Struktur Data Dasar (006 - 008)
> *Tujuan: Bisa mengolah data dalam jumlah banyak dengan loop, array, dan string*

- [ ] **006 — Perulangan** → for, while, do-while, nested loop, break, continue, goto (dan kenapa dihindari), infinite loop
- [ ] **007 — Array** → 1D, 2D, multidimensional, VLA (Variable Length Array), sorting dasar (bubble sort), linear/binary search
- [ ] **008 — String** → String sebagai array of char, `string.h` (`strlen`, `strcpy`/`strncpy`, `strcat`/`strncat`, `strcmp`, `strchr`, `strtok`, `sprintf`/`snprintf`), string vs char array, buffer overflow risk di string

### ⚙️ Fase 3: Fungsi & Modularitas Modern (009 - 011)
> *Tujuan: Bisa memecah program jadi fungsi-fungsi kecil, reusable, dan siap di-split ke banyak file*

- [ ] **009 — Function & Storage Classes** → void, return, parameter by value, function prototype, scope, `static` (function & variable), `extern`, storage duration (automatic vs static)
- [ ] **010 — Header, Multi-file, Preprocessor** → `#define` (object-like & function-like macro), `#include` (`<>` vs `""`), `#ifdef`/`#ifndef`/`#endif`, include guards, split `.h`/`.c`, Makefile dasar (target, dependency, `$@`/`$<`), linker basics (kenapa muncul "undefined reference")
- [ ] **011 — Rekursi** → Base case & recursive case, call stack, stack overflow, tail recursion, studi kasus: factorial, fibonacci, tower of hanoi, memoization intro

### 🧠 Fase 4: Pointer & Level Memori (Pondasi C++!)
> *Tujuan: Memahami cara C bekerja di level memori — ini yang bikin C POWERFUL dan jadi fondasi C++*

- [ ] **012 — Pointer Dasar & Const Correctness** → Address-of (`&`), dereference (`*`), NULL pointer, void pointer, `const` dengan pointer (`const int*` vs `int* const`), dangling pointer, wild pointer
- [ ] **013 — Pointer Arithmetic, Array, & String Safety** → Pointer arithmetic, hubungan pointer-array (`arr[i]` == `*(arr+i)`), pointer ke string literal vs char array, common bugs (off-by-one, buffer overrun)
- [ ] **014 — Function Pointer & Callback** → Deklarasi function pointer, array of function pointer, callback pattern, `typedef` untuk function pointer, use-case: simple event dispatcher/state machine, intro `stdarg.h` (variadic function, cara `printf` bekerja) — *opsional/advanced*

### 🏗️ Fase 5: Data Kompleks (015 - 016)
> *Tujuan: Bisa bikin tipe data custom untuk merepresentasikan objek dunia nyata*

- [ ] **015 — Struct & Union** → Struct, nested struct, array of struct, pointer ke struct (`->` operator), struct sebagai parameter/return function, union & kapan dipakai, struct padding/alignment (intro)
- [ ] **016 — Enum, Typedef, & Bit Fields** → enum (dan kenapa lebih aman dari `#define` untuk konstanta bernama), typedef untuk readability & opaque types, bit fields dalam struct (revisit bitwise dari modul 003)

### 💾 Fase 6: Struktur Data & Advanced Memory (017 - 019)
> *Tujuan: Bisa mengelola memori secara manual, membangun struktur data sendiri, dan bekerja dengan file*

- [ ] **017 — Dynamic Memory** → `malloc`, `calloc`, `realloc`, `free`, memory leak, dangling pointer setelah `free`, double-free, wajib pakai `-fsanitize=address` & `valgrind` mulai modul ini
- [ ] **018 — Linked List, Stack, & Queue (Data Structures Dasar)** → Singly linked list (insert/delete/traverse), stack (LIFO) via array & linked list, queue (FIFO) via array & linked list — *modul jembatan wajib* antara "paham pointer+malloc" dan "bisa bikin project modular"
- [ ] **019 — File I/O** → `fopen`/`fclose`, text mode vs binary mode, `fread`/`fwrite`, `fprintf`/`fscanf`, `fseek`/`ftell`, error handling saat file operation gagal

### 🔧 Fase 7: Engineering & Robustness (020 - 021)
> *Tujuan: Menulis kode C yang profesional, aman, dan maintainable — level "siap kerja"*

- [ ] **020 — Error Handling & Undefined Behavior (UB)** → `errno`, `perror`, `strerror`, `assert`, defensive programming, graceful exit vs crash, contoh-contoh UB klasik di C (out-of-bounds, uninitialized variable, signed overflow, dst)
- [ ] **021 — Debugging, Static Analysis, & Code Style** → GDB/LLDB dasar (breakpoint, step, print variable, backtrace), static analysis tools (`cppcheck`, compiler warning sebagai static analysis paling murah), code style guide (konsisten dengan konvensi repo ini), code review checklist

### 🎓 Fase 8: Final Project
> *Tujuan: Mengaplikasikan SEMUA yang sudah dipelajari dalam satu project utuh*

- [ ] **022 — Aplikasi Terminal Modular** → Clean architecture (pisah `include/`, `src/`, `Makefile` di root), pakai minimal: struct, dynamic memory, linked list, file I/O (persist data ke disk), error handling. Contoh ide: to-do list CLI, inventory manager, simple contact book — semua dengan file persistence.

---

## 🎯 Setelah Selesai Semua Modul

| Skill | Status |
|-------|--------|
| Menulis program C dari nol | ✅ |
| Memahami semua tipe data, operator (termasuk bitwise) | ✅ |
| Modularitas: header, multi-file, Makefile | ✅ |
| Menguasai pointer & memory management | ✅ |
| Membangun struktur data sendiri (linked list, stack, queue) | ✅ |
| Bekerja dengan file & dynamic memory secara aman | ✅ |
| Debugging (GDB), static analysis, defensive programming | ✅ |
| Membuat project modular (multi-file + Makefile + clean architecture) | ✅ |
| **Siap transisi ke C++** | 🚀 |

> **Next step:** Belajar C++ — lu akan kagum betapa banyak konsep C yang langsung applicable di C++ (terutama pointer, struct, dan manual memory management yang jadi dasar `new`/`delete` dan RAII).

---

## 📚 Referensi Tambahan (opsional, untuk pendalaman)

- *The C Programming Language* — Kernighan & Ritchie (K&R), buku klasik wajib baca
- *C Programming: A Modern Approach* — K.N. King, lebih detail untuk pemula
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/) — gratis, praktis, enak dibaca
- [cppreference.com/w/c](https://en.cppreference.com/w/c) — referensi standar library paling akurat
- Compiler Explorer ([godbolt.org](https://godbolt.org/)) — buat lihat kode C jadi assembly, bagus buat modul pointer & memory

---

## 🤝 Kontribusi

Repo ini terbuka untuk kontribusi — kalau nemu typo, bug di kode contoh, atau mau nambah exercise, silakan buka issue/PR. Pastikan kontribusi baru tetap ikutin konvensi struktur & coding style di atas.

---

*Semangat belajar, semuanya!. 💪*