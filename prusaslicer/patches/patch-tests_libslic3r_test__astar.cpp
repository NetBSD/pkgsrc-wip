$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_astar.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/libslic3r/test_astar.cpp
@@ -1,4 +1,7 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_template_test_macros.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
 
 #include "libslic3r/BoundingBox.hpp"
 #include "libslic3r/AStar.hpp"
@@ -6,6 +9,7 @@
 #include "libslic3r/PointGrid.hpp"
 
 using namespace Slic3r;
+using Catch::Matchers::WithinRel;
 
 TEST_CASE("Testing basic invariants of AStar", "[AStar]") {
     struct DummyTracer {
@@ -397,7 +401,7 @@ TEST_CASE("Zero heuristic function shoul
     // arrive to the source within less hops than the full number of nodes.
     for (size_t i = 0, k = 0; i < graph.nodes.size(); ++i, k = 0) {
         GraphTracer::QNode *q = &graph.nodes[i];
-        REQUIRE(q->g == Approx(ref_distances[i]));
+        REQUIRE_THAT(q->g, WithinRel(ref_distances[i]));
         while (k++ < graph.nodes.size() && q->parent != astar::Unassigned)
             q = &graph.nodes[q->parent];
 
