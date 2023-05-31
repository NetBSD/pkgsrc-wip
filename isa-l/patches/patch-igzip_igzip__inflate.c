$NetBSD$

# NetBSD bswap hack

--- igzip/igzip_inflate.c.orig	2023-05-31 16:18:23.382475799 +0000
+++ igzip/igzip_inflate.c
@@ -39,7 +39,7 @@
 #include "static_inflate.h"
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/types.h>
 #include <sys/endian.h>
 # define bswap_32(x) bswap32(x)
