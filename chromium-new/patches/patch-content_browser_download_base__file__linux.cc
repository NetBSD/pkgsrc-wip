$NetBSD$

--- content/browser/download/base_file_linux.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ content/browser/download/base_file_linux.cc
@@ -16,7 +16,9 @@ DownloadInterruptReason BaseFile::Annota
   DCHECK_CURRENTLY_ON(BrowserThread::FILE);
   DCHECK(!detached_);
 
+#if !defined(OS_BSD)
   AddOriginMetadataToFile(full_path_, source_url, referrer_url);
+#endif
   return DOWNLOAD_INTERRUPT_REASON_NONE;
 }
 
