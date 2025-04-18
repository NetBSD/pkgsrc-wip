$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/ppapi_plugin/ppapi_plugin_main.cc.orig	2024-10-18 12:34:14.262462000 +0000
+++ content/ppapi_plugin/ppapi_plugin_main.cc
@@ -52,6 +52,11 @@
 #include "gin/v8_initializer.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#include "sandbox/policy/sandbox_type.h"
+#endif
+
 #if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID)
 #include <stdlib.h>
 #endif
@@ -141,7 +146,7 @@ int PpapiPluginMain(MainFunctionParams p
   gin::V8Initializer::LoadV8Snapshot();
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
   sandbox::policy::SandboxLinux::GetInstance()->InitializeSandbox(
       sandbox::policy::SandboxTypeFromCommandLine(command_line),
       sandbox::policy::SandboxLinux::PreSandboxHook(),
