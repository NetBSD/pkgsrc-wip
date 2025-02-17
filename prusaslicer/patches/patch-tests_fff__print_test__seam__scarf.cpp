$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/fff_print/test_seam_scarf.cpp.orig	2025-02-17 06:53:05.395956984 +0000
+++ tests/fff_print/test_seam_scarf.cpp
@@ -1,9 +1,11 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_approx.hpp>
+#include <catch2/catch_test_macros.hpp>
 #include <libslic3r/GCode/SeamScarf.hpp>
 #include <libslic3r/GCode/SmoothPath.hpp>
 
 using namespace Slic3r;
 using Seams::Scarf::Impl::PathPoint;
+using Catch::Approx;
 
 TEST_CASE("Get path point", "[Seams][Scarf]") {
     using Seams::Scarf::Impl::get_path_point;
