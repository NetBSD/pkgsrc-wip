$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_placeholder_parser.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/libslic3r/test_placeholder_parser.cpp
@@ -1,9 +1,13 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
 
 #include "libslic3r/PlaceholderParser.hpp"
 #include "libslic3r/PrintConfig.hpp"
 
 using namespace Slic3r;
+using Catch::Matchers::WithinRel;
+using Catch::Matchers::WithinAbs;
 
 SCENARIO("Placeholder parser scripting", "[PlaceholderParser]") {
 	PlaceholderParser 	parser;
@@ -69,17 +73,17 @@ SCENARIO("Placeholder parser scripting",
     SECTION("math: 2*3") { REQUIRE(parser.process("{2*3}") == "6"); }
     SECTION("math: 2*3/6") { REQUIRE(parser.process("{2*3/6}") == "1"); }
     SECTION("math: 2*3/12") { REQUIRE(parser.process("{2*3/12}") == "0"); }
-    SECTION("math: 2.*3/12") { REQUIRE(std::stod(parser.process("{2.*3/12}")) == Approx(0.5)); }
-    SECTION("math: 10 % 2.5") { REQUIRE(std::stod(parser.process("{10%2.5}")) == Approx(0.)); }
-    SECTION("math: 11 % 2.5") { REQUIRE(std::stod(parser.process("{11%2.5}")) == Approx(1.)); }
+    SECTION("math: 2.*3/12") { REQUIRE_THAT(std::stod(parser.process("{2.*3/12}")), WithinRel(0.5)); }
+    SECTION("math: 10 % 2.5") { REQUIRE_THAT(std::stod(parser.process("{10%2.5}")), WithinAbs(0., EPSILON)); }
+    SECTION("math: 11 % 2.5") { REQUIRE_THAT(std::stod(parser.process("{11%2.5}")), WithinRel(1.)); }
     SECTION("math: 2*(3-12)") { REQUIRE(parser.process("{2*(3-12)}") == "-18"); }
     SECTION("math: 2*foo*(3-12)") { REQUIRE(parser.process("{2*foo*(3-12)}") == "0"); }
     SECTION("math: 2*bar*(3-12)") { REQUIRE(parser.process("{2*bar*(3-12)}") == "-36"); }
-    SECTION("math: 2.5*bar*(3-12)") { REQUIRE(std::stod(parser.process("{2.5*bar*(3-12)}")) == Approx(-45)); }
+    SECTION("math: 2.5*bar*(3-12)") { REQUIRE_THAT(std::stod(parser.process("{2.5*bar*(3-12)}")), WithinRel(-45.0)); }
     SECTION("math: min(12, 14)") { REQUIRE(parser.process("{min(12, 14)}") == "12"); }
     SECTION("math: max(12, 14)") { REQUIRE(parser.process("{max(12, 14)}") == "14"); }
-    SECTION("math: min(13.4, -1238.1)") { REQUIRE(std::stod(parser.process("{min(13.4, -1238.1)}")) == Approx(-1238.1)); }
-    SECTION("math: max(13.4, -1238.1)") { REQUIRE(std::stod(parser.process("{max(13.4, -1238.1)}")) == Approx(13.4)); }
+    SECTION("math: min(13.4, -1238.1)") { REQUIRE_THAT(std::stod(parser.process("{min(13.4, -1238.1)}")), WithinRel(-1238.1)); }
+    SECTION("math: max(13.4, -1238.1)") { REQUIRE_THAT(std::stod(parser.process("{max(13.4, -1238.1)}")), WithinRel(13.4)); }
     SECTION("math: int(13.4)") { REQUIRE(parser.process("{int(13.4)}") == "13"); }
     SECTION("math: int(-13.4)") { REQUIRE(parser.process("{int(-13.4)}") == "-13"); }
     SECTION("math: round(13.4)") { REQUIRE(parser.process("{round(13.4)}") == "13"); }
@@ -101,19 +105,19 @@ SCENARIO("Placeholder parser scripting",
     SECTION("math: ternary3") { REQUIRE(parser.process("{12 == 13 ? 1 - 1 * unknown_symbol : 2 * 2}") == "4"); }
     SECTION("math: ternary4") { REQUIRE(parser.process("{12 == 2 * 6 ? 1 - 1 : 2 * unknown_symbol}") == "0"); }
     SECTION("math: ternary nested") { REQUIRE(parser.process("{12 == 2 * 6 ? 3 - 1 != 2 ? does_not_exist : 0 * 0 - 0 / 1 + 12345 : bull ? 3 - cokoo : 2 * unknown_symbol}") == "12345"); }
-    SECTION("math: interpolate_table(13.84375892476, (0, 0), (20, 20))") { REQUIRE(std::stod(parser.process("{interpolate_table(13.84375892476, (0, 0), (20, 20))}")) == Approx(13.84375892476)); }
-    SECTION("math: interpolate_table(13, (0, 0), (20, 20), (30, 20))") { REQUIRE(std::stod(parser.process("{interpolate_table(13, (0, 0), (20, 20), (30, 20))}")) == Approx(13.)); }
-    SECTION("math: interpolate_table(25, (0, 0), (20, 20), (30, 20))") { REQUIRE(std::stod(parser.process("{interpolate_table(25, (0, 0), (20, 20), (30, 20))}")) == Approx(20.)); }
+    SECTION("math: interpolate_table(13.84375892476, (0, 0), (20, 20))") { REQUIRE_THAT(std::stod(parser.process("{interpolate_table(13.84375892476, (0, 0), (20, 20))}")), WithinRel(13.84375892476, EPSILON)); }
+    SECTION("math: interpolate_table(13, (0, 0), (20, 20), (30, 20))") { REQUIRE_THAT(std::stod(parser.process("{interpolate_table(13, (0, 0), (20, 20), (30, 20))}")), WithinRel(13.)); }
+    SECTION("math: interpolate_table(25, (0, 0), (20, 20), (30, 20))") { REQUIRE_THAT(std::stod(parser.process("{interpolate_table(25, (0, 0), (20, 20), (30, 20))}")), WithinRel(20.)); }
 
     // Test the "coFloatOrPercent" and "xxx_extrusion_width" substitutions.
     // first_layer_extrusion_width ratio_over first_layer_heigth.
-    SECTION("perimeter_extrusion_width") { REQUIRE(std::stod(parser.process("{perimeter_extrusion_width}")) == Approx(0.67500001192092896)); }
-    SECTION("first_layer_extrusion_width") { REQUIRE(std::stod(parser.process("{first_layer_extrusion_width}")) == Approx(0.9)); }
-    SECTION("support_material_xy_spacing") { REQUIRE(std::stod(parser.process("{support_material_xy_spacing}")) == Approx(0.3375)); }
+    SECTION("perimeter_extrusion_width") { REQUIRE_THAT(std::stod(parser.process("{perimeter_extrusion_width}")), WithinRel(0.67500001192092896, EPSILON)); }
+    SECTION("first_layer_extrusion_width") { REQUIRE_THAT(std::stod(parser.process("{first_layer_extrusion_width}")), WithinRel(0.9)); }
+    SECTION("support_material_xy_spacing") { REQUIRE_THAT(std::stod(parser.process("{support_material_xy_spacing}")), WithinRel(0.3375)); }
     // external_perimeter_speed over perimeter_speed
-    SECTION("external_perimeter_speed") { REQUIRE(std::stod(parser.process("{external_perimeter_speed}")) == Approx(30.)); }
+    SECTION("external_perimeter_speed") { REQUIRE_THAT(std::stod(parser.process("{external_perimeter_speed}")), WithinRel(30.)); }
     // infill_overlap over perimeter_extrusion_width
-    SECTION("infill_overlap") { REQUIRE(std::stod(parser.process("{infill_overlap}")) == Approx(0.16875)); }
+    SECTION("infill_overlap") { REQUIRE_THAT(std::stod(parser.process("{infill_overlap}")), WithinRel(0.16875)); }
     // If first_layer_speed is set to percent, then it is applied over respective extrusion types by overriding their respective speeds.
     // The PlaceholderParser has no way to know which extrusion type the caller has in mind, therefore it throws.
     SECTION("first_layer_speed") { REQUIRE_THROWS(parser.process("{first_layer_speed}")); }
@@ -173,7 +177,7 @@ SCENARIO("Placeholder parser scripting",
         DynamicConfig config_outputs;
         config_outputs.set_key_value("writable_floats", new ConfigOptionFloats({ 0., 0., 0. }));
         parser.process("{writable_floats[1] = 33}", 0, nullptr, &config_outputs, nullptr);
-        REQUIRE(config_outputs.opt_float("writable_floats", 1) == Approx(33.));
+        REQUIRE_THAT(config_outputs.opt_float("writable_floats", 1), WithinRel(33.));
     }
 }
 
