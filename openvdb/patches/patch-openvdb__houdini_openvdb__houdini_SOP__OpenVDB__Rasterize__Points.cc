$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb_houdini/openvdb_houdini/SOP_OpenVDB_Rasterize_Points.cc.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb_houdini/openvdb_houdini/SOP_OpenVDB_Rasterize_Points.cc
@@ -20,6 +20,7 @@
 #include <openvdb/tools/GridTransformer.h>
 #include <openvdb/tools/PointIndexGrid.h>
 #include <openvdb/tools/Prune.h>
+#include <openvdb/util/Threading.h>
 
 #include <CH/CH_Manager.h>
 #include <CVEX/CVEX_Context.h>
@@ -786,7 +787,7 @@ struct ConstructCandidateVoxelMask
         for (size_t n = range.begin(), N = range.end(); n != N; ++n) {
 
             if (this->wasInterrupted()) {
-                tbb::task::self().cancel_group_execution();
+                openvdb::util::cancelGroupExecution();
                 break;
             }
 
@@ -2092,7 +2093,7 @@ struct RasterizePoints
         for (size_t n = range.begin(), N = range.end(); n != N; ++n) {
 
             if (this->wasInterrupted()) {
-                tbb::task::self().cancel_group_execution();
+                openvdb::util::cancelGroupExecution();
                 break;
             }
 
