$NetBSD$

Avoid narrowing conversion errors.

--- numbers.cpp.orig	2014-03-04 16:47:15.000000000 +0000
+++ numbers.cpp
@@ -1226,7 +1226,7 @@ int TranslateRoman(Translator *tr, char 
 		p = &ph_out[strlen(ph_roman)];
 	}
 
-	sprintf(number_chars,"  %d %s    ",acc, tr->langopts.roman_suffix);
+	sprintf(number_chars,"  %d %ls    ",acc, tr->langopts.roman_suffix);
 
 	if(word[0] == '.')
 	{
