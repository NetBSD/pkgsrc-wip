$NetBSD$

Treat NetBSD like Linux.

--- makewav/makewav.c.orig	2026-03-08 01:57:06.681063034 +0000
+++ makewav/makewav.c
@@ -22,7 +22,7 @@
 #include <stdlib.h>
 #include <math.h>
 
-#if defined(__CYGWIN32__) || defined(__linux__) || defined(WIN32)
+#if defined(__CYGWIN32__) || defined(__linux__) || defined(WIN32) || defined(__NetBSD__)
 /* implemented based on OSX man page */
 static inline int digittoint(int c)
 {
