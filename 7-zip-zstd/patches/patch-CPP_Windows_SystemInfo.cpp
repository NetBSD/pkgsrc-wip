$NetBSD$

Add NetBSD support.

--- CPP/Windows/SystemInfo.cpp.orig	2024-07-19 16:14:42.941103660 +0000
+++ CPP/Windows/SystemInfo.cpp
@@ -14,7 +14,7 @@
 
 #include <unistd.h>
 #include <sys/utsname.h>
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__NetBSD__)
 #include <sys/sysctl.h>
 #elif !defined(_AIX)
 
