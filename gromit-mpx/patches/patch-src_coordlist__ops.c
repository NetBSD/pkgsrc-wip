$NetBSD$

Threat the 2nd argument as a single one instead of 6.

Fix the build with NetBSD memcpy(3).

--- src/coordlist_ops.c.orig	2025-05-04 16:37:58.021770918 +0000
+++ src/coordlist_ops.c
@@ -270,7 +270,7 @@ static gfloat angle_deg_snap(gfloat angl
 // -------------------- 2D affine transformations --------------------
 
 static void unity2D(trans2D *m) {
-    memcpy(m->m, (gfloat[6]){1.0, 0.0, 0.0, 0.0, 1.0, 0.0}, sizeof(gfloat[6]));
+    memcpy(m->m, ((gfloat[6]){1.0, 0.0, 0.0, 0.0, 1.0, 0.0}), sizeof(gfloat[6]));
 }
 
 static void rotate2D(gfloat angle, trans2D *m) {
