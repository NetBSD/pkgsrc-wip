$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/tab_group_sync/tab_group_sync_service_factory.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/tab_group_sync/tab_group_sync_service_factory.cc
@@ -31,7 +31,7 @@
 #include "components/sync_device_info/device_info_sync_service.h"
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/tabs/saved_tab_groups/tab_group_sync_delegate_desktop.h"
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) ||
         // BUILDFLAG(IS_WIN)
@@ -89,7 +89,7 @@ TabGroupSyncServiceFactory::BuildService
 
   std::unique_ptr<TabGroupSyncDelegate> delegate;
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (tab_groups::IsTabGroupSyncServiceDesktopMigrationEnabled()) {
     delegate =
         std::make_unique<TabGroupSyncDelegateDesktop>(service.get(), profile);
