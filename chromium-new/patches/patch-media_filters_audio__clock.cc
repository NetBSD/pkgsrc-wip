$NetBSD$

--- media/filters/audio_clock.cc.orig	2016-06-24 01:02:23.000000000 +0000
+++ media/filters/audio_clock.cc
@@ -121,7 +121,7 @@ base::TimeDelta AudioClock::TimeUntilPla
   }
 
   return base::TimeDelta::FromMicroseconds(
-      std::round(frames_until_timestamp * microseconds_per_frame_));
+      round(frames_until_timestamp * microseconds_per_frame_));
 }
 
 void AudioClock::ContiguousAudioDataBufferedForTesting(
