$NetBSD$

Avoid strdupa.

--- library.c.orig	2018-01-19 20:40:49.000000000 +0000
+++ library.c
@@ -17,7 +17,6 @@
  *
  */
 
-#define _GNU_SOURCE /* strdupa() */
 #include <assert.h>
 #include <errno.h>
 #include <iconv.h>
@@ -43,7 +42,7 @@ int library_global_init(void)
 {
     assert(ascii == (iconv_t)-1);
 
-    ascii = iconv_open("ASCII//TRANSLIT", "");
+    ascii = iconv_open("ascii", "c99");
     if (ascii == (iconv_t)-1) {
         perror("iconv_open");
         return -1;
@@ -593,8 +592,13 @@ int library_import(struct library *li, c
     char *cratename, *pathname;
     struct crate *crate;
 
-    pathname = strdupa(path);
+    pathname = strdup(path);
+    if (pathname == NULL) {
+        perror("strdup");
+        return -1;
+    }
     cratename = basename(pathname); /* POSIX version, see basename(3) */
+    free(pathname);
     assert(cratename != NULL);
 
     crate = malloc(sizeof *crate);
