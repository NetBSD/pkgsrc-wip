$NetBSD$

--- device/usb/usb_device_impl.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ device/usb/usb_device_impl.cc
@@ -22,7 +22,11 @@
 #include "device/usb/usb_descriptors.h"
 #include "device/usb/usb_device_handle_impl.h"
 #include "device/usb/usb_error.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace device {
 
