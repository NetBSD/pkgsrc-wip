$NetBSD$

--- endian.hh.orig	2015-09-16 07:28:04.000000000 +0000
+++ endian.hh
@@ -6,7 +6,7 @@
 
 #include <stdint.h>
 #include <arpa/inet.h>
-#ifdef __APPLE__
+#if defined(__NetBSD__) ||defined(__FreeBSD__)
 #include <machine/endian.h>
 #else
 #include <endian.h>
