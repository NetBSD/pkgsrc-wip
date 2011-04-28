$NetBSD: patch-chrome_renderer_mock__render__thread.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/renderer/mock_render_thread.h.orig	2011-04-13 08:01:45.000000000 +0000
+++ chrome/renderer/mock_render_thread.h
@@ -108,7 +108,7 @@ class MockRenderThread : public RenderTh
                                     base::SharedMemoryHandle* handle);
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void OnAllocateTempFileForPrinting(base::FileDescriptor* renderer_fd,
                                      int* browser_fd);
   void OnTempFileForPrintingWritten(int browser_fd);
