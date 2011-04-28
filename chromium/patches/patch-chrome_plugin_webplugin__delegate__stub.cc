$NetBSD: patch-chrome_plugin_webplugin__delegate__stub.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/plugin/webplugin_delegate_stub.cc.orig	2011-04-13 08:01:44.000000000 +0000
+++ chrome/plugin/webplugin_delegate_stub.cc
@@ -314,7 +314,7 @@ void WebPluginDelegateStub::OnUpdateGeom
       param.window_rect, param.clip_rect,
       param.windowless_buffer, param.background_buffer,
       param.transparent
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
       ,
       param.ack_key
 #endif
