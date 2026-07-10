# 006 — Perulangan

**Fase:** 2 · Kontrol & Struktur Data Dasar | **Prasyarat:** [005 — Percabangan](../005-percabangan/) | **Estimasi waktu:** 4-5 jam

---

## 🎯 Tujuan Belajar

- Bisa menggunakan **`for`, `while`, dan `do-while`** loop dan tahu kapan pakai yang mana
- Bisa menulis **nested loop** dan memahami pola eksekusinya
- Bisa menggunakan **`break`** dan **`continue`** untuk mengontrol alur loop
- Bisa menjelaskan kenapa **`goto`** sebaiknya dihindari (tapi tetap tahu cara kerjanya)
- Bisa mengenali dan membuat **infinite loop** yang terkontrol

---

## 📖 Konsep Inti

### 1. `for` Loop — Loop dengan Counter

> **Analogi:** `for` itu kayak **checklist terstruktur**. Lu tahu dari awal: mulai dari mana, sampai mana, dan langkahnya berapa. Contoh: "Cek kamar 1 sampai 10, satu per satu."

```c
for (inisialisasi; kondisi; update) {
    // body — dijalankan selama kondisi true
}
```

**Anatomi:**

```c
for (int i = 0; i < 5; i++) {
//   ^^^^^^^^^^  ^^^^^  ^^^
//   1. Init     2. Cek  3. Update
//   (1x saja)   (tiap   (setelah
//               iterasi) body)
    printf("i = %d\n", i);
}
// Output: 0, 1, 2, 3, 4
```

**Alur eksekusi `for`:**
1. **Init** → jalankan SEKALI di awal
2. **Cek kondisi** → kalau false, KELUAR loop
3. **Body** → jalankan isi loop
4. **Update** → eksekusi update (misal `i++`)
5. Kembali ke langkah 2

```c
/* Hitung mundur */
for (int i = 10; i >= 1; i--) {
    printf("%d... ", i);
}
printf("LIFTOFF!\n");

/* Loncat 2 */
for (int i = 0; i <= 20; i += 2) {
    printf("%d ", i);   // 0 2 4 6 8 10 12 14 16 18 20
}

/* Multiple variabel di for (pakai comma) */
for (int i = 0, j = 10; i < j; i++, j--) {
    printf("i=%d, j=%d\n", i, j);
}
```

### 2. `while` Loop — Loop dengan Kondisi

> **Analogi:** `while` itu kayak **"selama masih ada antrian, layani terus"**. Lu tidak tahu pasti berapa kali loop-nya jalan — lu cuma tahu kapan harus berhenti.

```c
while (kondisi) {
    // body — dijalankan selama kondisi true
}
```

```c
int counter = 1;
while (counter <= 5) {
    printf("Counter: %d\n", counter);
    counter++;
}
```

**Kapan pakai `while` vs `for`?**

| Situasi | Pakai | Alasan |
|---------|-------|--------|
| Tahu jumlah iterasi pasti | `for` | `for (int i = 0; i < 10; i++)` |
| Tidak tahu jumlah iterasi | `while` | Loop sampai user input "quit" |
| Loop berdasarkan kondisi | `while` | `while (data_available)` |
| Iterasi dengan counter | `for` | Lebih ringkas dan jelas |

```c
/* while: baca input sampai user ketik 0 */
int angka = -1;   /* Inisialisasi agar masuk loop pertama kali */
while (angka != 0) {
    printf("Masukkan angka (0 untuk berhenti): ");
    scanf("%d", &angka);
    if (angka != 0) {
        printf("  Lu ketik: %d\n", angka);
    }
}
printf("Selesai!\n");
```

### 3. `do-while` Loop — Minimal Sekali Jalan

> **Analogi:** `do-while` itu kayak **mesin tiket parkir** — mesin pasti cetak tiket dulu (body), baru ngecek apakah masih ada kendaraan berikutnya (kondisi).

```c
do {
    // body — pasti dijalankan MINIMAL SEKALI
} while (kondisi);   // ← jangan lupa semicolon!
```

**Perbedaan kunci:**
- `while`: cek kondisi **DULU** → body mungkin TIDAK pernah jalan
- `do-while`: body jalan **DULU** → baru cek kondisi

```c
/* while: bisa tidak pernah jalan */
int x = 10;
while (x < 5) {
    printf("Ini TIDAK pernah dicetak\n");  /* x=10, 10 < 5 = false */
}

/* do-while: pasti jalan minimal 1 kali */
int y = 10;
do {
    printf("Ini PASTI dicetak sekali\n");   /* Jalan dulu, baru cek */
} while (y < 5);   /* 10 < 5 = false, keluar */
```

**Use-case terbaik `do-while`:** validasi input!

