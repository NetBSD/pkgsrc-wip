$NetBSD: patch-chrome_common_chrome__features.cc,v 1.1 2025/02/06 09:57:57 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/chrome_features.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/common/chrome_features.cc
@@ -83,7 +83,7 @@ BASE_FEATURE(kUseAdHocSigningForWebAppSh
 #endif  // BUILDFLAG(IS_MAC)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables or disables the Autofill survey triggered by opening a prompt to
 // save address info.
 BASE_FEATURE(kAutofillAddressSurvey,
@@ -101,7 +101,7 @@ BASE_FEATURE(kAutofillPasswordSurvey,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables the Restart background mode optimization. When all Chrome UI is
 // closed and it goes in the background, allows to restart the browser to
 // discard memory.
@@ -273,7 +273,7 @@ BASE_FEATURE(kDesktopPWAsElidedExtension
 BASE_FEATURE(kDesktopPWAsRunOnOsLogin,
              "DesktopPWAsRunOnOsLogin",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -305,7 +305,7 @@ BASE_FEATURE(kDesktopPWAsTabStripSetting
              "DesktopPWAsTabStripSettings",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Controls whether Chrome Apps are supported. See https://crbug.com/1221251.
 // If the feature is disabled, Chrome Apps continue to work. If enabled, Chrome
 // Apps will not launch and will be marked in the UI as deprecated.
@@ -867,7 +867,7 @@ BASE_FEATURE(kKAnonymityServiceStorage,
              "KAnonymityServiceStorage",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kLinuxLowMemoryMonitor,
              "LinuxLowMemoryMonitor",
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -880,7 +880,7 @@ constexpr base::FeatureParam<int> kLinux
     &kLinuxLowMemoryMonitor, "critical_level", 255};
 #endif  // BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kListWebAppsSwitch,
              "ListWebAppsSwitch",
              base::FEATURE_DISABLED_BY_DEFAULT);
