$NetBSD$
Already upstream
Joystick stuff
--- lib/irrlicht/source/Irrlicht/CIrrDeviceLinux.cpp.orig	2017-01-08 01:48:28.116234464 +0000
+++ lib/irrlicht/source/Irrlicht/CIrrDeviceLinux.cpp	2017-01-08 01:48:57.844356334 +0000
@@ -2207,7 +2207,7 @@
 		returnInfo.Axes = info.axes;
 		returnInfo.Buttons = info.buttons;
 
-#if !defined(__FreeBSD__) && !defined(__OpenBSD__)
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 		char name[80];
 		ioctl( info.fd, JSIOCGNAME(80), name);
 		returnInfo.Name = name;
