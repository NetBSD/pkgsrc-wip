$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/fff_print/test_gcode_travels.cpp.orig	2024-04-14 02:13:14.663964766 +0000
+++ tests/fff_print/test_gcode_travels.cpp
@@ -1,4 +1,9 @@
-#include <catch2/catch.hpp>
+#include <vector>
+
+#include <catch2/catch_approx.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_vector.hpp>
 #include <libslic3r/GCode/Travels.hpp>
 #include <libslic3r/ExPolygon.hpp>
 #include <libslic3r/GCode.hpp>
@@ -6,8 +11,9 @@
 
 using namespace Slic3r;
 using namespace Slic3r::GCode::Impl::Travels;
+using Catch::Approx;
 
-struct ApproxEqualsPoints : public Catch::MatcherBase<Points> {
+struct ApproxEqualsPoints : public Catch::Matchers::MatcherBase<Points> {
     ApproxEqualsPoints(const Points& expected, unsigned tolerance): expected(expected), tolerance(tolerance) {}
     bool match(const Points& points) const override {
         if (points.size() != expected.size()) {
