$NetBSD$

Avoid undefined symbol on NetBSD.
https://github.com/Critlist/restoHack/issues/4

--- src/hack.unix.c.orig	2025-08-09 16:01:24.973179273 +0000
+++ src/hack.unix.c
@@ -28,7 +28,7 @@
 void
 setrandom(void)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 	/* Linux doesn't have srandomdev(), use time-based seeding */
 	(void) srandom((unsigned int)time(NULL));
 #else
