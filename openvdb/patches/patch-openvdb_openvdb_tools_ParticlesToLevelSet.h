$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb/openvdb/tools/ParticlesToLevelSet.h.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb/openvdb/tools/ParticlesToLevelSet.h
@@ -62,19 +62,23 @@
 #ifndef OPENVDB_TOOLS_PARTICLES_TO_LEVELSET_HAS_BEEN_INCLUDED
 #define OPENVDB_TOOLS_PARTICLES_TO_LEVELSET_HAS_BEEN_INCLUDED
 
-#include <tbb/parallel_reduce.h>
-#include <tbb/blocked_range.h>
-#include <openvdb/Types.h>
-#include <openvdb/Grid.h>
-#include <openvdb/math/Math.h>
-#include <openvdb/math/Transform.h>
-#include <openvdb/tree/LeafManager.h>
-#include <openvdb/util/logging.h>
-#include <openvdb/util/NullInterrupter.h>
+#include "openvdb/Types.h"
+#include "openvdb/Grid.h"
+#include "openvdb/math/Math.h"
+#include "openvdb/math/Transform.h"
+#include "openvdb/tree/LeafManager.h"
+#include "openvdb/util/logging.h"
+#include "openvdb/util/NullInterrupter.h"
+#include "openvdb/util/Threading.h"
+
 #include "Composite.h" // for csgUnion()
 #include "PointPartitioner.h"
 #include "Prune.h"
 #include "SignedFloodFill.h"
+
+#include <tbb/parallel_reduce.h>
+#include <tbb/blocked_range.h>
+
 #include <functional>
 #include <iostream>
 #include <type_traits>
@@ -738,7 +742,7 @@ private:
         for (Coord c = lo; c.x() <= hi.x(); ++c.x()) {
             //only check interrupter every 32'th scan in x
             if (!(count++ & ((1<<5)-1)) && util::wasInterrupted(mParent.mInterrupter)) {
-                tbb::task::self().cancel_group_execution();
+                util::cancelGroupExecution();
                 return false;
             }
             const Real x2 = math::Pow2(c.x() - P[0]);
@@ -804,7 +808,7 @@ private:
         // Densely fill the remaining regions.
         for (const auto& bbox: padding) {
             if (util::wasInterrupted(mParent.mInterrupter)) {
-                tbb::task::self().cancel_group_execution();
+                util::cancelGroupExecution();
                 return false;
             }
             const Coord &bmin = bbox.min(), &bmax = bbox.max();
