$NetBSD$

Avoid narrowing conversion errors.

--- tr_languages.cpp.orig	2014-03-04 16:47:15.000000000 +0000
+++ tr_languages.cpp
@@ -198,7 +198,7 @@ static const unsigned short chars_ignore
 	0x200d,  1, // zero width joiner
 	0, 0 };
 
-const char string_ordinal[] = {0xc2,0xba,0};  // masculine ordinal character, UTF-8
+const wchar_t string_ordinal[] = {0xc2,0xba,0};  // masculine ordinal character, UTF-8
 
 
 static Translator* NewTranslator(void)
@@ -296,7 +296,7 @@ static const char transpose_map_latin[] 
 	tr->langopts.replace_chars = NULL;
 	tr->langopts.ascii_language[0] = 0;    // Non-Latin alphabet languages, use this language to speak Latin words, default is English
 	tr->langopts.alt_alphabet_lang = L('e','n');
-	tr->langopts.roman_suffix = "";
+	tr->langopts.roman_suffix = L"";
 
 	SetLengthMods(tr,201);
 //	tr->langopts.length_mods = length_mods_en;
