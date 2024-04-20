$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_static_map.cpp.orig	2024-04-14 02:13:14.943711298 +0000
+++ tests/libslic3r/test_static_map.cpp
@@ -1,4 +1,4 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
 #include <string_view>
 
 #include "libslic3r/StaticMap.hpp"
