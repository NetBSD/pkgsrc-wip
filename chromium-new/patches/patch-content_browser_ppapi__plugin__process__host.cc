$NetBSD$

--- content/browser/ppapi_plugin_process_host.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ content/browser/ppapi_plugin_process_host.cc
@@ -52,7 +52,7 @@
 
 namespace content {
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 ZygoteHandle g_ppapi_zygote;
 #endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
 
@@ -119,7 +119,7 @@ class PpapiPluginSandboxedProcessLaunche
   }
 
 #elif defined(OS_POSIX)
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   ZygoteHandle* GetZygote() override {
     const base::CommandLine& browser_command_line =
         *base::CommandLine::ForCurrentProcess();
@@ -222,7 +222,7 @@ PpapiPluginProcessHost* PpapiPluginProce
   return NULL;
 }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 // static
 void PpapiPluginProcessHost::EarlyZygoteLaunch() {
   DCHECK(!g_ppapi_zygote);
@@ -380,7 +380,7 @@ bool PpapiPluginProcessHost::Init(const 
   base::CommandLine::StringType plugin_launcher =
       browser_command_line.GetSwitchValueNative(switches::kPpapiPluginLauncher);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   int flags = plugin_launcher.empty() ? ChildProcessHost::CHILD_ALLOW_SELF :
                                         ChildProcessHost::CHILD_NORMAL;
 #else
