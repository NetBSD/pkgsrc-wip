$NetBSD: patch-src_graph_texture.c,v 1.1 2012/12/03 22:50:30 othyro Exp $

Needs bswap if OPSYS = NetBSD.

--- src/graph/texture.c.orig	2010-02-24 12:02:16.000000000 +0000
+++ src/graph/texture.c
@@ -2,7 +2,13 @@
 #include <GL/glu.h>
 #include <GL/glext.h>
 
-#ifdef UNIX
+#if defined(__NetBSD__)
+#include <sys/types.h>
+#include <machine/bswap.h>
+#if defined(__BSWAP_RENAME) && !defined(__bswap_32)
+#define __bswap_32 bswap32
+#endif
+#elif defined(UNIX)
 #include <byteswap.h>
 #endif
 
