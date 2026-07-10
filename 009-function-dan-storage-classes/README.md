# 009 — Function & Storage Classes

**Fase:** 3 · Fungsi & Modularitas Modern | **Prasyarat:** [008 — String](../008-string/) | **Estimasi waktu:** 5-6 jam

---

## 🎯 Tujuan Belajar

- Bisa mendeklarasikan dan mendefinisikan **function** dengan berbagai return type dan parameter
- Memahami **parameter passing by value** (satu-satunya cara di C) dan trik "by reference" via pointer
- Mengerti pentingnya **function prototype** dan kenapa selalu taruh di atas `main()`
- Memahami **scope** (block scope, file scope) dan lifetime variabel
- Menguasai **storage classes**: `auto`, `static`, `extern`, `register`
- Bisa menggunakan **`static` variable** di dalam function untuk persistent state
- Memahami **`static` function** untuk internal linkage

---

## 📖 Konsep Inti

### 1. Anatomi Function

> **Analogi:** Function itu kayak **mesin di pabrik** — lu masukin bahan baku (parameter), mesin proses, keluar produk jadi (return value). Mesin bisa dipanggil berulang kali tanpa harus bangun mesin baru.

```c
// Syntax:
// return_type nama_function(parameter_list) {
//     body
//     return value;   /* kalau bukan void */
// }

/* Function dengan return value */
int tambah(int a, int b) {
    return a + b;
}

/* Function tanpa return value (void) */
void sapa(const char *nama) {
    printf("Halo, %s!\n", nama);
}

/* Function tanpa parameter */
void garis(void) {
    printf("========================\n");
}

/* Pemanggilan */
int hasil = tambah(3, 5);    // hasil = 8
sapa("Budi");                 // "Halo, Budi!"
garis();                      // "========================"
```

> **Kenapa `void` di parameter (`void garis(void)`) bukan `void garis()`?**
> Di C, `f()` artinya "function yang menerima **jumlah parameter tidak tentu**" (legacy C), sedangkan `f(void)` artinya "function yang **benar-benar tidak menerima parameter**". Selalu pakai `(void)` untuk kejelasan.

### 2. Function Prototype (Forward Declaration)

```c
/* ✅ Prototype dulu — definisi di bawah main */
int kuadrat(int x);          // Prototype (deklarasi)
void cetak_array(int arr[], int n);

int main(void) {
    printf("%d\n", kuadrat(5));    // 25 — compiler tahu tipe dari prototype
    return 0;
}

/* Definisi function */
int kuadrat(int x) {
    return x * x;
}
```

**Kenapa prototype penting?**
1. Compiler baca kode dari **atas ke bawah** — tanpa prototype, fungsi harus didefinisikan SEBELUM dipakai
2. Prototype memungkinkan **pengecekan tipe** argumen saat compile time
3. Prototype membuat kode lebih **terorganisir** — `main()` bisa di atas, helper functions di bawah

```c
/* ❌ TANPA prototype — compiler warning/error */
int main(void) {
    int x = kuadrat(5);   // Compiler: "kuadrat? Siapa itu?"
    return 0;
}

int kuadrat(int n) { return n * n; }
```

### 3. Parameter Passing — By Value (SELALU)

> **Konsep kunci:** Di C, function parameter **SELALU by value** — artinya function menerima **COPY** dari nilai argumen, bukan variabel aslinya.

```c
void coba_ubah(int x) {
    x = 999;    // Mengubah COPY, bukan variabel asli!
    printf("Di dalam function: x = %d\n", x);   // 999
}

int main(void) {
    int angka = 42;
    coba_ubah(angka);
    printf("Di main: angka = %d\n", angka);      // 42 — TIDAK BERUBAH!
    return 0;
}
```

**Trik "pass by reference" pakai pointer (preview modul 012):**

```c
void ubah_beneran(int *ptr) {
    *ptr = 999;    // Mengubah nilai di alamat yang ditunjuk
}

int main(void) {
    int angka = 42;
    ubah_beneran(&angka);      // Kirim ALAMAT variabel
    printf("angka = %d\n", angka);   // 999 — BERUBAH!
    return 0;
}
```

