$NetBSD: patch-chrome_browser_sync_sync__service__factory.cc,v 1.1 2025/02/06 09:57:51 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/sync/sync_service_factory.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/sync/sync_service_factory.cc
@@ -109,7 +109,7 @@
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/tabs/saved_tab_groups/saved_tab_group_keyed_service.h"
 #include "chrome/browser/ui/tabs/saved_tab_groups/saved_tab_group_service_factory.h"
 #include "chrome/browser/ui/tabs/saved_tab_groups/saved_tab_group_utils.h"
@@ -157,7 +157,7 @@ syncer::DataTypeSet GetDisabledCommonDat
 tab_groups::TabGroupSyncService* GetTabGroupSyncService(Profile* profile) {
   CHECK(profile);
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   tab_groups::TabGroupSyncService* service =
       tab_groups::SavedTabGroupUtils::GetServiceForProfile(profile);
   CHECK(service);
@@ -395,7 +395,7 @@ std::unique_ptr<KeyedService> BuildSyncS
   // included in lacros-chrome once build flag switch of lacros-chrome is
   // complete.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
   syncer::SyncPrefs prefs(profile->GetPrefs());
   local_sync_backend_enabled = prefs.IsLocalSyncEnabled();
   base::UmaHistogramBoolean("Sync.Local.Enabled2", local_sync_backend_enabled);
@@ -531,7 +531,7 @@ SyncServiceFactory::SyncServiceFactory()
   DependsOn(ProfilePasswordStoreFactory::GetInstance());
   DependsOn(PowerBookmarkServiceFactory::GetInstance());
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   DependsOn(tab_groups::SavedTabGroupServiceFactory::GetInstance());
 #elif BUILDFLAG(IS_ANDROID)
   DependsOn(tab_groups::TabGroupSyncServiceFactory::GetInstance());
