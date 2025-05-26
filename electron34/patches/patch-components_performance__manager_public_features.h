$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/performance_manager/public/features.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/performance_manager/public/features.h
@@ -21,7 +21,7 @@ BASE_DECLARE_FEATURE(kRunOnMainThreadSyn
 
 #if !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define URGENT_DISCARDING_FROM_PERFORMANCE_MANAGER() false
 #else
 #define URGENT_DISCARDING_FROM_PERFORMANCE_MANAGER() true
