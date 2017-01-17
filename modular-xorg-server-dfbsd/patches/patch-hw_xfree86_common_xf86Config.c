$NetBSD$

devd support to detect devices from FreeBSD ports / DragonFly dports

--- hw/xfree86/common/xf86Config.c.orig	2017-01-05 21:19:31.000000000 +0000
+++ hw/xfree86/common/xf86Config.c
@@ -1375,13 +1375,16 @@ checkCoreInputDevices(serverLayoutPtr se
     }
 
     if (!xf86Info.forceInputDevices && !(foundPointer && foundKeyboard)) {
-#if defined(CONFIG_HAL) || defined(CONFIG_UDEV) || defined(CONFIG_WSCONS)
+#if defined(CONFIG_HAL) || defined(CONFIG_UDEV) || defined(CONFIG_WSCONS) || \
+		defined(CONFIG_DEVD)
         const char *config_backend;
 
 #if defined(CONFIG_HAL)
         config_backend = "HAL";
 #elif defined(CONFIG_UDEV)
         config_backend = "udev";
+#elif defined(CONFIG_DEVD)
+	config_backend = "devd";
 #else
         config_backend = "wscons";
 #endif
