$NetBSD$

--- device/usb/usb_context.cc.orig	2016-06-24 01:02:22.000000000 +0000
+++ device/usb/usb_context.cc
@@ -9,8 +9,13 @@
 #include "base/macros.h"
 #include "base/threading/simple_thread.h"
 #include "device/usb/usb_error.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#define LIBUSB_CALL
+#else
 #include "third_party/libusb/src/libusb/interrupt.h"
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace device {
 
@@ -58,7 +63,9 @@ void UsbContext::UsbEventHandler::Run() 
 
 void UsbContext::UsbEventHandler::Stop() {
   base::subtle::Release_Store(&running_, 0);
+#if !defined(OS_FREEBSD) && !defined(OS_NETBSD) // XXX(rene) not available in base version
   libusb_interrupt_handle_event(context_);
+#endif
 }
 
 UsbContext::UsbContext(PlatformUsbContext context) : context_(context) {