**Array sebagai parameter — otomatis by reference:**

```c
/* Array SELALU di-pass sebagai pointer (decay) */
void isi_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i * 10;    // Mengubah array ASLI!
    }
}

int main(void) {
    int data[5] = {0};
    isi_array(data, 5);
    // data sekarang = {0, 10, 20, 30, 40}
    return 0;
}
```

> **Kenapa array berbeda?** Karena array "decay" jadi pointer saat di-pass ke function. Yang dikirim bukan copy array, tapi **alamat elemen pertama**. Detail di modul 012-013.

### 4. Scope — Di Mana Variabel Bisa Diakses

#### Block Scope (Local Variable)

```c
int main(void) {
    int x = 10;       // Scope: seluruh main()

    if (x > 5) {
        int y = 20;   // Scope: hanya di dalam if block
        printf("x=%d, y=%d\n", x, y);   // ✅ OK
    }

    printf("x=%d\n", x);   // ✅ OK
    // printf("y=%d\n", y);   // ❌ ERROR: y tidak ada di sini!

    for (int i = 0; i < 3; i++) {
        // i hanya ada di dalam for
    }
    // printf("%d\n", i);    // ❌ ERROR: i tidak ada di sini!

    return 0;
}
```

#### File Scope (Global Variable)

```c
int global_counter = 0;    // File scope — bisa diakses dari mana saja di file ini

void increment(void) {
    global_counter++;
}

int main(void) {
    increment();
    increment();
    printf("counter = %d\n", global_counter);   // 2
    return 0;
}
```

> **⚠️ Global variable = anti-pattern!** Hindari sebisa mungkin. Global variable bikin kode susah di-debug, di-test, dan di-maintain. Pakai parameter dan return value.

#### Shadowing — Variabel Lokal "Menutupi" Global

```c
int x = 100;   // Global

void demo(void) {
    int x = 50;    // Lokal — "shadow" global x
    printf("Lokal x = %d\n", x);     // 50
}

int main(void) {
    demo();
    printf("Global x = %d\n", x);    // 100
    return 0;
}
```

### 5. Storage Classes

Storage class menentukan **lifetime** (berapa lama variabel hidup) dan **linkage** (bisa diakses dari file lain atau tidak).

#### `auto` — Default untuk Local Variable

```c
void demo(void) {
    auto int x = 10;   // Sama persis dengan: int x = 10;
    // 'auto' jarang ditulis eksplisit — ini default
    // Lifetime: dari deklarasi sampai keluar block
    // Linkage: none (hanya di block ini)
}
```

#### `static` — Persistent Local Variable

> **Analogi:** `static` variable di dalam function itu kayak **odometer di mobil** — setiap kali mobil dihidupkan (function dipanggil), odometer tidak reset ke 0, tapi lanjut dari angka terakhir.

```c
void hitung_panggilan(void) {
    static int count = 0;   // Inisialisasi HANYA SEKALI!
    count++;
    printf("Function ini sudah dipanggil %d kali\n", count);
}

int main(void) {
    hitung_panggilan();   // 1 kali
    hitung_panggilan();   // 2 kali
    hitung_panggilan();   // 3 kali
    return 0;
}
```

**Sifat `static` local variable:**
1. **Inisialisasi hanya SEKALI** — saat program pertama kali lewat baris itu
2. **Nilai bertahan** antar panggilan function
3. **Scope tetap lokal** — hanya bisa diakses di function itu
4. **Lifetime = sepanjang program** (bukan cuma selama function jalan)

#### `static` Function — Internal Linkage

```c
/* static function: HANYA bisa dipanggil dari file INI */
static int helper(int x) {
    return x * 2;
}

/* Function biasa: bisa di-link dari file lain */
int public_function(int x) {
    return helper(x) + 1;   // Helper hanya dipakai internal
}
```

> **Use-case:** Kalau function hanya dipakai di satu file, tandai `static`. Ini mencegah **name collision** di project multi-file dan memberi sinyal ke developer lain bahwa function itu "private".

