$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gin/v8_platform.cc.orig	2024-10-18 12:34:18.340386400 +0000
+++ gin/v8_platform.cc
@@ -205,6 +205,10 @@ ThreadIsolatedAllocator* V8Platform::Get
 }
 #endif  // PA_BUILDFLAG(ENABLE_THREAD_ISOLATION)
 
+PageAllocator* V8Platform::GetCurrentPageAllocator() {
+  return g_page_allocator.Pointer();
+}
+
 void V8Platform::OnCriticalMemoryPressure() {
 // We only have a reservation on 32-bit Windows systems.
 // TODO(bbudge) Make the #if's in BlinkInitializer match.
