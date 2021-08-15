$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb/openvdb/tools/PointPartitioner.h.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb/openvdb/tools/PointPartitioner.h
@@ -23,7 +23,7 @@
 
 #include <tbb/blocked_range.h>
 #include <tbb/parallel_for.h>
-#include <tbb/task_scheduler_init.h>
+#include <tbb/task_arena.h>
 
 #include <algorithm>
 #include <cmath> // for std::isfinite()
@@ -764,7 +764,7 @@ inline void binAndSegment(
     using IndexPairListMap = std::map<Coord, IndexPairListPtr>;
     using IndexPairListMapPtr = std::shared_ptr<IndexPairListMap>;
 
-    size_t numTasks = 1, numThreads = size_t(tbb::task_scheduler_init::default_num_threads());
+    size_t numTasks = 1, numThreads = size_t(tbb::this_task_arena::max_concurrency());
     if (points.size() > (numThreads * 2)) numTasks = numThreads * 2;
     else if (points.size() > numThreads) numTasks = numThreads;
 
