$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_voronoi.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/libslic3r/test_voronoi.cpp
@@ -1,4 +1,6 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
 #include <test_utils.hpp>
 
 #include <libslic3r/Polygon.hpp>
@@ -25,6 +27,8 @@ using namespace Slic3r;
 
 using VD = Geometry::VoronoiDiagram;
 
+using Catch::Matchers::WithinRel;
+
 // https://svn.boost.org/trac10/ticket/12067
 // This bug seems to be confirmed.
 // Vojtech supposes that there may be no Voronoi edges produced for
@@ -69,7 +73,7 @@ TEST_CASE("Voronoi missing edges - point
         vd, pts, Lines());
 #endif
 
-//    REQUIRE(closest_point.z() == Approx(1.));
+//    REQUIRE_THAT(closest_point.z(), WithinRel(1.));
 }
 
 // https://svn.boost.org/trac10/ticket/12707
