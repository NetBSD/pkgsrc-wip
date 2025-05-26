$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- media/capture/content/video_capture_oracle_unittest.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ media/capture/content/video_capture_oracle_unittest.cc
@@ -158,21 +158,26 @@ TEST(VideoCaptureOracleTest, Transitions
     const bool provide_animated_content_event =
         (i % 100) >= 25 && (i % 100) < 75;
 
-    // Only the few events that trigger the lock-out transition should be
-    // dropped, because the AnimatedContentSampler doesn't yet realize the
-    // animation ended.  Otherwise, the oracle should always decide to sample
-    // because one of its samplers says to.
-    const bool require_oracle_says_sample = (i % 100) < 75 || (i % 100) >= 78;
+    // https://crbug.com/391118566
+    // Previously the AnimatedContentSampler has a bug that cause jank.
+    // The oracle should always use SmoothEventSampler as a fallback. If
+    // AnimatedContentSampler doesn't yet realize the animation ended or
+    // doesn't keep up with the prediction it make, and it will wait for
+    // kNonAnimatingThreshold before it lock-out and hand over to smooth
+    // handler. This will cause the video to stutter and it is unacceptable.
+    // So, when the AnimatedContentSampler goes into wrong state, we now
+    // use SmoothEventSampler's decision as a fallback to prevent jank output
+    // and still has a overall limit on capture frequency.
     const bool oracle_says_sample = oracle.ObserveEventAndDecideCapture(
         VideoCaptureOracle::kCompositorUpdate,
         provide_animated_content_event ? animation_damage_rect : gfx::Rect(),
         t);
-    if (require_oracle_says_sample)
-      ASSERT_TRUE(oracle_says_sample);
-    if (!oracle_says_sample) {
-      ASSERT_EQ(base::TimeDelta(), oracle.estimated_frame_duration());
-      continue;
-    }
+
+    // Because we now use SmoothEventSampler as a fallback, oracle should
+    // always say sample. The previous AnimatedContentSampler lock-out
+    // dropped frame are now revived by SmoothEventSampler, since this test's
+    // capture frequency always meets min capture limit requirement.
+    ASSERT_TRUE(oracle_says_sample);
     ASSERT_LT(base::TimeDelta(), oracle.estimated_frame_duration());
 
     const int frame_number = oracle.next_frame_number();
@@ -184,12 +189,9 @@ TEST(VideoCaptureOracleTest, Transitions
     if (!last_frame_timestamp.is_null()) {
       const base::TimeDelta delta = frame_timestamp - last_frame_timestamp;
       EXPECT_LE(event_increment.InMicroseconds(), delta.InMicroseconds());
-      // Right after the AnimatedContentSampler lock-out transition, there were
-      // a few frames dropped, so allow a gap in the timestamps.  Otherwise, the
-      // delta between frame timestamps should never be more than 2X the
+      // The delta between frame timestamps should never be more than 2X the
       // |event_increment|.
-      const base::TimeDelta max_acceptable_delta =
-          (i % 100) == 78 ? event_increment * 5 : event_increment * 2;
+      const base::TimeDelta max_acceptable_delta = event_increment * 2;
       EXPECT_GE(max_acceptable_delta.InMicroseconds(), delta.InMicroseconds());
     }
     last_frame_timestamp = frame_timestamp;
@@ -444,9 +446,9 @@ void RunAutoThrottleTest(bool is_content
   // expect the resolution to remain constant.  Repeat.
   for (int i = 0; i < 2; ++i) {
     const gfx::Size starting_size = oracle.capture_size();
-    SCOPED_TRACE(::testing::Message() << "Stepping down from "
-                                      << starting_size.ToString()
-                                      << ", i=" << i);
+    SCOPED_TRACE(::testing::Message()
+                 << "Stepping down from " << starting_size.ToString()
+                 << ", i=" << i);
 
     gfx::Size stepped_down_size;
     end_t = t + base::Seconds(10);
@@ -471,9 +473,10 @@ void RunAutoThrottleTest(bool is_content
       oracle.RecordCapture(with_consumer_feedback ? 0.25 : utilization);
       base::TimeTicks ignored;
       ASSERT_TRUE(oracle.CompleteCapture(frame_number, true, &ignored));
-      if (with_consumer_feedback)
+      if (with_consumer_feedback) {
         oracle.RecordConsumerFeedback(frame_number,
                                       media::VideoCaptureFeedback(utilization));
+      }
     }
   }
 
@@ -482,9 +485,9 @@ void RunAutoThrottleTest(bool is_content
   // utilization and expect the resolution to remain constant.  Repeat.
   for (int i = 0; i < 2; ++i) {
     const gfx::Size starting_size = oracle.capture_size();
-    SCOPED_TRACE(::testing::Message() << "Stepping up from "
-                                      << starting_size.ToString()
-                                      << ", i=" << i);
+    SCOPED_TRACE(::testing::Message()
+                 << "Stepping up from " << starting_size.ToString()
+                 << ", i=" << i);
 
     gfx::Size stepped_up_size;
     end_t = t + base::Seconds(is_content_animating ? 90 : 10);
@@ -513,9 +516,10 @@ void RunAutoThrottleTest(bool is_content
       oracle.RecordCapture(with_consumer_feedback ? 0.25 : utilization);
       base::TimeTicks ignored;
       ASSERT_TRUE(oracle.CompleteCapture(frame_number, true, &ignored));
-      if (with_consumer_feedback)
+      if (with_consumer_feedback) {
         oracle.RecordConsumerFeedback(frame_number,
                                       media::VideoCaptureFeedback(utilization));
+      }
     }
   }
 }
