$NetBSD: patch-content_browser_renderer__host_render__message__filter.cc,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- content/browser/renderer_host/render_message_filter.cc.orig	2011-05-24 08:01:07.000000000 +0000
+++ content/browser/renderer_host/render_message_filter.cc
@@ -416,7 +416,7 @@ bool RenderMessageFilter::OnMessageRecei
     IPC_MESSAGE_HANDLER(ViewHostMsg_V8HeapStats, OnV8HeapStats)
     IPC_MESSAGE_HANDLER(ViewHostMsg_DidZoomURL, OnDidZoomURL)
     IPC_MESSAGE_HANDLER_DELAY_REPLY(ViewHostMsg_ResolveProxy, OnResolveProxy)
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
     IPC_MESSAGE_HANDLER(ViewHostMsg_AllocTransportDIB, OnAllocTransportDIB)
     IPC_MESSAGE_HANDLER(ViewHostMsg_FreeTransportDIB, OnFreeTransportDIB)
 #endif
@@ -1111,7 +1111,7 @@ void RenderMessageFilter::OnRendererHist
   HistogramSynchronizer::DeserializeHistogramList(sequence_number, histograms);
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 void RenderMessageFilter::OnAllocTransportDIB(
     size_t size, bool cache_in_browser, TransportDIB::Handle* handle) {
   render_widget_helper_->AllocTransportDIB(size, cache_in_browser, handle);
