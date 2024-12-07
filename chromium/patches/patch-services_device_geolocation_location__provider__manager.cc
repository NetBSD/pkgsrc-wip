$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/geolocation/location_provider_manager.cc.orig	2024-12-03 23:30:25.393251000 +0000
+++ services/device/geolocation/location_provider_manager.cc
@@ -87,7 +87,7 @@ LocationProviderManager::LocationProvide
 #if BUILDFLAG(IS_ANDROID)
   // On Android, default to using the platform location provider.
   provider_manager_mode_ = kPlatformOnly;
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Ash / Lacros / Linux, default to using the network location provider.
   provider_manager_mode_ = kNetworkOnly;
 #else
