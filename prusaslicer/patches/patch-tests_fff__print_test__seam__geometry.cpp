$NetBSD$

Support Catch2 v3.

--- tests/fff_print/test_seam_geometry.cpp.orig	2024-06-16 00:13:41.674445563 +0000
+++ tests/fff_print/test_seam_geometry.cpp
@@ -1,5 +1,8 @@
 #include <libslic3r/Point.hpp>
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/catch_approx.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_vector.hpp>
 #include <libslic3r/GCode/SeamGeometry.hpp>
 #include <libslic3r/Geometry.hpp>
 
@@ -69,7 +72,7 @@ TEST_CASE("Vertex angle calculation coun
 
     CHECK(angles.size() == 4);
     for (const double angle : angles) {
-        CHECK(angle == Approx(-M_PI / 2));
+        CHECK(angle == Catch::Approx(-M_PI / 2));
     }
 }
 
@@ -79,7 +82,7 @@ TEST_CASE("Vertex angle calculation cloc
 
     CHECK(angles.size() == 4);
     for (const double angle : angles) {
-        CHECK(angle == Approx(M_PI / 2));
+        CHECK(angle == Catch::Approx(M_PI / 2));
     }
 }
 
@@ -121,7 +124,7 @@ TEST_CASE("Vertex angle is rotation agno
     );
 
     std::vector<double> rotated_angles = Seams::Geometry::get_vertex_angles(points, 0.1);
-    CHECK(rotated_angles[1] == Approx(angles[1]));
+    CHECK(rotated_angles[1] == Catch::Approx(angles[1]));
 }
 
 TEST_CASE("Calculate overhangs", "[Seams][SeamGeometry]") {
