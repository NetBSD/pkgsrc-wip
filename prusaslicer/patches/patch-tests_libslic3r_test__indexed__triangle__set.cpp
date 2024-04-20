$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_indexed_triangle_set.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/libslic3r/test_indexed_triangle_set.cpp
@@ -1,6 +1,7 @@
 #include <iostream>
 #include <fstream>
-#include <catch2/catch.hpp>
+#include <random>
+#include <catch2/catch_test_macros.hpp>
 
 #include "libslic3r/TriangleMesh.hpp"
 
