$NetBSD$

we have endian.h

--- include/grgsm/endian.h.orig	2018-08-12 18:13:50.000000000 +0000
+++ include/grgsm/endian.h
@@ -13,7 +13,7 @@
 
 #endif
 
-#if defined(__linux__) || defined(__CYGWIN__)
+#if defined(__linux__) || defined(__CYGWIN__) || defined(__NetBSD__)
 
 #	include <endian.h>
 
