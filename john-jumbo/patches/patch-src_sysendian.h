$NetBSD$

--- src/sysendian.h.orig	2014-05-16 13:40:40.000000000 +0000
+++ src/sysendian.h
@@ -36,7 +36,7 @@
 #undef HAVE_SYS_ENDIAN_H
 #endif
 
-#ifdef HAVE_SYS_ENDIAN_H
+#if 1 /* def HAVE_SYS_ENDIAN_H */
 
 #include <sys/endian.h>
 
