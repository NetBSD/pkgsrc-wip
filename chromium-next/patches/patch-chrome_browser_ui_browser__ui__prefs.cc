$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser_ui_prefs.cc.orig	2025-03-20 19:11:33.000000000 +0000
+++ chrome/browser/ui/browser_ui_prefs.cc
@@ -71,7 +71,7 @@ void RegisterBrowserPrefs(PrefRegistrySi
   registry->RegisterIntegerPref(prefs::kDefaultBrowserDeclinedCount, 0);
   registry->RegisterTimePref(prefs::kDefaultBrowserFirstShownTime,
                              base::Time());
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   registry->RegisterStringPref(prefs::kEnterpriseCustomLabelForBrowser,
                                std::string());
   registry->RegisterStringPref(prefs::kEnterpriseLogoUrlForBrowser,
@@ -184,7 +184,7 @@ void RegisterBrowserUserPrefs(user_prefs
   registry->RegisterDictionaryPref(prefs::kHttpsUpgradeFallbacks);
   registry->RegisterDictionaryPref(prefs::kHttpsUpgradeNavigations);
   registry->RegisterBooleanPref(prefs::kHttpsOnlyModeAutoEnabled, false);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   registry->RegisterStringPref(prefs::kEnterpriseLogoUrlForProfile,
                                std::string());
   registry->RegisterStringPref(prefs::kEnterpriseCustomLabelForProfile,
