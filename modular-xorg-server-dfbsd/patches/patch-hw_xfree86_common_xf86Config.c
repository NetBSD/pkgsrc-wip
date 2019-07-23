$NetBSD$

Option for "ws" from openbsd xenocara 1.19.7

From NetBSD xsrc:

Oct 22 15:00:40 2011

if the video driver is "vmware" or "vmwlegacy" and no mouse section exists,
use the "vmmouse" input driver instead of "mouse" -- no xorg works properly
in vmware without a config file

devd support to detect devices from FreeBSD ports / DragonFly dports
x11-servers/xorg-server 1.18.4.

--- hw/xfree86/common/xf86Config.c.orig	2019-05-30 18:27:34.000000000 +0000
+++ hw/xfree86/common/xf86Config.c
@@ -1024,7 +1024,11 @@ checkCoreInputDevices(serverLayoutPtr se
     MessageType from = X_DEFAULT;
 
     const char *mousedrivers[] = { "mouse", "synaptics", "evdev", "vmmouse",
+#if defined(WS_DRIVERS_OPENBSD)
+        "ws", "void", NULL
+#else
         "void", NULL
+#endif
     };
 
     /*
@@ -1115,7 +1119,18 @@ checkCoreInputDevices(serverLayoutPtr se
     if (!foundPointer && xf86Info.forceInputDevices) {
         memset(&defPtr, 0, sizeof(defPtr));
         defPtr.inp_identifier = strdup("<default pointer>");
+#if defined(__NetBSD__) && (defined(__i386__) || defined(__amd64__))
+	if (xf86findDeviceByDriver("vmware", xf86configptr->conf_device_lst) ||
+	    xf86findDeviceByDriver("vmwlegacy", xf86configptr->conf_device_lst)) {
+		defPtr.inp_driver = strdup("vmmouse");
+		defPtr.inp_option_lst = xf86addNewOption(defPtr.inp_option_lst, strdup("Protocol"), "wsmouse");
+		defPtr.inp_option_lst = xf86addNewOption(defPtr.inp_option_lst, strdup("Device"), "/dev/wsmouse");
+	} else {
+#endif
         defPtr.inp_driver = strdup("mouse");
+#if defined(__NetBSD__) && (defined(__i386__) || defined(__amd64__))
+        }
+#endif
         confInput = &defPtr;
         foundPointer = TRUE;
         from = X_DEFAULT;
@@ -1264,13 +1279,16 @@ checkCoreInputDevices(serverLayoutPtr se
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
