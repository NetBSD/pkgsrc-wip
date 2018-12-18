$NetBSD$

Use the correct bswap functions on NetBSD.

--- jfbuild/include/compat.h.orig	2018-12-18 11:09:10.000000000 +0000
+++ jfbuild/include/compat.h
@@ -116,9 +116,15 @@
 #  define B_LITTLE_ENDIAN 0
 #  define B_BIG_ENDIAN    1
 # endif
-# define B_SWAP64(x) __bswap64(x)
-# define B_SWAP32(x) __bswap32(x)
-# define B_SWAP16(x) __bswap16(x)
+# if defined(__FreeBSD__) || defined(__OpenBSD__)
+#  define B_SWAP64(x) __bswap64(x)
+#  define B_SWAP32(x) __bswap32(x)
+#  define B_SWAP16(x) __bswap16(x)
+# elif defined(__NetBSD__)
+#  define B_SWAP64(x) bswap64(x)
+#  define B_SWAP32(x) bswap32(x)
+#  define B_SWAP16(x) bswap16(x)
+# endif
 
 #elif defined(__APPLE__)
 # if defined(__LITTLE_ENDIAN__)
