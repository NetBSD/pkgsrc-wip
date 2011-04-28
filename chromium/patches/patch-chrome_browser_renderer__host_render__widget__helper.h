$NetBSD: patch-chrome_browser_renderer__host_render__widget__helper.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/renderer_host/render_widget_helper.h.orig	2011-04-13 08:01:43.000000000 +0000
+++ chrome/browser/renderer_host/render_widget_helper.h
@@ -112,7 +112,7 @@ class RenderWidgetHelper
                         const base::TimeDelta& max_delay,
                         IPC::Message* msg);
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   // Given the id of a transport DIB, return a mapping to it or NULL on error.
   TransportDIB* MapTransportDIB(TransportDIB::Id dib_id);
 #endif
@@ -133,7 +133,7 @@ class RenderWidgetHelper
                                  WebKit::WebPopupType popup_type,
                                  int* route_id);
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   // Called on the IO thread to handle the allocation of a TransportDIB.  If
   // |cache_in_browser| is |true|, then a copy of the shmem is kept by the
   // browser, and it is the caller's repsonsibility to call
@@ -188,7 +188,7 @@ class RenderWidgetHelper
   // Called on the IO thread to resume a cross-site response.
   void OnCrossSiteClosePageACK(const ViewMsg_ClosePage_Params& params);
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   // Called on destruction to release all allocated transport DIBs
   void ClearAllocatedDIBs();
 
