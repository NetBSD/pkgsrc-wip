$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/services/speech/audio_source_fetcher_impl.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ chrome/services/speech/audio_source_fetcher_impl.cc
@@ -132,7 +132,7 @@ void AudioSourceFetcherImpl::Start(
 
   // TODO(crbug.com/40753481): Check implementation / sandbox policy on Mac and
   // Windows.
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   is_started_ = true;
   // Initialize the AudioCapturerSource with |this| as the CaptureCallback,
   // get the parameters for the device ID, then start audio capture.