```c
int pilihan;
do {
    printf("Pilih menu (1-4): ");
    scanf("%d", &pilihan);
    if (pilihan < 1 || pilihan > 4) {
        printf("  Menu tidak valid! Coba lagi.\n");
    }
} while (pilihan < 1 || pilihan > 4);
/* Loop sampai user masukkan nilai yang valid */
printf("Pilihan: %d\n", pilihan);
```

### 4. Nested Loop (Loop Bersarang)

Loop di dalam loop. Setiap iterasi outer loop, inner loop jalan **PENUH dari awal**.

```c
/* Tabel perkalian 1-5 */
for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {
        printf("%4d", i * j);   /* %4d = width 4, rata kanan */
    }
    printf("\n");   /* Pindah baris setelah inner loop selesai */
}
```

Output:
```
   1   2   3   4   5
   2   4   6   8  10
   3   6   9  12  15
   4   8  12  16  20
   5  10  15  20  25
```

> **Analogi:** Nested loop itu kayak **jam**. Jarum menit (inner) berputar penuh 60 kali untuk setiap 1 langkah jarum jam (outer). Kalau outer loop = 3 dan inner loop = 4, total iterasi = 3 × 4 = 12.

**Pattern printing — segitiga bintang:**

```c
int tinggi = 5;

/* Segitiga kanan */
for (int i = 1; i <= tinggi; i++) {
    for (int j = 1; j <= i; j++) {
        printf("* ");
    }
    printf("\n");
}
/*
* 
* * 
* * * 
* * * * 
* * * * * 
*/

/* Piramida tengah */
for (int i = 1; i <= tinggi; i++) {
    /* Cetak spasi */
    for (int j = i; j < tinggi; j++) {
        printf(" ");
    }
    /* Cetak bintang */
    for (int j = 1; j <= (2 * i - 1); j++) {
        printf("*");
    }
    printf("\n");
}
/*
    *
   ***
  *****
 *******
*********
*/
```

### 5. `break` — Keluar dari Loop Seketika

`break` langsung menghentikan loop **terdalam** dan lanjut ke statement setelah loop.

```c
/* Cari angka pertama yang habis dibagi 7 */
for (int i = 1; i <= 100; i++) {
    if (i % 7 == 0) {
        printf("Ketemu! %d habis dibagi 7\n", i);
        break;   /* Keluar loop, tidak lanjut ke i=8, 9, ... */
    }
}
/* Output: Ketemu! 7 habis dibagi 7 */
```

**`break` di nested loop — hanya keluar dari loop TERDALAM:**

```c
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        if (j == 1) {
            break;   /* Hanya keluar inner loop */
        }
        printf("i=%d, j=%d\n", i, j);
    }
    /* break inner loop lanjut ke sini */
}
/* Output:
   i=0, j=0
   i=1, j=0
   i=2, j=0
*/
```

### 6. `continue` — Skip Iterasi Saat Ini

`continue` loncat ke **iterasi berikutnya**, melewatkan sisa body loop.

```c
/* Cetak angka 1-10, skip yang genap */
for (int i = 1; i <= 10; i++) {
    if (i % 2 == 0) {
        continue;   /* Skip printf, langsung ke i++ */
    }
    printf("%d ", i);
}
/* Output: 1 3 5 7 9 */
```

> **Penting di `while`:** Kalau pakai `continue`, pastikan update counter **sebelum** `continue`, atau bisa infinite loop!

```c
/* ❌ INFINITE LOOP — counter update di-skip oleh continue */
int i = 0;
while (i < 10) {
    if (i == 5) {
        continue;   /* Loncat ke cek kondisi, tapi i masih 5! */
    }
    printf("%d ", i);
    i++;            /* Ini di-skip saat i=5 → infinite loop */
}

/* ✅ AMAN — update counter sebelum continue */
int j = 0;
while (j < 10) {
    j++;
    if (j == 5) {
        continue;   /* j sudah di-update, aman */
    }
    printf("%d ", j);
}
```

### 7. `goto` — Dan Kenapa Dihindari

`goto` melompat ke **label** tertentu di dalam fungsi yang sama.

```c
printf("Step 1\n");
goto langkah_tiga;   /* Loncat ke label */

printf("Step 2\n");   /* DILEWATI! */

langkah_tiga:
printf("Step 3\n");
/* Output: Step 1, Step 3 */
```

**Kenapa `goto` dihindari?**

1. **Membuat alur kode jadi "spaghetti"** — susah di-trace dan di-debug
2. **Hampir selalu bisa diganti** dengan `break`, `continue`, `return`, atau flag boolean
3. **Code review nightmare** — developer lain akan kesulitan membaca kode lu

**SATU-SATUNYA use-case yang diterima:** keluar dari nested loop (karena `break` hanya keluar dari loop terdalam):

```c
/* Satu-satunya penggunaan goto yang "diterima" komunitas C */
for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        if (i * j > 25) {
            goto selesai;   /* Keluar dari KEDUA loop */
        }
    }
}
selesai:
printf("Keluar dari nested loop\n");
```

