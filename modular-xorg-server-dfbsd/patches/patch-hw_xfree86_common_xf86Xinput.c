$NetBSD$

devd support to detect devices from FreeBSD ports / DragonFly dports

--- hw/xfree86/common/xf86Xinput.c.orig	2017-01-04 21:32:10.000000000 +0000
+++ hw/xfree86/common/xf86Xinput.c
@@ -1034,6 +1034,7 @@ NewInputDeviceRequest(InputOption *optio
         if (strcmp(key, "_source") == 0 &&
             (strcmp(value, "server/hal") == 0 ||
              strcmp(value, "server/udev") == 0 ||
+             strcmp(value, "server/devd") == 0 ||
              strcmp(value, "server/wscons") == 0)) {
             is_auto = 1;
             if (!xf86Info.autoAddDevices) {
