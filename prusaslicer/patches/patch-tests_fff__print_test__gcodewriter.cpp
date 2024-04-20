$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/fff_print/test_gcodewriter.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/fff_print/test_gcodewriter.cpp
@@ -1,10 +1,13 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_string.hpp>
 
 #include <memory>
 
 #include "libslic3r/GCode/GCodeWriter.hpp"
 
 using namespace Slic3r;
+using Catch::Matchers::Equals;
 
 SCENARIO("set_speed emits values with fixed-point output.", "[GCodeWriter]") {
 
@@ -12,22 +15,22 @@ SCENARIO("set_speed emits values with fi
         GCodeWriter writer;
         WHEN("set_speed is called to set speed to 99999.123") {
             THEN("Output string is G1 F99999.123") {
-                REQUIRE_THAT(writer.set_speed(99999.123), Catch::Equals("G1 F99999.123\n"));
+                REQUIRE_THAT(writer.set_speed(99999.123), Equals("G1 F99999.123\n"));
             }
         }
         WHEN("set_speed is called to set speed to 1") {
             THEN("Output string is G1 F1") {
-                REQUIRE_THAT(writer.set_speed(1.0), Catch::Equals("G1 F1\n"));
+                REQUIRE_THAT(writer.set_speed(1.0), Equals("G1 F1\n"));
             }
         }
         WHEN("set_speed is called to set speed to 203.200022") {
             THEN("Output string is G1 F203.2") {
-                REQUIRE_THAT(writer.set_speed(203.200022), Catch::Equals("G1 F203.2\n"));
+                REQUIRE_THAT(writer.set_speed(203.200022), Equals("G1 F203.2\n"));
             }
         }
         WHEN("set_speed is called to set speed to 203.200522") {
             THEN("Output string is G1 F203.201") {
-                REQUIRE_THAT(writer.set_speed(203.200522), Catch::Equals("G1 F203.201\n"));
+                REQUIRE_THAT(writer.set_speed(203.200522), Equals("G1 F203.201\n"));
             }
         }
     }
