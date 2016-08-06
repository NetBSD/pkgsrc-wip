$NetBSD$

--- base/trace_event/memory_dump_manager.cc.orig	2016-08-05 17:13:37.000000000 +0000
+++ base/trace_event/memory_dump_manager.cc
@@ -165,7 +165,7 @@ void MemoryDumpManager::EnableHeapProfil
   }
   else if (profiling_mode == switches::kEnableHeapProfilingModeNative) {
 #if HAVE_TRACE_STACK_FRAME_POINTERS && \
-    (BUILDFLAG(ENABLE_PROFILING) || !defined(NDEBUG))
+    (!defined(NDEBUG))
     // We need frame pointers for native tracing to work, and they are
     // enabled in profiling and debug builds.
     AllocationContextTracker::SetCaptureMode(
