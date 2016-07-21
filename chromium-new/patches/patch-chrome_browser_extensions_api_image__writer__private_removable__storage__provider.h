$NetBSD$

--- chrome/browser/extensions/api/image_writer_private/removable_storage_provider.h.orig	2016-06-24 01:02:12.000000000 +0000
+++ chrome/browser/extensions/api/image_writer_private/removable_storage_provider.h
@@ -33,9 +33,11 @@ class RemovableStorageProvider {
   // Clears the list of devices that is used during testing.
   static void ClearDeviceListForTesting();
 
+#if !defined(OS_NETBSD)
  private:
   // Fills the provided empty device list with the available devices.
   static bool PopulateDeviceList(scoped_refptr<StorageDeviceList> device_list);
+#endif
 };
 
 } // namespace extensions
