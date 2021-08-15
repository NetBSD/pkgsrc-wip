$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb/openvdb/tools/LevelSetTracker.h.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb/openvdb/tools/LevelSetTracker.h
@@ -12,24 +12,26 @@
 #ifndef OPENVDB_TOOLS_LEVEL_SET_TRACKER_HAS_BEEN_INCLUDED
 #define OPENVDB_TOOLS_LEVEL_SET_TRACKER_HAS_BEEN_INCLUDED
 
-#include <tbb/parallel_for.h>
-#include <openvdb/Types.h>
-#include <openvdb/math/Math.h>
-#include <openvdb/math/FiniteDifference.h>
-#include <openvdb/math/Operators.h>
-#include <openvdb/math/Stencils.h>
-#include <openvdb/math/Transform.h>
-#include <openvdb/Grid.h>
-#include <openvdb/util/NullInterrupter.h>
-#include <openvdb/tree/ValueAccessor.h>
-#include <openvdb/tree/LeafManager.h>
+#include "openvdb/Types.h"
+#include "openvdb/Grid.h"
+#include "openvdb/math/Math.h"
+#include "openvdb/math/FiniteDifference.h"
+#include "openvdb/math/Operators.h"
+#include "openvdb/math/Stencils.h"
+#include "openvdb/math/Transform.h"
+#include "openvdb/util/NullInterrupter.h"
+#include "openvdb/util/Threading.h"
+#include "openvdb/tree/ValueAccessor.h"
+#include "openvdb/tree/LeafManager.h"
 #include "ChangeBackground.h"// for changeLevelSetBackground
 #include "Morphology.h"//for dilateActiveValues
 #include "Prune.h"// for pruneLevelSet
+
+#include <tbb/parallel_for.h>
+
 #include <functional>
 #include <type_traits>
 
-
 namespace openvdb {
 OPENVDB_USE_VERSION_NAMESPACE
 namespace OPENVDB_VERSION_NAME {
@@ -383,7 +385,7 @@ LevelSetTracker<GridT, InterruptT>::
 checkInterrupter()
 {
     if (util::wasInterrupted(mInterrupter)) {
-        tbb::task::self().cancel_group_execution();
+        util::cancelGroupExecution();
         return false;
     }
     return true;
