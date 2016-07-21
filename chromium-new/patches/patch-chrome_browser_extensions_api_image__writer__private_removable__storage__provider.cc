$NetBSD$

--- chrome/browser/extensions/api/image_writer_private/removable_storage_provider.cc.orig	2016-06-24 01:02:12.000000000 +0000
+++ chrome/browser/extensions/api/image_writer_private/removable_storage_provider.cc
@@ -27,11 +27,13 @@ void RemovableStorageProvider::GetAllDev
   scoped_refptr<StorageDeviceList> device_list(new StorageDeviceList);
 
   // We need to do some file i/o to get the device block size
+#if !defined(OS_NETBSD)
   content::BrowserThread::PostTaskAndReplyWithResult(
       content::BrowserThread::FILE,
       FROM_HERE,
       base::Bind(PopulateDeviceList, device_list),
       base::Bind(callback, device_list));
+#endif
 }
 
 void RemovableStorageProvider::SetDeviceListForTesting(
