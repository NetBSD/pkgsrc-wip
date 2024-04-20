$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_quadric_edge_collapse.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/libslic3r/test_quadric_edge_collapse.cpp
@@ -1,4 +1,4 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
 #include <test_utils.hpp>
 
 #include <libslic3r/QuadricEdgeCollapse.hpp>
@@ -240,7 +240,7 @@ TEST_CASE("Simplify frog_legs.obj to 5% 
 }
 
 #include <libigl/igl/qslim.h>
-TEST_CASE("Simplify frog_legs.obj to 5% by IGL/qslim", "[]")
+TEST_CASE("Simplify frog_legs.obj to 5% by IGL/qslim")
 {
     std::string  obj_filename    = "frog_legs.obj";
     TriangleMesh mesh            = load_model(obj_filename);
