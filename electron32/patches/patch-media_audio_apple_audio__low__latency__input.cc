$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- media/audio/apple/audio_low_latency_input.cc.orig	2024-10-18 12:34:27.511887600 +0000
+++ media/audio/apple/audio_low_latency_input.cc
@@ -34,19 +34,23 @@
 
 namespace {
 extern "C" {
+#if !IS_MAS_BUILD()
 // See:
 // https://trac.webkit.org/browser/webkit/trunk/Source/WebCore/PAL/pal/spi/cf/CoreAudioSPI.h?rev=228264
 OSStatus AudioDeviceDuck(AudioDeviceID inDevice,
                          Float32 inDuckedLevel,
                          const AudioTimeStamp* __nullable inStartTime,
                          Float32 inRampDuration) __attribute__((weak_import));
+#endif
 }
 
 void UndoDucking(AudioDeviceID output_device_id) {
+#if !IS_MAS_BUILD()
   if (AudioDeviceDuck != nullptr) {
     // Ramp the volume back up over half a second.
     AudioDeviceDuck(output_device_id, 1.0, nullptr, 0.5);
   }
+#endif
 }
 }  // namespace
 #endif
