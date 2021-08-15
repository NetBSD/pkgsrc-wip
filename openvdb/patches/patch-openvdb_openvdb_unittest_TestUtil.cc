$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb/openvdb/unittest/TestUtil.cc.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb/openvdb/unittest/TestUtil.cc
@@ -8,7 +8,6 @@
 
 #include <gtest/gtest.h>
 
-#include <tbb/task_scheduler_init.h>
 #include <tbb/enumerable_thread_specific.h>
 #include <tbb/parallel_for.h>
 #include <tbb/blocked_range.h>
