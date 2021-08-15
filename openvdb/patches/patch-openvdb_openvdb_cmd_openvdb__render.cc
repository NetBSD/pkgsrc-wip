$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb/openvdb/cmd/openvdb_render.cc.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb/openvdb/cmd/openvdb_render.cc
@@ -19,7 +19,14 @@
 #include <OpenEXR/ImfHeader.h>
 #include <OpenEXR/ImfOutputFile.h>
 #include <OpenEXR/ImfPixelType.h>
-#include <tbb/task_scheduler_init.h>
+
+// tbb/task_scheduler_init.h was removed in TBB 2021. The best construct to swap
+// to is tbb/global_control (for executables). global_control was only officially
+// added in TBB 2019U4 but exists in 2018 as a preview feature. To avoid more
+// compile time branching (as we still support 2018), we use it in 2018 too by
+// enabling the below define.
+#define TBB_PREVIEW_GLOBAL_CONTROL
+#include <tbb/global_control.h>
 #include <tbb/tick_count.h>
 
 #include <algorithm>
@@ -606,8 +613,12 @@ main(int argc, char *argv[])
     }
 
     try {
-        tbb::task_scheduler_init schedulerInit(
-            (opts.threads == 0) ? tbb::task_scheduler_init::automatic : opts.threads);
+        std::unique_ptr<tbb::global_control> control;
+        if (opts.threads > 0) {
+            // note, opts.threads == 0 means use all threads (default), so don't
+            // manually create a tbb::global_control in this case
+            control.reset(new tbb::global_control(tbb::global_control::max_allowed_parallelism, opts.threads));
+        }
 
         openvdb::initialize();
 
