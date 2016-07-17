$NetBSD$

--- media/audio/audio_output_device.cc.orig	2016-06-24 01:02:23.000000000 +0000
+++ media/audio/audio_output_device.cc
@@ -426,7 +426,7 @@ void AudioOutputDevice::AudioThreadCallb
   // frames, and ask client to render audio.  Since |output_bus_| is wrapping
   // the shared memory the Render() call is writing directly into the shared
   // memory.
-  render_callback_->Render(output_bus_.get(), std::round(frames_delayed),
+  render_callback_->Render(output_bus_.get(), round(frames_delayed),
                            frames_skipped);
 }
 
