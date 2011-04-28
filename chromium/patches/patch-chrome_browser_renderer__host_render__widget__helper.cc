$NetBSD: patch-chrome_browser_renderer__host_render__widget__helper.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/renderer_host/render_widget_helper.cc.orig	2011-04-13 08:01:43.000000000 +0000
+++ chrome/browser/renderer_host/render_widget_helper.cc
@@ -60,7 +60,7 @@ RenderWidgetHelper::~RenderWidgetHelper(
   // object, so we should not be destroyed unless pending_paints_ is empty!
   DCHECK(pending_paints_.empty());
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   ClearAllocatedDIBs();
 #endif
 }
@@ -281,7 +281,7 @@ void RenderWidgetHelper::OnCreateFullscr
     host->CreateNewFullscreenWidget(route_id, popup_type);
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 TransportDIB* RenderWidgetHelper::MapTransportDIB(TransportDIB::Id dib_id) {
   base::AutoLock locked(allocated_dibs_lock_);
 
