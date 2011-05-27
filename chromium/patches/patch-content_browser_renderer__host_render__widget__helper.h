$NetBSD: patch-content_browser_renderer__host_render__widget__helper.h,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- content/browser/renderer_host/render_widget_helper.h.orig	2011-05-24 08:01:07.000000000 +0000
+++ content/browser/renderer_host/render_widget_helper.h
@@ -112,7 +112,7 @@ class RenderWidgetHelper
                         const base::TimeDelta& max_delay,
                         IPC::Message* msg);
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   // Given the id of a transport DIB, return a mapping to it or NULL on error.
   TransportDIB* MapTransportDIB(TransportDIB::Id dib_id);
 #endif
@@ -131,7 +131,7 @@ class RenderWidgetHelper
                        int* route_id);
   void CreateNewFullscreenWidget(int opener_id, int* route_id);
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   // Called on the IO thread to handle the allocation of a TransportDIB.  If
   // |cache_in_browser| is |true|, then a copy of the shmem is kept by the
   // browser, and it is the caller's repsonsibility to call
@@ -184,7 +184,7 @@ class RenderWidgetHelper
   // Called on the IO thread to resume a cross-site response.
   void OnCrossSiteClosePageACK(const ViewMsg_ClosePage_Params& params);
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   // Called on destruction to release all allocated transport DIBs
   void ClearAllocatedDIBs();
 
