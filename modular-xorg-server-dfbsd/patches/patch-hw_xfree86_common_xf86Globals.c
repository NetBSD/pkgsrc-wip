$NetBSD$

devd support to detect devices from FreeBSD ports / DragonFly dports

--- hw/xfree86/common/xf86Globals.c.orig	2015-07-18 23:25:51.820719000 +0000
+++ hw/xfree86/common/xf86Globals.c
@@ -122,7 +122,8 @@ xf86InfoRec xf86Info = {
     .pmFlag = TRUE,
     .disableRandR = FALSE,
     .randRFrom = X_DEFAULT,
-#if defined(CONFIG_HAL) || defined(CONFIG_UDEV) || defined(CONFIG_WSCONS)
+#if defined(CONFIG_HAL) || defined(CONFIG_UDEV) || defined(CONFIG_WSCONS) || \
+	defined(CONFIG_DEVD)
     .forceInputDevices = FALSE,
     .autoAddDevices = TRUE,
     .autoEnableDevices = TRUE,
