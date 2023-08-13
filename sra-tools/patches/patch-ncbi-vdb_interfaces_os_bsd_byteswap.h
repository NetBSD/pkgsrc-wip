$NetBSD$

# Add NetBSD support

--- ncbi-vdb/interfaces/os/bsd/byteswap.h.orig	2023-08-12 23:35:46.000000000 +0000
+++ ncbi-vdb/interfaces/os/bsd/byteswap.h
@@ -2,7 +2,7 @@
 #ifndef _bsd_byteswap_h_
 #define _bsd_byteswap_h_
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 
 #include <sys/endian.h>
 
@@ -14,6 +14,13 @@
 #define bswap_32(x) bswap32 (x)
 #define bswap_64(x) bswap64 (x)
 
+// #define XSTR(x) STR(x)
+// #define STR(x)  #x
+
+// #pragma message "_BYTE_ORDER = " XSTR(_BYTE_ORDER)
+// #pragma message "__BYTE_ORDER = " XSTR(__BYTE_ORDER)
+// #pragma message "__LITTLE_ENDIAN = " XSTR(__LITTLE_ENDIAN)
+
 #else
 
 #error "You must define macros for this BSD variant."
