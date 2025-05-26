$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- media/audio/apple/audio_low_latency_input.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ media/audio/apple/audio_low_latency_input.cc
@@ -28,6 +28,7 @@
 #include "base/strings/sys_string_conversions.h"
 #include "base/time/time.h"
 #include "base/trace_event/trace_event.h"
+#include "electron/mas.h"
 #include "media/audio/apple/audio_manager_apple.h"
 #include "media/audio/apple/scoped_audio_unit.h"
 #include "media/base/audio_bus.h"
@@ -39,19 +40,23 @@
 
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
