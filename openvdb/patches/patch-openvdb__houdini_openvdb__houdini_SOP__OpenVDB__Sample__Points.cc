$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb_houdini/openvdb_houdini/SOP_OpenVDB_Sample_Points.cc.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb_houdini/openvdb_houdini/SOP_OpenVDB_Sample_Points.cc
@@ -16,13 +16,11 @@
 #include <openvdb_houdini/SOP_NodeVDB.h>
 
 #include <openvdb/tools/Interpolation.h>  // for box sampler
+#include <openvdb/util/Threading.h>
 #include <openvdb/points/PointCount.h>
 #include <openvdb/points/PointSample.h>
 #include <openvdb/points/IndexFilter.h>   // for MultiGroupFilter
 
-#include <tbb/tick_count.h>                 // for timing
-#include <tbb/task.h>                       // for cancel
-
 #include <UT/UT_Interrupt.h>
 #include <GA/GA_PageHandle.h>
 #include <GA/GA_PageIterator.h>
@@ -38,6 +36,7 @@
 #include <stdexcept>
 #include <string>
 #include <vector>
+#include <chrono>
 
 
 
@@ -327,7 +326,7 @@ public:
     {
 
         if (mInterrupter->wasInterrupted()) {
-            tbb::task::self().cancel_group_execution();
+            openvdb::util::cancelGroupExecution();
         }
         const GridType& grid = UTvdbGridCast<GridType>(mGrid);
         // task local grid accessor
@@ -481,7 +480,7 @@ SOP_OpenVDB_Sample_Points::Cache::cookVD
         int numUnnamedGrids = 0;
 
         // start time
-        tbb::tick_count time_start = tbb::tick_count::now();
+        auto time_start = std::chrono::steady_clock::now();
         UT_AutoInterrupt progress("Sampling from VDB grids");
 
         for (hvdb::VdbPrimCIterator it(bGdp, group); it; ++it) {
@@ -707,14 +706,16 @@ SOP_OpenVDB_Sample_Points::Cache::cookVD
         }
 
         // timing: end time
-        tbb::tick_count time_end = tbb::tick_count::now();
+        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
+            std::chrono::steady_clock::now() - time_start);
+        const double seconds = double(duration.count()) / 1000.0;
 
         if (verbose) {
             std::cout << "Sampling " << nPoints + nVDBPoints << " points in "
                       << numVectorGrids << " vector grid" << (numVectorGrids == 1 ? "" : "s")
                       << " and " << numScalarGrids << " scalar grid"
                           << (numScalarGrids == 1 ? "" : "s")
-                      << " took " << (time_end - time_start).seconds() << " seconds\n "
+                      << " took " << seconds << " seconds\n "
                       << (threaded ? "threaded" : "non-threaded") << std::endl;
         }
 