**Alternatif tanpa `goto` (biasanya lebih baik):**

```c
int found = 0;
for (int i = 0; i < 10 && !found; i++) {
    for (int j = 0; j < 10 && !found; j++) {
        if (i * j > 25) {
            found = 1;   /* Flag untuk keluar kedua loop */
        }
    }
}
```

### 8. Infinite Loop — Loop Tanpa Batas

```c
/* Cara 1: for tanpa kondisi */
for (;;) {
    printf("Selamanya...\n");
}

/* Cara 2: while(1) — PALING UMUM */
while (1) {
    printf("Selamanya...\n");
}

/* Cara 3: do-while */
do {
    printf("Selamanya...\n");
} while (1);
```

**Use-case:** program yang harus terus jalan (server, game loop, menu interaktif):

```c
/* Menu interaktif — loop sampai user pilih "keluar" */
while (1) {
    printf("\n=== MENU ===\n");
    printf("1. Hitung\n");
    printf("2. Lihat\n");
    printf("0. Keluar\n");
    printf("Pilih: ");

    int pilihan;
    scanf("%d", &pilihan);

    if (pilihan == 0) {
        printf("Bye!\n");
        break;   /* Keluar dari infinite loop */
    }

    switch (pilihan) {
        case 1: printf("Menghitung...\n"); break;
        case 2: printf("Menampilkan...\n"); break;
        default: printf("Menu tidak valid!\n"); break;
    }
}
```

### 9. Idiom Loop Umum di C

```c
/* Iterasi dari 0 sampai N-1 (paling umum di C, karena array 0-indexed) */
for (int i = 0; i < n; i++) { ... }

/* Iterasi dari 1 sampai N */
for (int i = 1; i <= n; i++) { ... }

/* Iterasi mundur */
for (int i = n - 1; i >= 0; i--) { ... }

/* Iterasi dengan step */
for (int i = 0; i < n; i += step) { ... }

/* Input loop dengan sentinel value */
int val;
while (scanf("%d", &val) == 1 && val != -1) {
    /* Proses val, berhenti kalau bukan angka atau val == -1 */
}

/* Membaca karakter satu-satu sampai EOF */
int ch;
while ((ch = getchar()) != EOF) {
    putchar(ch);
}
```

---

## ⚠️ Perangkap Umum (Common Pitfalls)

### 1. Off-by-One Error

```c
/* ❌ Harusnya 10 iterasi, tapi jadi 11 */
for (int i = 0; i <= 10; i++) { ... }   /* 0,1,...,10 = 11 iterasi */

/* ✅ 10 iterasi (0-9) */
for (int i = 0; i < 10; i++) { ... }    /* 0,1,...,9 = 10 iterasi */
```

> **Tips:** Di C, **selalu pakai `< n`** bukan `<= n-1`. Ini konvensi standar karena array di C mulai dari index 0.

### 2. Infinite Loop Tidak Disengaja

```c
/* ❌ Lupa update counter */
int i = 0;
while (i < 10) {
    printf("%d\n", i);
    /* Lupa i++; → loop selamanya */
}

/* ❌ Salah arah update */
for (int i = 10; i > 0; i++) {  /* i++ bukan i-- → never ends */
    printf("%d\n", i);
}
```

### 3. Semicolon Setelah `for` / `while`

```c
/* ❌ Semicolon membuat loop body kosong! */
for (int i = 0; i < 5; i++);   /* Loop "jalan" tapi body kosong */
{
    printf("%d\n", i);   /* Ini BUKAN bagian loop! ERROR: i not defined */
}

/* ❌ Sama untuk while */
while (x > 0);   /* Loop body kosong → infinite loop kalau x > 0 */
{
    x--;   /* Ini tidak pernah dieksekusi */
}
```

### 4. Modifikasi Counter di Dalam Loop Body

```c
/* ❌ Jangan ubah counter di body — bikin bingung */
for (int i = 0; i < 10; i++) {
    i += 2;   /* Lompat 2 tambahan — total skip 3 per iterasi */
    printf("%d\n", i);
    /* Output unpredictable untuk pembaca kode */
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
| 🟢 EASY | FizzBuzz klasik: cetak 1-100, ganti kelipatan 3 jadi "Fizz", kelipatan 5 jadi "Buzz", kelipatan 15 jadi "FizzBuzz" |
| 🟡 MEDIUM | Pattern printer: cetak piramida, diamond, dan hollow rectangle berdasarkan tinggi input user |
| 🔴 HARD | Menu interaktif kalkulator: loop sampai user pilih keluar, support +, -, *, /, history 5 operasi terakhir (pakai array dari modul berikutnya? Tidak — pakai variabel manual) |

---

## 🔗 Lanjut ke

**[007 — Array →](../007-array/)**
