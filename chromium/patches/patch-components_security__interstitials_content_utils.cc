$NetBSD: patch-components_security__interstitials_content_utils.cc,v 1.1 2025/02/06 09:58:02 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/security_interstitials/content/utils.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/security_interstitials/content/utils.cc
@@ -38,7 +38,7 @@ void LaunchDateAndTimeSettings() {
 #if BUILDFLAG(IS_ANDROID)
   JNIEnv* env = base::android::AttachCurrentThread();
   Java_DateAndTimeSettingsHelper_openDateAndTimeSettings(env);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   struct ClockCommand {
     const char* const pathname;
     const char* const argument;
