$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/chromeos/native_pixmap_frame_resource.cc.orig	2024-07-24 02:44:41.165220000 +0000
+++ media/gpu/chromeos/native_pixmap_frame_resource.cc
@@ -154,7 +154,7 @@ scoped_refptr<NativePixmapFrameResource>
   const bool is_intel_media_compression_enabled =
 #if BUILDFLAG(IS_CHROMEOS)
       base::FeatureList::IsEnabled(features::kEnableIntelMediaCompression);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       false;
 #endif
   CHECK(!is_intel_media_compressed_buffer ||
