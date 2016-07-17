$NetBSD$

--- media/audio/audio_output_stream_sink.cc.orig	2016-06-24 01:02:23.000000000 +0000
+++ media/audio/audio_output_stream_sink.cc
@@ -85,7 +85,7 @@ int AudioOutputStreamSink::OnMoreData(Au
   if (!active_render_callback_)
     return 0;
 
-  uint32_t frames_delayed = std::round(static_cast<double>(total_bytes_delay) /
+  uint32_t frames_delayed = round(static_cast<double>(total_bytes_delay) /
                                        active_params_.GetBytesPerFrame());
 
   return active_render_callback_->Render(dest, frames_delayed, frames_skipped);
