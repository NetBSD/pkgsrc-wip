$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/fff_print/test_gcode.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/fff_print/test_gcode.cpp
@@ -2,7 +2,8 @@
  * Mostly ported from t/gcode.t
  */
 
-#include <catch2/catch.hpp>
+#include <catch2/catch_approx.hpp>
+#include <catch2/catch_test_macros.hpp>
 
 #include <memory>
 #include <regex>
@@ -15,6 +16,7 @@
 
 using namespace Slic3r;
 using namespace Test;
+using Catch::Approx;
 
 constexpr bool debug_files = false;
 
@@ -66,7 +68,7 @@ TEST_CASE("Wiping speeds", "[GCode]") {
         INFO("Wipe moves don\'t retract faster than configured speed");
         CHECK(retract_speed < expected_retract_speed);
     }
-    INFO("No wiping after layer change")
+    INFO("No wiping after layer change");
     CHECK(!wiping_on_new_layer);
 }
 
