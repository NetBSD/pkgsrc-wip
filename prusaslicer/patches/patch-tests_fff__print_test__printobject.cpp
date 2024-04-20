$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/fff_print/test_printobject.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/fff_print/test_printobject.cpp
@@ -1,4 +1,6 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
 
 #include "libslic3r/libslic3r.h"
 #include "libslic3r/Print.hpp"
@@ -8,6 +10,7 @@
 
 using namespace Slic3r;
 using namespace Slic3r::Test;
+using Catch::Matchers::WithinRel;
 
 SCENARIO("PrintObject: object layer heights", "[PrintObject]") {
     GIVEN("20mm cube and default initial config, initial layer height of 2mm") {
@@ -25,7 +28,7 @@ SCENARIO("PrintObject: object layer heig
             AND_THEN("Each layer is approximately 2mm above the previous Z") {
                 coordf_t last = 0.0;
                 for (size_t i = 0; i < layers.size(); ++ i) {
-                    REQUIRE((layers[i]->print_z - last) == Approx(2.0));
+                    REQUIRE_THAT((layers[i]->print_z - last), WithinRel(2.0));
                     last = layers[i]->print_z;
                 }
             }
@@ -42,10 +45,10 @@ SCENARIO("PrintObject: object layer heig
                 REQUIRE(layers.size() == 3);
             }
             AND_THEN("Layer 0 is at 2mm") {
-                REQUIRE(layers.front()->print_z == Approx(2.0));
+                REQUIRE_THAT(layers.front()->print_z, WithinRel(2.0));
             }
             AND_THEN("Layer 1 is at 12mm") {
-                REQUIRE(layers[1]->print_z == Approx(12.0));
+                REQUIRE_THAT(layers[1]->print_z, WithinRel(12.0));
             }
         }
         WHEN("generate_object_layers() is called for 15mm layer heights and nozzle diameter of 16mm") {
@@ -60,10 +63,10 @@ SCENARIO("PrintObject: object layer heig
                 REQUIRE(layers.size() == 2);
             }
             AND_THEN("Layer 0 is at 2mm") {
-                REQUIRE(layers[0]->print_z == Approx(2.0));
+                REQUIRE_THAT(layers[0]->print_z, WithinRel(2.0));
             }
             AND_THEN("Layer 1 is at 17mm") {
-                REQUIRE(layers[1]->print_z == Approx(17.0));
+                REQUIRE_THAT(layers[1]->print_z, WithinRel(17.0));
             }
         }
 #if 0
@@ -79,7 +82,7 @@ SCENARIO("PrintObject: object layer heig
                 CHECK(layers.size() == 5);
                 coordf_t last = 2.0;
                 for (size_t i = 1; i < layers.size(); i++) {
-                    REQUIRE((layers[i]->print_z - last) == Approx(5.0));
+                    REQUIRE_THAT((layers[i]->print_z - last), WithinRel(5.0));
                     last = layers[i]->print_z;
                 }
             }
