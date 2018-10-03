$NetBSD$

glutLeaveMainLoop() is present only on freeglut, define it otherwise.

--- platform/gl/gl-main.c.orig	2018-10-03 11:29:14.000000000 +0000
+++ platform/gl/gl-main.c
@@ -16,7 +16,7 @@
 char *realpath(const char *path, char *resolved_path); /* in gl-file.c */
 #endif
 
-#ifdef __APPLE__
+#ifndef FREEGLUT
 static void cleanup(void);
 void glutLeaveMainLoop(void)
 {
