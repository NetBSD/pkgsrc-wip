$NetBSD$

--- chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc.orig	2016-06-24 01:02:12.000000000 +0000
+++ chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc
@@ -166,10 +166,12 @@ ImageWriterPrivateListRemovableStorageDe
 }
 
 bool ImageWriterPrivateListRemovableStorageDevicesFunction::RunAsync() {
+#if !defined(OS_FREEBSD)
   RemovableStorageProvider::GetAllDevices(
     base::Bind(
       &ImageWriterPrivateListRemovableStorageDevicesFunction::OnDeviceListReady,
       this));
+#endif
   return true;
 }
 
