$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/sync/sync_service_factory.cc.orig	2024-10-26 06:59:59.289169800 +0000
+++ chrome/browser/sync/sync_service_factory.cc
@@ -105,7 +105,7 @@
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/tabs/saved_tab_groups/saved_tab_group_keyed_service.h"
 #include "chrome/browser/ui/tabs/saved_tab_groups/saved_tab_group_service_factory.h"
 #include "chrome/browser/ui/tabs/saved_tab_groups/saved_tab_group_utils.h"
@@ -153,7 +153,7 @@ syncer::DataTypeSet GetDisabledCommonDat
 tab_groups::TabGroupSyncService* GetTabGroupSyncService(Profile* profile) {
   CHECK(profile);
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   tab_groups::TabGroupSyncService* service =
       tab_groups::SavedTabGroupUtils::GetServiceForProfile(profile);
   CHECK(service);
@@ -381,7 +381,7 @@ std::unique_ptr<KeyedService> BuildSyncS
   // included in lacros-chrome once build flag switch of lacros-chrome is
   // complete.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
   syncer::SyncPrefs prefs(profile->GetPrefs());
   local_sync_backend_enabled = prefs.IsLocalSyncEnabled();
   base::UmaHistogramBoolean("Sync.Local.Enabled2", local_sync_backend_enabled);
@@ -517,7 +517,7 @@ SyncServiceFactory::SyncServiceFactory()
   DependsOn(ProfilePasswordStoreFactory::GetInstance());
   DependsOn(PowerBookmarkServiceFactory::GetInstance());
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   DependsOn(tab_groups::SavedTabGroupServiceFactory::GetInstance());
 #elif BUILDFLAG(IS_ANDROID)
   DependsOn(tab_groups::TabGroupSyncServiceFactory::GetInstance());
