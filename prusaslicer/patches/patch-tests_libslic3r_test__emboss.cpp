$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_emboss.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/libslic3r/test_emboss.cpp
@@ -1,4 +1,4 @@
-﻿#include <catch2/catch.hpp>
+﻿#include <catch2/catch_test_macros.hpp>
 
 #include <libslic3r/Emboss.hpp>
 #include <libslic3r/SVG.hpp> // only debug visualization
@@ -412,7 +412,7 @@ TEST_CASE("ray segment intersection", "[
     CHECK(abs(*t1 - *t2) < std::numeric_limits<double>::epsilon());
 }
 
-TEST_CASE("triangle intersection", "[]")
+TEST_CASE("triangle intersection")
 {
     Vec2d                point(1, 1);
     Vec2d                dir(-1, 0);
@@ -481,7 +481,7 @@ TEST_CASE("Italic check", "[Emboss]") 
 #endif // FONT_DIR_PATH
 
 #include "libslic3r/CutSurface.hpp"
-TEST_CASE("Cut surface", "[]")
+TEST_CASE("Cut surface")
 {
     std::string  font_path  = get_font_filepath();
     char         letter     = '%';
