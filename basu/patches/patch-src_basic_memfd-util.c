$NetBSD$

--- src/basic/memfd-util.c.orig	2025-12-11 16:20:23.258634161 +0000
+++ src/basic/memfd-util.c
@@ -9,7 +9,7 @@
 #include "memfd-util.h"
 
 int memfd_set_sealed(int fd) {
-#if defined(__FreeBSD__) && __FreeBSD__ < 13
+#if (defined(__FreeBSD__) && __FreeBSD__ < 13) || (defined(__NetBSD__) && __NetBSD__ < 11)
         return 0;
 #else
         int r;
