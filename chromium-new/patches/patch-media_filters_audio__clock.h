$NetBSD$

--- media/filters/audio_clock.h.orig	2016-06-24 01:02:23.000000000 +0000
+++ media/filters/audio_clock.h
@@ -92,11 +92,11 @@ class MEDIA_EXPORT AudioClock {
   //                                             1000 + 500 + 250 = 1750 ms.
   base::TimeDelta front_timestamp() const {
     return base::TimeDelta::FromMicroseconds(
-        std::round(front_timestamp_micros_));
+        round(front_timestamp_micros_));
   }
   base::TimeDelta back_timestamp() const {
     return base::TimeDelta::FromMicroseconds(
-        std::round(back_timestamp_micros_));
+        round(back_timestamp_micros_));
   }
 
   // Returns the amount of wall time until |timestamp| will be played by the
