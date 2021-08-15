$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb/openvdb/unittest/TestCoord.cc.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb/openvdb/unittest/TestCoord.cc
@@ -2,9 +2,9 @@
 // SPDX-License-Identifier: MPL-2.0
 
 #include <openvdb/Types.h>
+#include <openvdb/math/Coord.h>
 
 #include <gtest/gtest.h>
-#include <tbb/tbb_stddef.h> // for tbb::split
 
 #include <unordered_map>
 #include <sstream>
