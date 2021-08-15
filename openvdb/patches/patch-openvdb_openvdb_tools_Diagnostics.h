$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb/openvdb/tools/Diagnostics.h.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb/openvdb/tools/Diagnostics.h
@@ -11,14 +11,17 @@
 #ifndef OPENVDB_TOOLS_DIAGNOSTICS_HAS_BEEN_INCLUDED
 #define OPENVDB_TOOLS_DIAGNOSTICS_HAS_BEEN_INCLUDED
 
-#include <openvdb/Grid.h>
-#include <openvdb/math/Math.h>
-#include <openvdb/math/Vec3.h>
-#include <openvdb/math/Stencils.h>
-#include <openvdb/math/Operators.h>
-#include <openvdb/tree/LeafManager.h>
+#include "openvdb/Grid.h"
+#include "openvdb/math/Math.h"
+#include "openvdb/math/Vec3.h"
+#include "openvdb/math/Stencils.h"
+#include "openvdb/math/Operators.h"
+#include "openvdb/tree/LeafManager.h"
+#include "openvdb/util/Threading.h"
+
 #include <tbb/blocked_range.h>
 #include <tbb/parallel_reduce.h>
+
 #include <cmath> // for std::isnan(), std::isfinite()
 #include <set>
 #include <sstream>
@@ -26,7 +29,6 @@
 #include <type_traits>
 #include <vector>
 
-
 namespace openvdb {
 OPENVDB_USE_VERSION_NAMESPACE
 namespace OPENVDB_VERSION_NAME {
@@ -1160,13 +1162,13 @@ InactiveVoxelValues<TreeType>::operator(
 {
     typename TreeType::LeafNodeType::ValueOffCIter iter;
 
-    for (size_t n = range.begin(); n < range.end() && !tbb::task::self().is_cancelled(); ++n) {
+    for (size_t n = range.begin(); n < range.end() && !util::isGroupExecutionCancelled(); ++n) {
         for (iter = mLeafArray.leaf(n).cbeginValueOff(); iter; ++iter) {
             mInactiveValues.insert(iter.getValue());
         }
 
         if (mInactiveValues.size() > mNumValues) {
-            tbb::task::self().cancel_group_execution();
+            util::cancelGroupExecution();
         }
     }
 }
@@ -1250,14 +1252,14 @@ template<typename TreeType>
 inline void
 InactiveTileValues<TreeType>::operator()(IterRange& range)
 {
-    for (; range && !tbb::task::self().is_cancelled(); ++range) {
+    for (; range && !util::isGroupExecutionCancelled(); ++range) {
         typename TreeType::ValueOffCIter iter = range.iterator();
         for (; iter; ++iter) {
             mInactiveValues.insert(iter.getValue());
         }
 
         if (mInactiveValues.size() > mNumValues) {
-            tbb::task::self().cancel_group_execution();
+            util::cancelGroupExecution();
         }
     }
 }
