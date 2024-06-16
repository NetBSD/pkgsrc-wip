$NetBSD$

Support Catch2 v3.

--- tests/fff_print/test_seam_shells.cpp.orig	2024-06-16 00:12:02.757306546 +0000
+++ tests/fff_print/test_seam_shells.cpp
@@ -1,4 +1,5 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/catch_approx.hpp>
 #include <filesystem>
 #include <fstream>
 #include "libslic3r/ClipperUtils.hpp"
@@ -37,7 +38,7 @@ TEST_CASE_METHOD(ProjectionFixture, "Pro
     REQUIRE(result.size() == 1);
     REQUIRE(result[0].polygon.size() == 4);
     // Boundary polygon is picked.
-    CHECK(result[0].polygon[0].x() == Approx(scaled(-(1.0 + extrusion_width / 2.0 + 0.1))));
+    CHECK(result[0].polygon[0].x() == Catch::Approx(scaled(-(1.0 + extrusion_width / 2.0 + 0.1))));
 }
 
 TEST_CASE_METHOD(ProjectionFixture, "Project to geometry does not match", "[Seams][SeamShells]") {
