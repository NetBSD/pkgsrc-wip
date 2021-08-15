$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb/openvdb/tools/PointsToMask.h.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb/openvdb/tools/PointsToMask.h
@@ -46,14 +46,18 @@
 #ifndef OPENVDB_TOOLS_POINTSTOMASK_HAS_BEEN_INCLUDED
 #define OPENVDB_TOOLS_POINTSTOMASK_HAS_BEEN_INCLUDED
 
+
+#include "openvdb/openvdb.h" // for MaskGrid
+#include "openvdb/Grid.h"
+#include "openvdb/Types.h"
+#include "openvdb/util/NullInterrupter.h"
+#include "openvdb/util/Threading.h"
+
 #include <tbb/enumerable_thread_specific.h>
 #include <tbb/parallel_for.h>
 #include <tbb/parallel_reduce.h>
 #include <tbb/blocked_range.h>
-#include <openvdb/openvdb.h> // for MaskGrid
-#include <openvdb/Grid.h>
-#include <openvdb/Types.h>
-#include <openvdb/util/NullInterrupter.h>
+
 #include <vector>
 
 
@@ -150,7 +154,7 @@ private:
     bool interrupt() const
     {
         if (mInterrupter && util::wasInterrupted(mInterrupter)) {
-            tbb::task::self().cancel_group_execution();
+            util::cancelGroupExecution();
             return true;
         }
         return false;
