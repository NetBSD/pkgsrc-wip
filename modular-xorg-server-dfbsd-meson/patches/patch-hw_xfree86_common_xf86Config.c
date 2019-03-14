$NetBSD$

devd support to detect devices from FreeBSD ports / DragonFly dports
x11-servers/xorg-server 1.18.4.

--- hw/xfree86/common/xf86Config.c.orig	2019-03-05 16:34:21.000000000 +0000
+++ hw/xfree86/common/xf86Config.c
@@ -1020,7 +1020,11 @@ checkCoreInputDevices(serverLayoutPtr se
     MessageType from = X_DEFAULT;
 
     const char *mousedrivers[] = { "mouse", "synaptics", "evdev", "vmmouse",
+#if defined(WS_DRIVERS_OPENBSD)
+        "ws", "void", NULL
+#else
         "void", NULL
+#endif
     };
 
     /*
@@ -1260,13 +1264,16 @@ checkCoreInputDevices(serverLayoutPtr se
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
+        config_backend = "devd";
 #else
         config_backend = "wscons";
 #endif
