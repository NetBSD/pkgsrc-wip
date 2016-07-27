$NetBSD$

--- src/SFML/Window/FreeBSD/JoystickImpl.hpp.orig	2015-08-24 16:01:06.000000000 +0000
+++ src/SFML/Window/FreeBSD/JoystickImpl.hpp
@@ -28,6 +28,7 @@
 ////////////////////////////////////////////////////////////
 // Headers
 ////////////////////////////////////////////////////////////
+#include <dev/usb/usb.h>
 #include <dev/usb/usbhid.h>
 #include <usbhid.h>
 #include <vector>
