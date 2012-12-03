$NetBSD: patch-src_cpu_int.c,v 1.1 2012/12/03 22:50:30 othyro Exp $

Needs bswap.h if OPSYS = NetBSD.

--- src/cpu/int.c.orig	2010-03-19 22:22:53.000000000 +0000
+++ src/cpu/int.c
@@ -1,6 +1,14 @@
 #include <math.h>
 
-#ifdef UNIX
+#if defined(__NetBSD__)
+#include <sys/types.h>
+#include <machine/bswap.h>
+#if defined(__BSWAP_RENAME) && (!defined(__bswap_16) && !defined(__bswap_32))
+#define __bswap_16 bswap16
+#define __bswap_32 bswap32
+#define __bswap_64 bswap64
+#endif
+#elif defined(UNIX)
 #include <byteswap.h>
 #else
 #include <string.h>
