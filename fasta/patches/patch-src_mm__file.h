$NetBSD: patch-src_mm__file.h,v 1.1 2012/10/15 22:33:20 asau Exp $

--- src/mm_file.h.orig	2011-03-23 17:21:38.000000000 +0000
+++ src/mm_file.h
@@ -22,6 +22,9 @@ typedef off_t fseek_t;
 #endif
 #define FSEEK_T_DEF
 
+#ifdef HAS_STDINT
+#include <stdint.h>
+#else
 #ifdef HAS_INTTYPES
 #include <inttypes.h>
 #else
@@ -33,6 +36,7 @@ typedef long int64_t;
 typedef unsigned long uint64_t;
 #endif
 #endif
+#endif
 typedef int64_t MM_OFF;
 
 #ifdef MYSQL_DB
