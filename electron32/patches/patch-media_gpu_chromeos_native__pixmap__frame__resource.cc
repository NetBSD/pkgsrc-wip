$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- media/gpu/chromeos/native_pixmap_frame_resource.cc.orig	2024-10-18 12:34:28.091610400 +0000
+++ media/gpu/chromeos/native_pixmap_frame_resource.cc
@@ -176,7 +176,7 @@ scoped_refptr<NativePixmapFrameResource>
   const bool is_intel_media_compression_enabled =
 #if BUILDFLAG(IS_CHROMEOS)
       base::FeatureList::IsEnabled(features::kEnableIntelMediaCompression);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       false;
 #endif
   CHECK(!is_intel_media_compressed_buffer ||
