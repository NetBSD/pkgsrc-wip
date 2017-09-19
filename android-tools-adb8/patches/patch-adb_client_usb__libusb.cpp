$NetBSD$

--- adb/client/usb_libusb.cpp.orig	2017-06-27 22:39:52.000000000 +0000
+++ adb/client/usb_libusb.cpp
@@ -27,8 +27,9 @@
 #include <string>
 #include <thread>
 #include <unordered_map>
+#include <condition_variable>
 
-#include <libusb/libusb.h>
+#include <libusb-1.0/libusb.h>
 
 #include <android-base/file.h>
 #include <android-base/logging.h>
