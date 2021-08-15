$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb/openvdb/math/Coord.h.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb/openvdb/math/Coord.h
@@ -13,8 +13,7 @@
 #include "Math.h"
 #include "Vec3.h"
 
-namespace tbb { class split; } // forward declaration
-
+#include <tbb/blocked_range.h> // for tbb::split
 
 namespace openvdb {
 OPENVDB_USE_VERSION_NAMESPACE
