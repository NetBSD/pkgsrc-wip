$NetBSD$

--- device/usb/usb_device_handle_impl.cc.orig	2017-02-02 02:02:54.000000000 +0000
+++ device/usb/usb_device_handle_impl.cc
@@ -25,7 +25,11 @@
 #include "device/usb/usb_error.h"
 #include "device/usb/usb_service.h"
 #include "net/base/io_buffer.h"
-#include "third_party/libusb/src/libusb/libusb.h"
+#if defined(OS_FREEBSD)
+#  include "libusb.h"
+#else
+#  include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace device {
 
