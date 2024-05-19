$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/fff_print/test_cancel_object.cpp.orig	2024-05-19 01:35:07.417821468 +0000
+++ tests/fff_print/test_cancel_object.cpp
@@ -1,4 +1,5 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_approx.hpp>
+#include <catch2/catch_test_macros.hpp>
 #include <sstream>
 #include <fstream>
 
@@ -7,6 +8,7 @@
 
 using namespace Slic3r;
 using namespace Test;
+using Catch::Approx;
 
 constexpr bool debug_files{false};
 
