$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- media/audio/mac/audio_manager_mac.cc.orig	2024-10-18 12:34:27.535876000 +0000
+++ media/audio/mac/audio_manager_mac.cc
@@ -971,7 +971,7 @@ AudioParameters AudioManagerMac::GetPref
 
 void AudioManagerMac::InitializeOnAudioThread() {
   DCHECK(GetTaskRunner()->BelongsToCurrentThread());
-  InitializeCoreAudioDispatchOverride();
+  // InitializeCoreAudioDispatchOverride();
   power_observer_ = std::make_unique<AudioPowerObserver>();
 }
 
