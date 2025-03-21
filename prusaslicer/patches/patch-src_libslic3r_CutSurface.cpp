$NetBSD$

Patch for new CGAL 6.x based on
https://github.com/prusa3d/PrusaSlicer/pull/13081

--- src/libslic3r/CutSurface.cpp.orig	2024-12-20 11:54:34.000000000 +0000
+++ src/libslic3r/CutSurface.cpp
@@ -4,6 +4,14 @@
 ///|/
 #include "CutSurface.hpp"
 
+template <typename T>
+auto access_pmap(std::optional<T> opt) -> T {
+    return opt.value_or(T{});
+}
+
+template <typename Pair>
+auto access_pmap(Pair pair) { return pair.first; }
+
 /// models_input.obj - Check transormation of model to each others
 /// projection_center.obj - circle representing center of projection with correct distance
 /// {M} .. model index
@@ -31,6 +39,7 @@ using namespace Slic3r;
 #include <CGAL/Exact_integer.h>
 #include <CGAL/Surface_mesh.h>
 #include <CGAL/Cartesian_converter.h>
+#include <CGAL/AABB_traits.h>
 #include <oneapi/tbb/blocked_range.h>
 #include <oneapi/tbb/parallel_for.h>
 #include <boost/property_map/property_map.hpp>
