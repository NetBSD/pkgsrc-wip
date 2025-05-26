$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/supervised_user/core/browser/supervised_user_preferences.cc.orig	2025-02-24 19:59:26.000000000 +0000
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
