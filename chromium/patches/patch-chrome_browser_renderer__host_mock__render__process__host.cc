$NetBSD: patch-chrome_browser_renderer__host_mock__render__process__host.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/renderer_host/mock_render_process_host.cc.orig	2011-04-13 08:01:43.000000000 +0000
+++ chrome/browser/renderer_host/mock_render_process_host.cc
@@ -106,7 +106,7 @@ TransportDIB* MockRenderProcessHost::Get
   DuplicateHandle(GetCurrentProcess(), dib_id.handle, GetCurrentProcess(),
                   &duped, 0, TRUE, DUPLICATE_SAME_ACCESS);
   transport_dib_ = TransportDIB::Map(duped);
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
   // On Mac, TransportDIBs are always created in the browser, so we cannot map
   // one from a dib_id.
   transport_dib_ = TransportDIB::Create(100 * 100 * 4, 0);
