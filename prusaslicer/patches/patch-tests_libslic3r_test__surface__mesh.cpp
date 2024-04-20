$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_surface_mesh.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/libslic3r/test_surface_mesh.cpp
@@ -1,10 +1,12 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_approx.hpp>
+#include <catch2/catch_test_macros.hpp>
 #include <test_utils.hpp>
 
 
 #include <libslic3r/SurfaceMesh.hpp>
 
 using namespace Slic3r;
+using Catch::Approx;
 
 
 // Generate a broken cube mesh. Face 8 is inverted, face 11 is missing.
