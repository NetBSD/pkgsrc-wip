$NetBSD$

Avoid narrowing conversion errors.

--- translate.h.orig	2014-03-04 16:47:15.000000000 +0000
+++ translate.h
@@ -545,7 +545,7 @@ typedef struct {
 	int decimal_sep;
 	int max_digits;    // max number of digits which can be spoken as an integer number (rather than individual digits)
 	const char *ordinal_indicator;   // UTF-8 string
-	const char *roman_suffix;    // add this (ordinal) suffix to Roman numbers (LANG=an)
+	const wchar_t *roman_suffix;    // add this (ordinal) suffix to Roman numbers (LANG=an)
 
 	// bit 0, accent name before the letter name, bit 1 "capital" after letter name
 	int accents;
