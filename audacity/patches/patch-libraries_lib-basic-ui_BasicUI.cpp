$NetBSD$

Provide environ on NetBSD.

--- libraries/lib-basic-ui/BasicUI.cpp.orig	2025-11-29 17:55:20.752873345 +0000
+++ libraries/lib-basic-ui/BasicUI.cpp
@@ -31,7 +31,7 @@ Paul Licameli
 
 #include <string>
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 extern char** environ;
 #endif
 
