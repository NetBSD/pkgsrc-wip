$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb/openvdb/tools/VolumeAdvect.h.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb/openvdb/tools/VolumeAdvect.h
@@ -13,15 +13,18 @@
 #ifndef OPENVDB_TOOLS_VOLUME_ADVECT_HAS_BEEN_INCLUDED
 #define OPENVDB_TOOLS_VOLUME_ADVECT_HAS_BEEN_INCLUDED
 
-#include <tbb/parallel_for.h>
-#include <openvdb/Types.h>
-#include <openvdb/math/Math.h>
-#include <openvdb/util/NullInterrupter.h>
+#include "openvdb/Types.h"
+#include "openvdb/math/Math.h"
+#include "openvdb/util/NullInterrupter.h"
+#include "openvdb/util/Threading.h"
 #include "Interpolation.h"// for Sampler
 #include "VelocityFields.h" // for VelocityIntegrator
 #include "Morphology.h"//for dilateActiveValues
 #include "Prune.h"// for prune
 #include "Statistics.h" // for extrema
+
+#include <tbb/parallel_for.h>
+
 #include <functional>
 
 
@@ -294,7 +297,7 @@ private:
     bool interrupt() const
     {
         if (mInterrupter && util::wasInterrupted(mInterrupter)) {
-            tbb::task::self().cancel_group_execution();
+            util::cancelGroupExecution();
             return true;
         }
         return false;
