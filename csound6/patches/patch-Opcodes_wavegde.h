$NetBSD$

Use native len_t on SunOS.

--- Opcodes/wavegde.h.orig	2019-07-12 21:54:19.000000000 +0000
+++ Opcodes/wavegde.h
@@ -43,7 +43,9 @@
 #endif
 
 /* TYPEDEFS */
+#ifndef __sun
 typedef int64_t    len_t;    /* length type */
+#endif
 
 /* CLASS DEFINITIONS */
 
