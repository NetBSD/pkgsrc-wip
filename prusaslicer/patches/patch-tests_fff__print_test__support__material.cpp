$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/fff_print/test_support_material.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/fff_print/test_support_material.cpp
@@ -1,4 +1,4 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
 
 #include "libslic3r/GCodeReader.hpp"
 #include "libslic3r/Layer.hpp"
