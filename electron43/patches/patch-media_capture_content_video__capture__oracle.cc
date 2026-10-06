$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- media/capture/content/video_capture_oracle.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ media/capture/content/video_capture_oracle.cc
@@ -118,8 +118,9 @@ void VideoCaptureOracle::SetCaptureSizeC
 void VideoCaptureOracle::SetAutoThrottlingEnabled(bool enabled) {
   const bool was_enabled =
       (capture_size_throttling_mode_ != kThrottlingDisabled);
-  if (was_enabled == enabled)
+  if (was_enabled == enabled) {
     return;
+  }
   capture_size_throttling_mode_ =
       enabled ? kThrottlingEnabled : kThrottlingDisabled;
   VLOG(1) << "Capture size auto-throttling is now "
@@ -127,19 +128,22 @@ void VideoCaptureOracle::SetAutoThrottli
 
   // When not auto-throttling, have the CaptureResolutionChooser target the max
   // resolution within constraints.
-  if (!enabled)
+  if (!enabled) {
     resolution_chooser_.SetTargetFrameArea(std::numeric_limits<int>::max());
+  }
 
-  if (next_frame_number_ > 0)
+  if (next_frame_number_ > 0) {
     CommitCaptureSizeAndReset(GetFrameTimestamp(next_frame_number_ - 1));
+  }
 }
 
 void VideoCaptureOracle::SetSourceSize(const gfx::Size& source_size) {
   resolution_chooser_.SetSourceSize(source_size);
   // If the |resolution_chooser_| computed a new capture size, that will become
   // visible via a future call to ObserveEventAndDecideCapture().
-  source_size_change_time_ = (next_frame_number_ == 0) ?
-      base::TimeTicks() : GetFrameTimestamp(next_frame_number_ - 1);
+  source_size_change_time_ = (next_frame_number_ == 0)
+                                 ? base::TimeTicks()
+                                 : GetFrameTimestamp(next_frame_number_ - 1);
 }
 
 bool VideoCaptureOracle::ObserveEventAndDecideCapture(
@@ -172,6 +176,15 @@ bool VideoCaptureOracle::ObserveEventAnd
         if (should_sample) {
           event_time = content_sampler_.frame_timestamp();
           duration_of_next_frame_ = content_sampler_.sampling_period();
+        } else {
+          // https://crbug.com/391118566
+          // The content sampler may not sample the frame, if the
+          // `detected_region_` does not match the `damage_rect`. In this case,
+          // the capture may halt up to kNonAnimatingThreshold (250ms) and cause
+          // the video stutter, until it recovers and do another animation
+          // detection. To avoid this, we should use the smoothing sampler as a
+          // fallback to prevent the bad output.
+          should_sample = smoothing_sampler_.ShouldSample();
         }
         last_time_animation_was_detected_ = event_time;
       } else {
@@ -198,8 +211,9 @@ bool VideoCaptureOracle::ObserveEventAnd
       NOTREACHED();
   }
 
-  if (!should_sample)
+  if (!should_sample) {
     return false;
+  }
 
   // If the exact duration of the next frame has not been determined, estimate
   // it using the difference between the current and last frame.
@@ -373,16 +387,18 @@ void VideoCaptureOracle::RecordConsumerF
 
   // resource_utilization feedback.
 
-  if (capture_size_throttling_mode_ == kThrottlingDisabled)
+  if (capture_size_throttling_mode_ == kThrottlingDisabled) {
     return;
+  }
 
   if (!std::isfinite(feedback.resource_utilization)) {
     LOG(DFATAL) << "Non-finite utilization provided by consumer for frame #"
                 << frame_number << ": " << feedback.resource_utilization;
     return;
   }
-  if (feedback.resource_utilization <= 0.0)
+  if (feedback.resource_utilization <= 0.0) {
     return;  // Non-positive values are normal, meaning N/A.
+  }
 
   if (capture_size_throttling_mode_ != kThrottlingActive) {
     VLOG(1) << "Received consumer feedback at frame #" << frame_number
@@ -553,12 +569,14 @@ int VideoCaptureOracle::AnalyzeForIncrea
   const int current_area = capture_size_.GetArea();
   const int increased_area =
       resolution_chooser_.FindLargerFrameSize(current_area, 1).GetArea();
-  if (increased_area <= current_area)
+  if (increased_area <= current_area) {
     return -1;
+  }
 
   // Determine whether the buffer pool could handle an increase in area.
-  if (!HasSufficientRecentFeedback(buffer_pool_utilization_, analyze_time))
+  if (!HasSufficientRecentFeedback(buffer_pool_utilization_, analyze_time)) {
     return -1;
+  }
   if (buffer_pool_utilization_.current() > 0.0) {
     const int buffer_capable_area = base::saturated_cast<int>(
         current_area / buffer_pool_utilization_.current());
@@ -593,8 +611,9 @@ int VideoCaptureOracle::AnalyzeForIncrea
 
   // At this point, the system is currently under-utilized.  Reset the start
   // time if the system was not under-utilized when the last analysis was made.
-  if (start_time_of_underutilization_.is_null())
+  if (start_time_of_underutilization_.is_null()) {
     start_time_of_underutilization_ = analyze_time;
+  }
 
   // If the under-utilization started soon after the last source size change,
   // permit an immediate increase in the capture area.  This allows the system
