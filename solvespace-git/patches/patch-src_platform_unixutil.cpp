$NetBSD$

Add missing semicolon

--- src/platform/unixutil.cpp.orig	2017-01-24 20:55:17.000000000 +0000
+++ src/platform/unixutil.cpp
@@ -122,7 +122,7 @@ static const std::string &FindLocalResou
 #if defined(__linux__)
     selfPath = "/proc/self/exe";
 #elif defined(__NetBSD__)
-    selfPath = "/proc/curproc/exe"
+    selfPath = "/proc/curproc/exe";
 #elif defined(__OpenBSD__) || defined(__FreeBSD__)
     selfPath = "/proc/curproc/file";
 #elif defined(__APPLE__)
