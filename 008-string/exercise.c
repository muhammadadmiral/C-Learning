/*
 * ============================================================
 *  008 — String: Latihan
 * ============================================================
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o exercise exercise.c
 *    ./exercise
 * ============================================================
 */

#include <stdio.h>
#include <string.h>

int main(void) {

    /* ============================================
     * LEVEL 1: EASY — Hitung Karakter
     * ============================================
     * Tugas:
     * 1. Minta user input sebuah kalimat (pakai fgets, max 200 char)
     * 2. Hitung dan tampilkan:
     *    - Jumlah vowel (a, e, i, o, u — case insensitive)
     *    - Jumlah consonant (huruf selain vowel)
     *    - Jumlah digit (0-9)
     *    - Jumlah spasi
     *    - Jumlah karakter lain (simbol, tanda baca, dll)
     *
     * Contoh output:
     *   Input   : "Hello World 123!"
     *   Vowel   : 3 (e, o, o)
     *   Consonant: 7 (H, l, l, W, r, l, d)
     *   Digit   : 3 (1, 2, 3)
     *   Spasi   : 2
     *   Lainnya : 1 (!)
     *
     * Tips:
     *   - Cek huruf: (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
     *   - Atau pakai tolower() dari <ctype.h>
     *   - Cek digit: c >= '0' && c <= '9'
     */

    // TODO: Tulis kode lu di sini


    /* ============================================
     * LEVEL 2: MEDIUM — Reverse String & Palindrome
     * ============================================
     * Tugas:
     * 1. Buat fungsi my_strrev(char *str) yang membalik string
     *    IN-PLACE (tanpa array tambahan)
     *    Contoh: "Hello" → "olleH"
     *
     * 2. Buat fungsi int is_palindrome(const char *str) yang
     *    mengecek apakah string adalah palindrome
     *    (dibaca dari depan dan belakang sama)
     *    Return 1 kalau palindrome, 0 kalau bukan
     *    Case-insensitive! "Katak" → palindrome (katak ↔ katak)
     *
     * 3. Test dengan beberapa input:
     *    - "racecar" → palindrome ✅
     *    - "Katak" → palindrome ✅
     *    - "hello" → bukan palindrome ❌
     *    - "madam" → palindrome ✅
     *    - "A" → palindrome ✅
     *    - "" → palindrome ✅ (string kosong = palindrome)
     *
     * Tips:
     *   - Reverse in-place: swap str[0]↔str[len-1], str[1]↔str[len-2], ...
     *   - Palindrome: bandingkan tanpa mengubah string asli!
     *     Jangan pakai my_strrev untuk cek palindrome (itu mengubah string)
     *   - Case insensitive: bandingkan tolower(str[i]) == tolower(str[j])
     */

    // TODO: Tulis kode lu di sini


    /* ============================================
     * LEVEL 3: HARD — Word Counter & Frequency
     * ============================================
     * Tugas:
     * 1. Minta user input sebuah kalimat (max 500 char)
     * 2. Pecah kalimat jadi kata-kata (pisah by spasi)
     * 3. Hitung total kata
     * 4. Tampilkan setiap kata UNIK beserta frekuensinya
     *    (case insensitive — "The" dan "the" dihitung sama)
     *
     * Contoh output:
     *   Input: "the cat sat on the mat the cat"
     *
     *   Total kata: 8
     *   Kata unik : 5
     *
     *   Frekuensi:
     *     "the" : 3
     *     "cat" : 2
     *     "sat" : 1
     *     "on"  : 1
     *     "mat" : 1
     *
     * Tips:
     *   - Pakai strtok untuk pecah kata (⚠️ strtok merusak string asli!)
     *   - Simpan kata unik di array of string: char words[100][50]
     *   - Simpan frekuensi di array int: int freq[100]
     *   - Untuk case insensitive, convert ke lowercase sebelum bandingkan
     *   - Hati-hati: strtok modifikasi string asli, jadi copy dulu
     *     kalau masih butuh string aslinya
     */

    // TODO: Tulis kode lu di sini


    return 0;
}
