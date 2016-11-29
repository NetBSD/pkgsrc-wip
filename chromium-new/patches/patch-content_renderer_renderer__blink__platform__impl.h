$NetBSD$

--- content/renderer/renderer_blink_platform_impl.h.orig	2016-11-10 20:02:14.000000000 +0000
+++ content/renderer/renderer_blink_platform_impl.h
@@ -264,7 +264,7 @@ class CONTENT_EXPORT RendererBlinkPlatfo
   class MimeRegistry;
   std::unique_ptr<MimeRegistry> mime_registry_;
 
-#if !defined(OS_ANDROID) && !defined(OS_WIN)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_BSD)
   class SandboxSupport;
   std::unique_ptr<SandboxSupport> sandbox_support_;
 #endif
