$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb/openvdb/tools/VolumeToMesh.h.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb/openvdb/tools/VolumeToMesh.h
@@ -18,7 +18,7 @@
 #include <tbb/blocked_range.h>
 #include <tbb/parallel_for.h>
 #include <tbb/parallel_reduce.h>
-#include <tbb/task_scheduler_init.h>
+#include <tbb/task_arena.h>
 
 #include <cmath> // for std::isfinite()
 #include <map>
@@ -388,7 +388,7 @@ inline void
 fillArray(ValueType* array, const ValueType& val, const size_t length)
 {
     const auto grainSize = std::max<size_t>(
-        length / tbb::task_scheduler_init::default_num_threads(), 1024);
+        length / tbb::this_task_arena::max_concurrency(), 1024);
     const tbb::blocked_range<size_t> range(0, length, grainSize);
     tbb::parallel_for(range, FillArray<ValueType>(array, val), tbb::simple_partitioner());
 }
