$NetBSD$

--- content/public/test/mock_render_thread.cc.orig	2020-07-08 21:40:42.000000000 +0000
+++ content/public/test/mock_render_thread.cc
@@ -51,7 +51,7 @@ class MockRenderMessageFilterImpl : publ
     std::move(callback).Run(false);
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void SetThreadPriority(int32_t platform_thread_id,
                          base::ThreadPriority thread_priority) override {}
 #endif
