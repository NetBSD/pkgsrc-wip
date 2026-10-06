$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/platform/graphics/gpu/image_layer_bridge.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/platform/graphics/gpu/image_layer_bridge.cc
@@ -49,7 +49,7 @@ scoped_refptr<StaticBitmapImage> MakeAcc
   const auto paint_image = source->PaintImageForCurrentFrame();
   const auto image_info = paint_image.GetSkImageInfo().makeWH(
       source->Size().width(), source->Size().height());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(b/330865436): On Linux, CanvasResourceProvider doesn't always check
   // for SCANOUT support correctly on X11 and it's never supported in
   // practice. Therefore, don't include it until this flow is reworked.
