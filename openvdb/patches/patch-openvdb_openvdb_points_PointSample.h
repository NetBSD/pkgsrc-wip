$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb/openvdb/points/PointSample.h.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb/openvdb/points/PointSample.h
@@ -10,8 +10,9 @@
 #ifndef OPENVDB_POINTS_POINT_SAMPLE_HAS_BEEN_INCLUDED
 #define OPENVDB_POINTS_POINT_SAMPLE_HAS_BEEN_INCLUDED
 
-#include <openvdb/util/NullInterrupter.h>
-#include <openvdb/tools/Interpolation.h>
+#include "openvdb/util/NullInterrupter.h"
+#include "openvdb/util/Threading.h"
+#include "openvdb/tools/Interpolation.h"
 
 #include "PointDataGrid.h"
 #include "PointAttribute.h"
@@ -19,7 +20,6 @@
 #include <sstream>
 #include <type_traits>
 
-
 namespace openvdb {
 OPENVDB_USE_VERSION_NAMESPACE
 namespace OPENVDB_VERSION_NAME {
@@ -299,7 +299,7 @@ private:
             using TargetHandleT = AttributeWriteHandle<typename SamplerWrapperT::ValueType>;
 
             if (util::wasInterrupted(interrupter)) {
-                tbb::task::self().cancel_group_execution();
+                util::cancelGroupExecution();
                 return;
             }
 
