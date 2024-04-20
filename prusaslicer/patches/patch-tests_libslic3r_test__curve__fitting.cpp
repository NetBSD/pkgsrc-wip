$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_curve_fitting.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/libslic3r/test_curve_fitting.cpp
@@ -1,10 +1,14 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
 #include <test_utils.hpp>
 
 #include <libslic3r/Geometry/Curves.hpp>
 #include <libslic3r/Utils.hpp>
 #include <libslic3r/SVG.hpp>
 
+using Catch::Matchers::WithinRel;
+
 TEST_CASE("Curves: cubic b spline fit test", "[Curves]") {
     using namespace Slic3r;
     using namespace Slic3r::Geometry;
@@ -31,14 +35,11 @@ TEST_CASE("Curves: cubic b spline fit te
 
     auto bspline = fit_cubic_bspline(observations, observation_points, weights, 1);
 
-    Approx ap(1.0f);
-    ap.epsilon(0.1f);
-
     for (int p = 0; p < 200; ++p) {
         float fitted_val = bspline.get_fitted_value(fx(p))(0);
         float expected = fy(p);
 
-        REQUIRE(fitted_val == ap(expected));
+        REQUIRE_THAT(fitted_val, WithinRel(expected, 0.1f));
 
     }
 }
@@ -106,13 +107,10 @@ TEST_CASE("Curves: polynomial fit test",
     Vec2f fmin { fx(0), fy(0) };
     Vec2f fmax { fx(200), fy(200) };
 
-    Approx ap(1.0f);
-    ap.epsilon(0.1f);
-
     auto poly = fit_polynomial(observations, observation_points, weights, 2);
 
-    REQUIRE(poly.coefficients(0, 0) == ap(1));
-    REQUIRE(poly.coefficients(0, 1) == ap(-2));
-    REQUIRE(poly.coefficients(0, 2) == ap(1));
+    REQUIRE_THAT(poly.coefficients(0, 0), WithinRel(1, 0.1f));
+    REQUIRE_THAT(poly.coefficients(0, 1), WithinRel(-2, 0.1f));
+    REQUIRE_THAT(poly.coefficients(0, 2), WithinRel(1, 0.1f));
 }
 
