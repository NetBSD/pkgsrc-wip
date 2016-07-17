$NetBSD$

--- chrome/browser/download/download_commands.h.orig	2016-06-24 01:02:12.000000000 +0000
+++ chrome/browser/download/download_commands.h
@@ -42,7 +42,8 @@ class DownloadCommands {
   void ExecuteCommand(Command command);
 
 #if defined(OS_WIN) || defined(OS_LINUX) || \
-    (defined(OS_MACOSX) && !defined(OS_IOS))
+    defined(OS_BSD) || (defined(OS_MACOSX) && \
+    !defined(OS_IOS))
   bool IsDownloadPdf() const;
   bool CanOpenPdfInSystemViewer() const;
 #endif
