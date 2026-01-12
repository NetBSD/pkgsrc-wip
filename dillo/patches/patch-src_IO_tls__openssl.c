$NetBSD$

Avoid ctype(3) undefined behaviours.

Shared upstream via:
<https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/>

--- src/IO/tls_openssl.c.orig	2026-01-06 16:25:07.228170607 +0000
+++ src/IO/tls_openssl.c
@@ -576,13 +576,13 @@ static bool_t pattern_match (const char 
 
   const char *p = pattern, *n = string;
   char c;
-  for (; (c = tolower (*p++)) != '\0'; n++)
+  for (; (c = tolower ((unsigned char)*p++)) != '\0'; n++)
     if (c == '*')
       {
-        for (c = tolower (*p); c == '*'; c = tolower (*++p))
+        for (c = tolower ((unsigned char)*p); c == '*'; c = tolower ((unsigned char)*++p))
           ;
         for (; *n != '\0'; n++)
-          if (tolower (*n) == c && pattern_match (p, n))
+          if (tolower ((unsigned char)*n) == c && pattern_match (p, n))
             return TRUE;
 #ifdef ASTERISK_EXCLUDES_DOT
           else if (*n == '.')
@@ -592,7 +592,7 @@ static bool_t pattern_match (const char 
       }
     else
       {
-        if (c != tolower (*n))
+        if (c != tolower ((unsigned char)*n))
           return FALSE;
       }
   return *n == '\0';
