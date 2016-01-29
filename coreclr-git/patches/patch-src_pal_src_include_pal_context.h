$NetBSD$

--- src/pal/src/include/pal/context.h.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/include/pal/context.h
@@ -44,7 +44,58 @@ typedef ucontext_t native_context_t;
 #include <mach/mach_port.h>
 #endif // !HAVE_MACH_EXCEPTIONS else
 
-#if HAVE_GREGSET_T
+#if HAVE___GREGSET_T
+
+#ifdef BIT64
+#define MCREG_Rbx(mc)       ((mc).__gregs[_REG_RBX])
+#define MCREG_Rcx(mc)       ((mc).__gregs[_REG_RCX])
+#define MCREG_Rdx(mc)       ((mc).__gregs[_REG_RDX])
+#define MCREG_Rsi(mc)       ((mc).__gregs[_REG_RSI])
+#define MCREG_Rdi(mc)       ((mc).__gregs[_REG_RDI])
+#define MCREG_Rbp(mc)       ((mc).__gregs[_REG_RBP])
+#define MCREG_Rax(mc)       ((mc).__gregs[_REG_RAX])
+#define MCREG_Rip(mc)       ((mc).__gregs[_REG_RIP])
+#define MCREG_Rsp(mc)       ((mc).__gregs[_REG_RSP])
+#define MCREG_SegCs(mc)     ((mc).__gregs[_REG_CS])
+#define MCREG_SegSs(mc)     ((mc).__gregs[_REG_SS])
+#define MCREG_R8(mc)        ((mc).__gregs[_REG_R8])
+#define MCREG_R9(mc)        ((mc).__gregs[_REG_R9])
+#define MCREG_R10(mc)       ((mc).__gregs[_REG_R10])
+#define MCREG_R11(mc)       ((mc).__gregs[_REG_R11])
+#define MCREG_R12(mc)       ((mc).__gregs[_REG_R12])
+#define MCREG_R13(mc)       ((mc).__gregs[_REG_R13])
+#define MCREG_R14(mc)       ((mc).__gregs[_REG_R14])
+#define MCREG_R15(mc)       ((mc).__gregs[_REG_R15])
+#define MCREG_EFlags(mc)    ((mc).__gregs[_REG_RFLAGS])
+
+#define FPREG_Xmm(uc, index) *(M128A*)&((struct fxsave*)((uc)->uc_mcontext.__fpregs)->fx_xmm[index])
+
+#define FPREG_St(uc, index) *(M128A*)&((struct fxsave*)((uc)->uc_mcontext.__fpregs)->fx_87_ac[index])
+
+#define FPREG_ControlWord(uc) ((struct fxsave*)((uc)->uc_mcontext.__fpregs)->fx_cw)
+#define FPREG_StatusWord(uc) ((struct fxsave*)((uc)->uc_mcontext.__fpregs)->fx_sw)
+#define FPREG_TagWord(uc) ((struct fxsave*)((uc)->uc_mcontext.__fpregs)->fx_tw)
+#define FPREG_MxCsr(uc) ((struct fxsave*)((uc)->uc_mcontext.__fpregs)->fx_mxcsr)
+#define FPREG_MxCsr_Mask(uc) ((struct fxsave*)((uc)->uc_mcontext.__fpregs)->fx_mxcsr_mask)
+
+#else // BIT64
+
+#define MCREG_Ebx(mc)       ((mc).__gregs[_REG_EBX])
+#define MCREG_Ecx(mc)       ((mc).__gregs[_REG_ECX])
+#define MCREG_Edx(mc)       ((mc).__gregs[_REG_EDX])
+#define MCREG_Esi(mc)       ((mc).__gregs[_REG_ESI])
+#define MCREG_Edi(mc)       ((mc).__gregs[_REG_EDI])
+#define MCREG_Ebp(mc)       ((mc).__gregs[_REG_EBP])
+#define MCREG_Eax(mc)       ((mc).__gregs[_REG_EAX])
+#define MCREG_Eip(mc)       ((mc).__gregs[_REG_EIP])
+#define MCREG_Esp(mc)       ((mc).__gregs[_REG_ESP])
+#define MCREG_SegCs(mc)     ((mc).__gregs[_REG_CS])
+#define MCREG_SegSs(mc)     ((mc).__gregs[_REG_SS])
+#define MCREG_EFlags(mc)    ((mc).__gregs[_REG_RFLAGS])
+
+#endif // BIT64
+
+#elif HAVE_GREGSET_T
 
 #ifdef BIT64
 #define MCREG_Rbx(mc)       ((mc).gregs[REG_RBX])
