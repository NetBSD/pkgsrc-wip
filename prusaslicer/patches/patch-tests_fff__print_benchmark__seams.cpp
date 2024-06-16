$NetBSD$

Support Catch2 v3.

--- tests/fff_print/benchmark_seams.cpp.orig	2024-06-16 00:31:48.747974361 +0000
+++ tests/fff_print/benchmark_seams.cpp
@@ -1,4 +1,7 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/benchmark/catch_benchmark.hpp>
+#include <catch2/benchmark/catch_chronometer.hpp>
+#include <catch2/benchmark/catch_constructor.hpp>
 #include "test_data.hpp"
 
 #include "libslic3r/GCode/SeamGeometry.hpp"
