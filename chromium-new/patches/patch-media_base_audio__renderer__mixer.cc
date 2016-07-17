$NetBSD$

--- media/base/audio_renderer_mixer.cc.orig	2016-06-24 01:02:23.000000000 +0000
+++ media/base/audio_renderer_mixer.cc
@@ -138,7 +138,7 @@ int AudioRendererMixer::Render(AudioBus*
   // expect a count of frames delayed instead of TimeDelta (less precise).
   // See http://crbug.com/587522.
   base::TimeDelta audio_delay = base::TimeDelta::FromMicroseconds(
-      std::round(frames_delayed * output_params_.GetMicrosecondsPerFrame()));
+      round(frames_delayed * output_params_.GetMicrosecondsPerFrame()));
 
   master_converter_.ConvertWithDelay(audio_delay, audio_bus);
   return audio_bus->frames();
