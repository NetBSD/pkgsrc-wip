$NetBSD$

--- Misc/common.h.orig	2019-12-17 16:05:14.000000000 +0000
+++ Misc/common.h
@@ -70,11 +70,11 @@
 void swab( const char *from, char *to, int nbytes);
 #endif
 
-#if defined(__GLIBC__)
+#if defined(__GLIBC__) || defined(TARGET_OS_NETBSD)
 #include <endian.h>
 #undef BIG_ENDIAN
 #undef LITTLE_ENDIAN
-#if __BYTE_ORDER == __LITTLE_ENDIAN
+#if __BYTE_ORDER == __LITTLE_ENDIAN || _BYTE_ORDER == _LITTLE_ENDIAN
 #  define LITTLE_ENDIAN
 #else
 #  define BIG_ENDIAN
@@ -100,6 +100,10 @@ void swab( const char *from, char *to, i
 #endif
 #endif
 
+#if defined(LITTLE_ENDIAN) && defined(BIG_ENDIAN)
+#error "Both LITTLE_ENDIAN and BIG_ENDIAN are defined and this should not happen."
+#endif
+
 /* memmove is not defined on SUN4, but memcpy will do */
 #ifdef TARGET_OS_SUN4
 #define memmove memcpy
