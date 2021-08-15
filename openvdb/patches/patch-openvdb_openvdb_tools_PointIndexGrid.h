$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb/openvdb/tools/PointIndexGrid.h.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb/openvdb/tools/PointIndexGrid.h
@@ -16,6 +16,7 @@
 #ifndef OPENVDB_TOOLS_POINT_INDEX_GRID_HAS_BEEN_INCLUDED
 #define OPENVDB_TOOLS_POINT_INDEX_GRID_HAS_BEEN_INCLUDED
 
+#include "openvdb/util/Threading.h"
 #include "PointPartitioner.h"
 
 #include <openvdb/version.h>
@@ -355,7 +356,7 @@ struct ValidPartitioningOp
     void operator()(LeafT &leaf, size_t /*leafIndex*/) const
     {
         if ((*mHasChanged)) {
-            tbb::task::self().cancel_group_execution();
+            util::cancelGroupExecution();
             return;
         }
 
