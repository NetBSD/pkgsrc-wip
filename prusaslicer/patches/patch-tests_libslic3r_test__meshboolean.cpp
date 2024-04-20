$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_meshboolean.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/libslic3r/test_meshboolean.cpp
@@ -1,10 +1,13 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
 #include <test_utils.hpp>
 
 #include <libslic3r/TriangleMesh.hpp>
 #include <libslic3r/MeshBoolean.hpp>
 
 using namespace Slic3r;
+using Catch::Matchers::WithinRel;
 
 TEST_CASE("CGAL and TriangleMesh conversions", "[MeshBoolean]") {
     TriangleMesh sphere = make_sphere(1.);
@@ -19,7 +22,7 @@ TEST_CASE("CGAL and TriangleMesh convers
     REQUIRE(M.its.vertices.size() == sphere.its.vertices.size());
     REQUIRE(M.its.indices.size() == sphere.its.indices.size());
     
-    REQUIRE(M.volume() == Approx(sphere.volume()));
+    REQUIRE_THAT(M.volume(), WithinRel(sphere.volume()));
     
     REQUIRE(! MeshBoolean::cgal::does_self_intersect(M));
 }
