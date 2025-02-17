$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_point.cpp.orig	2024-12-20 11:54:34.000000000 +0000
+++ tests/libslic3r/test_point.cpp
@@ -5,11 +5,15 @@
  *  and cross product uses doubles
  */
 
-#include <catch2/catch.hpp>
+#include <catch2/catch_approx.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
+#include <catch2/catch_test_macros.hpp>
 #include <libslic3r/Point.hpp>
 #include "test_utils.hpp"
 
 using namespace Slic3r;
+using Catch::Approx;
 
 TEST_CASE("Nearest point", "[Point]") {
     const Point point{10, 15};
