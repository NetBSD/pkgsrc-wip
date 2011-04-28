$NetBSD: patch-chrome_renderer_render__process__impl.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/renderer/render_process_impl.cc.orig	2011-04-13 08:01:45.000000000 +0000
+++ chrome/renderer/render_process_impl.cc
@@ -244,7 +244,7 @@ TransportDIB* RenderProcessImpl::CreateT
 #if defined(OS_WIN) || defined(OS_LINUX)
   // Windows and Linux create transport DIBs inside the renderer
   return TransportDIB::Create(size, transport_dib_next_sequence_number_++);
-#elif defined(OS_MACOSX)  // defined(OS_WIN) || defined(OS_LINUX)
+#elif defined(OS_MACOSX) || defined(OS_BSD) // defined(OS_WIN) || defined(OS_LINUX)
   // Mac creates transport DIBs in the browser, so we need to do a sync IPC to
   // get one.  The TransportDIB is cached in the browser.
   TransportDIB::Handle handle;
@@ -261,7 +261,7 @@ void RenderProcessImpl::FreeTransportDIB
   if (!dib)
     return;
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   // On Mac we need to tell the browser that it can drop a reference to the
   // shared memory.
   IPC::Message* msg = new ViewHostMsg_FreeTransportDIB(dib->id());
@@ -279,7 +279,7 @@ skia::PlatformCanvas* RenderProcessImpl:
   int width = rect.width();
   int height = rect.height();
   const size_t stride = skia::PlatformCanvas::StrideForWidth(rect.width());
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   const size_t max_size = base::SysInfo::MaxSharedMemorySize();
 #else
   const size_t max_size = 0;
