$NetBSD: patch-src_tuxpaint.c,v 1.1 2014/08/17 10:28:55 thomasklausner Exp $

Fix build on NetBSD.
Already included upstream.

--- src/tuxpaint.c.orig	2014-08-14 06:08:48.000000000 +0000
+++ src/tuxpaint.c
@@ -549,7 +549,7 @@ static void mtw(wchar_t * wtok, char * t
 
 //#define fmemopen_alternative */ /* Uncomment this to test the fmemopen alternative in systems were fmemopen exists */
 
-#if defined (WIN32) || defined (__APPLE__) // MINGW/MSYS, and MacOSX need it, at least for now
+#if defined (WIN32) || defined (__APPLE__) || defined(__NetBSD__) // MINGW/MSYS, NetBSD, and MacOSX need it, at least for now
 #define fmemopen_alternative 
 #endif
 
