$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb/openvdb/tools/Filter.h.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb/openvdb/tools/Filter.h
@@ -14,21 +14,24 @@
 #ifndef OPENVDB_TOOLS_FILTER_HAS_BEEN_INCLUDED
 #define OPENVDB_TOOLS_FILTER_HAS_BEEN_INCLUDED
 
-#include <tbb/parallel_for.h>
-#include <openvdb/Types.h>
-#include <openvdb/math/Math.h>
-#include <openvdb/math/Stencils.h>
-#include <openvdb/math/Transform.h>
-#include <openvdb/tree/NodeManager.h>
-#include <openvdb/tree/LeafManager.h>
-#include <openvdb/util/NullInterrupter.h>
-#include <openvdb/util/Util.h>
-#include <openvdb/Grid.h>
+#include "openvdb/Types.h"
+#include "openvdb/Grid.h"
+#include "openvdb/math/Math.h"
+#include "openvdb/math/Stencils.h"
+#include "openvdb/math/Transform.h"
+#include "openvdb/tree/NodeManager.h"
+#include "openvdb/tree/LeafManager.h"
+#include "openvdb/util/NullInterrupter.h"
+#include "openvdb/util/Util.h"
+#include "openvdb/util/Threading.h"
 #include "Interpolation.h"
+
+#include <tbb/parallel_for.h>
+#include <tbb/concurrent_vector.h>
+
 #include <algorithm> // for std::max()
 #include <functional>
 #include <type_traits>
-#include <tbb/concurrent_vector.h>
 
 namespace openvdb {
 OPENVDB_USE_VERSION_NAMESPACE
@@ -833,7 +836,7 @@ inline bool
 Filter<GridT, MaskT, InterruptT>::wasInterrupted()
 {
     if (util::wasInterrupted(mInterrupter)) {
-        tbb::task::self().cancel_group_execution();
+        util::cancelGroupExecution();
         return true;
     }
     return false;
