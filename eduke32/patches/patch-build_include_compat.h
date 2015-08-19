$NetBSD: patch-build_include_compat.h,v 1.1 2015/08/19 20:36:32 yhardy Exp $

Use the correct bswap functions on NetBSD.

--- build/include/compat.h.orig	2015-05-27 08:48:07.000000000 +0000
+++ build/include/compat.h
@@ -288,6 +288,11 @@
 # define B_SWAP64(x) __bswap64(x)
 # define B_SWAP32(x) __bswap32(x)
 # define B_SWAP16(x) __bswap16(x)
+# ifdef __NetBSD__
+#  define B_SWAP64(x) bswap64(x)
+#  define B_SWAP32(x) bswap32(x)
+#  define B_SWAP16(x) bswap16(x)
+# endif
 
 #elif defined(__APPLE__)
 # if !defined __x86_64__ && defined __GNUC__
