$NetBSD: patch-content_browser_renderer__host_render__widget__helper.cc,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- content/browser/renderer_host/render_widget_helper.cc.orig	2011-05-24 08:01:07.000000000 +0000
+++ content/browser/renderer_host/render_widget_helper.cc
@@ -58,7 +58,7 @@ RenderWidgetHelper::~RenderWidgetHelper(
   // object, so we should not be destroyed unless pending_paints_ is empty!
   DCHECK(pending_paints_.empty());
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   ClearAllocatedDIBs();
 #endif
 }
@@ -277,7 +277,7 @@ void RenderWidgetHelper::OnCreateFullscr
     host->CreateNewFullscreenWidget(route_id);
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 TransportDIB* RenderWidgetHelper::MapTransportDIB(TransportDIB::Id dib_id) {
   base::AutoLock locked(allocated_dibs_lock_);
 
