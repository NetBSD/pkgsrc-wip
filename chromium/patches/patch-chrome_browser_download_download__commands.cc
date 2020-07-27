$NetBSD$

--- chrome/browser/download/download_commands.cc.orig	2020-07-08 21:40:34.000000000 +0000
+++ chrome/browser/download/download_commands.cc
@@ -27,7 +27,7 @@
 #include "net/base/url_util.h"
 #include "ui/base/clipboard/scoped_clipboard_writer.h"
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 #include "chrome/browser/ui/browser.h"
 #include "chrome/browser/ui/browser_finder.h"
 #include "chrome/browser/ui/scoped_tabbed_browser_displayer.h"
@@ -154,7 +154,7 @@ void DownloadCommands::ExecuteCommand(Co
   model_->ExecuteCommand(this, command);
 }
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 Browser* DownloadCommands::GetBrowser() const {
   chrome::ScopedTabbedBrowserDisplayer browser_displayer(model_->profile());
@@ -177,7 +177,7 @@ bool DownloadCommands::CanOpenPdfInSyste
   return IsDownloadPdf() &&
          (IsAdobeReaderDefaultPDFViewer() ? is_adobe_pdf_reader_up_to_date
                                           : true);
-#elif defined(OS_MACOSX) || defined(OS_LINUX)
+#elif defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   return IsDownloadPdf();
 #endif
 }
