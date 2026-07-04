$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/threading/platform_thread.h.orig	2026-06-23 23:37:18.000000000 +0000
+++ base/threading/platform_thread.h
@@ -67,6 +67,8 @@ class BASE_EXPORT PlatformThreadId {
   using UnderlyingType = zx_koid_t;
 #elif BUILDFLAG(IS_APPLE)
   using UnderlyingType = uint64_t;
+#elif BUILDFLAG(IS_BSD)
+  using UnderlyingType = uint64_t;
 #elif BUILDFLAG(IS_POSIX)
   using UnderlyingType = pid_t;
 #endif
