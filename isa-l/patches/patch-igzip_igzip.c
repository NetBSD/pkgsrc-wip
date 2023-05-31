$NetBSD$

# NetBSD bswap hack

--- igzip/igzip.c.orig	2023-05-31 16:16:39.867982257 +0000
+++ igzip/igzip.c
@@ -54,7 +54,7 @@
 #include "igzip_wrapper.h"
 #include "unaligned.h"
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/types.h>
 #include <sys/endian.h>
 # define to_be32(x) bswap32(x)
