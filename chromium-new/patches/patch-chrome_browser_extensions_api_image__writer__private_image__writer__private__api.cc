$NetBSD$

--- chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc.orig	2017-02-02 02:02:49.000000000 +0000
+++ chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc
@@ -166,10 +166,12 @@ ImageWriterPrivateListRemovableStorageDe
 }
 
 bool ImageWriterPrivateListRemovableStorageDevicesFunction::RunAsync() {
+#if !defined(OS_BSD)
   RemovableStorageProvider::GetAllDevices(
     base::Bind(
       &ImageWriterPrivateListRemovableStorageDevicesFunction::OnDeviceListReady,
       this));
+#endif
   return true;
 }
 
