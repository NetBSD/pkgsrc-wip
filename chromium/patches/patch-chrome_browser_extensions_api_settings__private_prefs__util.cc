$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/settings_private/prefs_util.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ chrome/browser/extensions/api/settings_private/prefs_util.cc
@@ -196,7 +196,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil
   (*s_allowlist)[autofill::prefs::kAutofillPaymentCardBenefits] =
       settings_api::PrefType::kBoolean;
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   (*s_allowlist)[autofill::prefs::kAutofillBnplEnabled] =
       settings_api::PrefType::kBoolean;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
@@ -214,7 +214,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil
   (*s_allowlist)[tab_groups::prefs::kAutoPinNewTabGroups] =
       settings_api::PrefType::kBoolean;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   (*s_allowlist)[::prefs::kUseCustomChromeFrame] =
       settings_api::PrefType::kBoolean;
 #endif
@@ -228,7 +228,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil
   (*s_allowlist)[::prefs::kCurrentThemeID] = settings_api::PrefType::kString;
   (*s_allowlist)[::prefs::kPinnedActions] = settings_api::PrefType::kList;
   (*s_allowlist)[::prefs::kPolicyThemeColor] = settings_api::PrefType::kNumber;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   (*s_allowlist)[::prefs::kSystemTheme] = settings_api::PrefType::kNumber;
 #endif
   (*s_allowlist)[::prefs::kHomePage] = settings_api::PrefType::kUrl;
