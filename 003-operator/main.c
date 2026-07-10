/*
 * ============================================================
 *  003 — Operator: Contoh Kode Utama
 * ============================================================
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o program main.c
 *    ./program
 * ============================================================
 */

#include <stdio.h>

int main(void) {

    printf("╔══════════════════════════════════════════╗\n");
    printf("║  003 — Operator                          ║\n");
    printf("╚══════════════════════════════════════════╝\n\n");

    /* -------------------------------------------------------
     * 1. OPERATOR ARITMATIKA
     * ------------------------------------------------------- */
    printf("--- 1. Operator Aritmatika ---\n");

    int a = 17, b = 5;
    printf("  a = %d, b = %d\n", a, b);
    printf("  a + b  = %d\n", a + b);     /* Penjumlahan  : 22 */
    printf("  a - b  = %d\n", a - b);     /* Pengurangan  : 12 */
    printf("  a * b  = %d\n", a * b);     /* Perkalian    : 85 */
    printf("  a / b  = %d\n", a / b);     /* Pembagian    : 3 (integer division!) */
    printf("  a %% b = %d\n", a % b);     /* Modulo (sisa): 2 */

    /* Integer division vs floating-point division */
    printf("\n  Integer division : 7 / 2   = %d\n", 7 / 2);
    printf("  Float division   : 7.0 / 2 = %f\n", 7.0 / 2);
    printf("  Cast division    : (double)7 / 2 = %f\n\n", (double)7 / 2);

    /* -------------------------------------------------------
     * 2. OPERATOR RELASIONAL (PERBANDINGAN)
     *    Mengembalikan 1 (true) atau 0 (false)
     * ------------------------------------------------------- */
    printf("--- 2. Operator Relasional ---\n");

    int x = 10, y = 20;
    printf("  x = %d, y = %d\n", x, y);
    printf("  x == y : %d\n", x == y);    /* 0 (false) */
    printf("  x != y : %d\n", x != y);    /* 1 (true) */
    printf("  x > y  : %d\n", x > y);     /* 0 (false) */
    printf("  x < y  : %d\n", x < y);     /* 1 (true) */
    printf("  x >= 10: %d\n", x >= 10);   /* 1 (true) */
    printf("  y <= 15: %d\n\n", y <= 15); /* 0 (false) */

    /* -------------------------------------------------------
     * 3. OPERATOR LOGIKA
     *    && = AND, || = OR, ! = NOT
     * ------------------------------------------------------- */
    printf("--- 3. Operator Logika ---\n");

    int umur = 20;
    int punya_ktp = 1;   /* 1 = true, 0 = false */

    printf("  umur = %d, punya_ktp = %d\n", umur, punya_ktp);
    printf("  umur >= 17 && punya_ktp : %d (boleh vote?)\n",
           umur >= 17 && punya_ktp);
    printf("  umur < 17 || !punya_ktp : %d (tidak boleh vote?)\n",
           umur < 17 || !punya_ktp);
    printf("  !punya_ktp              : %d (negasi)\n\n", !punya_ktp);

    /* Short-circuit evaluation demo */
    printf("  Short-circuit demo:\n");
    int denominator = 0;
    /*
     * Tanpa short-circuit, 10 / denominator akan CRASH (division by zero).
     * Tapi karena denominator != 0 sudah false, bagian kanan tidak dievaluasi.
     */
    if (denominator != 0 && 10 / denominator > 2) {
        printf("  Ini tidak akan dicetak\n");
    } else {
        printf("  Short-circuit mencegah division by zero!\n\n");
    }

    /* -------------------------------------------------------
     * 4. OPERATOR ASSIGNMENT (compound)
     * ------------------------------------------------------- */
    printf("--- 4. Compound Assignment ---\n");

    int saldo = 100;
    printf("  Saldo awal  : %d\n", saldo);

    saldo += 50;    /* saldo = saldo + 50 */
    printf("  += 50       : %d\n", saldo);

    saldo -= 30;    /* saldo = saldo - 30 */
    printf("  -= 30       : %d\n", saldo);

    saldo *= 2;     /* saldo = saldo * 2 */
    printf("  *= 2        : %d\n", saldo);

    saldo /= 4;     /* saldo = saldo / 4 */
    printf("  /= 4        : %d\n", saldo);

    saldo %= 7;     /* saldo = saldo % 7 */
    printf("  %%= 7       : %d\n\n", saldo);

    /* -------------------------------------------------------
     * 5. INCREMENT & DECREMENT: PREFIX vs POSTFIX
     * ------------------------------------------------------- */
    printf("--- 5. Prefix vs Postfix ---\n");

    int p = 5;
    int q;

    /* Prefix: tambah DULU, baru pakai */
    q = ++p;    /* p naik jadi 6, lalu q = 6 */
    printf("  Prefix:  p = 5, q = ++p  -> p = %d, q = %d\n", p, q);

    p = 5;  /* Reset */

    /* Postfix: pakai DULU, baru tambah */
    q = p++;    /* q = 5 (nilai lama p), lalu p naik jadi 6 */
    printf("  Postfix: p = 5, q = p++  -> p = %d, q = %d\n\n", p, q);

    /* -------------------------------------------------------
     * 6. OPERATOR BITWISE
     * ------------------------------------------------------- */
    printf("--- 6. Operator Bitwise ---\n");

    unsigned int m = 0xA;    /* 10 desimal = 1010 biner */
    unsigned int n = 0xC;    /* 12 desimal = 1100 biner */

    printf("  m = 0xA (1010 = 10), n = 0xC (1100 = 12)\n");
    printf("  m & n  = %u  (AND:  1010 & 1100 = 1000)\n", m & n);   /* 8 */
    printf("  m | n  = %u (OR:   1010 | 1100 = 1110)\n", m | n);    /* 14 */
    printf("  m ^ n  = %u  (XOR:  1010 ^ 1100 = 0110)\n", m ^ n);   /* 6 */

    /* Shift operators */
    unsigned int shift_val = 1;
    printf("\n  Left shift  : 1 << 0 = %u\n", shift_val << 0);    /* 1 */
    printf("  Left shift  : 1 << 1 = %u\n", shift_val << 1);      /* 2 */
    printf("  Left shift  : 1 << 2 = %u\n", shift_val << 2);      /* 4 */
    printf("  Left shift  : 1 << 3 = %u\n", shift_val << 3);      /* 8 */
    printf("  (Left shift n = kalikan dengan 2^n)\n");

    unsigned int big = 16;
    printf("\n  Right shift : 16 >> 1 = %u\n", big >> 1);     /* 8 */
    printf("  Right shift : 16 >> 2 = %u\n", big >> 2);       /* 4 */
    printf("  (Right shift n = bagi dengan 2^n)\n\n");

    /* -------------------------------------------------------
     * 7. REAL WORLD: Bit Flags Permission System
     *    Seperti Linux chmod (rwx = 421)
     * ------------------------------------------------------- */
    printf("--- 7. Bit Flags: Permission System ---\n");

    #define PERM_READ    (1 << 0)   /* 001 = 1 */
    #define PERM_WRITE   (1 << 1)   /* 010 = 2 */
    #define PERM_EXECUTE (1 << 2)   /* 100 = 4 */

    unsigned int perm = 0;   /* Mulai tanpa izin */
    printf("  Awal        : perm = %u (tidak ada izin)\n", perm);

    /* SET permission: pakai OR (|=) */
    perm |= PERM_READ;
    perm |= PERM_WRITE;
    printf("  Set R+W     : perm = %u (READ + WRITE)\n", perm);

    /* CHECK permission: pakai AND (&) */
    printf("  Has READ?   : %s\n", (perm & PERM_READ) ? "Ya" : "Tidak");
    printf("  Has EXEC?   : %s\n", (perm & PERM_EXECUTE) ? "Ya" : "Tidak");

    /* REMOVE permission: pakai AND NOT (&= ~) */
    perm &= ~PERM_WRITE;
    printf("  Remove W    : perm = %u (hanya READ)\n", perm);

    /* TOGGLE permission: pakai XOR (^=) */
    perm ^= PERM_EXECUTE;
    printf("  Toggle EXEC : perm = %u (READ + EXECUTE)\n\n", perm);

    /* -------------------------------------------------------
     * 8. OPERATOR PRECEDENCE DEMO
     * ------------------------------------------------------- */
    printf("--- 8. Operator Precedence ---\n");

    int result;

    /* Tanpa tanda kurung: * punya prioritas lebih tinggi dari + */
    result = 2 + 3 * 4;     /* = 2 + (3*4) = 2 + 12 = 14 */
    printf("  2 + 3 * 4         = %d  (bukan 20!)\n", result);

    /* Dengan tanda kurung: paksa penjumlahan dulu */
    result = (2 + 3) * 4;   /* = 5 * 4 = 20 */
    printf("  (2 + 3) * 4       = %d\n", result);

    /* Precedence bisa bikin bingung di bitwise! */
    /*
     * PERINGATAN: == punya precedence LEBIH TINGGI dari &
     * Jadi: x & 1 == 0 dievaluasi sebagai x & (1 == 0) = x & 0 = 0
     * BUKAN (x & 1) == 0 seperti yang diharapkan!
     */
    int val = 6;
    /*
     * PERINGATAN: & punya precedence LEBIH RENDAH dari ==
     * val & 1 == 0  dievaluasi sebagai  val & (1 == 0) = val & 0 = 0
     * (val & 1) == 0  baru benar: ambil bit terakhir, cek apakah 0
     */
    printf("  val & (1 == 0)     = %d  (BUKAN cek genap! precedence & < ==)\n",
           (val & (1 == 0)));
    printf("  (val & 1) == 0     = %d  (BENAR: cek genap)\n", (val & 1) == 0);
    printf("\n  LESSON: Selalu pakai () untuk bitwise + comparison!\n");

    printf("\n========================================\n");
    printf("Selesai! Lanjut ke modul 004 (Input/Output).\n");

    return 0;
}
