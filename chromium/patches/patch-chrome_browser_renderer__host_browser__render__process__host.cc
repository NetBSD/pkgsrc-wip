$NetBSD: patch-chrome_browser_renderer__host_browser__render__process__host.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/renderer_host/browser_render_process_host.cc.orig	2011-04-13 08:01:43.000000000 +0000
+++ chrome/browser/renderer_host/browser_render_process_host.cc
@@ -886,7 +886,7 @@ TransportDIB* BrowserRenderProcessHost::
   HANDLE section = app::win::GetSectionFromProcess(
       dib_id.handle, GetHandle(), false /* read write */);
   return TransportDIB::Map(section);
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
   // On OSX, the browser allocates all DIBs and keeps a file descriptor around
   // for each.
   return widget_helper_->MapTransportDIB(dib_id);
