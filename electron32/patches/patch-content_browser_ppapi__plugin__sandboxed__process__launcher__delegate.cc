$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/ppapi_plugin_sandboxed_process_launcher_delegate.cc.orig	2024-10-18 12:34:12.999114800 +0000
+++ content/browser/ppapi_plugin_sandboxed_process_launcher_delegate.cc
@@ -10,6 +10,7 @@
 #include "build/build_config.h"
 #include "content/public/common/content_switches.h"
 #include "sandbox/policy/mojom/sandbox.mojom.h"
+#include "sandbox/policy/switches.h"
 
 #if BUILDFLAG(IS_WIN)
 #include "sandbox/policy/win/sandbox_win.h"
@@ -56,6 +57,9 @@ bool PpapiPluginSandboxedProcessLauncher
 ZygoteCommunication* PpapiPluginSandboxedProcessLauncherDelegate::GetZygote() {
   const base::CommandLine& browser_command_line =
       *base::CommandLine::ForCurrentProcess();
+  if (browser_command_line.HasSwitch(sandbox::policy::switches::kNoSandbox)) {
+    return nullptr;
+  }
   base::CommandLine::StringType plugin_launcher =
       browser_command_line.GetSwitchValueNative(switches::kPpapiPluginLauncher);
   if (!plugin_launcher.empty())
