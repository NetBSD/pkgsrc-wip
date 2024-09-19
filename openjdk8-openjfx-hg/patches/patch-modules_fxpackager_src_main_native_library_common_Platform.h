$NetBSD$

Pretend we are Linux for now.

--- modules/fxpackager/src/main/native/library/common/Platform.h.orig	2016-03-04 00:57:09.000000000 +0000
+++ modules/fxpackager/src/main/native/library/common/Platform.h
@@ -55,7 +55,7 @@
 #endif //__APPLE__
 
 
-#ifdef __linux
+#if defined(__linux) || defined(__NetBSD__)
 #define LINUX
 #endif //__linux
 
