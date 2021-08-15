$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb/openvdb/tools/Morphology.h.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb/openvdb/tools/Morphology.h
@@ -24,7 +24,7 @@
 #include "openvdb/tree/ValueAccessor.h"
 #include "openvdb/tree/LeafManager.h"
 
-#include <tbb/task_scheduler_init.h>
+#include <tbb/task_arena.h>
 #include <tbb/enumerable_thread_specific.h>
 #include <tbb/parallel_for.h>
 
@@ -726,7 +726,7 @@ void Morphology<TreeType>::dilateVoxels(
         }
 
         // @note this grain size is used for optimal threading
-        const size_t numThreads = size_t(tbb::task_scheduler_init::default_num_threads());
+        const size_t numThreads = size_t(tbb::this_task_arena::max_concurrency());
         const size_t subTreeSize = math::Max(size_t(1), array.size()/(2*numThreads));
 
         // perform recursive dilation to sub trees
