$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/sync_preferences/common_syncable_prefs_database.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ components/sync_preferences/common_syncable_prefs_database.cc
@@ -349,7 +349,7 @@ constexpr auto kCommonSyncablePrefsAllow
           syncer::PREFERENCES, PrefSensitivity::kNone, MergeBehavior::kNone}},
 #endif  // BUILDFLAG(IS_ANDROID)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
         {autofill::prefs::kAutofillBnplEnabled,
          {syncable_prefs_ids::kAutofillBnplEnabled, syncer::PREFERENCES,
           PrefSensitivity::kNone, MergeBehavior::kNone}},
