$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/profiler/stack_sampling_profiler_test_util.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ base/profiler/stack_sampling_profiler_test_util.cc
@@ -42,7 +42,7 @@
 // Fortunately, it provides _alloca, which functions identically.
 #include <malloc.h>
 #define alloca _alloca
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
