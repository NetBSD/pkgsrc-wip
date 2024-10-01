$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/tab_group_sync/tab_group_sync_service_factory.cc.orig	2024-09-24 20:49:19.941112300 +0000
+++ chrome/browser/tab_group_sync/tab_group_sync_service_factory.cc
@@ -110,7 +110,7 @@ TabGroupSyncServiceFactory::BuildService
 
   std::unique_ptr<TabGroupSyncDelegate> delegate;
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   delegate =
       std::make_unique<TabGroupSyncDelegateDesktop>(service.get(), profile);
 #else
