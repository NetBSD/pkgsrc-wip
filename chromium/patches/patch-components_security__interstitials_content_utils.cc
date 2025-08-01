$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/security_interstitials/content/utils.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ components/security_interstitials/content/utils.cc
@@ -37,7 +37,7 @@ void LaunchDateAndTimeSettings() {
 #if BUILDFLAG(IS_ANDROID)
   JNIEnv* env = base::android::AttachCurrentThread();
   Java_DateAndTimeSettingsHelper_openDateAndTimeSettings(env);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   struct ClockCommand {
     const char* const pathname;
     const char* const argument;
