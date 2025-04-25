$NetBSD$

rename kMaxOutputStreams so doesn't clash with one in audio_manager_alsa.cc

--- src/3rdparty/chromium/media/audio/audioio/audio_manager_audioio.cc.orig	2024-11-04 10:01:05.000000000 +0000
+++ src/3rdparty/chromium/media/audio/audioio/audio_manager_audioio.cc
@@ -15,7 +15,7 @@
 namespace media {
 
 // Maximum number of output streams that can be open simultaneously.
-static const int kMaxOutputStreams = 50;
+static const int kMaxOutputStreamsAIO = 50;
 
 // Default sample rate for input and output streams.
 static const int kDefaultSampleRate = 48000;
@@ -66,7 +66,7 @@ AudioManagerAudioIO::AudioManagerAudioIO
     : AudioManagerBase(std::move(audio_thread),
                        audio_log_factory) {
   LOG(INFO) << "[AUDIOIO] AudioManagerAudioIO";
-  SetMaxOutputStreamsAllowed(kMaxOutputStreams);
+  SetMaxOutputStreamsAllowed(kMaxOutputStreamsAIO);
 }
 
 AudioManagerAudioIO::~AudioManagerAudioIO() = default;
@@ -156,4 +156,4 @@ std::unique_ptr<media::AudioManager> Cre
                                               audio_log_factory);
 }
 
-}  // namespace media
\ No newline at end of file
+}  // namespace media
