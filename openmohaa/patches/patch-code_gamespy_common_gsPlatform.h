$NetBSD$

Support *BSD as well.

--- code/gamespy/common/gsPlatform.h.orig	2024-12-27 07:58:52.772504167 +0000
+++ code/gamespy/common/gsPlatform.h
@@ -34,7 +34,7 @@
 	#endif
 #endif
 
-#if defined(_LINUX) || defined(_MACOSX) || defined(__APPLE__)
+#if defined(_LINUX) || defined(_MACOSX) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 	#define _UNIX
 #endif
 
