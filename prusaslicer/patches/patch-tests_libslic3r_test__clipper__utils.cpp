$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_clipper_utils.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/libslic3r/test_clipper_utils.cpp
@@ -1,4 +1,6 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
 
 #include <numeric>
 #include <iostream>
@@ -9,6 +11,7 @@
 #include "libslic3r/SVG.hpp"
 
 using namespace Slic3r;
+using Catch::Matchers::WithinRel;
 
 SCENARIO("Various Clipper operations - xs/t/11_clipper.t", "[ClipperUtils]") {
 	// CCW oriented contour
@@ -122,7 +125,7 @@ SCENARIO("Various Clipper operations - x
 			REQUIRE(result.size() == 1);
 		}
 		THEN("intersection_pl - result has same length as subject polyline") {
-			REQUIRE(result.front().length() == Approx(subject.length()));
+			REQUIRE_THAT(result.front().length(), WithinRel(subject.length()));
 		}
 	}
 
@@ -185,7 +188,7 @@ SCENARIO("Various Clipper operations - t
                 ExPolygon match({ { 20, 18 }, { 10, 18 }, { 10, 12 }, { 20, 12 } },
                                 { { 14, 16 }, { 16, 16 }, { 16, 14 }, { 14, 14 } });
                 REQUIRE(intersection.size() == 1);
-                REQUIRE(intersection.front().area() == Approx(match.area()));
+                REQUIRE_THAT(intersection.front().area(), WithinRel(match.area()));
             }
         }
 
@@ -193,39 +196,39 @@ SCENARIO("Various Clipper operations - t
         WHEN("Clipping line 1") {
             Polylines intersection = intersection_pl({ Polyline { { 15, 18 }, { 15, 15 } } }, expolygons);
             THEN("line is clipped to square with hole") {
-                REQUIRE((Vec2f(15, 18) - Vec2f(15, 16)).norm() == Approx(intersection.front().length()));
+                REQUIRE_THAT((Vec2f(15, 18) - Vec2f(15, 16)).norm(), WithinRel(intersection.front().length()));
             }
         }
         WHEN("Clipping line 2") {
             Polylines intersection = intersection_pl({ Polyline { { 15, 15 }, { 15, 12 } } }, expolygons);
             THEN("line is clipped to square with hole") {
-                REQUIRE((Vec2f(15, 14) - Vec2f(15, 12)).norm() == Approx(intersection.front().length()));
+                REQUIRE_THAT((Vec2f(15, 14) - Vec2f(15, 12)).norm(), WithinRel(intersection.front().length()));
             }
         }
         WHEN("Clipping line 3") {
             Polylines intersection = intersection_pl({ Polyline { { 12, 18 }, { 18, 18 } } }, expolygons);
             THEN("line is clipped to square with hole") {
-                REQUIRE((Vec2f(18, 18) - Vec2f(12, 18)).norm() == Approx(intersection.front().length()));
+                REQUIRE_THAT((Vec2f(18, 18) - Vec2f(12, 18)).norm(), WithinRel(intersection.front().length()));
             }
         }
         WHEN("Clipping line 4") {
             Polylines intersection = intersection_pl({ Polyline { { 5, 15 }, { 30, 15 } } }, expolygons);
             THEN("line is clipped to square with hole") {
-                REQUIRE((Vec2f(14, 15) - Vec2f(10, 15)).norm() == Approx(intersection.front().length()));
-                REQUIRE((Vec2f(20, 15) - Vec2f(16, 15)).norm() == Approx(intersection[1].length()));
+                REQUIRE_THAT((Vec2f(14, 15) - Vec2f(10, 15)).norm(), WithinRel(intersection.front().length()));
+                REQUIRE_THAT((Vec2f(20, 15) - Vec2f(16, 15)).norm(), WithinRel(intersection[1].length()));
             }
         }
         WHEN("Clipping line 5") {
             Polylines intersection = intersection_pl({ Polyline { { 30, 15 }, { 5, 15 } } }, expolygons);
             THEN("reverse line is clipped to square with hole") {
-                REQUIRE((Vec2f(20, 15) - Vec2f(16, 15)).norm() == Approx(intersection.front().length()));
-                REQUIRE((Vec2f(14, 15) - Vec2f(10, 15)).norm() == Approx(intersection[1].length()));
+                REQUIRE_THAT((Vec2f(20, 15) - Vec2f(16, 15)).norm(), WithinRel(intersection.front().length()));
+                REQUIRE_THAT((Vec2f(14, 15) - Vec2f(10, 15)).norm(), WithinRel(intersection[1].length()));
             }
         }
         WHEN("Clipping line 6") {
             Polylines intersection = intersection_pl({ Polyline { { 10, 18 }, { 20, 18 } } }, expolygons);
             THEN("tangent line is clipped to square with hole") {
-                REQUIRE((Vec2f(20, 18) - Vec2f(10, 18)).norm() == Approx(intersection.front().length()));
+                REQUIRE_THAT((Vec2f(20, 18) - Vec2f(10, 18)).norm(), WithinRel(intersection.front().length()));
             }
         }
     }
