$NetBSD$

Support Catch2 v3.

--- tests/sla_print/sla_zcorrection_tests.cpp.orig	2024-06-15 23:48:02.608865326 +0000
+++ tests/sla_print/sla_zcorrection_tests.cpp
@@ -1,4 +1,8 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_approx.hpp>
+#include <catch2/catch_template_test_macros.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/generators/catch_generators.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
 #include <test_utils.hpp>
 
 #include <algorithm>
@@ -64,7 +68,7 @@ TEST_CASE("Testing DepthMap for a cube",
         REQUIRE(dlayer.begin()->first == i);
         double ad = area(dlayer.begin()->second);
         double as = area(slayer);
-        REQUIRE(ad == Approx(as).margin(EPSILON));
+        REQUIRE(ad == Catch::Approx(as).margin(EPSILON));
     }
 }
 
@@ -101,7 +105,7 @@ TEST_CASE("Testing DepthMap for arbitrar
         const ExPolygons &slayer = corrslices_fast[i];
         double ad = area(dlayer);
         double as = area(slayer);
-        REQUIRE(ad == Approx(as).margin(EPSILON));
+        REQUIRE(ad == Catch::Approx(as).margin(EPSILON));
     }
 }
 
