$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/osr/osr_video_consumer.cc.orig	2025-05-09 16:52:15.000000000 +0000
+++ electron/shell/browser/osr/osr_video_consumer.cc
@@ -103,7 +103,7 @@ void OffScreenVideoConsumer::OnFrameCapt
 #elif BUILDFLAG(IS_APPLE)
     texture.shared_texture_handle =
         reinterpret_cast<uintptr_t>(gmb_handle.io_surface.get());
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     const auto& native_pixmap = gmb_handle.native_pixmap_handle;
     texture.modifier = native_pixmap.modifier;
     for (const auto& plane : native_pixmap.planes) {
