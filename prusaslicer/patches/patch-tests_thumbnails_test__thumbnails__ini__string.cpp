$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/thumbnails/test_thumbnails_ini_string.cpp.orig	2024-04-14 02:13:15.056763916 +0000
+++ tests/thumbnails/test_thumbnails_ini_string.cpp
@@ -1,4 +1,4 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
 
 #include "libslic3r/Config.hpp"
 #include "libslic3r/PrintConfig.hpp"
