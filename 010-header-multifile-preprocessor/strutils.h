/*
 * ============================================================
 *  010 — strutils.h: Header untuk String Utilities
 * ============================================================
 */

#ifndef STRUTILS_H
#define STRUTILS_H

#include <stddef.h>   /* untuk size_t */

/* -------------------------------------------------------
 * Function Prototypes
 * ------------------------------------------------------- */

/* String info */
int str_count_words(const char *s);
int str_count_char(const char *s, char c);

/* String transform */
void str_to_upper(char *s);
void str_to_lower(char *s);
void str_trim_newline(char *s);
void str_reverse(char *s);

/* String check */
int str_is_palindrome(const char *s);
int str_starts_with(const char *s, const char *prefix);
int str_ends_with(const char *s, const char *suffix);

#endif /* STRUTILS_H */
