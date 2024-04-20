$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/fff_print/test_extrusion_entity.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/fff_print/test_extrusion_entity.cpp
@@ -1,4 +1,7 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_approx.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
 
 #include <cstdlib>
 
@@ -11,6 +14,8 @@
 #include "test_data.hpp"
 
 using namespace Slic3r;
+using Catch::Approx;
+using Catch::Matchers::WithinRel;
 
 static inline Slic3r::Point random_point(float LO=-50, float HI=50) 
 {
@@ -62,11 +67,11 @@ SCENARIO("ExtrusionLoop", "[ExtrusionEnt
         ExtrusionLoop loop;
         loop.paths.emplace_back(new_extrusion_path(square.split_at_first_point(), ExtrusionRole::ExternalPerimeter, 1.));
         THEN("polygon area") {
-            REQUIRE(loop.polygon().area() == Approx(square.area()));
-            REQUIRE(loop.area() == Approx(square.area()));
+            REQUIRE_THAT(loop.polygon().area(), WithinRel(square.area()));
+            REQUIRE_THAT(loop.area(), WithinRel(square.area()));
         }
         THEN("loop length") {
-            REQUIRE(loop.length() == Approx(square.length()));
+            REQUIRE_THAT(loop.length(), WithinRel(square.length()));
         }
 
         WHEN("cloned") {
@@ -112,14 +117,14 @@ SCENARIO("ExtrusionLoop", "[ExtrusionEnt
         }
         double tot_len = polyline1.length() + polyline2.length();
         THEN("length") {
-            REQUIRE(loop.length() == Approx(tot_len));
+            REQUIRE_THAT(loop.length(), WithinRel(tot_len));
         }
 
         WHEN("splitting at intermediate point") {
             auto loop2 = std::unique_ptr<ExtrusionLoop>(dynamic_cast<ExtrusionLoop*>(loop.clone()));
             loop2->split_at_vertex(polyline1.points[1]);
             THEN("length after splitting is unchanged") {
-                REQUIRE(loop2->length() == Approx(tot_len));
+                REQUIRE_THAT(loop2->length(), WithinRel(tot_len));
             }
             THEN("loop contains three paths after splitting") {
                 REQUIRE(loop2->paths.size() == 3);
@@ -151,7 +156,7 @@ SCENARIO("ExtrusionLoop", "[ExtrusionEnt
                 double l2 = 0;
                 for (const ExtrusionPath &p : paths)
                     l2 += p.length();
-                REQUIRE(l2 == Approx(l - 3.));
+                REQUIRE_THAT(l2, WithinRel(l - 3.));
             }
         }
         
@@ -159,7 +164,7 @@ SCENARIO("ExtrusionLoop", "[ExtrusionEnt
             auto loop2 = std::unique_ptr<ExtrusionLoop>(dynamic_cast<ExtrusionLoop*>(loop.clone()));
             loop2->split_at_vertex(polyline2.points.front());
             THEN("length after splitting is unchanged") {
-                REQUIRE(loop2->length() == Approx(tot_len));
+                REQUIRE_THAT(loop2->length(), WithinRel(tot_len));
             }
             THEN("loop contains two paths after splitting") {
                 REQUIRE(loop2->paths.size() == 2);
@@ -189,7 +194,7 @@ SCENARIO("ExtrusionLoop", "[ExtrusionEnt
             auto loop2 = std::unique_ptr<ExtrusionLoop>(dynamic_cast<ExtrusionLoop*>(loop.clone()));
             loop2->split_at(point, false, 0);
             THEN("length after splitting is unchanged") {
-                REQUIRE(loop2->length() == Approx(tot_len));
+                REQUIRE_THAT(loop2->length(), WithinRel(tot_len));
             }
             Point expected_start_point(200, 150);
             THEN("expected starting point") {
@@ -220,7 +225,7 @@ SCENARIO("ExtrusionLoop", "[ExtrusionEnt
             if (! loop.split_at_vertex(point))
                 loop.split_at(point, false, 0);
             THEN("total length is preserved after splitting") {
-                REQUIRE(loop.length() == Approx(len));
+                REQUIRE_THAT(loop.length(), WithinRel(len));
             }
             THEN("order is correctly preserved after splitting") {
                 REQUIRE(loop.paths.front().role() == ExtrusionRole::ExternalPerimeter);
@@ -243,7 +248,7 @@ SCENARIO("ExtrusionLoop", "[ExtrusionEnt
         double len = loop.length();
         THEN("split_at() preserves total length") {
             loop.split_at({ 15896783, 15868739 }, false, 0);
-            REQUIRE(loop.length() == Approx(len));
+            REQUIRE_THAT(loop.length(), WithinRel(len));
         }
     }
 }
