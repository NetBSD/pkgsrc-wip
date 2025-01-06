$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/sharing/sharing_device_registration.cc.orig	2024-10-18 12:34:02.252882000 +0000
+++ chrome/browser/sharing/sharing_device_registration.cc
@@ -331,7 +331,7 @@ bool SharingDeviceRegistration::IsSmsFet
 
 bool SharingDeviceRegistration::IsRemoteCopySupported() const {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
