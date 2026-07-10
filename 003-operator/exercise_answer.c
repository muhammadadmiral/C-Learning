/*
 * ============================================================
 *  003 — Operator: Jawaban Latihan
 * ============================================================
 *  SPOILER ALERT! Kerjakan exercise.c dulu.
 *
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o answer exercise_answer.c
 *    ./answer
 * ============================================================
 */

#include <stdio.h>

int main(void) {

    /* ============================================
     * LEVEL 1: EASY — Kalkulator Geometri
     * ============================================ */
    printf("=== LEVEL 1: Kalkulator Geometri ===\n\n");

    int panjang = 12;
    int lebar = 5;

    int luas     = panjang * lebar;
    int keliling = 2 * (panjang + lebar);
    int diag_sq  = panjang * panjang + lebar * lebar;
    int sisa     = panjang % lebar;

    printf("  Panjang  : %d\n", panjang);
    printf("  Lebar    : %d\n", lebar);
    printf("  Luas     : %d\n", luas);
    printf("  Keliling : %d\n", keliling);
    printf("  p^2+l^2  : %d  (= diagonal^2, tanpa sqrt)\n", diag_sq);
    printf("  p %% l   : %d\n", sisa);
    printf("  p / l    : %d    (integer division)\n", panjang / lebar);
    printf("  p / l    : %.2f (float division)\n\n", (double)panjang / lebar);

    /* ============================================
     * LEVEL 2: MEDIUM — Bit Flags: Status Player
     * ============================================ */
    printf("=== LEVEL 2: Bit Flags: Status Player ===\n\n");

    #define STATUS_ALIVE     (1 << 0)   /* 0001 = 1 */
    #define STATUS_POISONED  (1 << 1)   /* 0010 = 2 */
    #define STATUS_SHIELDED  (1 << 2)   /* 0100 = 4 */
    #define STATUS_ON_FIRE   (1 << 3)   /* 1000 = 8 */

    /* Macro helper untuk cek status (menghasilkan "Ya" atau "Tidak") */
    #define CHECK(status, flag) (((status) & (flag)) ? "Ya" : "Tidak")

    unsigned int player_status = 0;

    /* a. SET: ALIVE + SHIELDED */
    player_status |= STATUS_ALIVE;
    player_status |= STATUS_SHIELDED;
    printf("  [a] Set ALIVE + SHIELDED\n");
    printf("      Status: %u | Alive: %s, Poisoned: %s, Shielded: %s, On Fire: %s\n",
           player_status,
           CHECK(player_status, STATUS_ALIVE),
           CHECK(player_status, STATUS_POISONED),
           CHECK(player_status, STATUS_SHIELDED),
           CHECK(player_status, STATUS_ON_FIRE));

    /* b. SET: kena poison */
    player_status |= STATUS_POISONED;
    printf("  [b] Kena poison! SET POISONED\n");
    printf("      Status: %u | Alive: %s, Poisoned: %s, Shielded: %s, On Fire: %s\n",
           player_status,
           CHECK(player_status, STATUS_ALIVE),
           CHECK(player_status, STATUS_POISONED),
           CHECK(player_status, STATUS_SHIELDED),
           CHECK(player_status, STATUS_ON_FIRE));

    /* c. REMOVE: shield pecah */
    player_status &= ~STATUS_SHIELDED;
    printf("  [c] Shield pecah! REMOVE SHIELDED\n");
    printf("      Status: %u | Alive: %s, Poisoned: %s, Shielded: %s, On Fire: %s\n",
           player_status,
           CHECK(player_status, STATUS_ALIVE),
           CHECK(player_status, STATUS_POISONED),
           CHECK(player_status, STATUS_SHIELDED),
           CHECK(player_status, STATUS_ON_FIRE));

    /* d. TOGGLE: nyalain api */
    player_status ^= STATUS_ON_FIRE;
    printf("  [d] Toggle ON_FIRE (nyala)\n");
    printf("      Status: %u | Alive: %s, Poisoned: %s, Shielded: %s, On Fire: %s\n",
           player_status,
           CHECK(player_status, STATUS_ALIVE),
           CHECK(player_status, STATUS_POISONED),
           CHECK(player_status, STATUS_SHIELDED),
           CHECK(player_status, STATUS_ON_FIRE));

    /* e. TOGGLE: matiin api */
    player_status ^= STATUS_ON_FIRE;
    printf("  [e] Toggle ON_FIRE (mati)\n");
    printf("      Status: %u | Alive: %s, Poisoned: %s, Shielded: %s, On Fire: %s\n\n",
           player_status,
           CHECK(player_status, STATUS_ALIVE),
           CHECK(player_status, STATUS_POISONED),
           CHECK(player_status, STATUS_SHIELDED),
           CHECK(player_status, STATUS_ON_FIRE));

    /* ============================================
     * LEVEL 3: HARD — Precedence Puzzle
     * ============================================ */
    printf("=== LEVEL 3: Precedence Puzzle ===\n\n");

    /* 1. */
    int r1 = 2 + 3 * 4 - 1;
    /* Prediksi: 2 + (3*4) - 1 = 2 + 12 - 1 = 13 */
    printf("  1. 2 + 3 * 4 - 1      = %d  (prediksi: 13)\n", r1);

    /* 2. */
    int r2 = (2 + 3) * (4 - 1);
    /* Prediksi: 5 * 3 = 15 */
    printf("  2. (2+3) * (4-1)      = %d  (prediksi: 15)\n", r2);

    /* 3. */
    int r3 = 10 % 3 + 10 / 3;
    /* Prediksi: (10%3) + (10/3) = 1 + 3 = 4
     * % dan / punya precedence sama, evaluasi kiri-ke-kanan */
    printf("  3. 10 %% 3 + 10 / 3   = %d   (prediksi: 4)\n", r3);

    /* 4. */
    /*
     * int a = 5;
     * int r4 = a++ + ++a;
     *
     * INI ADALAH UNDEFINED BEHAVIOR (UB)!
     * Modifikasi variabel yang sama lebih dari sekali dalam satu ekspresi
     * tanpa sequence point = UB. Hasilnya bisa BERBEDA di compiler yang
     * berbeda (GCC vs Clang vs MSVC bisa kasih output beda).
     *
     * Jawaban yang benar: "UB — jangan pernah tulis kode seperti ini."
     */
    printf("  4. a++ + ++a          = UB! (Undefined Behavior, skip)\n");

    /* 5. */
    int r5 = 1 << 4 | 1 << 2;
    /* Prediksi: (1<<4) | (1<<2) = 16 | 4 = 10000 | 00100 = 10100 = 20 */
    printf("  5. 1<<4 | 1<<2        = %d  (prediksi: 20)\n", r5);

    /* 6. */
    int r6 = 15 & 0xF0;
    /* Prediksi:
     * 15   = 0000 1111
     * 0xF0 = 1111 0000
     * AND  = 0000 0000 = 0 */
    printf("  6. 15 & 0xF0          = %d   (prediksi: 0)\n", r6);

    /* 7. */
    int val = 42;
    int r7 = ((val > 40) && (val < 50)) || (val == 100);
    /* Prediksi:
     * (42 > 40) = 1 (true)
     * (42 < 50) = 1 (true)
     * 1 && 1 = 1 (true)
     * (42 == 100) = 0 (false)
     * 1 || 0 = 1 (true)
     * && punya precedence lebih tinggi dari ||
     */
    printf("  7. (42>40)&&(42<50)||(42==100) = %d   (prediksi: 1)\n", r7);

    return 0;
}
