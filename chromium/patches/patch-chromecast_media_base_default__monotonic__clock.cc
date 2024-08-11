$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chromecast/media/base/default_monotonic_clock.cc.orig	2024-07-24 02:44:32.416372500 +0000
+++ chromecast/media/base/default_monotonic_clock.cc
@@ -11,7 +11,7 @@
 #include "base/time/time.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chromecast/media/base/buildflags.h"
 #endif  // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -28,7 +28,7 @@ std::unique_ptr<MonotonicClock> Monotoni
   return std::make_unique<DefaultMonotonicClock>();
 }
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 int64_t MonotonicClockNow() {
   timespec now = {0, 0};
 #if BUILDFLAG(MEDIA_CLOCK_MONOTONIC_RAW)
