$NetBSD$

--- third_party/webrtc/modules/video_coding/receiver.cc.orig	2016-11-10 20:03:06.000000000 +0000
+++ third_party/webrtc/modules/video_coding/receiver.cc
@@ -165,8 +165,8 @@ VCMEncodedFrame* VCMReceiver::FrameForDe
   // Assume that render timing errors are due to changes in the video stream.
   if (render_time_ms < 0) {
     timing_error = true;
-  } else if (std::abs(render_time_ms - now_ms) > max_video_delay_ms_) {
-    int frame_delay = static_cast<int>(std::abs(render_time_ms - now_ms));
+  } else if (std::labs(render_time_ms - now_ms) > max_video_delay_ms_) {
+    int frame_delay = static_cast<int>(std::labs(render_time_ms - now_ms));
     LOG(LS_WARNING) << "A frame about to be decoded is out of the configured "
                     << "delay bounds (" << frame_delay << " > "
                     << max_video_delay_ms_
