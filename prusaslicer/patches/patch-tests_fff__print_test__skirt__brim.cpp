$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/fff_print/test_skirt_brim.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/fff_print/test_skirt_brim.cpp
@@ -1,4 +1,6 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
 
 #include "libslic3r/GCodeReader.hpp"
 #include "libslic3r/Config.hpp"
@@ -10,6 +12,7 @@
 
 using namespace Slic3r::Test;
 using namespace Slic3r;
+using Catch::Matchers::WithinRel;
 
 /// Helper method to find the tool used for the brim (always the first extrusion)
 static int get_brim_tool(const std::string &gcode)
@@ -54,7 +57,7 @@ TEST_CASE("Skirt height is honored", "[S
     double support_speed = config.opt<Slic3r::ConfigOptionFloat>("support_material_speed")->value * MM_PER_MIN;
 	GCodeReader parser;
     parser.parse_buffer(gcode, [&layers_with_skirt, &support_speed] (Slic3r::GCodeReader &self, const Slic3r::GCodeReader::GCodeLine &line) {
-        if (line.extruding(self) && self.f() == Approx(support_speed)) {
+        if (line.extruding(self) && WithinRel(support_speed).match(self.f())) {
             layers_with_skirt[self.z()] = 1;
         }
     });
@@ -90,8 +93,8 @@ SCENARIO("Original Slic3r Skirt/Brim tes
                 double support_speed = config.opt<Slic3r::ConfigOptionFloat>("support_material_speed")->value * MM_PER_MIN;
 			    Slic3r::GCodeReader parser;
                 parser.parse_buffer(gcode, [&brim_generated, support_speed] (Slic3r::GCodeReader& self, const Slic3r::GCodeReader::GCodeLine& line) {
-                    if (self.z() == Approx(0.3) || line.new_Z(self) == Approx(0.3)) {
-                        if (line.extruding(self) && self.f() == Approx(support_speed)) {
+                    if (WithinRel(0.3, EPSILON).match(self.z()) || WithinRel(0.3, EPSILON).match(line.new_Z(self))) {
+                        if (line.extruding(self) && WithinRel(support_speed, EPSILON).match(self.f())) {
                             brim_generated = true;
                         }
                     }
@@ -234,20 +237,20 @@ SCENARIO("Original Slic3r Skirt/Brim tes
                     // std::cerr << line.cmd() << "\n";
 					if (boost::starts_with(line.cmd(), "T")) {
 						tool = atoi(line.cmd().data() + 1);
-					} else if (self.z() == Approx(config.opt<ConfigOptionFloat>("first_layer_height")->value)) {
+					} else if (WithinRel(config.opt<ConfigOptionFloat>("first_layer_height")->value).match(self.z())) {
                         // on first layer
 						if (line.extruding(self) && line.dist_XY(self) > 0) {
                             float speed = ( self.f() > 0 ?  self.f() : line.new_F(self));
                             // std::cerr << "Tool " << tool << "\n";
-                            if (speed == Approx(support_speed) && tool == config.opt_int("perimeter_extruder") - 1) {
+                            if (WithinRel(support_speed).match(speed) && tool == config.opt_int("perimeter_extruder") - 1) {
                                 // Skirt uses first material extruder, support material speed.
                                 skirt_length += line.dist_XY(self);
                             } else
                                 extrusion_points.push_back(Slic3r::Point::new_scale(line.new_X(self), line.new_Y(self)));
                         }
                     }
-                    if (self.z() == Approx(0.3) || line.new_Z(self) == Approx(0.3)) {
-                        if (line.extruding(self) && self.f() == Approx(support_speed)) {
+                    if (WithinRel(0.3).match(self.z()) || WithinRel(0.3).match(line.new_Z(self))) {
+                        if (line.extruding(self) && WithinRel(support_speed).match(self.f())) {
                         }
                     }
                 });
