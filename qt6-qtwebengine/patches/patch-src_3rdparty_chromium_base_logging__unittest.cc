$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/logging_unittest.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/base/logging_unittest.cc
@@ -41,7 +41,7 @@
 #include "base/posix/eintr_wrapper.h"
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD)
 #include <ucontext.h>
 #endif
 
@@ -585,14 +585,18 @@ void CheckCrashTestSighandler(int, sigin
   // need the arch-specific boilerplate below, which is inspired by breakpad.
   // At the same time, on OSX, ucontext.h is deprecated but si_addr works fine.
   uintptr_t crash_addr = 0;
-#if BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_NETBSD)
   crash_addr = reinterpret_cast<uintptr_t>(info->si_addr);
 #else  // OS_*
   ucontext_t* context = reinterpret_cast<ucontext_t*>(context_ptr);
 #if defined(ARCH_CPU_X86)
   crash_addr = static_cast<uintptr_t>(context->uc_mcontext.gregs[REG_EIP]);
 #elif defined(ARCH_CPU_X86_64)
+#if BUILDFLAG(IS_OPENBSD)
+  crash_addr = static_cast<uintptr_t>(context->sc_rip);
+#else
   crash_addr = static_cast<uintptr_t>(context->uc_mcontext.gregs[REG_RIP]);
+#endif
 #elif defined(ARCH_CPU_ARMEL)
   crash_addr = static_cast<uintptr_t>(context->uc_mcontext.arm_pc);
 #elif defined(ARCH_CPU_ARM64)
