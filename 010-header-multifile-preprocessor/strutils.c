/*
2 * ============================================================
 *  010 — strutils.c: Implementasi String Utilities
 * ============================================================
 */

#include "strutils.h"
#include <ctype.h>
#include <string.h>

/* -------------------------------------------------------
 * String Info
 * ------------------------------------------------------- */

int str_count_words(const char *s) {
  int count = 0;
  int in_word = 0;

  while (*s) {
    if (isspace(*s)) {
      in_word = 0;
    } else if (!in_word) {
      in_word = 1;
      count++;
    }
    s++;
  }

  return count;
}

int str_count_char(const char *s, char c) {
  int count = 0;
  while (*s) {
    if (*s == c)
      count++;
    s++;
  }
  return count;
}

/* -------------------------------------------------------
 * String Transform
 * ------------------------------------------------------- */

void str_to_upper(char *s) {
  while (*s) {
    *s = toupper(*s);
    s++;
  }
}

void str_to_lower(char *s) {
  while (*s) {
    *s = tolower(*s);
    s++;
  }
}

void str_trim_newline(char *s) { s[strcspn(s, "\n")] = '\0'; }

void str_reverse(char *s) {
  int len = strlen(s);
  for (int i = 0, j = len - 1; i < j; i++, j--) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}

/* -------------------------------------------------------
 * String Check
 * ------------------------------------------------------- */

int str_is_palindrome(const char *s) {
  int len = strlen(s);
  if (len <= 1)
    return 1;

  int left = 0;
  int right = len - 1;

  while (left < right) {
    while (left < right && !isalpha(s[left]))
      left++;
    while (left < right && !isalpha(s[right]))
      right--;

    if (tolower(s[left]) != tolower(s[right])) {
      return 0;
    }
    left++;
    right--;
  }
  return 1;
}

int str_starts_with(const char *s, const char *prefix) {
  return strncmp(s, prefix, strlen(prefix)) == 0;
}

int str_ends_with(const char *s, const char *suffix) {
  size_t s_len = strlen(s);
  size_t suf_len = strlen(suffix);

  if (suf_len > s_len)
    return 0;

  return strcmp(s + s_len - suf_len, suffix) == 0;
}
