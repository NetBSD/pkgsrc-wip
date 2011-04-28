$NetBSD: patch-chrome_renderer_renderer__main.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/renderer/renderer_main.cc.orig	2011-04-13 08:01:45.000000000 +0000
+++ chrome/renderer/renderer_main.cc
@@ -272,7 +272,7 @@ int RendererMain(const MainFunctionParam
   PepperPluginRegistry::GetInstance();
 
   {
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
     // TODO(markus): Check if it is OK to unconditionally move this
     // instruction down.
     RenderProcessImpl render_process;
@@ -284,7 +284,7 @@ int RendererMain(const MainFunctionParam
     } else {
       LOG(ERROR) << "Running without renderer sandbox";
     }
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     RenderProcessImpl render_process;
     render_process.set_main_thread(new RenderThread());
 #endif
