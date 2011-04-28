$NetBSD: patch-media_audio_openbsd_audio__manager__openbsd.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- media/audio/openbsd/audio_manager_openbsd.cc.orig	2011-04-13 08:01:06.000000000 +0000
+++ media/audio/openbsd/audio_manager_openbsd.cc
@@ -4,21 +4,23 @@
 
 #include "media/audio/openbsd/audio_manager_openbsd.h"
 
+#include "base/command_line.h"
 #include "base/logging.h"
-
-namespace {
-AudioManagerOpenBSD* g_audio_manager = NULL;
-}  // namespace
+#include "media/audio/audio_output_dispatcher.h"
+#include "media/audio/fake_audio_input_stream.h"
+#include "media/audio/fake_audio_output_stream.h"
+#include "media/base/limits.h"
+#include "media/base/media_switches.h"
 
 // Implementation of AudioManager.
 bool AudioManagerOpenBSD::HasAudioOutputDevices() {
   NOTIMPLEMENTED();
-  return false;
+  return true;
 }
 
 bool AudioManagerOpenBSD::HasAudioInputDevices() {
   NOTIMPLEMENTED();
-  return false;
+  return true;
 }
 
 AudioOutputStream* AudioManagerOpenBSD::MakeAudioOutputStream(
@@ -51,6 +53,10 @@ void AudioManagerOpenBSD::UnMuteAll() {
   NOTIMPLEMENTED();
 }
 
+void AudioManagerOpenBSD::ReleaseOutputStream(AlsaPcmOutputStream* stream) {
+  NOTIMPLEMENTED();
+}
+
 // static
 AudioManager* AudioManager::CreateAudioManager() {
   return new AudioManagerOpenBSD();
