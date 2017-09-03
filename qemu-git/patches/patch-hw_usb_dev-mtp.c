$NetBSD$

--- hw/usb/dev-mtp.c.orig	2017-08-25 15:26:30.000000000 +0000
+++ hw/usb/dev-mtp.c
@@ -26,6 +26,10 @@
 #include "hw/usb.h"
 #include "hw/usb/desc.h"
 
+#ifndef NAME_MAX
+#define NAME_MAX 255
+#endif
+
 /* ----------------------------------------------------------------------- */
 
 enum mtp_container_type {
