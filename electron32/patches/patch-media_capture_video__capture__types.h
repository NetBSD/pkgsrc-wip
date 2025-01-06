$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- media/capture/video_capture_types.h.orig	2024-10-18 12:34:27.819740300 +0000
+++ media/capture/video_capture_types.h
@@ -355,6 +355,8 @@ struct CAPTURE_EXPORT VideoCaptureParams
   // Flag indicating whether HiDPI mode should be enabled for tab capture
   // sessions.
   bool is_high_dpi_enabled = true;
+
+  std::optional<bool> use_native_picker;
 };
 
 CAPTURE_EXPORT std::ostream& operator<<(
