$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/libusb/src/libusb/core.c.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/libusb/src/libusb/core.c
@@ -448,7 +448,7 @@ libusb_free_device_list(list, 1);
  * which grows when required. it can be freed once discovery has completed,
  * eliminating the need for a list node in the libusb_device structure
  * itself. */
-#define DISCOVERED_DEVICES_SIZE_STEP 8
+#define DISCOVERED_DEVICES_SIZE_STEP 16
 
 static struct discovered_devs *discovered_devs_alloc(void)
 {
