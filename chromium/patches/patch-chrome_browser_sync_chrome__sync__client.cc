$NetBSD$

--- chrome/browser/sync/chrome_sync_client.cc.orig	2020-07-08 21:41:47.000000000 +0000
+++ chrome/browser/sync/chrome_sync_client.cc
@@ -449,7 +449,7 @@ ChromeSyncClient::CreateDataTypeControll
 
 // Chrome prefers OS provided spell checkers where they exist. So only sync the
 // custom dictionary on platforms that typically don't provide one.
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   // Dictionary sync is enabled by default.
   if (!disabled_types.Has(syncer::DICTIONARY) &&
       GetPrefService()->GetBoolean(spellcheck::prefs::kSpellCheckEnable)) {
