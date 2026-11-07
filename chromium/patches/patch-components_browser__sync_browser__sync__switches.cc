$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/browser_sync/browser_sync_switches.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ components/browser_sync/browser_sync_switches.cc
@@ -40,7 +40,7 @@ BASE_FEATURE(kMigrateOutOfSyncSetupIncom
              base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableReadingListForMigratedUsers,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
