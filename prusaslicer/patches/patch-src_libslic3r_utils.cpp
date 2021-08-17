$NetBSD$

Remove use of deprecated tbb::task_scheduler_init.

--- src/libslic3r/utils.cpp.orig	2021-07-16 10:14:03.000000000 +0000
+++ src/libslic3r/utils.cpp
@@ -43,7 +43,7 @@
 #include <boost/nowide/convert.hpp>
 #include <boost/nowide/cstdio.hpp>
 
-#include <tbb/task_scheduler_init.h>
+#include <tbb/global_control.h>
 
 #if defined(__linux__) || defined(__GNUC__ )
 #include <strings.h>
@@ -118,9 +118,9 @@ void trace(unsigned int level, const cha
 void disable_multi_threading()
 {
     // Disable parallelization so the Shiny profiler works
-    static tbb::task_scheduler_init *tbb_init = nullptr;
-    if (tbb_init == nullptr)
-        tbb_init = new tbb::task_scheduler_init(1);
+    static tbb::global_control *tbb_global = nullptr;
+    if (tbb_global == nullptr)
+        tbb_global = new tbb::global_control(tbb::global_control::max_allowed_parallelism, 1);
 }
 
 static std::string g_var_dir;
