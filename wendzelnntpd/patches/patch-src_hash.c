$NetBSD$

Silence "xyz redefined" warning (VERSION is defined by "main.h" and "mhash.h").

--- src/hash.c.orig	2021-04-17 20:18:01.000000000 +0000
+++ src/hash.c
@@ -18,6 +18,8 @@
  */
  
 #include "main.h"
+/* VERSION is defined by mhash.h (from libmhash) too */
+#undef VERSION
 #include <mhash.h>
 
 #define SHA256_LEN 64 /* 32 bytes * 8 bits = 256 bits;
