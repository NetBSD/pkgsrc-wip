$NetBSD: patch-chrome_renderer_webplugin__delegate__proxy.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/renderer/webplugin_delegate_proxy.h.orig	2011-04-13 08:01:45.000000000 +0000
+++ chrome/renderer/webplugin_delegate_proxy.h
@@ -21,7 +21,7 @@
 #include "webkit/plugins/npapi/webplugininfo.h"
 #include "webkit/plugins/npapi/webplugin_delegate.h"
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 #include "base/hash_tables.h"
 #include "base/linked_ptr.h"
 #endif
@@ -216,7 +216,7 @@ class WebPluginDelegateProxy
   // point the window has already been destroyed).
   void WillDestroyWindow();
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   // Synthesize a fake window handle for the plug-in to identify the instance
   // to the browser, allowing mapping to a surface for hardware acceleration
   // of plug-in content. The browser generates the handle which is then set on
