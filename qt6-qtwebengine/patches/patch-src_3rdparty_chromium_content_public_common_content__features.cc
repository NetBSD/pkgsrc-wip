$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/public/common/content_features.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/content/public/common/content_features.cc
@@ -37,7 +37,7 @@ BASE_FEATURE(kAudioServiceLaunchOnStartu
 
 // Runs the audio service in a separate process.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
 BASE_FEATURE(kAudioServiceOutOfProcess,
              "AudioServiceOutOfProcess",
              // TODO(crbug.com/1052397): Remove !IS_CHROMEOS_LACROS once lacros
@@ -670,7 +670,7 @@ BASE_FEATURE(kOverscrollHistoryNavigatio
              base::FEATURE_ENABLED_BY_DEFAULT);
 
 // Setting to control overscroll history navigation.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kOverscrollHistoryNavigationSetting,
              "OverscrollHistoryNavigationSetting",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -1220,7 +1220,7 @@ BASE_FEATURE(kWebAssemblyTiering,
 
 // Enable WebAssembly trap handler.
 #if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-      BUILDFLAG(IS_MAC)) &&                                                 \
+      BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)) &&                            \
      defined(ARCH_CPU_X86_64)) ||                                           \
     (BUILDFLAG(IS_MAC) && defined(ARCH_CPU_ARM64))
 BASE_FEATURE(kWebAssemblyTrapHandler,
@@ -1265,7 +1265,11 @@ BASE_FEATURE(kWebUICodeCache,
 
 // Controls whether the WebUSB API is enabled:
 // https://wicg.github.io/webusb
+#if BUILDFLAG(IS_BSD)
+BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_DISABLED_BY_DEFAULT);
+#else
 BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_ENABLED_BY_DEFAULT);
+#endif
 
 // Controls whether the WebXR Device API is enabled.
 BASE_FEATURE(kWebXr, "WebXR", base::FEATURE_ENABLED_BY_DEFAULT);
