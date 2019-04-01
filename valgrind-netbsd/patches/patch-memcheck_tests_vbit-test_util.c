$NetBSD$

--- memcheck/tests/vbit-test/util.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ memcheck/tests/vbit-test/util.c
@@ -39,6 +39,11 @@
 #  else
 #  define __BYTE_ORDER    __BIG_ENDIAN
 #  endif
+#elif defined(__NetBSD__)
+#include <endian.h>
+#define __BYTE_ORDER _BYTE_ORDER
+#define __LITTLE_ENDIAN _LITTLE_ENDIAN
+#define __BIG_ENDIAN _BIG_ENDIAN
 #else
 #include <endian.h>
 #endif
