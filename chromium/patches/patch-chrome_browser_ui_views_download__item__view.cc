$NetBSD: patch-chrome_browser_ui_views_download__item__view.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/ui/views/download_item_view.cc.orig	2011-04-13 08:01:42.000000000 +0000
+++ chrome/browser/ui/views/download_item_view.cc
@@ -261,7 +261,7 @@ DownloadItemView::DownloadItemView(Downl
 
     // Extract the file extension (if any).
     FilePath filename(download->target_name());
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     std::wstring extension = base::SysNativeMBToWide(filename.Extension());
 #else
     std::wstring extension = filename.Extension();
@@ -270,7 +270,7 @@ DownloadItemView::DownloadItemView(Downl
     // Remove leading '.'
     if (extension.length() > 0)
       extension = extension.substr(1);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     std::wstring rootname =
         base::SysNativeMBToWide(filename.RemoveExtension().value());
 #else
