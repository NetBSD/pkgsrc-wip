$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_layer_region.cpp.orig	2024-05-18 04:10:14.661979829 +0000
+++ tests/libslic3r/test_layer_region.cpp
@@ -2,11 +2,13 @@
 #include "libslic3r/Geometry.hpp"
 #include "libslic3r/Point.hpp"
 #include "libslic3r/SVG.hpp"
-#include <catch2/catch.hpp>
+#include <catch2/catch_approx.hpp>
+#include <catch2/catch_test_macros.hpp>
 #include <libslic3r/LayerRegion.hpp>
 
 using namespace Slic3r;
 using namespace Slic3r::Algorithm;
+using Catch::Approx;
 
 constexpr bool export_svgs = false;
 
