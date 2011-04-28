$NetBSD: patch-chrome_renderer_render__widget.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/renderer/render_widget.cc.orig	2011-04-13 08:01:45.000000000 +0000
+++ chrome/renderer/render_widget.cc
@@ -888,7 +888,7 @@ void RenderWidget::OnMsgPaintAtSize(cons
       // Close our unused handle.
 #if defined(OS_WIN)
       ::CloseHandle(dib_handle);
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
       base::SharedMemory::CloseHandle(dib_handle);
 #endif
     }
