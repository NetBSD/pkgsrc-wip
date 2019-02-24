$NetBSD$

devd support to detect devices from FreeBSD ports / DragonFly dports
x11-servers/xorg-server 1.18.4.

--- hw/xfree86/common/xf86Globals.c.orig	2018-05-10 16:32:35.000000000 +0000
+++ hw/xfree86/common/xf86Globals.c
@@ -117,7 +117,8 @@ xf86InfoRec xf86Info = {
     .miscModInDevEnabled = TRUE,
     .miscModInDevAllowNonLocal = FALSE,
     .pmFlag = TRUE,
-#if defined(CONFIG_HAL) || defined(CONFIG_UDEV) || defined(CONFIG_WSCONS)
+#if defined(CONFIG_HAL) || defined(CONFIG_UDEV) || defined(CONFIG_WSCONS) || \
+	defined(CONFIG_DEVD)
     .forceInputDevices = FALSE,
     .autoAddDevices = TRUE,
     .autoEnableDevices = TRUE,
