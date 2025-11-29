$NetBSD$

Support NetBSD.

--- lib-src/libnyquist/nyquist/xlisp/xlisp.h.orig	2025-11-29 17:56:29.163160252 +0000
+++ lib-src/libnyquist/nyquist/xlisp/xlisp.h
@@ -172,8 +172,8 @@ extern long ptrtoabs();
 #endif
 #endif
 
-/* FreeBSD / OpenBSD */
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+/* FreeBSD / NetBSD / OpenBSD */
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #if BYTE_ORDER == LITTLE_ENDIAN
 #define XL_LITTLE_ENDIAN
 #else
