$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_cut_surface.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/libslic3r/test_cut_surface.cpp
@@ -1,10 +1,10 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
 
 #include <libslic3r/CutSurface.hpp>
 #include <libslic3r/TriangleMesh.hpp> // its_make_cube + its_merge
 
 using namespace Slic3r;
-TEST_CASE("Cut character from surface", "[]")
+TEST_CASE("Cut character from surface")
 {
     std::string font_path = std::string(TEST_DATA_DIR) +
                             "/../../resources/fonts/NotoSans-Regular.ttf";
