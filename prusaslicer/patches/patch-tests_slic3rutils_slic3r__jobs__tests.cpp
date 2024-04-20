$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/slic3rutils/slic3r_jobs_tests.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/slic3rutils/slic3r_jobs_tests.cpp
@@ -1,4 +1,5 @@
-#include "catch2/catch.hpp"
+#include <catch2/catch_template_test_macros.hpp>
+#include <catch2/catch_test_macros.hpp>
 
 #include <chrono>
 #include <thread>
