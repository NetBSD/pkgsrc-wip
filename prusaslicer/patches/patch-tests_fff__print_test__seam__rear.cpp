$NetBSD$

Support Catch2 v3.

--- tests/fff_print/test_seam_rear.cpp.orig	2024-06-16 00:25:58.442182846 +0000
+++ tests/fff_print/test_seam_rear.cpp
@@ -1,5 +1,5 @@
 #include <libslic3r/Point.hpp>
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
 #include <libslic3r/GCode/SeamRear.hpp>
 #include "test_data.hpp"
 #include <fstream>
