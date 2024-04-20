$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/fff_print/test_retraction.cpp.orig	2024-04-14 02:13:14.728519199 +0000
+++ tests/fff_print/test_retraction.cpp
@@ -2,10 +2,12 @@
  * Ported from t/retraction.t
  */
 
-#include <catch2/catch.hpp>
+#include <catch2/catch_approx.hpp>
+#include <catch2/catch_test_macros.hpp>
 
 #include <libslic3r/GCodeReader.hpp>
 #include <libslic3r/Config.hpp>
+using Catch::Approx;
 
 #include "test_data.hpp"
 #include <regex>
@@ -77,7 +79,7 @@ void check_gcode(std::initializer_list<T
                 lift_dist = line.dist_Z(self);
             }
             if (line.dist_Z(self) < 0) {
-                INFO("Must be lifted before going down.")
+                INFO("Must be lifted before going down.");
                 CHECK(lifted);
                 INFO("Going down by the same amount of the lift or by the amount needed to get to next layer");
                 CHECK((
