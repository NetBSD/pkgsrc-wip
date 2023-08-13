$NetBSD$

# Add NetBSD support

--- ncbi-vdb/interfaces/os/bsd/endian.h.orig	2023-08-13 15:20:29.641640461 +0000
+++ ncbi-vdb/interfaces/os/bsd/endian.h
@@ -1,5 +1,5 @@
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 
 #include <sys/endian.h>
 
