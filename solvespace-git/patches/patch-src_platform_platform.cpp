$NetBSD$

Add missing semicolon

--- src/platform/platform.cpp.orig	2017-03-13 20:25:28.000000000 +0000
+++ src/platform/platform.cpp
@@ -504,7 +504,7 @@ static Platform::Path ResourcePath(const
 #    if defined(__linux__)
 static const char *selfSymlink = "/proc/self/exe";
 #    elif defined(__NetBSD__)
-static const char *selfSymlink = "/proc/curproc/exe"
+static const char *selfSymlink = "/proc/curproc/exe";
 #    elif defined(__OpenBSD__) || defined(__FreeBSD__)
 static const char *selfSymlink = "/proc/curproc/file";
 #    else
