$NetBSD$

--- content/renderer/renderer_main_platform_delegate_linux.cc.orig	2020-07-08 21:41:48.000000000 +0000
+++ content/renderer/renderer_main_platform_delegate_linux.cc
@@ -30,6 +30,7 @@ void RendererMainPlatformDelegate::Platf
 }
 
 bool RendererMainPlatformDelegate::EnableSandbox() {
+#if !defined(OS_BSD)
   // The setuid sandbox is started in the zygote process: zygote_main_linux.cc
   // https://chromium.googlesource.com/chromium/src/+/master/docs/linux/suid_sandbox.md
   //
@@ -66,6 +67,7 @@ bool RendererMainPlatformDelegate::Enabl
   }
 #endif  // __x86_64__
 
+#endif
   return true;
 }
 
