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
@@ -293,43 +344,55 @@ typedef ucontext_t native_context_t;
 
 #if HAVE_BSD_REGS_T
 
+/*
+#ifndef HAVE_BSD_REGS_STYLE
+#error "struct reg" has unrecognized format
+#endif
+*/
+
+#if 0
+#define BSD_REGS_STYLE(reg,RR,rr) ((reg).r_##rr)
+#else
+#define BSD_REGS_STYLE(reg,RR,rr) ((reg).regs[_REG_##RR])
+#endif
+
 #ifdef BIT64
 
-#define BSDREG_Rbx(reg)     ((reg).r_rbx)
-#define BSDREG_Rcx(reg)     ((reg).r_rcx)
-#define BSDREG_Rdx(reg)     ((reg).r_rdx)
-#define BSDREG_Rsi(reg)     ((reg).r_rsi)
-#define BSDREG_Rdi(reg)     ((reg).r_rdi)
-#define BSDREG_Rbp(reg)     ((reg).r_rbp)
-#define BSDREG_Rax(reg)     ((reg).r_rax)
-#define BSDREG_Rip(reg)     ((reg).r_rip)
-#define BSDREG_SegCs(reg)   ((reg).r_cs)
-#define BSDREG_SegSs(reg)   ((reg).r_ss)
-#define BSDREG_Rsp(reg)     ((reg).r_rsp)
-#define BSDREG_R8(reg)      ((reg).r_r8)
-#define BSDREG_R9(reg)      ((reg).r_r9)
-#define BSDREG_R10(reg)     ((reg).r_r10)
-#define BSDREG_R11(reg)     ((reg).r_r11)
-#define BSDREG_R12(reg)     ((reg).r_r12)
-#define BSDREG_R13(reg)     ((reg).r_r13)
-#define BSDREG_R14(reg)     ((reg).r_r14)
-#define BSDREG_R15(reg)     ((reg).r_r15)
-#define BSDREG_EFlags(reg)  ((reg).r_rflags)
+#define BSDREG_Rbx(reg)     BSD_REGS_STYLE((reg),RBX,rbx)
+#define BSDREG_Rcx(reg)     BSD_REGS_STYLE((reg),RCX,rcx)
+#define BSDREG_Rdx(reg)     BSD_REGS_STYLE((reg),RDX,rdx)
+#define BSDREG_Rsi(reg)     BSD_REGS_STYLE((reg),RSI,rsi)
+#define BSDREG_Rdi(reg)     BSD_REGS_STYLE((reg),RDI,rdi)
+#define BSDREG_Rbp(reg)     BSD_REGS_STYLE((reg),RBP,rbp)
+#define BSDREG_Rax(reg)     BSD_REGS_STYLE((reg),RAX,rax)
+#define BSDREG_Rip(reg)     BSD_REGS_STYLE((reg),RIP,rip)
+#define BSDREG_SegCs(reg)   BSD_REGS_STYLE((reg),CS,cs)
+#define BSDREG_SegSs(reg)   BSD_REGS_STYLE((reg),SS,ss)
+#define BSDREG_Rsp(reg)     BSD_REGS_STYLE((reg),RSP,rsp)
+#define BSDREG_R8(reg)      BSD_REGS_STYLE((reg),R8,r8)
+#define BSDREG_R9(reg)      BSD_REGS_STYLE((reg),R9,r9)
+#define BSDREG_R10(reg)     BSD_REGS_STYLE((reg),R10,r10)
+#define BSDREG_R11(reg)     BSD_REGS_STYLE((reg),R11,r11)
+#define BSDREG_R12(reg)     BSD_REGS_STYLE((reg),R12,r12)
+#define BSDREG_R13(reg)     BSD_REGS_STYLE((reg),R13,r13)
+#define BSDREG_R14(reg)     BSD_REGS_STYLE((reg),R14,r14)
+#define BSDREG_R15(reg)     BSD_REGS_STYLE((reg),R15,r15)
+#define BSDREG_EFlags(reg)  BSD_REGS_STYLE((reg),RFLAGS,rflags)
 
 #else // BIT64
 
-#define BSDREG_Ebx(reg)     ((reg).r_ebx)
-#define BSDREG_Ecx(reg)     ((reg).r_ecx)
-#define BSDREG_Edx(reg)     ((reg).r_edx)
-#define BSDREG_Esi(reg)     ((reg).r_esi)
-#define BSDREG_Edi(reg)     ((reg).r_edi)
-#define BSDREG_Ebp(reg)     ((reg).r_ebp)
-#define BSDREG_Eax(reg)     ((reg).r_eax)
-#define BSDREG_Eip(reg)     ((reg).r_eip)
-#define BSDREG_SegCs(reg)   ((reg).r_cs)
-#define BSDREG_EFlags(reg)  ((reg).r_eflags)
-#define BSDREG_Esp(reg)     ((reg).r_esp)
-#define BSDREG_SegSs(reg)   ((reg).r_ss)
+#define BSDREG_Ebx(reg)     ((reg).BSDREG_REGS(ebx))
+#define BSDREG_Ecx(reg)     ((reg).BSDREG_REGS(ecx))
+#define BSDREG_Edx(reg)     ((reg).BSDREG_REGS(edx))
+#define BSDREG_Esi(reg)     ((reg).BSDREG_REGS(esi))
+#define BSDREG_Edi(reg)     ((reg).BSDREG_REGS(edi))
+#define BSDREG_Ebp(reg)     ((reg).BSDREG_REGS(ebp))
+#define BSDREG_Eax(reg)     ((reg).BSDREG_REGS(eax))
+#define BSDREG_Eip(reg)     ((reg).BSDREG_REGS(eip))
+#define BSDREG_SegCs(reg)   ((reg).BSDREG_REGS(cs))
+#define BSDREG_EFlags(reg)  ((reg).BSDREG_REGS(eflags))
+#define BSDREG_Esp(reg)     ((reg).BSDREG_REGS(esp))
+#define BSDREG_SegSs(reg)   ((reg).BSDREG_REGS(ss))
 
 #endif // BIT64
 
