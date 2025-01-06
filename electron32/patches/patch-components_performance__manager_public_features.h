$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/performance_manager/public/features.h.orig	2024-10-18 12:34:07.302123500 +0000
+++ components/performance_manager/public/features.h
@@ -21,7 +21,7 @@ BASE_DECLARE_FEATURE(kRunOnMainThreadSyn
 
 #if !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define URGENT_DISCARDING_FROM_PERFORMANCE_MANAGER() false
 #else
 #define URGENT_DISCARDING_FROM_PERFORMANCE_MANAGER() true
