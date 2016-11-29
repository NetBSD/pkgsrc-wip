$NetBSD$

--- device/usb/usb_error.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ device/usb/usb_error.cc
@@ -4,7 +4,11 @@
 
 #include "device/usb/usb_error.h"
 
+#if defined(__FreeBSD__)
+#include "libusb.h"
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace device {
 
