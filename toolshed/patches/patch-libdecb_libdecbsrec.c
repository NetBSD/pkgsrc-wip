$NetBSD$

Treat NetBSD like Linux.

--- libdecb/libdecbsrec.c.orig	2026-03-08 01:56:19.927952440 +0000
+++ libdecb/libdecbsrec.c
@@ -12,7 +12,7 @@
 #define PREAMBLE 0x00
 #define POSTAMBLE 0xff
 
-#if defined(__linux__) || defined(WIN32)
+#if defined(__linux__) || defined(WIN32) || defined(__NetBSD__)
 static inline int digittoint(int c)
 /* implemented based on OSX man page */
 {
