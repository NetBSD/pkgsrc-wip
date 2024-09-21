$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_quadric_edge_collapse.cpp.orig	2024-09-18 13:39:04.000000000 +0000
+++ tests/libslic3r/test_quadric_edge_collapse.cpp
@@ -1,4 +1,4 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
 #include <igl/qslim.h>
 #include <test_utils.hpp>
 
