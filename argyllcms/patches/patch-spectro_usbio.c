$NetBSD$

Recognize NetBSD.

--- spectro/usbio.c.orig	2018-07-09 02:57:13.000000000 +0000
+++ spectro/usbio.c
@@ -95,7 +95,7 @@ static int icoms_usb_wait_io(
 #  include "usbio_ox.c"
 # endif
 # if defined(UNIX_X11)
-#  if defined(__FreeBSD__) || defined(__OpenBSD__)
+#  if defined(__FreeBSD__) || defined (__NetBSD__) || defined(__OpenBSD__)
 #   include "usbio_bsd.c"
 #  else
 #   include "usbio_lx.c"
