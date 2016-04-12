$NetBSD$

Fix build with gcc-5.

--- src/stageutils.h.orig	2012-08-10 14:42:54.000000000 +0000
+++ src/stageutils.h
@@ -39,7 +39,7 @@ void init_stage3d(Stage3D *s);
 void add_model(Stage3D *s, SegmentDrawRule draw, SegmentPositionRule pos);
 
 void set_perspective_viewport(Stage3D *s, float n, float f, int vx, int vy, int vw, int vh);
-inline void set_perspective(Stage3D *s, float near, float far);
+void set_perspective(Stage3D *s, float near, float far);
 void draw_stage3d(Stage3D *s, float maxrange);
 
 void free_stage3d(Stage3D *s);
