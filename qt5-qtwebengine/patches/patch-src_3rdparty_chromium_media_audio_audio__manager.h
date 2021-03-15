$NetBSD$

--- src/3rdparty/chromium/media/audio/audio_manager.h.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/media/audio/audio_manager.h
@@ -60,7 +60,7 @@ class MEDIA_EXPORT AudioManager {
   static std::unique_ptr<AudioManager> CreateForTesting(
       std::unique_ptr<AudioThread> audio_thread);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Sets the name of the audio source as seen by external apps. Only actually
   // used with PulseAudio and MPRIS as of this writing.
   static void SetGlobalAppName(const std::string& app_name);
