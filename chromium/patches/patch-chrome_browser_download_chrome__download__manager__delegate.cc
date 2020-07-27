$NetBSD$

--- chrome/browser/download/chrome_download_manager_delegate.cc.orig	2020-07-08 21:40:34.000000000 +0000
+++ chrome/browser/download/chrome_download_manager_delegate.cc
@@ -1309,7 +1309,7 @@ void ChromeDownloadManagerDelegate::OnDo
         target_info->is_filetype_handled_safely)
       DownloadItemModel(item).SetShouldPreferOpeningInBrowser(true);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     if (item->GetOriginalMimeType() == "application/x-x509-user-cert")
       DownloadItemModel(item).SetShouldPreferOpeningInBrowser(true);
 #endif
@@ -1358,7 +1358,7 @@ void ChromeDownloadManagerDelegate::OnDo
 
 bool ChromeDownloadManagerDelegate::IsOpenInBrowserPreferreredForFile(
     const base::FilePath& path) {
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   if (path.MatchesExtension(FILE_PATH_LITERAL(".pdf"))) {
     return !download_prefs_->ShouldOpenPdfInSystemReader();
   }
