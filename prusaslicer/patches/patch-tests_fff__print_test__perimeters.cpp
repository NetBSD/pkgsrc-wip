$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/fff_print/test_perimeters.cpp.orig	2024-04-05 09:25:31.000000000 +0000
+++ tests/fff_print/test_perimeters.cpp
@@ -1,4 +1,5 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_approx.hpp>
+#include <catch2/catch_test_macros.hpp>
 
 #include <numeric>
 #include <sstream>
@@ -15,6 +16,7 @@
 #include "test_data.hpp"
 
 using namespace Slic3r;
+using Catch::Approx;
 
 SCENARIO("Perimeter nesting", "[Perimeters]")
 {
