$NetBSD: patch-deps__openlibm_include_fpmath.h,v 1.1 2015/05/18 03:40:54 genolopolis Exp $

--- deps/openlibm/include/fpmath.h.orig	2015-03-22 19:50:02.000000000 +0000
+++ deps/openlibm/include/fpmath.h
@@ -59,6 +59,10 @@
 #include <machine/endian.h>
 #endif
 
+#ifdef __NetBSD__
+#include <machine/endian.h>
+#endif
+
 #ifdef _WIN32
 #define _LITTLE_ENDIAN 1234
 #define _BIG_ENDIAN    4321
@@ -103,7 +107,7 @@ union IEEEd2bits {
 		unsigned int	manh	:20;
 		unsigned int	exp	:11;
 		unsigned int	sign	:1;
-#if _IEEE_WORD_ORDER == _BIG_ENDIAN
+#if _IEEE_WORD_ORDER == _BIG_ENDIAN && _BIG_ENDIAN != _LITTLE_ENDIAN
 		unsigned int	manl	:32;
 #endif
 #else /* _BIG_ENDIAN */
