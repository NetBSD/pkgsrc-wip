$NetBSD: patch-media_audio_openbsd_audio__manager__openbsd.cc,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- media/audio/openbsd/audio_manager_openbsd.cc.orig	2011-05-24 08:01:03.000000000 +0000
+++ media/audio/openbsd/audio_manager_openbsd.cc
@@ -4,9 +4,13 @@
 
 #include "media/audio/openbsd/audio_manager_openbsd.h"
 
+#include "base/command_line.h"
 #include "base/logging.h"
-
-static AudioManagerOpenBSD* g_audio_manager = NULL;
+#include "media/audio/audio_output_dispatcher.h"
+#include "media/audio/fake_audio_input_stream.h"
+#include "media/audio/fake_audio_output_stream.h"
+#include "media/base/limits.h"
+#include "media/base/media_switches.h"
 
 // Implementation of AudioManager.
 bool AudioManagerOpenBSD::HasAudioOutputDevices() {
@@ -49,6 +53,10 @@ void AudioManagerOpenBSD::UnMuteAll() {
   NOTIMPLEMENTED();
 }
 
+void AudioManagerOpenBSD::ReleaseOutputStream(AlsaPcmOutputStream* stream) {
+  NOTIMPLEMENTED();
+}
+
 // static
 AudioManager* AudioManager::CreateAudioManager() {
   return new AudioManagerOpenBSD();
