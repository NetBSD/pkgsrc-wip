$NetBSD$

--- media/audio/alsa/audio_manager_alsa.cc.orig	2016-06-24 01:02:23.000000000 +0000
+++ media/audio/alsa/audio_manager_alsa.cc
@@ -129,7 +129,9 @@ void AudioManagerAlsa::GetAlsaAudioDevic
   int card = -1;
 
   // Loop through the sound cards to get ALSA device hints.
+#ifdef OS_LINUX
   while (!wrapper_->CardNext(&card) && card >= 0) {
+#endif
     void** hints = NULL;
     int error = wrapper_->DeviceNameHint(card, kPcmInterfaceName, &hints);
     if (!error) {
@@ -141,7 +143,9 @@ void AudioManagerAlsa::GetAlsaAudioDevic
       DLOG(WARNING) << "GetAlsaAudioDevices: unable to get device hints: "
                     << wrapper_->StrError(error);
     }
+#ifdef OS_LINUX
   }
+#endif
 }
 
 void AudioManagerAlsa::GetAlsaDevicesInfo(
@@ -227,7 +231,11 @@ bool AudioManagerAlsa::IsAlsaDeviceAvail
     // goes through software conversion if needed (e.g. incompatible
     // sample rate).
     // TODO(joi): Should we prefer "hw" instead?
+#ifdef OS_LINUX
     static const char kDeviceTypeDesired[] = "plughw";
+#else
+    static const char kDeviceTypeDesired[] = "plug";
+#endif
     return strncmp(kDeviceTypeDesired,
                    device_name,
                    arraysize(kDeviceTypeDesired) - 1) == 0;
@@ -251,7 +259,9 @@ bool AudioManagerAlsa::HasAnyAlsaAudioDe
   // Loop through the sound cards.
   // Don't use snd_device_name_hint(-1,..) since there is a access violation
   // inside this ALSA API with libasound.so.2.0.0.
+#ifdef OS_LINUX
   while (!wrapper_->CardNext(&card) && (card >= 0) && !has_device) {
+#endif
     int error = wrapper_->DeviceNameHint(card, kPcmInterfaceName, &hints);
     if (!error) {
       for (void** hint_iter = hints; *hint_iter != NULL; hint_iter++) {
@@ -275,7 +285,9 @@ bool AudioManagerAlsa::HasAnyAlsaAudioDe
       DLOG(WARNING) << "HasAnyAudioDevice: unable to get device hints: "
                     << wrapper_->StrError(error);
     }
+#ifdef OS_LINUX
   }
+#endif
 
   return has_device;
 }
