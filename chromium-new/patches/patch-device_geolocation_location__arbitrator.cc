$NetBSD$

--- device/geolocation/location_arbitrator.cc.orig	2017-02-02 02:02:54.000000000 +0000
+++ device/geolocation/location_arbitrator.cc
@@ -182,7 +182,7 @@ LocationArbitrator::NewNetworkLocationPr
 
 std::unique_ptr<LocationProvider>
 LocationArbitrator::NewSystemLocationProvider() {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   return nullptr;
 #else
   return device::NewSystemLocationProvider();
