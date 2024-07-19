$NetBSD$

Add NetBSD support.

--- CPP/7zip/UI/Common/UpdateCallback.cpp.orig	2024-07-19 16:14:07.643944168 +0000
+++ CPP/7zip/UI/Common/UpdateCallback.cpp
@@ -9,7 +9,7 @@
 // #include <pwd.h>
 
 // for major()/minor():
-#if defined(__FreeBSD__) || defined(BSD)
+#if defined(__FreeBSD__) || defined(BSD) || defined(__NetBSD__)
 #include <sys/types.h>
 #else
 #include <sys/sysmacros.h>
