$NetBSD: patch-chrome_browser_sync_syncable_directory__backing__store.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/sync/syncable/directory_backing_store.cc.orig	2011-04-13 08:01:39.000000000 +0000
+++ chrome/browser/sync/syncable/directory_backing_store.cc
@@ -304,13 +304,13 @@ bool DirectoryBackingStore::BeginLoad() 
 #else
   UMA_HISTOGRAM_COUNTS_100("Sync.DirectoryOpenFailedNotWinMac", bucket);
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   UMA_HISTOGRAM_COUNTS_100("Sync.DirectoryOpenFailedLinux", bucket);
 #elif defined(OS_CHROMEOS)
   UMA_HISTOGRAM_COUNTS_100("Sync.DirectoryOpenFailedCros", bucket);
 #else
   UMA_HISTOGRAM_COUNTS_100("Sync.DirectoryOpenFailedOther", bucket);
-#endif  // OS_LINUX && !OS_CHROMEOS
+#endif  // (OS_LINUX || OS_BSD) && !OS_CHROMEOS
 #endif  // OS_WIN
   return !failed_again;
 }
