$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/supervised_user/core/browser/supervised_user_preferences.cc.orig	2025-01-07 19:49:01.000000000 +0000
+++ components/supervised_user/core/browser/supervised_user_preferences.cc
@@ -147,7 +147,7 @@ void RegisterProfilePrefs(PrefRegistrySi
       prefs::kFamilyLinkUserState,
       static_cast<int>(FamilyLinkUserState::kUnknown));
 #if BUILDFLAG(ENABLE_EXTENSIONS) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   registry->RegisterIntegerPref(
       prefs::kLocallyParentApprovedExtensionsMigrationState,
       static_cast<int>(
