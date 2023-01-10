$NetBSD: patch-drivers_usbhid-ups.c,v 1.2 2022/11/26 14:45:47 gdt Exp $

Avoid re-closing a udev that already was closed.  Avoids a double-close
that triggers a SEGV in a list-delete operation.

This may actually be the real bug for this code in libusb1.c:

static int nut_libusb_open(libusb_device_handle **udevp,
[ ... ]
#ifndef __linux__ /* SUN_LIBUSB (confirmed to work on Solaris and FreeBSD) */
	/* Causes a double free corruption in linux if device is detached! */

as the same double-free list issue occurs here.


Fixed upstream slightly differently, but essentially the same, in:
https://github.com/networkupstools/nut/commit/89dbdd1e60

--- drivers/usbhid-ups.c.orig	2022-11-26 14:02:03.000000000 +0000
+++ drivers/usbhid-ups.c
@@ -1160,6 +1160,7 @@ void upsdrv_cleanup(void)
 	upsdebugx(1, "upsdrv_cleanup...");
 
 	comm_driver->close_dev(udev);
+	udev = HID_DEV_HANDLE_CLOSED;
 	Free_ReportDesc(pDesc);
 	free_report_buffer(reportbuf);
 #ifndef SHUT_MODE
