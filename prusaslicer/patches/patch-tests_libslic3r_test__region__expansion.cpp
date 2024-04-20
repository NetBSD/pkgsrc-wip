$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_region_expansion.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/libslic3r/test_region_expansion.cpp
@@ -1,4 +1,6 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
 
 #include <libslic3r/libslic3r.h>
 #include <libslic3r/Algorithm/RegionExpansion.hpp>
@@ -8,6 +10,7 @@
 #include <libslic3r/SVG.cpp>
 
 using namespace Slic3r;
+using Catch::Matchers::WithinRel;
 
 //#define DEBUG_TEMP_DIR "d:\\temp\\"
 
@@ -27,7 +30,7 @@ SCENARIO("Region expansion basics", "[Re
                 REQUIRE(expanded.size() == 1);
             }
             THEN("The area of the anchor is 10mm2") {
-                REQUIRE(area(expanded.front()) == Approx(expansion * ten));
+                REQUIRE_THAT(area(expanded.front()), WithinRel(expansion * ten));
             }
         };
 
@@ -61,8 +64,8 @@ SCENARIO("Region expansion basics", "[Re
                 REQUIRE(expanded.front().size() == 2);
             }
             THEN("The area of each anchor is 10mm2") {
-                REQUIRE(area(expanded.front().front()) == Approx(expansion * ten));
-                REQUIRE(area(expanded.front().back()) == Approx(expansion * ten));
+                REQUIRE_THAT(area(expanded.front().front()), WithinRel(expansion * ten));
+                REQUIRE_THAT(area(expanded.front().back()), WithinRel(expansion * ten));
             }
         }
 
@@ -77,8 +80,8 @@ SCENARIO("Region expansion basics", "[Re
                 REQUIRE(expanded.front().size() == 2);
             }
             THEN("The area of each anchor is 100mm2") {
-                REQUIRE(area(expanded.front().front()) == Approx(sqr<double>(ten)));
-                REQUIRE(area(expanded.front().back()) == Approx(sqr<double>(ten)));
+                REQUIRE_THAT(area(expanded.front().front()), WithinRel(sqr<double>(ten)));
+                REQUIRE_THAT(area(expanded.front().back()), WithinRel(sqr<double>(ten)));
             }
         }
     }
@@ -247,7 +250,7 @@ SCENARIO("Region expansion basics", "[Re
             THEN("The anchor expands into a single region with two holes, fully covering the boundary") {
                 REQUIRE(expanded.size() == 1);
                 REQUIRE(expanded.front().size() == 3);
-                REQUIRE(area(expanded.front()) == Approx(area(boundary)));
+                REQUIRE_THAT(area(expanded.front()), WithinRel(area(boundary)));
             }
         }
     }
