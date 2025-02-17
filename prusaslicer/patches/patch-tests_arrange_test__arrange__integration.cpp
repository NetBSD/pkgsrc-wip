$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/arrange/test_arrange_integration.cpp.orig	2024-12-20 11:54:34.000000000 +0000
+++ tests/arrange/test_arrange_integration.cpp
@@ -1,4 +1,10 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_template_test_macros.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/generators/catch_generators.hpp>
+#include <catch2/generators/catch_generators_adapters.hpp>
+#include <catch2/generators/catch_generators_range.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
 #include "test_utils.hpp"
 
 #include <arrange-wrapper/Arrange.hpp>
@@ -11,6 +17,8 @@
 #include "libslic3r/Geometry/ConvexHull.hpp"
 #include "libslic3r/Format/3mf.hpp"
 
+using Catch::Matchers::WithinRel;
+
 static Slic3r::Model get_example_model_with_20mm_cube()
 {
     using namespace Slic3r;
@@ -559,10 +567,10 @@ TEST_CASE("Virtual bed handlers - Stride
                 auto ref_pos = tr * Vec3d::Zero();
 
                 auto displace = bed_index * (unscaled(vbh.stride_scaled()));
-                REQUIRE(ref_pos.x() == Approx(-displace));
+                REQUIRE_THAT(ref_pos.x(), WithinRel(-displace));
 
                 auto ref_pos_mi = mi_to_move.get_matrix() * Vec3d::Zero();
-                REQUIRE(ref_pos_mi.x() == Approx(instance_displace.x() + (bed_index >= 0) * displace));
+                REQUIRE_THAT(ref_pos_mi.x(), WithinRel(instance_displace.x() + (bed_index >= 0) * displace));
             }
         }
     }
@@ -871,8 +879,8 @@ bool settings_eq(const Slic3r::arr2::Arr
 {
     return v1.is_rotation_enabled() == v2.is_rotation_enabled() &&
            v1.get_arrange_strategy() == v2.get_arrange_strategy() &&
-           v1.get_distance_from_bed() == Approx(v2.get_distance_from_bed()) &&
-           v1.get_distance_from_objects() == Approx(v2.get_distance_from_objects()) &&
+           WithinRel(v2.get_distance_from_bed()).match(v1.get_distance_from_bed()) &&
+           WithinRel(v2.get_distance_from_objects()).match(v1.get_distance_from_objects()) &&
            v1.get_geometry_handling() == v2.get_geometry_handling() &&
            v1.get_xl_alignment() == v2.get_xl_alignment();
         ;
