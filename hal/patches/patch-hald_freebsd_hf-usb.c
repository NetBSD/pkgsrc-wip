$NetBSD$

--- hald/freebsd/hf-usb.c.orig	2009-09-17 13:49:46.000000000 +0000
+++ hald/freebsd/hf-usb.c
@@ -36,9 +36,13 @@
 #if __FreeBSD_version >= 800064
 #include <legacy/dev/usb/usb.h>
 #else
+#ifdef __DragonFly__
+#include <bus/usb/usb.h>
+#else
 #include <dev/usb/usb.h>
 #endif
 #endif
+#endif
 
 #include "../logger.h"
 #include "../osspec.h"
@@ -392,7 +396,11 @@ hf_usb_device_new (HalDevice *parent,
     hf_devtree_device_set_name(device, di->udi_devnames[0]);
 
   if ((devname = hf_usb_get_devname(di, "ukbd")))	/* USB keyboard */
+#if defined(__FreeBSD__)
+    hf_device_set_input(device, "keyboard", "keys", NULL);
+#else
     hf_device_set_input(device, "keyboard", "keys", devname);
+#endif
   else if ((devname = hf_usb_get_devname(di, "ums")))	/* USB mouse */
     hf_device_set_input(device, "mouse", NULL, devname);
   else if ((devname = hf_usb_get_devname(di, "uhid")))	/* UHID device */
@@ -613,7 +621,6 @@ hf_usb_privileged_init (void)
   if (hf_usb_fd < 0)
     {
       HAL_INFO(("unable to open %s: %s", HF_USB_DEVICE, g_strerror(errno)));
-      return;
     }
 
   for (i = 0; i < 16; i++)
@@ -908,6 +915,8 @@ hf_usb_add_webcam_properties (HalDevice 
 
   hal_device_property_set_string(device, "info.category", "video4linux");
   hal_device_add_capability(device, "video4linux");
+  hal_device_add_capability(device, "video4linux.video_capture");
   hf_device_property_set_string_printf(device, "video4linux.device", "/dev/video%i", unit);
   hal_device_property_set_string(device, "info.product", "Video Device");
+  hal_device_property_set_string(device, "video4linux.version", "1");
 }
