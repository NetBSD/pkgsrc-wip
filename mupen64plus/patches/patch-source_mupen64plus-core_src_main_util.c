$NetBSD: patch-source_mupen64plus-core_src_main_util.c,v 1.2 2013/07/06 23:00:14 othyro Exp $

Fixes "array subscript has type 'char'" warning.

--- source/mupen64plus-core/src/main/util.c.orig	2013-07-04 00:27:56.000000000 +0000
+++ source/mupen64plus-core/src/main/util.c
@@ -257,10 +257,10 @@ char *trim(char *str)
 {
     char *start = str, *end = str + strlen(str);
 
-    while (start < end && isspace(*start))
+    while (start < end && isspace((unsigned char)*start))
         start++;
 
-    while (end > start && isspace(*(end-1)))
+    while (end > start && isspace((unsigned char)*(end-1)))
         end--;
 
     memmove(str, start, end - start);
@@ -273,7 +273,7 @@ int string_to_int(const char *str, int *
 {
     char *endptr;
     long int n;
-    if (*str == '\0' || isspace(*str))
+    if (*str == '\0' || isspace((unsigned char)*str))
         return 0;
     errno = 0;
     n = strtol(str, &endptr, 10);
@@ -285,7 +285,7 @@ int string_to_int(const char *str, int *
 
 static unsigned char char2hex(char c)
 {
-    c = tolower(c);
+    c = tolower((unsigned char)c);
     if(c >= '0' && c <= '9')
         return c - '0';
     else if(c >= 'a' && c <= 'f')
