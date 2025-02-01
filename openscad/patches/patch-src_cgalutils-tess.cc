$NetBSD$

Upstream patch for cgal 5.4
https://github.com/openscad/openscad/commit/71f2831c0484c3f35cbf44e1d1dc2c857384100b

--- src/cgalutils-tess.cc.orig	2021-01-31 17:41:09.000000000 +0000
+++ src/cgalutils-tess.cc
@@ -6,10 +6,12 @@
 #pragma push_macro("NDEBUG")
 #undef NDEBUG
 #include <CGAL/Constrained_Delaunay_triangulation_2.h>
-#if CGAL_VERSION_NR >= CGAL_VERSION_NUMBER(4,11,0)
+#if CGAL_VERSION_NR < 1050401000
   #include <CGAL/Triangulation_2_projection_traits_3.h>
+typedef CGAL::Triangulation_2_filtered_projection_traits_3<K> Projection;
 #else
-  #include <CGAL/Triangulation_2_filtered_projection_traits_3.h>
+#include <CGAL/Projection_traits_3.h>
+typedef CGAL::Filtered_projection_traits_3<K> Projection;
 #endif
 #include <CGAL/Triangulation_face_base_with_info_2.h>
 #pragma pop_macro("NDEBUG")
@@ -19,7 +21,6 @@ struct FaceInfo {
   bool in_domain() { return nesting_level%2 == 1; }
 };
 
-typedef CGAL::Triangulation_2_filtered_projection_traits_3<K> Projection;
 typedef CGAL::Triangulation_face_base_with_info_2<FaceInfo, K> Fbb;
 typedef CGAL::Triangulation_data_structure_2<
 	CGAL::Triangulation_vertex_base_2<Projection>,
