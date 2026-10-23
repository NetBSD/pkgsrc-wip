$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/service/frame_sinks/video_capture/frame_sink_video_capturer_impl.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ components/viz/service/frame_sinks/video_capture/frame_sink_video_capturer_impl.cc
@@ -1160,7 +1160,7 @@ void FrameSinkVideoCapturerImpl::MaybeCa
   const bool prefer_mappable_shared_image =
       buffer_format_preference_ ==
       mojom::BufferFormatPreference::kPreferMappableSharedImage;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool prefer_shared_image =
       prefer_mappable_shared_image ||
       buffer_format_preference_ ==
@@ -1395,7 +1395,7 @@ void FrameSinkVideoCapturerImpl::DidCopy
         frame_capture.CaptureFailed(CaptureResult::kARGBReadbackFailed);
       }
     } else {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       CHECK(buffer_format_preference_ ==
                 mojom::BufferFormatPreference::kPreferMappableSharedImage ||
             buffer_format_preference_ ==
