$NetBSD$

Add missing header.

--- 04-commit/main.c.orig	2014-05-02 21:04:50.000000000 +0000
+++ 04-commit/main.c
@@ -8,6 +8,7 @@
 #include <string.h>
 #include <sqlite3.h>
 #include <time.h>
+#include <unistd.h>
 #include <zlib.h>
 
 #include <openssl/md5.h>
