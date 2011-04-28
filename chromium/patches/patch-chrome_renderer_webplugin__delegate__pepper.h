$NetBSD: patch-chrome_renderer_webplugin__delegate__pepper.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/renderer/webplugin_delegate_pepper.h.orig	2011-04-13 08:01:45.000000000 +0000
+++ chrome/renderer/webplugin_delegate_pepper.h
@@ -310,7 +310,7 @@ class WebPluginDelegatePepper : public w
   // variable to hold on to the pixels.
   SkBitmap last_printed_page_;
 #endif   // defined(OS_MACOSX)
-#if defined (OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux, we always send all pages from the renderer to the browser.
   // So, if the plugin supports printPagesAsPDF we print the entire output
   // in one shot in the first call to PrintPage.
@@ -321,7 +321,7 @@ class WebPluginDelegatePepper : public w
   // Specifies whether we have already output all pages. This is used to ignore
   // subsequent PrintPage requests.
   bool pdf_output_done_;
-#endif   // defined(OS_LINUX)
+#endif   // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(ENABLE_GPU)
   // The command buffer used to issue commands to the nested GPU plugin.
