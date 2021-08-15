$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb/openvdb/tools/MeshToVolume.h.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb/openvdb/tools/MeshToVolume.h
@@ -16,12 +16,13 @@
 #ifndef OPENVDB_TOOLS_MESH_TO_VOLUME_HAS_BEEN_INCLUDED
 #define OPENVDB_TOOLS_MESH_TO_VOLUME_HAS_BEEN_INCLUDED
 
-#include <openvdb/Platform.h> // for OPENVDB_HAS_CXX11
-#include <openvdb/Types.h>
-#include <openvdb/math/FiniteDifference.h> // for GodunovsNormSqrd
-#include <openvdb/math/Proximity.h> // for closestPointOnTriangleToPoint
-#include <openvdb/util/NullInterrupter.h>
-#include <openvdb/util/Util.h>
+#include "openvdb/Platform.h" // for OPENVDB_HAS_CXX11
+#include "openvdb/Types.h"
+#include "openvdb/math/FiniteDifference.h" // for GodunovsNormSqrd
+#include "openvdb/math/Proximity.h" // for closestPointOnTriangleToPoint
+#include "openvdb/util/NullInterrupter.h"
+#include "openvdb/util/Util.h"
+#include "openvdb/util/Threading.h"
 
 #include "ChangeBackground.h"
 #include "Prune.h" // for pruneInactive and pruneLevelSet
@@ -33,7 +34,7 @@
 #include <tbb/parallel_reduce.h>
 #include <tbb/partitioner.h>
 #include <tbb/task_group.h>
-#include <tbb/task_scheduler_init.h>
+#include <tbb/task_arena.h>
 
 #include <algorithm> // for std::sort()
 #include <cmath> // for std::isfinite(), std::isnan()
@@ -1132,7 +1133,7 @@ inline void
 fillArray(ValueType* array, const ValueType val, const size_t length)
 {
     const auto grainSize = std::max<size_t>(
-        length / tbb::task_scheduler_init::default_num_threads(), 1024);
+        length / tbb::this_task_arena::max_concurrency(), 1024);
     const tbb::blocked_range<size_t> range(0, length, grainSize);
     tbb::parallel_for(range, FillArray<ValueType>(array, val), tbb::simple_partitioner());
 }
@@ -1989,7 +1990,7 @@ public:
         for (size_t n = range.begin(), N = range.end(); n < N; ++n) {
 
             if (this->wasInterrupted()) {
-                tbb::task::self().cancel_group_execution();
+                util::cancelGroupExecution();
                 break;
             }
 
@@ -2143,7 +2144,7 @@ private:
 
         while (!coordList.empty()) {
             if (interrupter && interrupter->wasInterrupted()) {
-                tbb::task::self().cancel_group_execution();
+                util::cancelGroupExecution();
                 break;
             }
             for (Int32 pass = 0; pass < 1048576 && !coordList.empty(); ++pass) {
