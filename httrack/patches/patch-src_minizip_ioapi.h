$NetBSD$

Fix build on NetBSD.

--- src/minizip/ioapi.h.orig	2016-04-26 17:10:23.000000000 +0000
+++ src/minizip/ioapi.h
@@ -50,7 +50,7 @@
 #define ftello64 ftell
 #define fseeko64 fseek
 #else
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #define fopen64 fopen
 #define ftello64 ftello
 #define fseeko64 fseeko
