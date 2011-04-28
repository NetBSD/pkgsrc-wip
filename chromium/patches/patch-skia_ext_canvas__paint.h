$NetBSD: patch-skia_ext_canvas__paint.h,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- skia/ext/canvas_paint.h.orig	2011-04-13 08:01:18.000000000 +0000
+++ skia/ext/canvas_paint.h
@@ -13,7 +13,8 @@
 #include "skia/ext/canvas_paint_win.h"
 #elif defined(__APPLE__)
 #include "skia/ext/canvas_paint_mac.h"
-#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__linux__) || defined(__DragonFly__) || defined(__FreeBSD__) || \
+      defined(__NetBSD__) || defined(__OpenBSD__)
 #include "skia/ext/canvas_paint_linux.h"
 #endif
 
