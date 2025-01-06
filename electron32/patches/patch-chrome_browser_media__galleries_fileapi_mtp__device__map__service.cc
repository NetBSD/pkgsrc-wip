$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/media_galleries/fileapi/mtp_device_map_service.cc.orig	2024-10-18 12:34:01.709184400 +0000
+++ chrome/browser/media_galleries/fileapi/mtp_device_map_service.cc
@@ -40,10 +40,12 @@ void MTPDeviceMapService::RegisterMTPFil
     // Note that this initializes the delegate asynchronously, but since
     // the delegate will only be used from the IO thread, it is guaranteed
     // to be created before use of it expects it to be there.
+#if !BUILDFLAG(IS_BSD) 
     CreateMTPDeviceAsyncDelegate(
         device_location, read_only,
         base::BindOnce(&MTPDeviceMapService::AddAsyncDelegate,
                        base::Unretained(this), device_location, read_only));
+#endif
     mtp_device_usage_map_[key] = 0;
   }
 
