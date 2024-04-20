$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/sla_print/sla_supptreeutils_tests.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/sla_print/sla_supptreeutils_tests.cpp
@@ -1,4 +1,6 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
 #include <test_utils.hpp>
 
 #include <unordered_set>
@@ -7,6 +9,9 @@
 #include "libslic3r/SLA/SupportTreeUtils.hpp"
 #include "libslic3r/SLA/SupportTreeUtilsLegacy.hpp"
 
+using Catch::Matchers::WithinRel;
+using Catch::Matchers::WithinAbs;
+
 // Test pair hash for 'nums' random number pairs.
 template <class I, class II> void test_pairhash()
 {
@@ -99,7 +104,7 @@ static void eval_ground_conn(const Slic3
     REQUIRE(conn.path.back().r < conn.pillar_base->r_top);
 
     // The end radius and the pillar base's upper radius should match
-    REQUIRE(conn.pillar_base->r_top == Approx(end_r));
+    REQUIRE_THAT(conn.pillar_base->r_top, WithinRel(end_r));
 }
 
 TEST_CASE("Pillar search dumb case", "[suptreeutils]") {
@@ -119,7 +124,7 @@ TEST_CASE("Pillar search dumb case", "[s
 
         REQUIRE(conn);
 //        REQUIRE(conn.path.size() == 1);
-        REQUIRE(conn.pillar_base->pos.z() == Approx(ground_level(sm)));
+        REQUIRE_THAT(conn.pillar_base->pos.z(), WithinRel(ground_level(sm)));
     }
 
     SECTION("with zero R source and destination") {
@@ -134,8 +139,8 @@ TEST_CASE("Pillar search dumb case", "[s
 
         REQUIRE(conn);
 //        REQUIRE(conn.path.size() == 1);
-        REQUIRE(conn.pillar_base->pos.z() == Approx(ground_level(sm)));
-        REQUIRE(conn.pillar_base->r_top == Approx(0.));
+        REQUIRE_THAT(conn.pillar_base->pos.z(), WithinRel(ground_level(sm)));
+        REQUIRE_THAT(conn.pillar_base->r_top, WithinAbs(0., EPSILON));
     }
 
     SECTION("with zero init direction") {
@@ -150,7 +155,7 @@ TEST_CASE("Pillar search dumb case", "[s
 
         REQUIRE(conn);
 //        REQUIRE(conn.path.size() == 1);
-        REQUIRE(conn.pillar_base->pos.z() == Approx(ground_level(sm)));
+        REQUIRE_THAT(conn.pillar_base->pos.z(), WithinRel(ground_level(sm)));
     }
 }
 
@@ -278,7 +283,7 @@ TEST_CASE("Find ground route just above 
 
     REQUIRE(conn);
 
-    REQUIRE(conn.pillar_base->pos.z() >= Approx(ground_level(sm)));
+    REQUIRE(conn.pillar_base->pos.z() >= ground_level(sm));
 }
 
 TEST_CASE("BranchingSupports::MergePointFinder", "[suptreeutils]") {
