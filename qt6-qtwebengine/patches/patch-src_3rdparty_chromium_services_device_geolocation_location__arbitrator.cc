$NetBSD$

--- src/3rdparty/chromium/services/device/geolocation/location_arbitrator.cc.orig	2025-01-24 10:49:20.000000000 +0000
+++ src/3rdparty/chromium/services/device/geolocation/location_arbitrator.cc
@@ -196,7 +196,7 @@ LocationArbitrator::NewNetworkLocationPr
 
 std::unique_ptr<LocationProvider>
 LocationArbitrator::NewSystemLocationProvider() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return nullptr;
 #else
   return device::NewSystemLocationProvider(main_task_runner_,
