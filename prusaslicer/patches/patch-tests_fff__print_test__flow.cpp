$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/fff_print/test_flow.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/fff_print/test_flow.cpp
@@ -1,4 +1,6 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
 
 #include <numeric>
 #include <sstream>
@@ -12,6 +14,7 @@
 
 using namespace Slic3r::Test;
 using namespace Slic3r;
+using Catch::Matchers::WithinRel;
 
 SCENARIO("Extrusion width specifics", "[Flow]") {
 
@@ -22,7 +25,7 @@ SCENARIO("Extrusion width specifics", "[
         parser.parse_buffer(Slic3r::Test::slice({ Slic3r::Test::TestMesh::cube_20x20x20 }, config),
             [&E_per_mm_bottom, layer_height] (Slic3r::GCodeReader& self, const Slic3r::GCodeReader::GCodeLine& line)
         { 
-            if (self.z() == Approx(layer_height).margin(0.01)) { // only consider first layer
+            if (WithinRel(layer_height, 0.01).match(self.z())) { // only consider first layer
                 if (line.extruding(self) && line.dist_XY(self) > 0)
                     E_per_mm_bottom.emplace_back(line.dist_E(self) / line.dist_XY(self));
             }
@@ -30,7 +33,7 @@ SCENARIO("Extrusion width specifics", "[
         THEN("First layer width applies to everything on first layer.") {
             REQUIRE(E_per_mm_bottom.size() > 0);
             const double E_per_mm_avg = std::accumulate(E_per_mm_bottom.cbegin(), E_per_mm_bottom.cend(), 0.0) / static_cast<double>(E_per_mm_bottom.size());
-            bool pass = (std::count_if(E_per_mm_bottom.cbegin(), E_per_mm_bottom.cend(), [E_per_mm_avg] (const double& v) { return v == Approx(E_per_mm_avg); }) == 0);
+            bool pass = (std::count_if(E_per_mm_bottom.cbegin(), E_per_mm_bottom.cend(), [E_per_mm_avg] (const double& v) { return WithinRel(E_per_mm_avg).match(v); }) == 0);
             REQUIRE(pass);
         }
         THEN("First layer width does not apply to upper layer.") {
@@ -156,18 +159,18 @@ SCENARIO("Flow: Flow math for non-bridge
         // Spacing for non-bridges is has some overlap
         THEN("External perimeter flow has spacing fixed to 1.125 * nozzle_diameter") {
             auto flow = Flow::new_from_config_width(frExternalPerimeter, ConfigOptionFloatOrPercent(0, false), nozzle_diameter, layer_height);
-            REQUIRE(flow.spacing() == Approx(1.125 * nozzle_diameter - layer_height * (1.0 - PI / 4.0)));
+            REQUIRE_THAT(flow.spacing(), WithinRel(1.125 * nozzle_diameter - layer_height * (1.0 - PI / 4.0), EPSILON));
         }
 
         THEN("Internal perimeter flow has spacing fixed to 1.125 * nozzle_diameter") {
             auto flow = Flow::new_from_config_width(frPerimeter, ConfigOptionFloatOrPercent(0, false), nozzle_diameter, layer_height);
-            REQUIRE(flow.spacing() == Approx(1.125 *nozzle_diameter - layer_height * (1.0 - PI / 4.0)));
+            REQUIRE_THAT(flow.spacing(), WithinRel(1.125 *nozzle_diameter - layer_height * (1.0 - PI / 4.0), EPSILON));
         }
         THEN("Spacing for supplied width is 0.8927f") {
             auto flow = Flow::new_from_config_width(frExternalPerimeter, width, nozzle_diameter, layer_height);
-            REQUIRE(flow.spacing() == Approx(width.value - layer_height * (1.0 - PI / 4.0)));
+            REQUIRE_THAT(flow.spacing(), WithinRel(width.value - layer_height * (1.0 - PI / 4.0), EPSILON));
             flow = Flow::new_from_config_width(frPerimeter, width, nozzle_diameter, layer_height);
-            REQUIRE(flow.spacing() == Approx(width.value - layer_height * (1.0 - PI / 4.0)));
+            REQUIRE_THAT(flow.spacing(), WithinRel(width.value - layer_height * (1.0 - PI / 4.0), EPSILON));
         }
     }
     /// Check the min/max
@@ -178,14 +181,14 @@ SCENARIO("Flow: Flow math for non-bridge
             layer_height = 0.15f;
             THEN("Max width is set.") {
                 auto flow = Flow::new_from_config_width(frPerimeter, ConfigOptionFloatOrPercent(0, false), nozzle_diameter, layer_height);
-                REQUIRE(flow.width() == Approx(1.125 * nozzle_diameter));
+                REQUIRE_THAT(flow.width(), WithinRel(1.125 * nozzle_diameter));
             }
         }
         WHEN("Layer height is set to 0.25") {
             layer_height = 0.25f;
             THEN("Min width is set.") {
                 auto flow = Flow::new_from_config_width(frPerimeter, ConfigOptionFloatOrPercent(0, false), nozzle_diameter, layer_height);
-                REQUIRE(flow.width() == Approx(1.125 * nozzle_diameter));
+                REQUIRE_THAT(flow.width(), WithinRel(1.125 * nozzle_diameter));
             }
         }
     }
@@ -216,10 +219,10 @@ SCENARIO("Flow: Flow math for bridges", 
         WHEN("Flow role is frExternalPerimeter") {
             auto flow = Flow::bridging_flow(nozzle_diameter * sqrt(bridge_flow), nozzle_diameter);
             THEN("Bridge width is same as nozzle diameter") {
-                REQUIRE(flow.width() == Approx(nozzle_diameter));
+                REQUIRE_THAT(flow.width(), WithinRel(nozzle_diameter));
             }
             THEN("Bridge spacing is same as nozzle diameter + BRIDGE_EXTRA_SPACING") {
-                REQUIRE(flow.spacing() == Approx(nozzle_diameter + BRIDGE_EXTRA_SPACING));
+                REQUIRE_THAT(flow.spacing(), WithinRel(nozzle_diameter + BRIDGE_EXTRA_SPACING, EPSILON));
             }
         }
     }
