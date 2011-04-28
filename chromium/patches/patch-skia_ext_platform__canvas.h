$NetBSD: patch-skia_ext_platform__canvas.h,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- skia/ext/platform_canvas.h.orig	2011-04-13 08:01:18.000000000 +0000
+++ skia/ext/platform_canvas.h
@@ -33,8 +33,8 @@ class PlatformCanvas : public SkCanvas {
   PlatformCanvas(int width, int height, bool is_opaque,
                  CGContextRef context);
   PlatformCanvas(int width, int height, bool is_opaque, uint8_t* context);
-#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || \
-      defined(__Solaris__)
+#elif defined(__linux__) || defined(__DragonFly__) || defined(__FreeBSD__) || \
+      defined(__NetBSD__) || defined(__OpenBSD__) || defined(__Solaris__)
   // Linux ---------------------------------------------------------------------
 
   // Construct a canvas from the given memory region. The memory is not cleared
@@ -55,8 +55,8 @@ class PlatformCanvas : public SkCanvas {
   bool initialize(CGContextRef context, int width, int height, bool is_opaque);
   bool initialize(int width, int height, bool is_opaque, uint8_t* data = NULL);
 
-#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || \
-      defined(__Solaris__)
+#elif defined(__linux__) || defined(__DragonFly__) || defined(__FreeBSD__) || \
+      defined(__NetBSD__) || defined(__OpenBSD__) || defined(__Solaris__)
   // For two-part init, call if you use the no-argument constructor above
   bool initialize(int width, int height, bool is_opaque, uint8_t* data = NULL);
 #endif
