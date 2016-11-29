$NetBSD$

--- device/geolocation/location_arbitrator_impl.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ device/geolocation/location_arbitrator_impl.cc
@@ -167,7 +167,7 @@ LocationArbitratorImpl::NewNetworkLocati
 
 std::unique_ptr<LocationProvider>
 LocationArbitratorImpl::NewSystemLocationProvider() {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   return nullptr;
 #else
   return device::NewSystemLocationProvider();
