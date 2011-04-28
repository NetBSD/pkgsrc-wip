$NetBSD: patch-skia_ext_platform__device.h,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- skia/ext/platform_device.h.orig	2011-04-13 08:01:18.000000000 +0000
+++ skia/ext/platform_device.h
@@ -13,8 +13,8 @@
 #include "skia/ext/platform_device_win.h"
 #elif defined(__APPLE__)
 #include "skia/ext/platform_device_mac.h"
-#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || \
-      defined(__Solaris__)
+#elif defined(__linux__) || defined(__DragonFly__) || defined(__FreeBSD__) || \
+      defined(__NetBSD__) || defined(__OpenBSD__) || defined(__Solaris__)
 #include "skia/ext/platform_device_linux.h"
 #endif
 