@@ -246,7 +249,7 @@ SCENARIO("Various Clipper operations - t
 			ExPolygons diff = Slic3r::diff_ex(Polygons{ square, square2 }, Polygons{ hole });
             THEN("difference of a cw from two ccw is a contour with one hole") {
                 REQUIRE(diff.size() == 1);
-                REQUIRE(diff.front().area() == Approx(ExPolygon({ {40, 40}, {0, 40}, {0, 0}, {40, 0} }, { {15, 25}, {25, 25}, {25, 15}, {15, 15} }).area()));
+                REQUIRE_THAT(diff.front().area(), WithinRel(ExPolygon({ {40, 40}, {0, 40}, {0, 0}, {40, 0} }, { {15, 25}, {25, 25}, {25, 15}, {15, 15} }).area()));
             }
         }
     }
@@ -296,8 +299,8 @@ SCENARIO("Various Clipper operations - t
             auto line = Polyline::new_scale({ { 152.742,288.086671142818 }, { 152.742,34.166466971035 } });    
             Polylines intersection = intersection_pl(line, to_polygons(circle_with_hole));
             THEN("clipped to two pieces") {
-                REQUIRE(intersection.front().length() == Approx((Vec2d(152742000, 215178843) - Vec2d(152742000, 288086661)).norm()));
-                REQUIRE(intersection[1].length() == Approx((Vec2d(152742000, 35166477) - Vec2d(152742000, 108087507)).norm()));
+                REQUIRE_THAT(intersection.front().length(), WithinRel((Vec2d(152742000, 215178843) - Vec2d(152742000, 288086661)).norm()));
+                REQUIRE_THAT(intersection[1].length(), WithinRel((Vec2d(152742000, 35166477) - Vec2d(152742000, 108087507)).norm()));
             }
         }
     }
@@ -360,25 +363,25 @@ TEST_CASE("Traversing Clipper PolyTree",
 
     SECTION("Traverse into Polygons WITHOUT spatial ordering") {
         Polygons output;
-        REQUIRE(area_sum == Approx(polytree_area(tree.GetFirst(), &output)));
+        REQUIRE_THAT(area_sum, WithinRel(polytree_area(tree.GetFirst(), &output)));
         REQUIRE(output.size() == reference.size());
     }
     
     SECTION("Traverse into ExPolygons WITHOUT spatial ordering") {
         ExPolygons output;
-        REQUIRE(area_sum == Approx(polytree_area(tree.GetFirst(), &output)));
+        REQUIRE_THAT(area_sum, WithinRel(polytree_area(tree.GetFirst(), &output)));
         REQUIRE(count_polys(output) == reference.size());
     }
     
     SECTION("Traverse into Polygons WITH spatial ordering") {
         Polygons output;
-        REQUIRE(area_sum == Approx(polytree_area<e_ordering::ON>(tree.GetFirst(), &output)));
+        REQUIRE_THAT(area_sum, WithinRel(polytree_area<e_ordering::ON>(tree.GetFirst(), &output)));
         REQUIRE(output.size() == reference.size());
     }
     
     SECTION("Traverse into ExPolygons WITH spatial ordering") {
         ExPolygons output;
-        REQUIRE(area_sum == Approx(polytree_area<e_ordering::ON>(tree.GetFirst(), &output)));
+        REQUIRE_THAT(area_sum, WithinRel(polytree_area<e_ordering::ON>(tree.GetFirst(), &output)));
         REQUIRE(count_polys(output) == reference.size());
     }
 }
