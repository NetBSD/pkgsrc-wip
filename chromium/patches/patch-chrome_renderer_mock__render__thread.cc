$NetBSD: patch-chrome_renderer_mock__render__thread.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/renderer/mock_render_thread.cc.orig	2011-04-13 08:01:45.000000000 +0000
+++ chrome/renderer/mock_render_thread.cc
@@ -112,7 +112,7 @@ bool MockRenderThread::OnMessageReceived
     IPC_MESSAGE_HANDLER(ViewHostMsg_AllocateSharedMemoryBuffer,
                         OnAllocateSharedMemoryBuffer)
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     IPC_MESSAGE_HANDLER(ViewHostMsg_AllocateTempFileForPrinting,
                         OnAllocateTempFileForPrinting)
     IPC_MESSAGE_HANDLER(ViewHostMsg_TempFileForPrintingWritten,
@@ -161,7 +161,7 @@ void MockRenderThread::OnAllocateSharedM
 }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void MockRenderThread::OnAllocateTempFileForPrinting(
     base::FileDescriptor* renderer_fd,
     int* browser_fd) {
