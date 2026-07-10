/*
 * ============================================================
 *  002 — Variabel & Tipe Data: Contoh Kode Utama
 * ============================================================
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o program main.c
 *    ./program
 * ============================================================
 */

#include <stdio.h>
#include <limits.h>   /* Batas nilai integer: INT_MAX, INT_MIN, dll */
#include <float.h>    /* Batas nilai float/double: FLT_MAX, DBL_MAX, dll */

int main(void) {

    printf("╔══════════════════════════════════════════╗\n");
    printf("║  002 — Variabel & Tipe Data              ║\n");
    printf("╚══════════════════════════════════════════╝\n\n");

    /* -------------------------------------------------------
     * 1. DEKLARASI vs INISIALISASI
     * ------------------------------------------------------- */
    printf("--- 1. Deklarasi vs Inisialisasi ---\n");

    int umur;               /* Deklarasi saja — belum diisi (BAHAYA!) */
    umur = 25;              /* Inisialisasi — baru sekarang diisi */

    int tinggi = 175;       /* Deklarasi + Inisialisasi sekaligus (RECOMMENDED) */

    printf("  Umur   : %d tahun\n", umur);
    printf("  Tinggi : %d cm\n\n", tinggi);

    /* -------------------------------------------------------
     * 2. SEMUA TIPE DATA INTEGER
     * ------------------------------------------------------- */
    printf("--- 2. Tipe Data Integer ---\n");

    char   huruf       = 'A';          /* 1 byte — karakter ASCII */
    short  angka_kecil = 1000;         /* 2 byte — bilangan kecil */
    int    angka       = 2000000;      /* 4 byte — DEFAULT bilangan bulat */
    long   angka_besar = 3000000000L;  /* 4-8 byte — bilangan besar */
    long long angka_huge = 9000000000000000000LL; /* 8 byte — sangat besar */

    printf("  char          : '%c' (ASCII: %d)\n", huruf, huruf);
    printf("  short         : %hd\n", angka_kecil);
    printf("  int           : %d\n", angka);
    printf("  long          : %ld\n", angka_besar);
    printf("  long long     : %lld\n\n", angka_huge);

    /* -------------------------------------------------------
     * 3. UNSIGNED — bilangan non-negatif, range 2x lipat
     * ------------------------------------------------------- */
    printf("--- 3. Unsigned Integer ---\n");

    unsigned char   uc = 255;           /* 0 s.d. 255 */
    unsigned int    ui = 4000000000U;   /* 0 s.d. ~4.2 miliar */
    unsigned long long ull = 18000000000000000000ULL;

    printf("  unsigned char      : %u\n", uc);
    printf("  unsigned int       : %u\n", ui);
    printf("  unsigned long long : %llu\n\n", ull);

    /* -------------------------------------------------------
     * 4. FLOATING-POINT — bilangan desimal
     * ------------------------------------------------------- */
    printf("--- 4. Floating-Point ---\n");

    float  ipk     = 3.75f;            /* 4 byte, presisi ~7 digit */
    double pi      = 3.14159265358979; /* 8 byte, presisi ~15 digit */
    long double e  = 2.71828182845904523536L; /* 8-16 byte */

    printf("  float       : %.2f\n", ipk);       /* 2 angka di belakang koma */
    printf("  double      : %.14f\n", pi);        /* 14 angka di belakang koma */
    printf("  long double : %.18Lf\n\n", e);      /* 18 angka di belakang koma */

    /*
     * Catatan format specifier floating-point:
     *   %f    = float/double (di printf, float dipromosi ke double)
     *   %Lf   = long double
     *   %.Nf  = N digit di belakang koma (contoh: %.2f = 2 digit)
     */

    /* -------------------------------------------------------
     * 5. CHAR sebagai INTEGER — konversi ASCII
     * ------------------------------------------------------- */
    printf("--- 5. Char & ASCII ---\n");

    char ch = 'Z';
    printf("  Karakter   : %c\n", ch);
    printf("  Kode ASCII : %d\n", ch);

    /* Trik konversi huruf besar <-> kecil */
    char lower = ch + 32;     /* 'Z' (90) + 32 = 'z' (122) */
    printf("  '%c' + 32  = '%c'\n\n", ch, lower);

    /* -------------------------------------------------------
     * 6. sizeof() — ukuran tipe data dalam byte
     * ------------------------------------------------------- */
    printf("--- 6. sizeof() [Ukuran dalam Byte] ---\n");

    printf("  sizeof(char)        = %zu byte\n", sizeof(char));
    printf("  sizeof(short)       = %zu byte\n", sizeof(short));
    printf("  sizeof(int)         = %zu byte\n", sizeof(int));
    printf("  sizeof(long)        = %zu byte\n", sizeof(long));
    printf("  sizeof(long long)   = %zu byte\n", sizeof(long long));
    printf("  sizeof(float)       = %zu byte\n", sizeof(float));
    printf("  sizeof(double)      = %zu byte\n", sizeof(double));
    printf("  sizeof(long double) = %zu byte\n\n", sizeof(long double));

    /* -------------------------------------------------------
     * 7. TYPE CASTING — konversi tipe data
     * ------------------------------------------------------- */
    printf("--- 7. Type Casting ---\n");

    /* Implicit casting (otomatis, aman) */
    int    bilangan_bulat = 42;
    double bilangan_desimal = bilangan_bulat;  /* int -> double otomatis */
    printf("  Implicit: int %d -> double %f\n", bilangan_bulat, bilangan_desimal);

    /* Explicit casting (manual, HATI-HATI) */
    double pi_val = 3.14159;
    int    pi_bulat = (int)pi_val;              /* double -> int: desimal HILANG */
    printf("  Explicit: double %.5f -> int %d (desimal hilang!)\n", pi_val, pi_bulat);

    /* Integer division trap */
    int a = 7, b = 2;
    printf("  7 / 2          = %d   (integer division, desimal dibuang)\n", a / b);
    printf("  (double)7 / 2  = %.1f (cast ke double dulu)\n\n", (double)a / b);

    /* -------------------------------------------------------
     * 8. OVERFLOW — batas tipe data terlampaui
     * ------------------------------------------------------- */
    printf("--- 8. Batas Tipe Data (dari <limits.h>) ---\n");

    printf("  INT_MIN    = %d\n", INT_MIN);
    printf("  INT_MAX    = %d\n", INT_MAX);
    printf("  UINT_MAX   = %u\n", UINT_MAX);
    printf("  CHAR_MIN   = %d\n", CHAR_MIN);
    printf("  CHAR_MAX   = %d\n", CHAR_MAX);
    printf("  LLONG_MAX  = %lld\n", LLONG_MAX);
    printf("  FLT_MAX    = %e\n", FLT_MAX);
    printf("  DBL_MAX    = %e\n\n", DBL_MAX);

    /* Demo unsigned overflow (terdefinisi, aman) */
    printf("--- Unsigned Overflow Demo ---\n");
    unsigned int u_max = UINT_MAX;
    printf("  UINT_MAX       = %u\n", u_max);
    printf("  UINT_MAX + 1   = %u (wrap around ke 0)\n\n", u_max + 1);

    /* -------------------------------------------------------
     * 9. KONSTANTA — nilai yang tidak berubah
     * ------------------------------------------------------- */
    printf("--- 9. Konstanta ---\n");

    const int MAX_SISWA = 40;
    /* MAX_SISWA = 50;  <-- Ini akan ERROR saat compile */

    #define NAMA_SEKOLAH "SMA Coding 1"
    /* #define = text replacement oleh preprocessor */

    printf("  const int MAX_SISWA    = %d\n", MAX_SISWA);
    printf("  #define NAMA_SEKOLAH   = %s\n\n", NAMA_SEKOLAH);

    /* -------------------------------------------------------
     * 10. SCOPE — cakupan variabel
     * ------------------------------------------------------- */
    printf("--- 10. Scope ---\n");

    int x = 100;   /* x hidup di seluruh main() */
    printf("  Luar blok  : x = %d\n", x);

    {
        int y = 200;   /* y HANYA hidup di dalam blok {} ini */
        printf("  Dalam blok : x = %d, y = %d\n", x, y);
    }

    /* printf("  y = %d\n", y);  <-- ERROR! y sudah "mati" di luar blok */
    printf("  Luar blok  : x = %d (y sudah tidak bisa diakses)\n", x);

    printf("\n========================================\n");
    printf("Selesai! Lanjut ke modul 003 (Operator).\n");

    return 0;
}
