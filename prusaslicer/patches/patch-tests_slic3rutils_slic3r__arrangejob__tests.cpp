$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/slic3rutils/slic3r_arrangejob_tests.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/slic3rutils/slic3r_arrangejob_tests.cpp
@@ -1,4 +1,6 @@
-#include "catch2/catch.hpp"
+#include <catch2/catch_template_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
 #include "test_utils.hpp"
 
 #include <random>
@@ -13,6 +15,8 @@
 
 #include "libslic3r/Format/3mf.hpp"
 
+using Catch::Matchers::WithinRel;
+
 class RandomArrangeSettings: public Slic3r::arr2::ArrangeSettingsView {
     Slic3r::arr2::ArrangeSettingsDb::Values m_v;
 
@@ -143,7 +147,7 @@ TEST_CASE("Basic arrange with cube", "[a
             std::swap(sz.x(), sz.y());
 
         double d_obj = settings.get_distance_from_objects();
-        REQUIRE(sz.y() == Approx(2. * bb1.size().y() + d_obj));
+        REQUIRE_THAT(sz.y(), WithinRel(2. * bb1.size().y() + d_obj, EPSILON));
     }
 
     SECTION("Selected cube (different object), needs to go beside existing") {
@@ -177,7 +181,7 @@ TEST_CASE("Basic arrange with cube", "[a
             std::swap(sz.x(), sz.y());
 
         double d_obj = settings.get_distance_from_objects();
-        REQUIRE(sz.y() == Approx(2. * bb1.size().y() + d_obj));
+        REQUIRE_THAT(sz.y(), WithinRel(2. * bb1.size().y() + d_obj, EPSILON));
     }
 
     SECTION("Four cubes needs to touch each other after arrange") {
@@ -229,8 +233,8 @@ TEST_CASE("Basic arrange with cube", "[a
         REQUIRE(c == bounding_box(bed).center());
 
         float d_obj = settings.get_distance_from_objects();
-        REQUIRE(pilebb.size().x() == Approx(2. * 20. + d_obj));
-        REQUIRE(pilebb.size().y() == Approx(2. * 20. + d_obj));
+        REQUIRE_THAT(pilebb.size().x(), WithinRel(2. * 20. + d_obj));
+        REQUIRE_THAT(pilebb.size().y(), WithinRel(2. * 20. + d_obj));
     }
 }
 
