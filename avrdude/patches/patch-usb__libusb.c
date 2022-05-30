$NetBSD$

Work around AVRISP mkII initial sync stalls on NetBSD.

--- usb_libusb.c.orig	2022-05-07 20:29:58.000000000 +0000
+++ usb_libusb.c
@@ -313,6 +313,17 @@ static void usbdev_close(union filedescr
   if (udev == NULL)
     return;
 
+#if defined(__NetBSD__)
+#define USB_FEAT_ENDPOINT_HALT 0
+  /*
+   * Clear Feature Endpoint Halt to reset device's data toggle to DATA0.
+   * This way, when we reopen expecting DATA0, things don't time out.
+   */
+  usb_control_msg(udev, USB_TYPE_STANDARD | USB_RECIP_ENDPOINT,
+		  USB_REQ_CLEAR_FEATURE, USB_FEAT_ENDPOINT_HALT,
+		  fd->usb.rep & 0xf, NULL, 0, 100);
+#endif
+
   (void)usb_release_interface(udev, usb_interface);
 
 #if defined(__linux__)
