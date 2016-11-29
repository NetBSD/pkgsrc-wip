$NetBSD$

--- media/base/audio_splicer.cc.orig	2016-11-10 20:02:15.000000000 +0000
+++ media/base/audio_splicer.cc
@@ -167,7 +167,7 @@ bool AudioStreamSanitizer::AddInput(cons
       output_timestamp_helper_.GetTimestamp();
   const base::TimeDelta delta = timestamp - expected_timestamp;
 
-  if (std::abs(delta.InMilliseconds()) >
+  if (std::labs(delta.InMilliseconds()) >
       AudioSplicer::kMaxTimeDeltaInMilliseconds) {
     MEDIA_LOG(ERROR, media_log_)
         << "Audio splicing failed: coded frame timestamp differs from "
@@ -183,7 +183,7 @@ bool AudioStreamSanitizer::AddInput(cons
   if (!delta.is_zero())
     frames_to_fill = output_timestamp_helper_.GetFramesToTarget(timestamp);
 
-  if (frames_to_fill == 0 || std::abs(frames_to_fill) < kMinGapSize) {
+  if (frames_to_fill == 0 || std::labs(frames_to_fill) < kMinGapSize) {
     AddOutputBuffer(input);
     return true;
   }
