$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/arrange/test_arrange.cpp.orig	2024-06-14 21:54:48.000000000 +0000
+++ tests/arrange/test_arrange.cpp
@@ -1,4 +1,7 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_template_test_macros.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
 #include "test_utils.hpp"
 
 #include <libslic3r/Execution/ExecutionSeq.hpp>
@@ -40,6 +43,9 @@
 
 #include <random>
 
+using Catch::Matchers::WithinRel;
+using Catch::Matchers::WithinAbs;
+
 template<class ArrItem = Slic3r::arr2::ArrangeItem>
 static std::vector<ArrItem> prusa_parts(double infl = 0.) {
     using namespace Slic3r;
@@ -930,7 +936,7 @@ TEST_CASE("Optimal nfp position search w
 
                 Slic3r::Vec2crd D = bed.center - item.shape.center();
                 REQUIRE(item.translation == D);
-                REQUIRE(score == Approx(0.).margin(EPSILON));
+                REQUIRE_THAT(score, WithinAbs(0., EPSILON));
             }
         }
     }
@@ -1063,6 +1069,6 @@ TEMPLATE_TEST_CASE("Test if allowed item
     bool packed = pack(strategy, bed, itm);
 
     REQUIRE(packed);
-    REQUIRE(get_rotation(itm) == Approx(PI));
+    REQUIRE_THAT(get_rotation(itm), WithinRel(PI));
 }
 
