$NetBSD: patch-chrome_renderer_webplugin__delegate__proxy.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/renderer/webplugin_delegate_proxy.cc.orig	2011-04-13 08:01:45.000000000 +0000
+++ chrome/renderer/webplugin_delegate_proxy.cc
@@ -158,7 +158,7 @@ class ResourceClientProxy : public webki
   bool multibyte_response_expected_;
 };
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 static void ReleaseTransportDIB(TransportDIB* dib) {
   if (dib) {
     IPC::Message* message = new ViewHostMsg_FreeTransportDIB(dib->id());
@@ -184,7 +184,7 @@ WebPluginDelegateProxy::WebPluginDelegat
 }
 
 WebPluginDelegateProxy::~WebPluginDelegateProxy() {
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   // Ask the browser to release old TransportDIB objects for which no
   // PluginHostMsg_UpdateGeometry_ACK was ever received from the plugin
   // process.
@@ -530,7 +530,7 @@ void WebPluginDelegateProxy::UpdateGeome
   bool bitmaps_changed = false;
 
   PluginMsg_UpdateGeometry_Param param;
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   param.ack_key = -1;
 #endif
 
@@ -542,7 +542,7 @@ void WebPluginDelegateProxy::UpdateGeome
       bitmaps_changed = true;
 
       bool needs_background_store = transparent_;
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
       // We don't support transparency under QuickDraw, and CoreGraphics
       // preserves transparency information (and does the compositing itself)
       // so plugins don't need access to the page background.
@@ -614,7 +614,7 @@ void WebPluginDelegateProxy::UpdateGeome
 }
 
 void WebPluginDelegateProxy::ResetWindowlessBitmaps() {
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   DCHECK(!background_store_.get());
   // The Mac TransportDIB implementation uses base::SharedMemory, which
   // cannot be disposed of if an in-flight UpdateGeometry message refers to
@@ -675,12 +675,12 @@ bool WebPluginDelegateProxy::CreateShare
     scoped_ptr<TransportDIB>* memory,
     scoped_ptr<skia::PlatformCanvas>* canvas) {
   const size_t size = BitmapSizeForPluginRect(plugin_rect_);
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   memory->reset(TransportDIB::Create(size, 0));
   if (!memory->get())
     return false;
 #endif
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   TransportDIB::Handle handle;
   IPC::Message* msg = new ViewHostMsg_AllocTransportDIB(size, true, &handle);
   if (!RenderThread::current()->Send(msg))
