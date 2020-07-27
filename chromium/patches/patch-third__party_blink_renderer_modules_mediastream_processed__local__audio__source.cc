$NetBSD$

--- third_party/blink/renderer/modules/mediastream/processed_local_audio_source.cc.orig	2020-07-15 18:56:03.000000000 +0000
+++ third_party/blink/renderer/modules/mediastream/processed_local_audio_source.cc
@@ -408,7 +408,7 @@ void ProcessedLocalAudioSource::CaptureU
     bool key_pressed) {
 #if defined(OS_WIN) || defined(OS_MACOSX)
   DCHECK_LE(volume, 1.0);
-#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_OPENBSD)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // We have a special situation on Linux where the microphone volume can be
   // "higher than maximum". The input volume slider in the sound preference
   // allows the user to set a scaling that is higher than 100%. It means that
