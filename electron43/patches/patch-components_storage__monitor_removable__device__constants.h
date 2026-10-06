$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/storage_monitor/removable_device_constants.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/storage_monitor/removable_device_constants.h
@@ -14,7 +14,7 @@ namespace storage_monitor {
 extern const char kFSUniqueIdPrefix[];
 extern const char kVendorModelSerialPrefix[];
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kVendorModelVolumeStoragePrefix[];
 #endif
 
