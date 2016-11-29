$NetBSD$

--- content/browser/renderer_host/render_process_host_impl.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ content/browser/renderer_host/render_process_host_impl.cc
@@ -369,7 +369,7 @@ SiteProcessMap* GetSiteProcessMapForBrow
   return map;
 }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 // This static member variable holds the zygote communication information for
 // the renderer.
 ZygoteHandle g_render_zygote;
@@ -402,7 +402,7 @@ class RendererSandboxedProcessLauncherDe
   }
 
 #elif defined(OS_POSIX)
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   ZygoteHandle* GetZygote() override {
     const base::CommandLine& browser_command_line =
         *base::CommandLine::ForCurrentProcess();
@@ -639,7 +639,7 @@ void RenderProcessHost::SetMaxRendererPr
   g_max_renderer_count_override = count;
 }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 // static
 void RenderProcessHostImpl::EarlyZygoteLaunch() {
   DCHECK(!g_render_zygote);
@@ -835,7 +835,7 @@ bool RenderProcessHostImpl::Init() {
   renderer_prefix =
       browser_command_line.GetSwitchValueNative(switches::kRendererCmdPrefix);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   int flags = renderer_prefix.empty() ? ChildProcessHost::CHILD_ALLOW_SELF
                                       : ChildProcessHost::CHILD_NORMAL;
 #else
