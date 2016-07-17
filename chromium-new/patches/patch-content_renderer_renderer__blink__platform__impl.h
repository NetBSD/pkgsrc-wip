$NetBSD$

--- content/renderer/renderer_blink_platform_impl.h.orig	2016-06-24 01:02:21.000000000 +0000
+++ content/renderer/renderer_blink_platform_impl.h
@@ -254,7 +254,7 @@ class CONTENT_EXPORT RendererBlinkPlatfo
   class MimeRegistry;
   scoped_ptr<MimeRegistry> mime_registry_;
 
-#if !defined(OS_ANDROID) && !defined(OS_WIN)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_BSD)
   class SandboxSupport;
   scoped_ptr<SandboxSupport> sandbox_support_;
 #endif
