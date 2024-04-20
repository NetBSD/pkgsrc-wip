$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_support_spots_generator.cpp.orig	2024-04-14 02:13:14.959463307 +0000
+++ tests/libslic3r/test_support_spots_generator.cpp
@@ -1,9 +1,13 @@
 #include "libslic3r/Point.hpp"
-#include <catch2/catch.hpp>
+#include <catch2/catch_approx.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
 #include <libslic3r/SupportSpotsGenerator.hpp>
 
 using namespace Slic3r;
 using namespace SupportSpotsGenerator;
+using Catch::Approx;
 
 namespace Rectangle {
 const float width = 10;
