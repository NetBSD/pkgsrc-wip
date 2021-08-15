$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb/openvdb/tools/PointAdvect.h.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb/openvdb/tools/PointAdvect.h
@@ -10,16 +10,19 @@
 #ifndef OPENVDB_TOOLS_POINT_ADVECT_HAS_BEEN_INCLUDED
 #define OPENVDB_TOOLS_POINT_ADVECT_HAS_BEEN_INCLUDED
 
-#include <openvdb/openvdb.h>
-#include <openvdb/math/Math.h>             // min
-#include <openvdb/Types.h>                 // Vec3 types and version number
-#include <openvdb/Grid.h>                  // grid
-#include <openvdb/util/NullInterrupter.h>
+#include "openvdb/openvdb.h"
+#include "openvdb/Types.h"                 // Vec3 types and version number
+#include "openvdb/Grid.h"                  // grid
+#include "openvdb/math/Math.h"             // min
+#include "openvdb/util/NullInterrupter.h"
+#include "openvdb/util/Threading.h"
 #include "Interpolation.h"                 // sampling
 #include "VelocityFields.h"                // VelocityIntegrator
+
 #include <tbb/blocked_range.h>             // threading
 #include <tbb/parallel_for.h>              // threading
 #include <tbb/task.h>                      // for cancel
+
 #include <vector>
 
 
@@ -167,7 +170,7 @@ public:
     void operator() (const tbb::blocked_range<size_t> &range) const
     {
         if (mInterrupter && mInterrupter->wasInterrupted()) {
-            tbb::task::self().cancel_group_execution();
+            util::cancelGroupExecution();
         }
 
         VelocityFieldIntegrator  velField(*mVelGrid);
@@ -307,7 +310,7 @@ public:
     void operator() (const tbb::blocked_range<size_t> &range) const
     {
         if (mInterrupter && mInterrupter->wasInterrupted()) {
-            tbb::task::self().cancel_group_execution();
+            util::cancelGroupExecution();
         }
 
         VelocityIntegratorType velField(*mVelGrid);
