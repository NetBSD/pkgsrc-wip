$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gin/public/v8_platform.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ gin/public/v8_platform.h
@@ -32,6 +32,7 @@ class GIN_EXPORT V8Platform : public v8:
   // enabling Arm's Branch Target Instructions for executable pages. This is
   // verified in the tests for gin::PageAllocator.
   PageAllocator* GetPageAllocator() override;
+  static PageAllocator* GetCurrentPageAllocator();
 #if PA_BUILDFLAG(ENABLE_THREAD_ISOLATION)
   ThreadIsolatedAllocator* GetThreadIsolatedAllocator() override;
 #endif
