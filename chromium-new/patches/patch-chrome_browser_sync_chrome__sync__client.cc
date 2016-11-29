$NetBSD$

--- chrome/browser/sync/chrome_sync_client.cc.orig	2016-11-10 20:02:11.000000000 +0000
+++ chrome/browser/sync/chrome_sync_client.cc
@@ -573,7 +573,7 @@ void ChromeSyncClient::RegisterDesktopDa
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Dictionary sync is enabled by default.
   if (!disabled_types.Has(syncer::DICTIONARY)) {
     sync_service->RegisterDataTypeController(new UIDataTypeController(
