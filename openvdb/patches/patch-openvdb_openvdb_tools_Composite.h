$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb/openvdb/tools/Composite.h.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb/openvdb/tools/Composite.h
@@ -24,7 +24,6 @@
 #include <tbb/parallel_for.h>
 #include <tbb/parallel_reduce.h>
 #include <tbb/task_group.h>
-#include <tbb/task_scheduler_init.h>
 
 #include <type_traits>
 #include <functional>
