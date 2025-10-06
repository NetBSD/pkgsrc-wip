$NetBSD$

Define HOST_NAME_MAX.

--- src/common/XAuth.cpp.orig	2024-02-26 10:23:03.000000000 +0000
+++ src/common/XAuth.cpp
@@ -31,7 +31,7 @@
 #include <unistd.h>
 #include <X11/Xauth.h>
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #define HOST_NAME_MAX _POSIX_HOST_NAME_MAX
 #endif
 
