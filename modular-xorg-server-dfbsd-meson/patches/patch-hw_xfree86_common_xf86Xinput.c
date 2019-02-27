$NetBSD$

devd support to detect devices from FreeBSD ports / DragonFly dports
x11-servers/xorg-server 1.18.4.

--- hw/xfree86/common/xf86Xinput.c.orig	2017-12-20 20:32:33.000000000 +0000
+++ hw/xfree86/common/xf86Xinput.c
@@ -874,7 +874,7 @@ xf86NewInputDevice(InputInfoPtr pInfo, D
 {
     InputDriverPtr drv = NULL;
     DeviceIntPtr dev = NULL;
-    Bool paused;
+    Bool paused = 0;
     int rval;
     char *path = NULL;
 
@@ -1037,6 +1037,7 @@ NewInputDeviceRequest(InputOption *optio
         if (strcmp(key, "_source") == 0 &&
             (strcmp(value, "server/hal") == 0 ||
              strcmp(value, "server/udev") == 0 ||
+             strcmp(value, "server/devd") == 0 ||
              strcmp(value, "server/wscons") == 0)) {
             is_auto = 1;
             if (!xf86Info.autoAddDevices) {
