$NetBSD$

Support Catch2 v3.

--- tests/fff_print/test_seam_aligned.cpp.orig	2024-06-16 00:22:05.214495978 +0000
+++ tests/fff_print/test_seam_aligned.cpp
@@ -1,5 +1,6 @@
 #include <libslic3r/Point.hpp>
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/catch_approx.hpp>
 #include <libslic3r/GCode/SeamAligned.hpp>
 #include "test_data.hpp"
 #include <fstream>
@@ -59,7 +60,7 @@ TEST_CASE("Get seam options", "[Seams][S
 
     CHECK(options.closest == 4);
     CHECK(options.adjacent == 0);
-    CHECK((options.on_edge - Vec2d{0.0, 0.3}).norm() == Approx(0.0));
+    CHECK((options.on_edge - Vec2d{0.0, 0.3}).norm() == Catch::Approx(0.0));
     REQUIRE(options.snapped);
     CHECK(options.snapped == 0);
 }
@@ -80,7 +81,7 @@ struct PickSeamOptionFixture
 TEST_CASE_METHOD(PickSeamOptionFixture, "Pick seam option", "[Seams][SeamAligned]") {
     auto [previous_index, next_index, position]{pick_seam_option(perimeter, options)};
     CHECK(previous_index == next_index);
-    CHECK((position - Vec2d{0.0, 0.0}).norm() == Approx(0.0));
+    CHECK((position - Vec2d{0.0, 0.0}).norm() == Catch::Approx(0.0));
 }
 
 TEST_CASE_METHOD(PickSeamOptionFixture, "Pick seam option picks enforcer", "[Seams][SeamAligned]") {
@@ -88,7 +89,7 @@ TEST_CASE_METHOD(PickSeamOptionFixture, 
 
     auto [previous_index, next_index, position]{pick_seam_option(perimeter, options)};
     CHECK(previous_index == next_index);
-    CHECK((position - Vec2d{0.0, 0.5}).norm() == Approx(0.0));
+    CHECK((position - Vec2d{0.0, 0.5}).norm() == Catch::Approx(0.0));
 }
 
 TEST_CASE_METHOD(PickSeamOptionFixture, "Nearest point", "[Seams][SeamAligned]") {
@@ -97,7 +98,7 @@ TEST_CASE_METHOD(PickSeamOptionFixture, 
     )};
     CHECK(result->previous_index == 0);
     CHECK(result->next_index == 1);
-    CHECK((result->position - Vec2d{0.4, 0.0}).norm() == Approx(0.0));
+    CHECK((result->position - Vec2d{0.4, 0.0}).norm() == Catch::Approx(0.0));
 }
 
 TEST_CASE_METHOD(PickSeamOptionFixture, "Least visible point", "[Seams][SeamAligned]") {
@@ -111,7 +112,7 @@ TEST_CASE_METHOD(PickSeamOptionFixture, 
     )};
     CHECK(result->previous_index == 4);
     CHECK(result->next_index == 4);
-    CHECK((result->position - Vec2d{0.0, 0.5}).norm() == Approx(0.0));
+    CHECK((result->position - Vec2d{0.0, 0.5}).norm() == Catch::Approx(0.0));
 }
 
 TEST_CASE_METHOD(Test::SeamsFixture, "Generate aligned seam", "[Seams][SeamAligned][Integration]") {
