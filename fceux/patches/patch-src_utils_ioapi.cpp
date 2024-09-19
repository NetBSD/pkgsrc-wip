$NetBSD: patch-src_utils_ioapi.cpp,v 1.1 2013/05/05 14:25:57 othyro Exp $

Map f{open,tello,seeko}64 to f{open,tello,seeko}) for NetBSD too.

--- src/utils/ioapi.cpp.orig	2013-03-10 19:59:33.000000000 +0000
+++ src/utils/ioapi.cpp
@@ -14,7 +14,7 @@
         #define _CRT_SECURE_NO_WARNINGS
 #endif
 
-#if defined(__APPLE__) || defined(IOAPI_NO_64)
+#if defined(__APPLE__) || defined(IOAPI_NO_64) || defined(__NetBSD__)
 // In darwin and perhaps other BSD variants off_t is a 64 bit value, hence no need for specific 64 bit functions
 #define FOPEN_FUNC(filename, mode) fopen(filename, mode)
 #define FTELLO_FUNC(stream) ftello(stream)
