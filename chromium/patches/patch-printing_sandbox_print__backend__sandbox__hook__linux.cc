$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/sandbox/print_backend_sandbox_hook_linux.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ printing/sandbox/print_backend_sandbox_hook_linux.cc
@@ -10,20 +10,27 @@
 #include "base/path_service.h"
 #include "build/build_config.h"
 #include "printing/buildflags/buildflags.h"
+#if !BUILDFLAG(IS_BSD)
 #include "sandbox/linux/syscall_broker/broker_command.h"
 #include "sandbox/linux/syscall_broker/broker_file_permission.h"
 #include "sandbox/policy/export.h"
 #include "sandbox/policy/linux/sandbox_linux.h"
+#else
+#include "sandbox/policy/sandbox.h"
+#endif
 
 #if BUILDFLAG(IS_CHROMEOS) && BUILDFLAG(USE_CUPS)
 #include "printing/backend/cups_connection_pool.h"
 #endif
 
+#if !BUILDFLAG(IS_BSD)
 using sandbox::syscall_broker::BrokerFilePermission;
 using sandbox::syscall_broker::MakeBrokerCommandSet;
+#endif
 
 namespace printing {
 
+#if !BUILDFLAG(IS_BSD)
 namespace {
 
 sandbox::syscall_broker::BrokerCommandSet GetPrintBackendBrokerCommandSet() {
@@ -76,9 +83,11 @@ std::vector<BrokerFilePermission> GetPri
 }
 
 }  // namespace
+#endif
 
 bool PrintBackendPreSandboxHook(
     sandbox::policy::SandboxLinux::Options options) {
+#if !BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_CHROMEOS) && BUILDFLAG(USE_CUPS)
   // Create the socket connections to the CUPS server before engaging the
   // sandbox, since new connections cannot be made after that.
@@ -91,6 +100,7 @@ bool PrintBackendPreSandboxHook(
                                GetPrintBackendFilePermissions(), options);
 
   instance->EngageNamespaceSandboxIfPossible();
+#endif
   return true;
 }
 
