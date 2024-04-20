$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_line.cpp.orig	2024-04-14 02:09:53.235169800 +0000
+++ tests/libslic3r/test_line.cpp
@@ -2,7 +2,8 @@
  * Ported from xs/t/10_line.t
  */
 
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/generators/catch_generators.hpp>
 #include <libslic3r/Line.hpp>
 #include "test_utils.hpp"
 
@@ -37,7 +38,7 @@ TEST_CASE("Parallel lines under angles",
     CHECK(line.parallel_to(line.direction()));
     INFO("Line is parallel to its direction + PI");
     line.parallel_to(line.direction() + M_PI);
-    INFO("line is parallel to its direction - PI")
+    INFO("line is parallel to its direction - PI");
     line.parallel_to(line.direction() - M_PI);
 
     SECTION("Line is parallel within epsilon") {
