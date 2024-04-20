$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/sla_print/sla_print_tests.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/sla_print/sla_print_tests.cpp
@@ -9,6 +9,8 @@
 #include <libslic3r/SLA/SupportTreeMesher.hpp>
 #include <libslic3r/BranchingTree/PointCloud.hpp>
 
+using Catch::Matchers::WithinRel;
+
 namespace {
 
 const char *const BELOW_PAD_TEST_OBJECTS[] = {
@@ -194,8 +196,8 @@ TEST_CASE("InitializedRasterShouldBeNONE
     sla::RasterGrayscaleAAGammaPower raster(res, pixdim, {}, 1.);
     REQUIRE(raster.resolution().width_px == res.width_px);
     REQUIRE(raster.resolution().height_px == res.height_px);
-    REQUIRE(raster.pixel_dimensions().w_mm == Approx(pixdim.w_mm));
-    REQUIRE(raster.pixel_dimensions().h_mm == Approx(pixdim.h_mm));
+    REQUIRE_THAT(raster.pixel_dimensions().w_mm, WithinRel(pixdim.w_mm));
+    REQUIRE_THAT(raster.pixel_dimensions().h_mm, WithinRel(pixdim.h_mm));
 }
 
 TEST_CASE("MirroringShouldBeCorrect", "[SLARasterOutput]") {
@@ -269,5 +271,5 @@ TEST_CASE("Test concurrency")
 
     double s = execution::accumulate(ex_tbb, vals.begin(), vals.end(), 0.);
 
-    REQUIRE(s == Approx(ref));
+    REQUIRE_THAT(s, WithinRel(ref));
 }
