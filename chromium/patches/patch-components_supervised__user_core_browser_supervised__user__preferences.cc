$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/supervised_user/core/browser/supervised_user_preferences.cc.orig	2024-08-06 19:52:24.101868600 +0000
+++ components/supervised_user/core/browser/supervised_user_preferences.cc
@@ -153,7 +153,7 @@ void RegisterProfilePrefs(PrefRegistrySi
       static_cast<int>(FirstTimeInterstitialBannerState::kUnknown));
   registry->RegisterBooleanPref(prefs::kChildAccountStatusKnown, false);
 #if BUILDFLAG(ENABLE_EXTENSIONS) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   registry->RegisterIntegerPref(
       prefs::kLocallyParentApprovedExtensionsMigrationState,
       static_cast<int>(
