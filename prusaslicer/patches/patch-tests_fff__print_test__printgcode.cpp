$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/fff_print/test_printgcode.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/fff_print/test_printgcode.cpp
@@ -1,4 +1,6 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
 
 #include "libslic3r/libslic3r.h"
 #include "libslic3r/GCodeReader.hpp"
@@ -10,6 +12,7 @@
 
 using namespace Slic3r;
 using namespace Slic3r::Test;
+using Catch::Matchers::WithinRel;
 
 boost::regex perimeters_regex("G1 X[-0-9.]* Y[-0-9.]* E[-0-9.]* ; perimeter");
 boost::regex infill_regex("G1 X[-0-9.]* Y[-0-9.]* E[-0-9.]* ; infill");
@@ -79,7 +82,7 @@ SCENARIO( "PrintGCode basic functionalit
                 reader.parse_buffer(gcode, [&final_z] (GCodeReader& self, const GCodeReader::GCodeLine& line) {
                     final_z = std::max<double>(final_z, static_cast<double>(self.z())); // record the highest Z point we reach
                 });
-                REQUIRE(final_z == Approx(20.));
+                REQUIRE_THAT(final_z, WithinRel(20.));
             }
         }
         WHEN("output is executed with complete objects and two differently-sized meshes") {
@@ -121,7 +124,7 @@ SCENARIO( "PrintGCode basic functionalit
                 reader.parse_buffer(gcode, [&final_z] (GCodeReader& self, const GCodeReader::GCodeLine& line) {
                     final_z = std::max(final_z, static_cast<double>(self.z())); // record the highest Z point we reach
                 });
-                REQUIRE(final_z == Approx(20.1));
+                REQUIRE_THAT(final_z, WithinRel(20.1, EPSILON));
             }
             THEN("Z height resets on object change") {
                 double final_z = 0.0;
@@ -257,14 +260,14 @@ SCENARIO( "PrintGCode basic functionalit
 				REQUIRE(pos < gcode.size());
 				double z = 0;
 				REQUIRE((sscanf(gcode.data() + pos, "(%lf mm)", &z) == 1));
-				REQUIRE(z == Approx(20.));
+				REQUIRE_THAT(z, WithinRel(20.));
 				// Second object
 				pos = gcode.find(";Layer:399 ", pos);
 				REQUIRE(pos != std::string::npos);
 				pos += token.size();
 				REQUIRE(pos < gcode.size());
 				REQUIRE((sscanf(gcode.data() + pos, "(%lf mm)", &z) == 1));
-				REQUIRE(z == Approx(20.));
+				REQUIRE_THAT(z, WithinRel(20.));
 			}
         }
     }
