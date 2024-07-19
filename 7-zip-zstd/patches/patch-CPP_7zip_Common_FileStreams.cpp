$NetBSD$

Add NetBSD support.

--- CPP/7zip/Common/FileStreams.cpp.orig	2024-07-19 16:13:09.258508447 +0000
+++ CPP/7zip/Common/FileStreams.cpp
@@ -12,7 +12,7 @@
 #include <pwd.h>
 
 // for major()/minor():
-#if defined(__FreeBSD__) || defined(BSD)
+#if defined(__FreeBSD__) || defined(BSD) || defined(__NetBSD__)
 #include <sys/types.h>
 #else
 #include <sys/sysmacros.h>
