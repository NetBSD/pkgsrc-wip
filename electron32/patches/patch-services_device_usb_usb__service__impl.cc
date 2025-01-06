$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- services/device/usb/usb_service_impl.cc.orig	2024-10-18 12:34:32.057736600 +0000
+++ services/device/usb/usb_service_impl.cc
@@ -203,7 +203,7 @@ void UsbServiceImpl::GetDevices(GetDevic
     return;
   }
 
-  if (enumeration_in_progress_) {
+  if (enumeration_in_progress_ || !enumeration_ready_) {
     pending_enumeration_callbacks_.push_back(std::move(callback));
     return;
   }
