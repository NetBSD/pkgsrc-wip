$NetBSD$

Don't redefine viewport if building for OpenGL ES.

--- src/slic3r/GUI/Gizmos/GLGizmoMeasure.cpp.orig	2024-06-19 22:46:33.687428298 +0000
+++ src/slic3r/GUI/Gizmos/GLGizmoMeasure.cpp
@@ -1561,7 +1561,9 @@ void GLGizmoMeasure::render_dimensioning
         const Vec3d label_position_world = Geometry::translation_transform(center) * (draw_radius * (Eigen::Quaternion<double>(Eigen::AngleAxisd(step * 0.5 * double(resolution), normal)) * e1_unit));
 
         // label screen coordinates
+#if !SLIC3R_OPENGL_ES
         const std::array<int, 4>& viewport = camera.get_viewport();
+#endif
         const Vec2d label_position_ss = TransformHelper::world_to_ss(label_position_world,
             camera.get_projection_matrix().matrix() * camera.get_view_matrix().matrix(), viewport);
 
