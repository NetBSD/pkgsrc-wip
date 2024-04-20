$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/sla_print/sla_raycast_tests.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/sla_print/sla_raycast_tests.cpp
@@ -1,4 +1,6 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
 #include <test_utils.hpp>
 
 #include <libslic3r/AABBMesh.hpp>
@@ -6,6 +8,8 @@
 
 #include "sla_test_utils.hpp"
 
+using Catch::Matchers::WithinRel;
+
 using namespace Slic3r;
 
 // First do a simple test of the hole raycaster.
@@ -20,8 +24,8 @@ TEST_CASE("Raycaster - find intersection
     s = {-1.f, 0, 5.f};
     dir = {1.f, 0, 0};
     hole.get_intersections(s, dir, out);
-    REQUIRE(out[0].first == Approx(-4.f));
-    REQUIRE(out[1].first == Approx(6.f));
+    REQUIRE_THAT(out[0].first, WithinRel(-4.f));
+    REQUIRE_THAT(out[1].first, WithinRel(6.f));
 
     // Start outside and cast parallel to axis.
     s = {0, 0, -1.f};
@@ -70,25 +74,25 @@ TEST_CASE("Raycaster with loaded drillho
     Vec3d s = center.cast<double>();
     // Fire from center, should hit the interior wall
     auto hit = emesh.query_ray_hit(s, {0, 1., 0.});
-    REQUIRE(hit.distance() == Approx(boxbb.size().x() / 2 - hcfg.min_thickness));
+    REQUIRE_THAT(hit.distance(), WithinRel(boxbb.size().x() / 2 - hcfg.min_thickness));
     
     // Fire upward from hole center, hit distance equals the radius (hits the
     // side of the hole cut.
     s.y() = hcfg.min_thickness / 2;
     hit = emesh.query_ray_hit(s, {0, 0., 1.});
-    REQUIRE(hit.distance() == Approx(radius));
+    REQUIRE_THAT(hit.distance(), WithinRel(radius));
 
     // Fire from outside, hit the back side of the cube interior
     s.y() = -1.;
     hit = emesh.query_ray_hit(s, {0, 1., 0.});
-    REQUIRE(hit.distance() == Approx(boxbb.max.y() - hcfg.min_thickness - s.y()));
+    REQUIRE_THAT(hit.distance(), WithinRel(boxbb.max.y() - hcfg.min_thickness - s.y()));
     
     // Fire downwards from above the hole cylinder. Has to go through the cyl.
     // as it was not there.
     s = center.cast<double>();
     s.z() = boxbb.max.z() - hcfg.min_thickness - 1.;
     hit = emesh.query_ray_hit(s, {0, 0., -1.});
-    REQUIRE(hit.distance() == Approx(s.z() - boxbb.min.z() - hcfg.min_thickness));
+    REQUIRE_THAT(hit.distance(), WithinRel(s.z() - boxbb.min.z() - hcfg.min_thickness));
 
     // Check for support tree correctness
     test_support_model_collision("20mm_cube.obj", {}, hcfg, holes);
