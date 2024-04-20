$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/fff_print/test_layers.cpp.orig	2024-04-14 02:13:14.684876605 +0000
+++ tests/fff_print/test_layers.cpp
@@ -2,11 +2,13 @@
 * Ported from t/layers.t
 */
 
-#include <catch2/catch.hpp>
+#include <catch2/catch_approx.hpp>
+#include <catch2/catch_test_macros.hpp>
 #include "test_data.hpp"
 
 using namespace Slic3r;
 using namespace Slic3r::Test;
+using Catch::Approx;
 
 void check_layers(const DynamicPrintConfig& config) {
 	GCodeReader parser;
@@ -27,10 +29,10 @@ void check_layers(const DynamicPrintConf
     const double layer_height = config.opt_float("layer_height");
     INFO("Correct first layer height.");
     CHECK(z.at(0) == Approx(first_layer_height + z_offset));
-    INFO("Correct second layer height")
+    INFO("Correct second layer height");
     CHECK(z.at(1) == Approx(first_layer_height + layer_height + z_offset));
 
-    INFO("Correct layer height")
+    INFO("Correct layer height");
     for (const double increment : tcb::span{increments}.subspan(1)) {
         CHECK(increment == Approx(layer_height));
     }
