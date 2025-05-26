$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/libsampler/sampler.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ v8/src/libsampler/sampler.cc
@@ -519,6 +519,16 @@ void SignalHandler::FillRegisterState(vo
   state->pc = reinterpret_cast<void*>(mcontext.__gregs[_REG_PC]);
   state->sp = reinterpret_cast<void*>(mcontext.__gregs[_REG_SP]);
   state->fp = reinterpret_cast<void*>(mcontext.__gregs[_REG_FP]);
+#elif V8_HOST_ARCH_ARM64
+#ifdef __CHERI_PURE_CAPABILITY__
+  state->pc = reinterpret_cast<void*>(mcontext.mc_capregs.cap_elr);
+  state->sp = reinterpret_cast<void*>(mcontext.mc_capregs.cap_sp);
+  state->fp = reinterpret_cast<void*>(mcontext.mc_capregs.cap_x[29]);
+#else   // !__CHERI_PURE_CAPABILITY__
+  state->pc = reinterpret_cast<void*>(mcontext.mc_gpregs.gp_elr);
+  state->sp = reinterpret_cast<void*>(mcontext.mc_gpregs.gp_sp);
+  state->fp = reinterpret_cast<void*>(mcontext.mc_gpregs.gp_x[29]);
+#endif  // __CHERI_PURE_CAPABILITY__
 #endif  // V8_HOST_ARCH_*
 #elif V8_OS_NETBSD
 #if V8_HOST_ARCH_IA32
