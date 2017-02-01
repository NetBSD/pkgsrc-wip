$NetBSD$

--- src/escrypt/sysendian.h.orig	2014-09-19 16:40:51.000000000 +0000
+++ src/escrypt/sysendian.h
@@ -36,7 +36,7 @@
 #undef HAVE_SYS_ENDIAN_H
 #endif
 
-#ifdef HAVE_SYS_ENDIAN_H
+#if 1 /* def HAVE_SYS_ENDIAN_H */
 
 #include <sys/endian.h>
 
