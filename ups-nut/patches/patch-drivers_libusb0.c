$NetBSD: patch-drivers_libusb0.c,v 1.1 2022/04/26 23:28:25 gdt Exp $

--- drivers/libusb0.c.orig	2024-12-02 14:39:55.000000000 +0000
+++ drivers/libusb0.c
@@ -765,6 +765,7 @@ static int nut_libusb_open(usb_dev_handl
  */
 static int nut_libusb_strerror(const int ret, const char *desc)
 {
+	/* \todo: Possibly change to >= */
 	if (ret > 0) {
 		return ret;
 	}
