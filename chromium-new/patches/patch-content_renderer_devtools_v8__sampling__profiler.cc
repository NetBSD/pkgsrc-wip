$NetBSD$

--- content/renderer/devtools/v8_sampling_profiler.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ content/renderer/devtools/v8_sampling_profiler.cc
@@ -547,6 +547,14 @@ void V8SamplingThread::HandleProfilerSig
   state.pc = reinterpret_cast<void*>(mcontext->__ss.REG_64_32(__rip, __eip));
   state.sp = reinterpret_cast<void*>(mcontext->__ss.REG_64_32(__rsp, __esp));
   state.fp = reinterpret_cast<void*>(mcontext->__ss.REG_64_32(__rbp, __ebp));
+#elif defined(OS_FREEBSD)
+  state.pc = reinterpret_cast<void*>(mcontext.REG_64_32(mc_rip, mc_eip));
+  state.sp = reinterpret_cast<void*>(mcontext.REG_64_32(mc_rsp, mc_esp));
+  state.fp = reinterpret_cast<void*>(mcontext.REG_64_32(mc_rbp, mc_ebp));
+#elif defined(OS_NETBSD)
+  state.pc = reinterpret_cast<void*>(mcontext.__gregs[REG_64_32(_REG_RIP, _REG_EIP)]);
+  state.sp = reinterpret_cast<void*>(mcontext.__gregs[REG_64_32(_REG_RSP, _REG_ESP)]);
+  state.fp = reinterpret_cast<void*>(mcontext.__gregs[REG_64_32(_REG_RBP, _REG_EBP)]);
 #else
   state.pc =
       reinterpret_cast<void*>(mcontext.gregs[REG_64_32(REG_RIP, REG_EIP)]);
