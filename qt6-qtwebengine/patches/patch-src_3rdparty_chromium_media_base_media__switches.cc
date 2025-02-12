$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/base/media_switches.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/media/base/media_switches.cc
@@ -21,7 +21,7 @@
 #include "ui/gl/gl_features.h"
 #include "ui/gl/gl_utils.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/cpu.h"
 #endif
 
@@ -61,7 +61,7 @@ const char kReportVp9AsAnUnsupportedMime
     "report-vp9-as-an-unsupported-mime-type";
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD) || \
-    BUILDFLAG(IS_SOLARIS)
+    BUILDFLAG(IS_SOLARIS) || BUILDFLAG(IS_NETBSD)
 // The Alsa device to use when opening an audio input stream.
 const char kAlsaInputDevice[] = "alsa-input-device";
 // The Alsa device to use when opening an audio stream.
@@ -370,7 +370,7 @@ BASE_FEATURE(kMacLoopbackAudioForScreenS
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables system audio mirroring using pulseaudio.
 BASE_FEATURE(kPulseaudioLoopbackForCast,
              "PulseaudioLoopbackForCast",
@@ -380,6 +380,31 @@ BASE_FEATURE(kPulseaudioLoopbackForCast,
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
@@ -608,7 +633,7 @@ BASE_FEATURE(kUseWritePixelsYUV,
 // Enables creating single shared image and mailbox for multi-planar formats for
 // hardware video decoders.
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FUCHSIA) || \
-    BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kUseMultiPlaneFormatForHardwareVideo,
              "UseMultiPlaneFormatForHardwareVideo",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -719,7 +744,7 @@ BASE_FEATURE(kFallbackAfterDecodeError,
              base::FEATURE_ENABLED_BY_DEFAULT);
 
 // Show toolbar button that opens dialog for controlling media sessions.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kGlobalMediaControls,
              "GlobalMediaControls",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -743,7 +768,7 @@ BASE_FEATURE(kGlobalMediaControlsCrOSUpd
 
 #if !BUILDFLAG(IS_ANDROID)
 // If enabled, users can request Media Remoting without fullscreen-in-tab.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kMediaRemotingWithoutFullscreen,
              "MediaRemotingWithoutFullscreen",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -756,7 +781,7 @@ BASE_FEATURE(kMediaRemotingWithoutFullsc
 
 // Show picture-in-picture button in Global Media Controls.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kGlobalMediaControlsPictureInPicture,
              "GlobalMediaControlsPictureInPicture",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -788,7 +813,7 @@ BASE_FEATURE(kUnifiedAutoplay,
              "UnifiedAutoplay",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enable vaapi video decoding on linux. This is already enabled by default on
 // chromeos, but needs an experiment on linux.
 BASE_FEATURE(kVaapiVideoDecodeLinux,
@@ -981,7 +1006,7 @@ BASE_FEATURE(kLiveCaptionUseWaitK,
              base::FEATURE_DISABLED_BY_DEFAULT);
 
 // Live Caption can be used in multiple languages, as opposed to just English.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kLiveCaptionMultiLanguage,
              "LiveCaptionMultiLanguage",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -1455,7 +1480,7 @@ BASE_FEATURE(kUseOutOfProcessVideoDecodi
 #endif
 #endif  // BUILDFLAG(ALLOW_OOP_VIDEO_DECODER)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Spawn utility processes to perform hardware encode acceleration instead of
 // using the GPU process.
 BASE_FEATURE(kUseOutOfProcessVideoEncoding,
