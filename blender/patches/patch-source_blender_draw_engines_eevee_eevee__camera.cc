$NetBSD$

--- source/blender/draw/engines/eevee/eevee_camera.cc.orig	2026-01-20 01:30:11.000000000 +0000
+++ source/blender/draw/engines/eevee/eevee_camera.cc
@@ -170,7 +170,7 @@ void Camera::sync()
       }
     }
 
-    if (isnan(data.winmat.w.x)) {
+    if (std::isnan(data.winmat.w.x)) {
       /* Can happen in weird corner case (see #134320).
        * Simply fall back to something that we can render with. */
       data.winmat = math::projection::orthographic(0.01f, 0.01f, 0.01f, 0.01f, -1000.0f, +1000.0f);
