$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/audio/alsa/audio_manager_alsa.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/media/audio/alsa/audio_manager_alsa.cc
@@ -88,7 +88,9 @@ void AudioManagerAlsa::GetAlsaAudioDevic
   int card = -1;
 
   // Loop through the sound cards to get ALSA device hints.
+#if !BUILDFLAG(IS_BSD) 
   while (!wrapper_->CardNext(&card) && card >= 0) {
+#endif
     void** hints = NULL;
     int error = wrapper_->DeviceNameHint(card, kPcmInterfaceName, &hints);
     if (!error) {
@@ -100,7 +102,9 @@ void AudioManagerAlsa::GetAlsaAudioDevic
       DLOG(WARNING) << "GetAlsaAudioDevices: unable to get device hints: "
                     << wrapper_->StrError(error);
     }
+#if !BUILDFLAG(IS_BSD) 
   }
+#endif
 }
 
 void AudioManagerAlsa::GetAlsaDevicesInfo(AudioManagerAlsa::StreamType type,
@@ -183,7 +187,11 @@ bool AudioManagerAlsa::IsAlsaDeviceAvail
   // goes through software conversion if needed (e.g. incompatible
   // sample rate).
   // TODO(joi): Should we prefer "hw" instead?
+#if BUILDFLAG(IS_BSD)
+  static const char kDeviceTypeDesired[] = "plug";
+#else
   static const char kDeviceTypeDesired[] = "plughw";
+#endif
   return strncmp(kDeviceTypeDesired, device_name,
                  std::size(kDeviceTypeDesired) - 1) == 0;
 }
@@ -205,7 +213,9 @@ bool AudioManagerAlsa::HasAnyAlsaAudioDe
   // Loop through the sound cards.
   // Don't use snd_device_name_hint(-1,..) since there is an access violation
   // inside this ALSA API with libasound.so.2.0.0.
+#if !BUILDFLAG(IS_BSD)
   while (!wrapper_->CardNext(&card) && (card >= 0) && !has_device) {
+#endif
     int error = wrapper_->DeviceNameHint(card, kPcmInterfaceName, &hints);
     if (!error) {
       for (void** hint_iter = hints; *hint_iter != NULL; hint_iter++) {
@@ -229,7 +239,9 @@ bool AudioManagerAlsa::HasAnyAlsaAudioDe
       DLOG(WARNING) << "HasAnyAudioDevice: unable to get device hints: "
                     << wrapper_->StrError(error);
     }
+#if !BUILDFLAG(IS_BSD)
   }
+#endif
 
   return has_device;
 }