@@ -1021,8 +1030,8 @@ priv::CutMesh priv::to_cgal(const ExPoly
     if (shapes.empty()) return {};
         
     CutMesh result;
-    EdgeShapeMap edge_shape_map = result.add_property_map<EI, IntersectingElement>(edge_shape_map_name).first;
-    FaceShapeMap face_shape_map = result.add_property_map<FI, IntersectingElement>(face_shape_map_name).first;
+    EdgeShapeMap edge_shape_map = access_pmap((result.add_property_map<EI, IntersectingElement>(edge_shape_map_name)));
+    FaceShapeMap face_shape_map = access_pmap((result.add_property_map<FI, IntersectingElement>(face_shape_map_name)));
 
     std::vector<VI> indices;
     auto insert_contour = [&projection, &indices, &result, 
@@ -1432,17 +1441,17 @@ priv::CutAOIs priv::cut_from_model(CutMe
                                    const ExPolygonsIndices &s2i)
 {
     // pointer to edge or face shape_map
-    VertexShapeMap vert_shape_map = cgal_model.add_property_map<VI, const IntersectingElement*>(vert_shape_map_name, nullptr).first;
+    VertexShapeMap vert_shape_map = access_pmap((cgal_model.add_property_map<VI, const IntersectingElement*>(vert_shape_map_name, nullptr)));
     
     // detect anomalities in visitor.
     bool is_valid = true;
     // NOTE: map are created when convert shapes to cgal model
-    const EdgeShapeMap& edge_shape_map = cgal_shape.property_map<EI, IntersectingElement>(edge_shape_map_name).first;
-    const FaceShapeMap& face_shape_map = cgal_shape.property_map<FI, IntersectingElement>(face_shape_map_name).first;
+    const EdgeShapeMap& edge_shape_map = access_pmap((cgal_shape.property_map<EI, IntersectingElement>(edge_shape_map_name)));
+    const FaceShapeMap& face_shape_map = access_pmap((cgal_shape.property_map<FI, IntersectingElement>(face_shape_map_name)));
     Visitor visitor{cgal_model, cgal_shape, edge_shape_map, face_shape_map, vert_shape_map, &is_valid};
 
     // a property map containing the constrained-or-not status of each edge
-    EdgeBoolMap ecm = cgal_model.add_property_map<EI, bool>(is_constrained_edge_name, false).first;
+    EdgeBoolMap ecm = access_pmap((cgal_model.add_property_map<EI, bool>(is_constrained_edge_name, false)));
     const auto &p = CGAL::parameters::visitor(visitor)
                         .edge_is_constrained_map(ecm)
                         .throw_on_self_intersection(false);
@@ -1451,7 +1460,7 @@ priv::CutAOIs priv::cut_from_model(CutMe
 
     if (!is_valid) return {};
 
-    FaceTypeMap face_type_map = cgal_model.add_property_map<FI, FaceType>(face_type_map_name, FaceType::not_constrained).first;
+    FaceTypeMap face_type_map = access_pmap((cgal_model.add_property_map<FI, FaceType>(face_type_map_name, FaceType::not_constrained)));
 
     // Select inside and outside face in model
     set_face_type(face_type_map, cgal_model, vert_shape_map, ecm, cgal_shape, s2i);
@@ -1587,8 +1596,8 @@ void priv::collect_surface_data(std::que
 
 void priv::create_reduce_map(ReductionMap &reduction_map, const CutMesh &mesh)
 {
-    const VertexShapeMap &vert_shape_map = mesh.property_map<VI, const IntersectingElement*>(vert_shape_map_name).first;
-    const EdgeBoolMap &ecm = mesh.property_map<EI, bool>(is_constrained_edge_name).first;
+    const VertexShapeMap &vert_shape_map = access_pmap((mesh.property_map<VI, const IntersectingElement*>(vert_shape_map_name)));
+    const EdgeBoolMap &ecm = access_pmap((mesh.property_map<EI, bool>(is_constrained_edge_name)));
 
     // check if vertex was made by edge_2 which is diagonal of quad
     auto is_reducible_vertex = [&vert_shape_map](VI reduction_from) -> bool {
@@ -1773,10 +1782,10 @@ priv::VDistances priv::calc_distances(co
     for (const SurfacePatch &patch : patches) {
         // map is created during intersection by corefine visitor
         const VertexShapeMap &vert_shape_map = 
-            models[patch.model_id].property_map<VI, const IntersectingElement *>(vert_shape_map_name).first;
+            access_pmap((models[patch.model_id].property_map<VI, const IntersectingElement *>(vert_shape_map_name)));
         uint32_t patch_index = &patch - &patches.front();
         // map is created during patch creation / dividing
-        const CvtVI2VI& cvt = patch.mesh.property_map<VI, VI>(patch_source_name).first;
+        const CvtVI2VI& cvt = access_pmap((patch.mesh.property_map<VI, VI>(patch_source_name)));
         // for each point on outline
         for (const Loop &loop : patch.loops) 
         for (const VI &vi_patch : loop) {
@@ -2666,7 +2675,7 @@ priv::SurfacePatch priv::create_surface_
                                               /* const */ CutMesh   &mesh,
                                               const ReductionMap    *rmap)
 {
-    auto is_counted = mesh.add_property_map<VI, bool>("v:is_counted").first;
+    auto is_counted = access_pmap((mesh.add_property_map<VI, bool>("v:is_counted")));
     uint32_t count_vertices = 0;
     if (rmap == nullptr) {
         for (FI fi : fis) 
@@ -2696,7 +2705,7 @@ priv::SurfacePatch priv::create_surface_
     cm.reserve(count_vertices, count_edges, count_faces);
 
     // vertex conversion function from mesh VI to result VI
-    CvtVI2VI mesh2result = mesh.add_property_map<VI,VI>("v:mesh2result").first;
+    CvtVI2VI mesh2result = access_pmap((mesh.add_property_map<VI,VI>("v:mesh2result")));
 
     if (rmap == nullptr) {
         for (FI fi : fis) {
@@ -2748,7 +2757,7 @@ priv::SurfacePatch priv::create_surface_
     assert(count_edges >= cm.edges().size());
     
     // convert VI from this patch to source VI, when exist
-    CvtVI2VI cvt = cm.add_property_map<VI, VI>(patch_source_name).first;
+    CvtVI2VI cvt = access_pmap((cm.add_property_map<VI, VI>(patch_source_name)));
     // vi_s .. VertexIndex into mesh (source)
     // vi_d .. new VertexIndex in cm (destination)
     for (VI vi_s : mesh.vertices()) { 
@@ -2939,7 +2948,7 @@ bool priv::is_patch_inside_of_model(cons
 uint32_t priv::get_shape_point_index(const CutAOI &cut, const CutMesh &model)
 {
     // map is created during intersection by corefine visitor
-    const VertexShapeMap &vert_shape_map = model.property_map<VI, const IntersectingElement *>(vert_shape_map_name).first;
+    const VertexShapeMap &vert_shape_map = access_pmap((model.property_map<VI, const IntersectingElement *>(vert_shape_map_name)));
     // for each half edge of outline
     for (HI hi : cut.second) {
         VI vi = model.source(hi);
@@ -2964,7 +2973,7 @@ priv::SurfacePatch priv::separate_patch(
     patch_new.model_id     = patch.model_id;
     patch_new.shape_id     = patch.shape_id;
     // fix cvt
-    CvtVI2VI cvt = patch_new.mesh.property_map<VI, VI>(patch_source_name).first;
+    CvtVI2VI cvt = access_pmap((patch_new.mesh.property_map<VI, VI>(patch_source_name)));
     for (VI &vi : cvt) {
         if (!vi.is_valid()) continue;
         vi = cvt_from[vi];
@@ -2982,9 +2991,9 @@ void priv::divide_patch(size_t i, Surfac
     CutMesh& cm = patch.mesh;
     assert(!cm.faces().empty());
     std::string patch_number_name = "f:patch_number";
-    CutMesh::Property_map<FI,bool> is_processed = cm.add_property_map<FI, bool>(patch_number_name, false).first;
+    CutMesh::Property_map<FI,bool> is_processed = access_pmap((cm.add_property_map<FI, bool>(patch_number_name, false)));
     
-    const CvtVI2VI& cvt_from = patch.mesh.property_map<VI, VI>(patch_source_name).first;
+    const CvtVI2VI& cvt_from = access_pmap((patch.mesh.property_map<VI, VI>(patch_source_name)));
 
     std::vector<FI> fis;
     fis.reserve(cm.faces().size());
@@ -3085,7 +3094,7 @@ priv::SurfacePatches priv::diff_models(V
         CutAOIs &model_cuts = cuts[model_index];
         CutMesh &cut_model_ = cut_models[model_index];
         const CutMesh &cut_model = cut_model_;
-        ReductionMap vertex_reduction_map = cut_model_.add_property_map<VI, VI>(vertex_reduction_map_name).first;
+        ReductionMap vertex_reduction_map = access_pmap((cut_model_.add_property_map<VI, VI>(vertex_reduction_map_name)));
         create_reduce_map(vertex_reduction_map, cut_model);
 
         for (size_t cut_index = 0; cut_index < model_cuts.size(); ++cut_index, ++index) {
@@ -3171,7 +3180,7 @@ bool priv::is_over_whole_expoly(const Cu
                                 const CutMesh   &mesh)
 {
     // NonInterupted contour is without other point and contain all from shape    
-    const VertexShapeMap &vert_shape_map = mesh.property_map<VI, const IntersectingElement*>(vert_shape_map_name).first;
+    const VertexShapeMap &vert_shape_map = access_pmap((mesh.property_map<VI, const IntersectingElement*>(vert_shape_map_name)));
     for (HI hi : cutAOI.second) { 
         const IntersectingElement *ie_s = vert_shape_map[mesh.source(hi)];
         const IntersectingElement *ie_t = vert_shape_map[mesh.target(hi)];
@@ -3559,7 +3568,7 @@ SurfaceCut priv::patch2cut(SurfacePatch 
 
     std::string convert_map_name = "v:convert";
     CutMesh::Property_map<VI, SurfaceCut::Index> convert_map = 
-        mesh.add_property_map<VI, SurfaceCut::Index>(convert_map_name).first;
+        access_pmap((mesh.add_property_map<VI, SurfaceCut::Index>(convert_map_name)));
 
     size_t indices_size  = mesh.faces().size();
     size_t vertices_size = mesh.vertices().size();
@@ -3708,7 +3717,7 @@ void priv::store(const CutMesh &mesh, co
     }
 
     CutMesh &mesh_ = const_cast<CutMesh &>(mesh);
-    auto face_colors = mesh_.add_property_map<priv::FI, CGAL::Color>("f:color").first;    
+    auto face_colors = access_pmap((mesh_.add_property_map<priv::FI, CGAL::Color>("f:color")));
     for (FI fi : mesh.faces()) { 
         auto &color = face_colors[fi];
         switch (face_type_map[fi]) {
@@ -3734,7 +3743,7 @@ void priv::store(const CutMesh &mesh, co
     std::string off_file = dir + "model" + std::to_string(reduction_order++) + ".off";
 
     CutMesh &mesh_ = const_cast<CutMesh &>(mesh);
-    auto vertex_colors = mesh_.add_property_map<priv::VI, CGAL::Color>("v:color").first;    
+    auto vertex_colors = access_pmap((mesh_.add_property_map<priv::VI, CGAL::Color>("v:color")));
     // initialize to gray color
     for (VI vi: mesh.vertices())
         vertex_colors[vi] = CGAL::Color{127, 127, 127};
