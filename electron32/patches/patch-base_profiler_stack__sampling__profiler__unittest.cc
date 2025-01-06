$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/profiler/stack_sampling_profiler_unittest.cc.orig	2024-10-18 12:33:59.802254200 +0000
+++ base/profiler/stack_sampling_profiler_unittest.cc
@@ -45,7 +45,7 @@
 
 #include <intrin.h>
 #include <malloc.h>
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
