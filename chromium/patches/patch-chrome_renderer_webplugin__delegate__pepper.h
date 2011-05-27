$NetBSD: patch-chrome_renderer_webplugin__delegate__pepper.h,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- chrome/renderer/webplugin_delegate_pepper.h.orig	2011-05-24 08:01:44.000000000 +0000
+++ chrome/renderer/webplugin_delegate_pepper.h
@@ -281,7 +281,7 @@ class WebPluginDelegatePepper : public w
   // variable to hold on to the pixels.
   SkBitmap last_printed_page_;
 #endif   // defined(OS_MACOSX)
-#if defined (OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux, we always send all pages from the renderer to the browser.
   // So, if the plugin supports printPagesAsPDF we print the entire output
   // in one shot in the first call to PrintPage.
@@ -292,7 +292,7 @@ class WebPluginDelegatePepper : public w
   // Specifies whether we have already output all pages. This is used to ignore
   // subsequent PrintPage requests.
   bool pdf_output_done_;
-#endif   // defined(OS_LINUX)
+#endif   // defined(OS_LINUX) || defined(OS_BSD)
 
   // The id of the current find operation, or -1 if none is in process.
   int find_identifier_;
