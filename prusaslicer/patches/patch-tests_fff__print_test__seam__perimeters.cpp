$NetBSD$

Support Catch2 v3.

--- tests/fff_print/test_seam_perimeters.cpp.orig	2024-06-16 00:15:07.448492235 +0000
+++ tests/fff_print/test_seam_perimeters.cpp
@@ -2,7 +2,8 @@
 #include "libslic3r/GCode/SeamPerimeters.hpp"
 #include "libslic3r/Layer.hpp"
 #include "libslic3r/Point.hpp"
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/catch_approx.hpp>
 #include <libslic3r/GCode/SeamGeometry.hpp>
 #include <libslic3r/Geometry.hpp>
 #include <fstream>
@@ -27,7 +28,7 @@ TEST_CASE("Oversample painted", "[Seams]
     )};
 
     REQUIRE(points.size() == 8);
-    CHECK((points[1] - Vec2d{0.2, 0.0}).norm() == Approx(0.0));
+    CHECK((points[1] - Vec2d{0.2, 0.0}).norm() == Catch::Approx(0.0));
 
     points = Perimeters::Impl::oversample_painted(
         Seams::Geometry::unscaled(square.contour.points), is_painted, 1.0, 0.199
@@ -53,8 +54,8 @@ TEST_CASE("Remove redundant points", "[S
 
     REQUIRE(resulting_points.size() == 6);
     REQUIRE(resulting_point_types.size() == 6);
-    CHECK((resulting_points[3] - Vec2d{3.0, 0.0}).norm() == Approx(0.0));
-    CHECK((resulting_points[4] - Vec2d{3.0, 2.0}).norm() == Approx(0.0));
+    CHECK((resulting_points[3] - Vec2d{3.0, 0.0}).norm() == Catch::Approx(0.0));
+    CHECK((resulting_points[4] - Vec2d{3.0, 2.0}).norm() == Catch::Approx(0.0));
     CHECK(resulting_point_types[3] == PointType::blocker);
     CHECK(resulting_point_types[4] == PointType::blocker);
 }
