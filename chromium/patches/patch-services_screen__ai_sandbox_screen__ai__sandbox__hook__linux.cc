$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc.orig	2025-09-29 17:05:47.000000000 +0000
+++ services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc
@@ -70,6 +70,7 @@ bool ScreenAIPreSandboxHook(base::FilePa
     }
   }
 
+#if !BUILDFLAG(IS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
 
   std::vector<BrokerFilePermission> permissions{
@@ -91,6 +92,7 @@ bool ScreenAIPreSandboxHook(base::FilePa
                             sandbox::syscall_broker::COMMAND_OPEN}),
       permissions, options);
   instance->EngageNamespaceSandboxIfPossible();
+#endif
 
   return true;
 }
