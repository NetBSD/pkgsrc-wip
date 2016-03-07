$NetBSD$

--- spectro/usbio.c.orig	2015-10-26 04:17:49.000000000 +0000
+++ spectro/usbio.c
@@ -94,7 +94,7 @@ static int icoms_usb_wait_io(
 #  include "usbio_ox.c"
 # endif
 # if defined(UNIX_X11)
-#  if defined(__FreeBSD__) || defined(__OpenBSD__)
+#  if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #   include "usbio_bsd.c"
 #  else
 #   include "usbio_lx.c"
