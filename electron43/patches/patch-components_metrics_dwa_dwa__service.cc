$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/metrics/dwa/dwa_service.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/metrics/dwa/dwa_service.cc
@@ -161,7 +161,7 @@ void DwaService::RecordCoarseSystemInfor
   coarse_system_info->set_platform(::dwa::CoarseSystemInfo::PLATFORM_WINDOWS);
 #elif BUILDFLAG(IS_MAC)
   coarse_system_info->set_platform(::dwa::CoarseSystemInfo::PLATFORM_MACOS);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   coarse_system_info->set_platform(::dwa::CoarseSystemInfo::PLATFORM_LINUX);
 #elif BUILDFLAG(IS_ANDROID)
   // TODO(b/366276323): Populate set_platform using more granular
