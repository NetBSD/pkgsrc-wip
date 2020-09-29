$NetBSD$

--- hald/freebsd/probing/probe-usb2-interface.c.orig	2009-08-24 12:42:29.000000000 +0000
+++ hald/freebsd/probing/probe-usb2-interface.c
@@ -58,11 +58,11 @@ main(int argc, char **argv)
   if (pbe == NULL)
     goto end;
 
-  busstr = getenv("HAL_PROP_USB_DEVICE_BUS_NUMBER");
+  busstr = getenv("HAL_PROP_USB_BUS_NUMBER");
   if (! busstr)
     goto end;
 
-  addrstr = getenv("HAL_PROP_USB_DEVICE_PORT_NUMBER");
+  addrstr = getenv("HAL_PROP_USB_PORT_NUMBER");
   if (! addrstr)
     goto end;
 
