$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/shell/common/v8_util.cc.orig	2026-11-18 22:22:58.000000000 +0000
+++ electron/shell/common/v8_util.cc
@@ -30,6 +30,12 @@
 #include "components/crash/core/app/crashpad.h"  // nogncheck
 #include "content/public/common/content_switches.h"
 #include "v8/include/v8-wasm-trap-handler-posix.h"
+#elif BUILDFLAG(IS_BSD) && defined(ARCH_CPU_X86_64)
+#define ENABLE_WEB_ASSEMBLY_TRAP_HANDLER_LINUX
+#include "base/command_line.h"
+#include "base/debug/stack_trace.h"
+#include "content/public/common/content_switches.h"
+#include "v8/include/v8-wasm-trap-handler-posix.h"
 #endif
 
 namespace electron {
@@ -340,6 +346,7 @@ void SetUpWebAssemblyTrapHandler() {
   // WebAssembly traps.
   v8::V8::EnableWebAssemblyTrapHandler(true);
 #elif defined(ENABLE_WEB_ASSEMBLY_TRAP_HANDLER_LINUX)
+#if !BUILDFLAG(IS_BSD)
   const bool crash_reporter_enabled =
       crash_reporter::GetHandlerSocket(nullptr, nullptr);
 
@@ -350,7 +357,7 @@ void SetUpWebAssemblyTrapHandler() {
     v8::V8::EnableWebAssemblyTrapHandler(false);
     return;
   }
-
+#endif
   const bool use_v8_default_handler =
       base::CommandLine::ForCurrentProcess()->HasSwitch(
           ::switches::kDisableInProcessStackTraces);
