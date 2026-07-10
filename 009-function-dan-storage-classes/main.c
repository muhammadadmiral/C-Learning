
/*
 * ============================================================
 *  009 — Function & Storage Classes: Contoh Kode Utama
 * ============================================================
 *  Compile & run:
 *    gcc -std=c17 -Wall -Wextra -Wpedantic -o program main.c
 *    ./program
 * ============================================================
 */

#include <stdio.h>
#include <string.h>

/* -------------------------------------------------------
 * Function Prototypes
 * ------------------------------------------------------- */
int tambah(int a, int b);
int kuadrat(int x);
void sapa(const char *nama);
void garis(void);
void coba_ubah(int x);
void ubah_beneran(int *ptr);
void isi_array(int arr[], int n);
void print_array(const int arr[], int n);
void hitung_panggilan(void);
int counter_value(void);
void scope_demo(void);
static int helper_internal(int x);
int fibonacci(int n);

/* Global variable (untuk demo — hindari di real code!) */
int g_total_calls = 0;

int main(void) {

  printf("╔══════════════════════════════════════════╗\n");
  printf("║  009 — Function & Storage Classes        ║\n");
  printf("╚══════════════════════════════════════════╝\n\n");

  /* -------------------------------------------------------
   * 1. FUNCTION BASICS
   * ------------------------------------------------------- */
  printf("--- 1. Function Basics ---\n\n");

  /* Function dengan return value */
  int hasil = tambah(15, 27);
  printf("  tambah(15, 27) = %d\n", hasil);
  printf("  kuadrat(9)     = %d\n", kuadrat(9));

  /* Void function */
  sapa("Budi");
  sapa("Andi");

  /* Function tanpa parameter */
  garis();

  /* Nested calls */
  printf("  kuadrat(tambah(3, 4)) = %d\n", kuadrat(tambah(3, 4)));

  /* -------------------------------------------------------
   * 2. PASS BY VALUE
   * ------------------------------------------------------- */
  printf("\n--- 2. Pass by Value ---\n\n");

  int angka = 42;
  printf("  Sebelum coba_ubah(): angka = %d\n", angka);
  coba_ubah(angka);
  printf("  Sesudah coba_ubah(): angka = %d (TIDAK BERUBAH)\n", angka);

  /* Pass by "reference" via pointer */
  printf("\n  Sebelum ubah_beneran(): angka = %d\n", angka);
  ubah_beneran(&angka);
  printf("  Sesudah ubah_beneran(): angka = %d (BERUBAH!)\n", angka);

  /* -------------------------------------------------------
   * 3. ARRAY SEBAGAI PARAMETER
   * ------------------------------------------------------- */
  printf("\n--- 3. Array sebagai Parameter ---\n\n");

  int data[5] = {0};
  printf("  Sebelum isi_array(): ");
  print_array(data, 5);

  isi_array(data, 5);
  printf("  Sesudah isi_array(): ");
  print_array(data, 5);

  printf("  Array SELALU di-pass by reference (pointer decay)\n");

  /* -------------------------------------------------------
   * 4. SCOPE DEMO
   * ------------------------------------------------------- */
  printf("\n--- 4. Scope Demo ---\n\n");
  scope_demo();

  /* -------------------------------------------------------
   * 5. STATIC VARIABLE — Persistent State
   * ------------------------------------------------------- */
  printf("\n--- 5. Static Variable ---\n\n");

  for (int i = 0; i < 5; i++) {
    hitung_panggilan();
  }
  printf("  Total panggilan (via getter): %d\n", counter_value());

  /* -------------------------------------------------------
   * 6. STATIC FUNCTION — Internal Linkage
   * ------------------------------------------------------- */
  printf("\n--- 6. Static Function ---\n\n");

  /* helper_internal() hanya bisa dipanggil dari file ini */
  printf("  helper_internal(21) = %d\n", helper_internal(21));
  printf("  (Function ini static — tidak bisa diakses dari file lain)\n");

  /* -------------------------------------------------------
   * 7. GLOBAL VARIABLE (demo — jangan ditiru!)
   * ------------------------------------------------------- */
  printf("\n--- 7. Global Variable (anti-pattern demo) ---\n\n");

  printf("  g_total_calls = %d\n", g_total_calls);
  g_total_calls += 10;
  printf("  Setelah += 10 : %d\n", g_total_calls);
  printf("  ⚠️  Hindari global variable di real code!\n");

  /* -------------------------------------------------------
   * 8. FIBONACCI — contoh function yang lebih kompleks
   * ------------------------------------------------------- */
  printf("\n--- 8. Fibonacci (demo function call) ---\n\n");

  printf("  Fibonacci sequence: ");
  for (int i = 0; i < 12; i++) {
    printf("%d ", fibonacci(i));
  }
  printf("\n");

  /* -------------------------------------------------------
   * 9. MULTIPLE RETURN DEMO (via pointer parameter)
   * ------------------------------------------------------- */
  printf("\n--- 9. Multiple Return Values (via pointer) ---\n\n");

  int min_val, max_val;
  int values[] = {42, 17, 85, 3, 56, 91, 28};
  int v_size = sizeof(values) / sizeof(values[0]);

  /* Function yang "return" 2 nilai via pointer */
  void find_min_max(const int arr[], int n, int *out_min, int *out_max);
  find_min_max(values, v_size, &min_val, &max_val);

  printf("  Array: ");
  print_array(values, v_size);
  printf("  Min = %d, Max = %d\n", min_val, max_val);

  printf("\n========================================\n");
  printf("Selesai! Lanjut ke modul 010 (Header & Multi-file).\n");

  return 0;
}

