$NetBSD: patch-jit_AsmJSSignalHandlers.cpp,v 1.1 2014/02/06 15:12:18 fhajny Exp $

* REG_EIP is not defined on Solaris/SunOS, use REG_PC instead.

--- jit/AsmJSSignalHandlers.cpp.orig	2013-10-29 20:40:19.000000000 +0000
+++ jit/AsmJSSignalHandlers.cpp
@@ -59,10 +59,11 @@ using namespace mozilla;
 #elif defined(__linux__) || defined(SOLARIS)
 # if defined(__linux__)
 #  define XMM_sig(p,i) ((p)->uc_mcontext.fpregs->_xmm[i])
+#  define EIP_sig(p) ((p)->uc_mcontext.gregs[REG_EIP])
 # else
 #  define XMM_sig(p,i) ((p)->uc_mcontext.fpregs.fp_reg_set.fpchip_state.xmm[i])
+#  define EIP_sig(p) ((p)->uc_mcontext.gregs[REG_PC])
 # endif
-# define EIP_sig(p) ((p)->uc_mcontext.gregs[REG_EIP])
 # define RIP_sig(p) ((p)->uc_mcontext.gregs[REG_RIP])
 # define PC_sig(p) ((p)->uc_mcontext.arm_pc)
 # define RAX_sig(p) ((p)->uc_mcontext.gregs[REG_RAX])
@@ -269,7 +270,7 @@ LookupHeapAccess(const AsmJSModule &modu
 # if defined(JS_CPU_X64)
 #  if defined(__DragonFly__)
 #   include <machine/npx.h> // for union savefpu
-#  elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__FreeBSD_kernel__)
+#  elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
 #   include <machine/fpu.h> // for struct savefpu/fxsave64
 #  endif
 # endif
