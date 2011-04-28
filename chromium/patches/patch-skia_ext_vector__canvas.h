$NetBSD: patch-skia_ext_vector__canvas.h,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- skia/ext/vector_canvas.h.orig	2011-04-13 08:01:18.000000000 +0000
+++ skia/ext/vector_canvas.h
@@ -9,7 +9,8 @@
 #include "skia/ext/platform_canvas.h"
 #include "skia/ext/vector_platform_device.h"
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__linux__) || defined(__DragonFly__) || defined(__FreeBSD__) || \
+    defined(__NetBSD__) || defined(__OpenBSD__)
 typedef struct _cairo cairo_t;
 #endif
 
@@ -25,7 +26,8 @@ class VectorCanvas : public PlatformCanv
   explicit VectorCanvas(SkDeviceFactory* factory);
 #if defined(WIN32)
   VectorCanvas(HDC dc, int width, int height);
-#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__linux__) || defined(__DragonFly__) || defined(__FreeBSD__) || \
+      defined(__NetBSD__) || defined(__OpenBSD__)
   // Caller owns |context|. Ownership is not transferred.
   VectorCanvas(cairo_t* context, int width, int height);
 #endif
@@ -34,7 +36,8 @@ class VectorCanvas : public PlatformCanv
   // For two-part init, call if you use the no-argument constructor above
 #if defined(WIN32)
   bool initialize(HDC context, int width, int height);
-#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__linux__) || defined(__DragonFly__) || defined(__FreeBSD__) || \
+      defined(__NetBSD__) || defined(__OpenBSD__)
   // Ownership of |context| is not transferred.
   bool initialize(cairo_t* context, int width, int height);
 #endif
