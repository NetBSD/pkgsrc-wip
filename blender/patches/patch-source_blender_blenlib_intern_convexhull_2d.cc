$NetBSD$

--- source/blender/blenlib/intern/convexhull_2d.cc.orig	2026-08-26 11:03:04.439289458 +0000
+++ source/blender/blenlib/intern/convexhull_2d.cc
@@ -638,7 +638,7 @@ static float convexhull_aabb_fit_hull_2d(const float (
     convexhull_2d_angle_iter_step(hull_iter);
   }
 
-  const float angle = (area_best != FLT_MAX) ? atan2(sincos_best[0], sincos_best[1]) : 0.0f;
+  const float angle = (area_best != FLT_MAX) ? atan2f(sincos_best[0], sincos_best[1]) : 0.0f;
 
 #if defined(USE_BRUTE_FORCE_ASSERT) && !defined(NDEBUG)
   {
