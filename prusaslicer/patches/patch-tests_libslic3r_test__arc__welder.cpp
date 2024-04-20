$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_arc_welder.cpp.orig	2024-04-14 02:13:14.797323585 +0000
+++ tests/libslic3r/test_arc_welder.cpp
@@ -1,4 +1,5 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_approx.hpp>
+#include <catch2/catch_test_macros.hpp>
 #include <test_utils.hpp>
 
 #include <random>
@@ -9,6 +10,7 @@
 #include <libslic3r/libslic3r.h>
 
 using namespace Slic3r;
+using Catch::Approx;
 
 TEST_CASE("arc basics", "[ArcWelder]") {
     using namespace Slic3r::Geometry;
