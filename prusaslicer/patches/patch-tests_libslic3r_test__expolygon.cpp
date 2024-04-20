$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_expolygon.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/libslic3r/test_expolygon.cpp
@@ -1,10 +1,13 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
 
 #include "libslic3r/Point.hpp"
 #include "libslic3r/Polygon.hpp"
 #include "libslic3r/ExPolygon.hpp"
 
 using namespace Slic3r;
+using Catch::Matchers::WithinRel;
 
 static inline bool points_close(const Point &p1, const Point &p2)
 {
@@ -30,7 +33,7 @@ SCENARIO("Basics", "[ExPolygon]") {
             REQUIRE(expolygon.is_valid());
         }
         THEN("expolygon area") {
-            REQUIRE(expolygon.area() == Approx(100*100-20*20));
+            REQUIRE_THAT(expolygon.area(), WithinRel(100.0*100-20*20));
         }
         WHEN("Expolygon scaled") {
             ExPolygon expolygon2 = expolygon;
@@ -160,4 +163,4 @@ TEST_CASE("Serialization of expolygons t
     }
 
     CHECK(expolys == expolys_loaded);
-}
\ No newline at end of file
+}
