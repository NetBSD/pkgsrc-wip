$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/sla_print/sla_test_utils.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/sla_print/sla_test_utils.cpp
@@ -6,6 +6,8 @@
 
 #include <iomanip>
 
+using Catch::Matchers::WithinRel;
+
 void test_support_model_collision(
     const std::string            &obj_filename,
     const sla::SupportTreeConfig &input_supportcfg,
@@ -182,7 +184,7 @@ void test_supports(const std::string    
         allowed_zmin = zmin - 2 * supportcfg.head_back_radius_mm;
 
 #ifndef NDEBUG
-    if (!(obb.min.z() >= Approx(allowed_zmin)) || !(obb.max.z() <= Approx(zmax)))
+    if (!(obb.min.z() >= allowed_zmin) || !(obb.max.z() <= zmax))
     {
         indexed_triangle_set its;
         treebuilder.retrieve_full_mesh(its);
@@ -193,8 +195,8 @@ void test_supports(const std::string    
     }
 #endif
 
-    REQUIRE(obb.min.z() >= Approx(allowed_zmin));
-    REQUIRE(obb.max.z() <= Approx(zmax));
+    REQUIRE(obb.min.z() >= allowed_zmin);
+    REQUIRE(obb.max.z() <= zmax);
 
     // Move out the support tree into the byproducts, we can examine it further
     // in various tests.
@@ -240,7 +242,7 @@ void check_support_tree_integrity(const 
     };
     
     for (auto &bridge : stree.bridges()) chck_bridge(bridge, max_bridgelen);
-    REQUIRE(max_bridgelen <= Approx(cfg.max_bridge_length_mm));
+    REQUIRE(max_bridgelen <= cfg.max_bridge_length_mm);
     
     max_bridgelen = 0;
     for (auto &bridge : stree.crossbridges()) chck_bridge(bridge, max_bridgelen);
@@ -272,7 +274,7 @@ void test_pad(const std::string &obj_fil
     check_validity(out.mesh);
     
     auto bb = out.mesh.bounding_box();
-    REQUIRE(bb.max.z() - bb.min.z() == Approx(padcfg.full_height()));
+    REQUIRE_THAT(bb.max.z() - bb.min.z(), WithinRel(padcfg.full_height()));
 }
 
 static void _test_concave_hull(const Polygons &hull, const ExPolygons &polys)
@@ -285,7 +287,7 @@ static void _test_concave_hull(const Pol
     double cchull_area = 0;
     for (const Slic3r::Polygon &p : hull) cchull_area += p.area();
     
-    REQUIRE(cchull_area >= Approx(polys_area));
+    REQUIRE(cchull_area >= polys_area);
     
     size_t cchull_holes = 0;
     for (const Slic3r::Polygon &p : hull)
