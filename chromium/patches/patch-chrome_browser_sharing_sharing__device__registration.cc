$NetBSD$

--- chrome/browser/sharing/sharing_device_registration.cc.orig	2020-07-08 21:40:35.000000000 +0000
+++ chrome/browser/sharing/sharing_device_registration.cc
@@ -329,7 +329,7 @@ bool SharingDeviceRegistration::IsSmsFet
 
 bool SharingDeviceRegistration::IsRemoteCopySupported() const {
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
   return base::FeatureList::IsEnabled(kRemoteCopyReceiver);
 #else
   return false;
@@ -338,7 +338,7 @@ bool SharingDeviceRegistration::IsRemote
 
 bool SharingDeviceRegistration::IsPeerConnectionSupported() const {
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
   return base::FeatureList::IsEnabled(kSharingPeerConnectionReceiver);
 #else
   return false;
