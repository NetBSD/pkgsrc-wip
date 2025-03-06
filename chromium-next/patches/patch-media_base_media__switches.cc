$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/base/media_switches.cc.orig	2025-02-25 19:55:16.000000000 +0000
+++ media/base/media_switches.cc
@@ -20,7 +20,7 @@
 #include "ui/gl/gl_features.h"
 #include "ui/gl/gl_utils.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/cpu.h"
 #endif
 
@@ -60,7 +60,7 @@ const char kReportVp9AsAnUnsupportedMime
     "report-vp9-as-an-unsupported-mime-type";
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD) || \
-    BUILDFLAG(IS_SOLARIS)
+    BUILDFLAG(IS_SOLARIS) || BUILDFLAG(IS_NETBSD)
 // The Alsa device to use when opening an audio input stream.
 const char kAlsaInputDevice[] = "alsa-input-device";
 // The Alsa device to use when opening an audio stream.
@@ -371,8 +371,8 @@ BASE_FEATURE(kUseSCContentSharingPicker,
              "UseSCContentSharingPicker",
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_MAC)
-
-#if BUILDFLAG(IS_LINUX)
+ 
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables system audio mirroring using pulseaudio.
 BASE_FEATURE(kPulseaudioLoopbackForCast,
              "PulseaudioLoopbackForCast",
@@ -382,6 +382,31 @@ BASE_FEATURE(kPulseaudioLoopbackForCast,
 BASE_FEATURE(kPulseaudioLoopbackForScreenShare,
              "PulseaudioLoopbackForScreenShare",
              base::FEATURE_DISABLED_BY_DEFAULT);
+
+BASE_FEATURE(kAudioBackend,
+             "AudioBackend",
+             base::FEATURE_ENABLED_BY_DEFAULT);
+
+constexpr base::FeatureParam<AudioBackend>::Option
+    kAudioBackendOptions[] = {
+        {AudioBackend::kAuto,
+         "auto"},
+        {AudioBackend::kAudioIO, "audioio"},
+        {AudioBackend::kPulseAudio, "pulseaudio"},
+        {AudioBackend::kSndio, "sndio"},
+        {AudioBackend::kAlsa, "alsa"}};
+
+const base::FeatureParam<AudioBackend>
+    kAudioBackendParam{
+        &kAudioBackend, "audio-backend",
+#if BUILDFLAG(IS_OPENBSD)
+        AudioBackend::kSndio,
+#elif BUILDFLAG(IS_NETBSD)
+        AudioBackend::kAudioIO,
+#elif BUILDFLAG(IS_FREEBSD)
+        AudioBackend::kAuto,
+#endif
+        &kAudioBackendOptions};
 #endif  // BUILDFLAG(IS_LINUX)
 
 // When enabled, MediaCapabilities will check with GPU Video Accelerator
@@ -624,7 +649,7 @@ BASE_FEATURE(kFileDialogsBlockPictureInP
 // Show toolbar button that opens dialog for controlling media sessions.
 BASE_FEATURE(kGlobalMediaControls,
              "GlobalMediaControls",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -647,7 +672,7 @@ BASE_FEATURE(kGlobalMediaControlsUpdated
 // If enabled, users can request Media Remoting without fullscreen-in-tab.
 BASE_FEATURE(kMediaRemotingWithoutFullscreen,
              "MediaRemotingWithoutFullscreen",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -659,7 +684,7 @@ BASE_FEATURE(kMediaRemotingWithoutFullsc
 BASE_FEATURE(kGlobalMediaControlsPictureInPicture,
              "GlobalMediaControlsPictureInPicture",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -688,7 +713,7 @@ BASE_FEATURE(kUnifiedAutoplay,
              "UnifiedAutoplay",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enable vaapi/v4l2 video decoding on linux. This is already enabled by default
 // on chromeos, but needs an experiment on linux.
 BASE_FEATURE(kAcceleratedVideoDecodeLinux,
@@ -791,7 +816,7 @@ BASE_FEATURE(kVSyncMjpegDecoding,
              "VSyncMjpegDecoding",
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // defined(ARCH_CPU_X86_FAMILY) && BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enable H264 temporal layer encoding with V4L2 HW encoder on ChromeOS.
 BASE_FEATURE(kV4L2H264TemporalLayerHWEncoding,
              "V4L2H264TemporalLayerHWEncoding",
@@ -1357,7 +1382,7 @@ BASE_FEATURE(kUseGTFOOutOfProcessVideoDe
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(ALLOW_OOP_VIDEO_DECODER)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Spawn utility processes to perform hardware encode acceleration instead of
 // using the GPU process.
 BASE_FEATURE(kUseOutOfProcessVideoEncoding,
@@ -1439,7 +1464,7 @@ BASE_FEATURE(kRecordWebAudioEngagement,
              "RecordWebAudioEngagement",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Reduces the number of buffers needed in the output video frame pool to
 // populate the Renderer pipeline for hardware accelerated VideoDecoder in
 // non-low latency scenarios.
