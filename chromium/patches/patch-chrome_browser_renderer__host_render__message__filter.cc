$NetBSD: patch-chrome_browser_renderer__host_render__message__filter.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/renderer_host/render_message_filter.cc.orig	2011-04-13 08:01:43.000000000 +0000
+++ chrome/browser/renderer_host/render_message_filter.cc
@@ -375,7 +375,7 @@ bool RenderMessageFilter::OnMessageRecei
     IPC_MESSAGE_HANDLER_DELAY_REPLY(ViewHostMsg_GetDefaultPrintSettings,
                                     OnGetDefaultPrintSettings)
     IPC_MESSAGE_HANDLER_DELAY_REPLY(ViewHostMsg_ScriptedPrint, OnScriptedPrint)
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
     IPC_MESSAGE_HANDLER(ViewHostMsg_AllocTransportDIB, OnAllocTransportDIB)
     IPC_MESSAGE_HANDLER(ViewHostMsg_FreeTransportDIB, OnFreeTransportDIB)
 #endif
@@ -1196,7 +1196,7 @@ void RenderMessageFilter::OnRendererHist
   HistogramSynchronizer::DeserializeHistogramList(sequence_number, histograms);
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 void RenderMessageFilter::OnAllocTransportDIB(
     size_t size, bool cache_in_browser, TransportDIB::Handle* handle) {
   render_widget_helper_->AllocTransportDIB(size, cache_in_browser, handle);
