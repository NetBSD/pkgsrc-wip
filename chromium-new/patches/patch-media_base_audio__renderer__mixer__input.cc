$NetBSD$

--- media/base/audio_renderer_mixer_input.cc.orig	2016-06-24 01:02:23.000000000 +0000
+++ media/base/audio_renderer_mixer_input.cc
@@ -164,7 +164,7 @@ double AudioRendererMixerInput::ProvideI
   // TODO(chcunningham): Delete this conversion and change ProvideInput to more
   // precisely describe delay as a count of frames delayed instead of TimeDelta.
   // See http://crbug.com/587522.
-  uint32_t frames_delayed = std::round(buffer_delay.InMicroseconds() /
+  uint32_t frames_delayed = round(buffer_delay.InMicroseconds() /
                                        params_.GetMicrosecondsPerFrame());
 
   int frames_filled = callback_->Render(audio_bus, frames_delayed, 0);
