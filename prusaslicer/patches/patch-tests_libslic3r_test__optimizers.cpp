$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_optimizers.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/libslic3r/test_optimizers.cpp
@@ -1,4 +1,4 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
 #include <test_utils.hpp>
 
 #include <libslic3r/Optimize/BruteforceOptimizer.hpp>
