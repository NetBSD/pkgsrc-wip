$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/sync/sync_service_factory.cc.orig	2024-10-18 12:34:02.300855400 +0000
+++ chrome/browser/sync/sync_service_factory.cc
@@ -85,7 +85,7 @@
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/tabs/saved_tab_groups/saved_tab_group_service_factory.h"
 #elif BUILDFLAG(IS_ANDROID)
 #include "chrome/browser/tab_group_sync/tab_group_sync_service_factory.h"
@@ -134,7 +134,7 @@ std::unique_ptr<KeyedService> BuildSyncS
 // TODO(crbug.com/40118868): Reassess whether the following block needs to be
 // included in lacros-chrome once build flag switch of lacros-chrome is
 // complete.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
   syncer::SyncPrefs prefs(profile->GetPrefs());
   local_sync_backend_enabled = prefs.IsLocalSyncEnabled();
@@ -271,7 +271,7 @@ SyncServiceFactory::SyncServiceFactory()
   DependsOn(ProfilePasswordStoreFactory::GetInstance());
   DependsOn(PowerBookmarkServiceFactory::GetInstance());
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   DependsOn(tab_groups::SavedTabGroupServiceFactory::GetInstance());
 #elif BUILDFLAG(IS_ANDROID)
   DependsOn(tab_groups::TabGroupSyncServiceFactory::GetInstance());
