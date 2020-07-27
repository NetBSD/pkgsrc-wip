$NetBSD$

--- services/device/geolocation/location_arbitrator.cc.orig	2020-07-15 18:56:01.000000000 +0000
+++ services/device/geolocation/location_arbitrator.cc
@@ -156,7 +156,7 @@ LocationArbitrator::NewNetworkLocationPr
 
 std::unique_ptr<LocationProvider>
 LocationArbitrator::NewSystemLocationProvider() {
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   return nullptr;
 #else
   return device::NewSystemLocationProvider();
