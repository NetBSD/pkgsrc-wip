$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/signin/public/base/signin_switches.cc.orig	2024-07-24 02:44:35.496671000 +0000
+++ components/signin/public/base/signin_switches.cc
@@ -129,11 +129,11 @@ bool IsExplicitBrowserSigninUIOnDesktopE
 }
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 
 // Desktop and Android are being launched (enabled by default), iOS is pending.
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #define MINOR_MODE_FEATURE_DEFAULT_STATUS base::FEATURE_ENABLED_BY_DEFAULT
 #else
 #define MINOR_MODE_FEATURE_DEFAULT_STATUS base::FEATURE_DISABLED_BY_DEFAULT
@@ -147,7 +147,7 @@ constexpr int kMinorModeRestrictionsFetc
 #if BUILDFLAG(IS_ANDROID)
     // Based on Signin.AccountCapabilities.UserVisibleLatency
     1000;
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     // Based on Signin.SyncOptIn.PreSyncConfirmationLatency
     1000;
 #elif BUILDFLAG(IS_IOS)
