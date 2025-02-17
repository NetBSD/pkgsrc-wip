$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

Patch for new CGAL 6.x based on
https://github.com/prusa3d/PrusaSlicer/pull/13081

--- tests/libslic3r/test_emboss.cpp.orig	2024-12-20 11:54:34.000000000 +0000
+++ tests/libslic3r/test_emboss.cpp
@@ -1,4 +1,4 @@
-﻿#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
 
 #include <libslic3r/Emboss.hpp>
 #include <libslic3r/SVG.hpp> // only debug visualization
@@ -9,8 +9,16 @@
 #include <libslic3r/IntersectionPoints.hpp>
 using namespace Slic3r;
 
-namespace Private{
+template <typename T>
+auto access_pmap(std::optional<T> opt) -> T {
+    return opt.value_or(T{});
+}
+
+template <typename Pair>
+auto access_pmap(Pair pair) { return pair.first; }
         
+namespace Private{
+
 // calculate multiplication of ray dir to intersect - inspired by
 // segment_segment_intersection when ray dir is normalized retur distance from
 // ray point to intersection No value mean no intersection
@@ -414,7 +422,7 @@ TEST_CASE("ray segment intersection", "[
     CHECK(abs(*t1 - *t2) < std::numeric_limits<double>::epsilon());
 }
 
-TEST_CASE("triangle intersection", "[]")
+TEST_CASE("triangle intersection")
 {
     Vec2d                point(1, 1);
     Vec2d                dir(-1, 0);
@@ -483,7 +491,7 @@ TEST_CASE("Italic check", "[Emboss]") 
 #endif // FONT_DIR_PATH
 
 #include "libslic3r/CutSurface.hpp"
-TEST_CASE("Cut surface", "[]")
+TEST_CASE("Cut surface")
 {
     std::string  font_path  = get_font_filepath();
     char         letter     = '%';
@@ -906,8 +914,8 @@ TEST_CASE("Emboss extrude cut", "[Emboss
     // identify glyph for intersected vertex
     std::string vert_shape_map_name = "v:glyph_id";
     MyMesh cgal_object = MeshBoolean::cgal2::to_cgal(cube, face_map_name);
-    auto face_map = cgal_object.property_map<MyMesh::Face_index, int32_t>(face_map_name).first;
-    auto vert_shape_map = cgal_object.add_property_map<MyMesh::Vertex_index, IntersectingElemnt>(vert_shape_map_name).first;
+    auto face_map = access_pmap((cgal_object.property_map<MyMesh::Face_index, int32_t>(face_map_name)));
+    auto vert_shape_map = access_pmap((cgal_object.add_property_map<MyMesh::Vertex_index, IntersectingElemnt>(vert_shape_map_name)));
 
     std::string edge_shape_map_name = "e:glyph_id";
     std::string face_shape_map_name = "f:glyph_id";
@@ -915,8 +923,8 @@ TEST_CASE("Emboss extrude cut", "[Emboss
 
     MyMesh cgal_shape = MeshBoolean::cgal2::to_cgal(shape, projection, 0, edge_shape_map_name, face_shape_map_name, glyph_contours);    
 
-    auto edge_shape_map = cgal_shape.property_map<MyMesh::Edge_index, IntersectingElemnt>(edge_shape_map_name).first;
-    auto face_shape_map = cgal_shape.property_map<MyMesh::Face_index, IntersectingElemnt>(face_shape_map_name).first;
+    auto edge_shape_map = access_pmap((cgal_shape.property_map<MyMesh::Edge_index, IntersectingElemnt>(edge_shape_map_name)));
+    auto face_shape_map = access_pmap((cgal_shape.property_map<MyMesh::Face_index, IntersectingElemnt>(face_shape_map_name)));
 
     // bool map for affected edge
     using d_prop_bool = CGAL::dynamic_edge_property_t<bool>;
@@ -1048,7 +1056,7 @@ TEST_CASE("Emboss extrude cut", "[Emboss
         // face without constrained edge (In or Out)
         not_constrained
     };
-    auto side_type_map = cgal_object.add_property_map<MyMesh::Face_index, SideType>("f:side").first;
+    auto side_type_map = access_pmap((cgal_object.add_property_map<MyMesh::Face_index, SideType>("f:side")));
     for (auto fi : cgal_object.faces()) {
         SideType side_type = SideType::not_constrained;
         auto hi_end = cgal_object.halfedge(fi);
@@ -1129,7 +1137,7 @@ TEST_CASE("Emboss extrude cut", "[Emboss
     }
     
     // debug output
-    auto face_colors = cgal_object.add_property_map<MyMesh::Face_index, CGAL::Color>("f:color").first;    
+    auto face_colors = access_pmap((cgal_object.add_property_map<MyMesh::Face_index, CGAL::Color>("f:color")));
     for (auto fi : cgal_object.faces()) { 
         auto &color = face_colors[fi];
         switch (side_type_map[fi]) {
