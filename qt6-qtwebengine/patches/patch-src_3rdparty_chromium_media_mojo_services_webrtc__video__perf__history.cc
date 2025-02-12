$NetBSD$

--- src/3rdparty/chromium/media/mojo/services/webrtc_video_perf_history.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/media/mojo/services/webrtc_video_perf_history.cc
@@ -169,7 +169,7 @@ bool AreVideoStatsInvalid(const media::m
          video_stats.frames_processed >
              WebrtcVideoStatsDB::kFramesProcessedMaxValue ||
          video_stats.key_frames_processed > video_stats.frames_processed ||
-         isnan(video_stats.p99_processing_time_ms) ||
+         std::isnan(video_stats.p99_processing_time_ms) ||
          video_stats.p99_processing_time_ms <
              WebrtcVideoStatsDB::kP99ProcessingTimeMinValueMs ||
          video_stats.p99_processing_time_ms >
