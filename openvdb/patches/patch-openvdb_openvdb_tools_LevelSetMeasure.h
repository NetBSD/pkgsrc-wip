$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb/openvdb/tools/LevelSetMeasure.h.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb/openvdb/tools/LevelSetMeasure.h
@@ -8,18 +8,21 @@
 #ifndef OPENVDB_TOOLS_LEVELSETMEASURE_HAS_BEEN_INCLUDED
 #define OPENVDB_TOOLS_LEVELSETMEASURE_HAS_BEEN_INCLUDED
 
-#include <openvdb/math/Math.h>
-#include <openvdb/Types.h>
-#include <openvdb/Grid.h>
-#include <openvdb/tree/LeafManager.h>
-#include <openvdb/tree/ValueAccessor.h>
-#include <openvdb/math/FiniteDifference.h>
-#include <openvdb/math/Operators.h>
-#include <openvdb/math/Stencils.h>
-#include <openvdb/util/NullInterrupter.h>
+#include "openvdb/Types.h"
+#include "openvdb/Grid.h"
+#include "openvdb/tree/LeafManager.h"
+#include "openvdb/tree/ValueAccessor.h"
+#include "openvdb/math/Math.h"
+#include "openvdb/math/FiniteDifference.h"
+#include "openvdb/math/Operators.h"
+#include "openvdb/math/Stencils.h"
+#include "openvdb/util/NullInterrupter.h"
+#include "openvdb/util/Threading.h"
+
 #include <tbb/parallel_for.h>
 #include <tbb/parallel_sort.h>
 #include <tbb/parallel_invoke.h>
+
 #include <type_traits>
 
 namespace openvdb {
@@ -329,7 +332,7 @@ inline bool
 LevelSetMeasure<GridT, InterruptT>::checkInterrupter()
 {
     if (util::wasInterrupted(mInterrupter)) {
-        tbb::task::self().cancel_group_execution();
+        util::cancelGroupExecution();
         return false;
     }
     return true;