#### `extern` — Deklarasi dari File Lain

```c
/* file: config.c */
int MAX_USERS = 100;   // Definisi variabel global

/* file: main.c */
extern int MAX_USERS;   // Deklarasi — "variabel ini didefinisikan di file lain"

int main(void) {
    printf("Max users: %d\n", MAX_USERS);
    return 0;
}
```

> `extern` dibahas lebih dalam di modul 010 (Multi-file).

#### `register` — Hint untuk Compiler

```c
void loop_cepat(void) {
    register int i;   // Hint: taruh 'i' di CPU register (bukan RAM)
    for (i = 0; i < 1000000; i++) {
        // Operasi intensif
    }
}
```

> **Praktisnya:** `register` sudah **usang** — compiler modern JAUH lebih pintar dari programmer dalam menentukan variabel mana yang perlu di-register. Jangan pakai `register` di kode baru.

### 6. Ringkasan Storage Classes

| Storage Class | Scope | Lifetime | Default Init | Linkage |
|---|---|---|---|---|
| `auto` (default) | Block | Block (temporary) | Garbage | None |
| `static` (lokal) | Block | Program (persistent) | 0 | None |
| `static` (global/func) | File | Program | 0 | Internal |
| `extern` | File/Global | Program | — | External |
| `register` | Block | Block | Garbage | None |

### 7. Best Practices: Menulis Function yang Baik

```c
/* ❌ BURUK — function terlalu panjang, banyak tanggung jawab */
void do_everything(void) {
    // 200 baris kode yang melakukan banyak hal...
}

/* ✅ BAIK — function kecil, satu tugas, nama deskriptif */
int hitung_rata2(const int data[], int n);
void cetak_header(const char *judul);
int cari_maks(const int data[], int n);
int validasi_input(int nilai, int min, int max);
```

**Prinsip:**
1. **Satu function = satu tugas** (Single Responsibility)
2. **Nama function = verb** (kata kerja) yang jelas
3. **Max ~30 baris** per function (rule of thumb)
4. **Gunakan `const`** untuk parameter yang tidak diubah
5. **Return value** untuk komunikasi, bukan global variable

---

## ⚠️ Perangkap Umum (Common Pitfalls)

### 1. Return Local Array/Pointer

```c
/* ❌ BAHAYA — arr hanya hidup selama function aktif! */
int *buat_array(void) {
    int arr[5] = {1, 2, 3, 4, 5};
    return arr;   // WARNING: return address of local variable!
    // arr MATI setelah function selesai → dangling pointer
}

/* ✅ Solusi: kirim array dari luar */
void isi_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}
```

### 2. Lupa Return Value

```c
/* ❌ Lupa return — undefined behavior (bukan compile error di beberapa compiler!) */
int tambah(int a, int b) {
    int hasil = a + b;
    // Lupa: return hasil;
}
// Compiler mungkin cuma warning, tapi hasilnya SAMPAH

/* ✅ Selalu return */
int tambah_benar(int a, int b) {
    return a + b;
}
```

### 3. Static Initialization Pitfall

```c
/* static variable hanya diinisialisasi SEKALI */
void demo(int start) {
    static int x = start;   // ⚠️ 'start' hanya dipakai PERTAMA kali!
    printf("x = %d\n", x);
    x++;
}

demo(10);   // x = 10
demo(20);   // x = 11 (BUKAN 20! static tidak re-init)
demo(30);   // x = 12
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
| 🟢 EASY | Buat fungsi `is_prime(int n)`, `gcd(int a, int b)`, dan `lcm(int a, int b)` — test dari main |
| 🟡 MEDIUM | Buat mini library statistik: `arr_min()`, `arr_max()`, `arr_mean()`, `arr_median()` — semua menerima array sebagai parameter |
| 🔴 HARD | Buat fungsi `caesar_encrypt()` dan `caesar_decrypt()` dengan **static call counter** yang menghitung total operasi enkripsi/dekripsi |

---

## 🔗 Lanjut ke

**[010 — Header, Multi-file, Preprocessor →](../010-header-multifile-preprocessor/)**
