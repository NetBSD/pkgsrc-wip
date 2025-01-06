$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/tab_group_sync/tab_group_sync_service_factory.cc.orig	2024-10-18 12:34:02.328839800 +0000
+++ chrome/browser/tab_group_sync/tab_group_sync_service_factory.cc
@@ -110,7 +110,7 @@ TabGroupSyncServiceFactory::BuildService
 
   std::unique_ptr<TabGroupSyncDelegate> delegate;
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   delegate =
       std::make_unique<TabGroupSyncDelegateDesktop>(service.get(), profile);
 #else
