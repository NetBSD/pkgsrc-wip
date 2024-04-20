$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/fff_print/test_fill.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/fff_print/test_fill.cpp
@@ -1,4 +1,6 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
 
 #include <numeric>
 #include <sstream>
@@ -18,6 +20,7 @@
 
 using namespace Slic3r;
 using namespace std::literals;
+using Catch::Matchers::WithinRel;
 
 bool test_if_solid_surface_filled(const ExPolygon& expolygon, double flow_spacing, double angle = 0, double density = 1.0);
 
@@ -25,7 +28,7 @@ bool test_if_solid_surface_filled(const 
 TEST_CASE("Fill: adjusted solid distance") {
     int surface_width = 250;
     int distance = Slic3r::Flow::solid_spacing(surface_width, 47);
-    REQUIRE(distance == Approx(50));
+    REQUIRE_THAT(distance, WithinRel(50));
     REQUIRE(surface_width % distance == 0);
 }
 #endif
