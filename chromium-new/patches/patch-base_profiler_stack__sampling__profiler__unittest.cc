$NetBSD$

--- base/profiler/stack_sampling_profiler_unittest.cc.orig	2016-11-10 20:02:09.000000000 +0000
+++ base/profiler/stack_sampling_profiler_unittest.cc
@@ -30,7 +30,7 @@
 #include <intrin.h>
 #include <malloc.h>
 #include <windows.h>
-#else
+#elif !defined(OS_BSD)
 #include <alloca.h>
 #endif
 
