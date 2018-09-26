$NetBSD$

glutLeaveMainLoop() is present only on freeglut, define it otherwise.

--- platform/gl/gl-main.c.orig	2018-09-25 12:39:17.000000000 +0000
+++ platform/gl/gl-main.c
@@ -16,7 +16,7 @@
 char *realpath(const char *path, char *resolved_path); /* in gl-file.c */
 #endif
 
-#ifdef __APPLE__
+#ifndef FREEGLUT
 void glutLeaveMainLoop(void)
 {
 	exit(0);