/* -------------------------------------------------------
 * IMPLEMENTASI FUNCTION
 * ------------------------------------------------------- */

int tambah(int a, int b) { return a + b; }

int kuadrat(int x) { return x * x; }

void sapa(const char *nama) { printf("  Halo, %s! 👋\n", nama); }

void garis(void) { printf("  ────────────────────────────\n"); }

void coba_ubah(int x) {
  x = 999; /* Ubah COPY, bukan asli */
  printf("  Di dalam coba_ubah(): x = %d\n", x);
}

void ubah_beneran(int *ptr) {
  *ptr = 999; /* Ubah nilai di alamat yang ditunjuk */
}

void isi_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    arr[i] = (i + 1) * 10; /* Mengubah array ASLI */
  }
}

void print_array(const int arr[], int n) {
  printf("[");
  for (int i = 0; i < n; i++) {
    printf("%d", arr[i]);
    if (i < n - 1)
      printf(", ");
  }
  printf("]\n");
}

void hitung_panggilan(void) {
  static int count = 0; /* Inisialisasi HANYA SEKALI */
  count++;
  printf("  Panggilan ke-%d\n", count);
}

int counter_value(void) {
  static int val = 0;
  val++;
  return val;
}

void scope_demo(void) {
  int outer = 100;
  printf("  outer = %d\n", outer);

  { /* Block baru */
    int inner = 200;
    int outer = 999; /* Shadow — menutupi outer yang di atas */
    printf("  inner block: outer = %d, inner = %d\n", outer, inner);
  }

  printf("  Kembali ke luar: outer = %d\n", outer);
  /* inner dan shadow outer sudah mati di sini */
}

/* Static function — hanya bisa diakses dari file ini */
static int helper_internal(int x) { return x * 2 + 1; }

/* Fibonacci iteratif (rekursif akan dibahas di modul 011) */
int fibonacci(int n) {
  if (n <= 0)
    return 0;
  if (n == 1)
    return 1;

  int prev = 0, curr = 1;
  for (int i = 2; i <= n; i++) {
    int next = prev + curr;
    prev = curr;
    curr = next;
  }
  return curr;
}

/* Function dengan "multiple return" via pointer parameters */
void find_min_max(const int arr[], int n, int *out_min, int *out_max) {
  *out_min = arr[0];
  *out_max = arr[0];

  for (int i = 1; i < n; i++) {
    if (arr[i] < *out_min)
      *out_min = arr[i];
    if (arr[i] > *out_max)
      *out_max = arr[i];
  }
}
