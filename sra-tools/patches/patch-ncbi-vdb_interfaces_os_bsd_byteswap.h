$NetBSD$

# Add NetBSD support

--- ncbi-vdb/interfaces/os/bsd/byteswap.h.orig	2023-08-13 14:38:57.514168395 +0000
+++ ncbi-vdb/interfaces/os/bsd/byteswap.h
@@ -2,7 +2,7 @@
 #ifndef _bsd_byteswap_h_
 #define _bsd_byteswap_h_
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 
 #include <sys/endian.h>
 
