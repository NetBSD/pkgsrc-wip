$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_aabbindirect.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/libslic3r/test_aabbindirect.cpp
@@ -1,5 +1,7 @@
 #include <algorithm>
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
 #include <test_utils.hpp>
 
 #include <libslic3r/TriangleMesh.hpp>
@@ -7,6 +9,8 @@
 #include <libslic3r/AABBTreeLines.hpp>
 
 using namespace Slic3r;
+using Catch::Matchers::WithinRel;
+using Catch::Matchers::WithinAbs;
 
 TEST_CASE("Building a tree over a box, ray caster and closest query", "[AABBIndirect]")
 {
@@ -24,7 +28,7 @@ TEST_CASE("Building a tree over a box, r
 		hit);
 
     REQUIRE(intersected);
-    REQUIRE(hit.t == Approx(5.));
+    REQUIRE_THAT(hit.t, WithinRel(5.));
 
     std::vector<igl::Hit> hits;
 	bool intersected2 = AABBTreeIndirect::intersect_ray_all_hits(
@@ -35,8 +39,8 @@ TEST_CASE("Building a tree over a box, r
 		hits);
     REQUIRE(intersected2);
     REQUIRE(hits.size() == 2);
-    REQUIRE(hits.front().t == Approx(5.));
-    REQUIRE(hits.back().t == Approx(6.));
+    REQUIRE_THAT(hits.front().t, WithinRel(5.));
+    REQUIRE_THAT(hits.back().t, WithinRel(6.));
 
     size_t hit_idx;
     Vec3d  closest_point;
@@ -45,20 +49,20 @@ TEST_CASE("Building a tree over a box, r
 		tree,
         Vec3d(0.3, 0.5, -5.),
 		hit_idx, closest_point);
-    REQUIRE(squared_distance == Approx(5. * 5.));
-    REQUIRE(closest_point.x() == Approx(0.3));
-    REQUIRE(closest_point.y() == Approx(0.5));
-    REQUIRE(closest_point.z() == Approx(0.));
+    REQUIRE_THAT(squared_distance, WithinRel(5. * 5.));
+    REQUIRE_THAT(closest_point.x(), WithinRel(0.3));
+    REQUIRE_THAT(closest_point.y(), WithinRel(0.5));
+    REQUIRE_THAT(closest_point.z(), WithinAbs(0., EPSILON));
 
     squared_distance = AABBTreeIndirect::squared_distance_to_indexed_triangle_set(
 		tmesh.its.vertices, tmesh.its.indices,
 		tree,
         Vec3d(0.3, 0.5, 5.),
 		hit_idx, closest_point);
-    REQUIRE(squared_distance == Approx(4. * 4.));
-    REQUIRE(closest_point.x() == Approx(0.3));
-    REQUIRE(closest_point.y() == Approx(0.5));
-    REQUIRE(closest_point.z() == Approx(1.));
+    REQUIRE_THAT(squared_distance, WithinRel(4. * 4.));
+    REQUIRE_THAT(closest_point.x(), WithinRel(0.3));
+    REQUIRE_THAT(closest_point.y(), WithinRel(0.5));
+    REQUIRE_THAT(closest_point.z(), WithinRel(1.));
 }
 
 TEST_CASE("Creating a several 2d lines, testing closest point query", "[AABBIndirect]")
@@ -75,17 +79,17 @@ TEST_CASE("Creating a several 2d lines, 
     Vec2d hit_point_out;
     auto sqr_dist = AABBTreeLines::squared_distance_to_indexed_lines(lines, tree, Vec2d(0.0, 0.0), hit_idx_out,
             hit_point_out);
-    REQUIRE(sqr_dist == Approx(0.0));
+    REQUIRE_THAT(sqr_dist, WithinAbs(0.0, EPSILON));
     REQUIRE((hit_idx_out == 0 || hit_idx_out == 3));
-    REQUIRE(hit_point_out.x() == Approx(0.0));
-    REQUIRE(hit_point_out.y() == Approx(0.0));
+    REQUIRE_THAT(hit_point_out.x(), WithinAbs(0.0, EPSILON));
+    REQUIRE_THAT(hit_point_out.y(), WithinAbs(0.0, EPSILON));
 
     sqr_dist = AABBTreeLines::squared_distance_to_indexed_lines(lines, tree, Vec2d(1.5, 0.5), hit_idx_out,
             hit_point_out);
-    REQUIRE(sqr_dist == Approx(0.25));
+    REQUIRE_THAT(sqr_dist, WithinRel(0.25));
     REQUIRE(hit_idx_out == 1);
-    REQUIRE(hit_point_out.x() == Approx(1.0));
-    REQUIRE(hit_point_out.y() == Approx(0.5));
+    REQUIRE_THAT(hit_point_out.x(), WithinRel(1.0));
+    REQUIRE_THAT(hit_point_out.y(), WithinRel(0.5));
 }
 
 TEST_CASE("Creating a several 2d lines, testing all lines in radius query", "[AABBIndirect]")
