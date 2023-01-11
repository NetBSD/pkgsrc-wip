$NetBSD$

NetBSD support.

--- galerautils/src/gu_arch.h.orig	2022-11-02 06:09:14.000000000 +0000
+++ galerautils/src/gu_arch.h
@@ -41,7 +41,7 @@
 # error "Byte order not defined"
 #endif
 
-#if defined(__sun__)
+#if defined(__sun__) || defined(__NetBSD__)
 # if defined (_LP64)
 #  define GU_WORDSIZE 64
 # else
