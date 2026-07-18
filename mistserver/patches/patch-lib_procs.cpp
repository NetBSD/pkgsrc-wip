$NetBSD$

NetBSD support

--- lib/procs.cpp.orig	2026-07-14 14:37:40.774027704 +0000
+++ lib/procs.cpp
@@ -30,7 +30,7 @@
 #include <stdlib.h>
 #include <sys/types.h>
 
-#if defined(__APPLE__) || defined(__MACH__)
+#if defined(__APPLE__) || defined(__MACH__) || defined(__NetBSD__)
 extern char **environ;
 #endif
 
