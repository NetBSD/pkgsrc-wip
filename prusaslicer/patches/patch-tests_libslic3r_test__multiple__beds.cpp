$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_multiple_beds.cpp.orig	2025-02-17 06:55:16.992196764 +0000
+++ tests/libslic3r/test_multiple_beds.cpp
@@ -1,4 +1,4 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
 
 #include <libslic3r/MultipleBeds.hpp>
 #include <numeric>
