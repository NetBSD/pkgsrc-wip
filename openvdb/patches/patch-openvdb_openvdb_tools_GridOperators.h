$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb/openvdb/tools/GridOperators.h.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb/openvdb/tools/GridOperators.h
@@ -9,14 +9,15 @@
 #ifndef OPENVDB_TOOLS_GRID_OPERATORS_HAS_BEEN_INCLUDED
 #define OPENVDB_TOOLS_GRID_OPERATORS_HAS_BEEN_INCLUDED
 
-#include <openvdb/Grid.h>
-#include <openvdb/math/Operators.h>
-#include <openvdb/util/NullInterrupter.h>
-#include <openvdb/tree/LeafManager.h>
-#include <openvdb/tree/ValueAccessor.h>
+#include "openvdb/Grid.h"
+#include "openvdb/math/Operators.h"
+#include "openvdb/util/NullInterrupter.h"
+#include "openvdb/util/Threading.h"
+#include "openvdb/tree/LeafManager.h"
+#include "openvdb/tree/ValueAccessor.h"
 #include "ValueTransformer.h" // for tools::foreach()
-#include <tbb/parallel_for.h>
 
+#include <tbb/parallel_for.h>
 
 namespace openvdb {
 OPENVDB_USE_VERSION_NAMESPACE
@@ -383,7 +384,9 @@ public:
     /// TBB threads only!
     void operator()(const typename LeafManagerT::LeafRange& range) const
     {
-        if (util::wasInterrupted(mInterrupt)) tbb::task::self().cancel_group_execution();
+        if (util::wasInterrupted(mInterrupt)) {
+            util::cancelGroupExecution();
+        }
 
         for (typename LeafManagerT::LeafRange::Iterator leaf=range.begin(); leaf; ++leaf) {
             for (typename OutLeafT::ValueOnIter value=leaf->beginValueOn(); value; ++value) {
