$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- media/capture/video_capture_types.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ media/capture/video_capture_types.h
@@ -355,6 +355,8 @@ struct CAPTURE_EXPORT VideoCaptureParams
   // Flag indicating whether HiDPI mode should be enabled for tab capture
   // sessions.
   bool is_high_dpi_enabled = true;
+
+  std::optional<bool> use_native_picker;
 };
 
 CAPTURE_EXPORT std::ostream& operator<<(
