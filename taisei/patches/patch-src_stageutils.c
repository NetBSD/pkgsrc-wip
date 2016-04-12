$NetBSD$

Fix build with gcc-5.

--- src/stageutils.c.orig	2012-08-10 14:42:54.000000000 +0000
+++ src/stageutils.c
@@ -34,7 +34,7 @@ void set_perspective_viewport(Stage3D *s
 	glMatrixMode(GL_MODELVIEW);
 }
 
-inline void set_perspective(Stage3D *s, float n, float f) {
+void set_perspective(Stage3D *s, float n, float f) {
 	set_perspective_viewport(s, n, f, VIEWPORT_X, VIEWPORT_Y, VIEWPORT_W, VIEWPORT_H);
 }
 
