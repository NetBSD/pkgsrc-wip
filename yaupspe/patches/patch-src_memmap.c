$NetBSD: patch-src_memmap.c,v 1.1 2012/12/03 22:50:30 othyro Exp $

Needs bswap if OPSYS = NetBSD.

--- src/memmap.c.orig	2010-03-24 21:36:45.000000000 +0000
+++ src/memmap.c
@@ -1,6 +1,13 @@
 #include <stdlib.h>
 
-#ifdef UNIX
+#if defined(__NetBSD__)
+#include <sys/types.h>
+#include <machine/bswap.h>
+#if defined(__BSWAP_RENAME) && (!defined(__bswap_16) && !defined(__bswap_32))
+#define __bswap_16 bswap16
+#define __bswap_32 bswap32
+#endif
+#elif defined(UNIX)
 #include <byteswap.h>
 #else
 #include <string.h>
