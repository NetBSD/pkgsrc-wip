$NetBSD$

Use fopen on NetBSD as well.

--- ./src/engine/unzip/ioapi.h.orig	2017-12-31 18:47:24.000000000 +0000
+++ ./src/engine/unzip/ioapi.h
@@ -50,7 +50,7 @@
 #define ftello64 ftell
 #define fseeko64 fseek
 #else
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #define fopen64 fopen
 #define ftello64 ftello
 #define fseeko64 fseeko
