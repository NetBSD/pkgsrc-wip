$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- skia/ext/platform_canvas.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ skia/ext/platform_canvas.h
@@ -58,7 +58,7 @@ SK_API HDC GetNativeDrawingContext(SkCan
 
 #elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || \
     defined(__sun) || defined(ANDROID) || defined(__APPLE__) ||             \
-    defined(__Fuchsia__)
+    defined(__Fuchsia__) || defined(__NetBSD__)
 // Construct a canvas from the given memory region. The memory is not cleared
 // first. @data must be, at least, @height * StrideForWidth(@width) bytes.
 SK_API std::unique_ptr<SkCanvas> CreatePlatformCanvasWithPixels(
