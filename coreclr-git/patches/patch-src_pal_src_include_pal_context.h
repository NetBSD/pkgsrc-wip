$NetBSD$

--- src/pal/src/include/pal/context.h.orig	2016-02-02 22:59:18.000000000 +0000
+++ src/pal/src/include/pal/context.h
@@ -334,43 +334,47 @@ typedef ucontext_t native_context_t;
 
 #if HAVE_BSD_REGS_T
 
+#ifndef BSD_REGS_STYLE
+#error "struct reg" has unrecognized format
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
+#define BSDREG_Rbx(reg)     BSD_REGS_STYLE(reg,RBX,rbx)
+#define BSDREG_Rcx(reg)     BSD_REGS_STYLE(reg,RCX,rcx)
+#define BSDREG_Rdx(reg)     BSD_REGS_STYLE(reg,RDX,rdx)
+#define BSDREG_Rsi(reg)     BSD_REGS_STYLE(reg,RSI,rsi)
+#define BSDREG_Rdi(reg)     BSD_REGS_STYLE(reg,RDI,rdi)
+#define BSDREG_Rbp(reg)     BSD_REGS_STYLE(reg,RBP,rbp)
+#define BSDREG_Rax(reg)     BSD_REGS_STYLE(reg,RAX,rax)
+#define BSDREG_Rip(reg)     BSD_REGS_STYLE(reg,RIP,rip)
+#define BSDREG_SegCs(reg)   BSD_REGS_STYLE(reg,CS,cs)
+#define BSDREG_SegSs(reg)   BSD_REGS_STYLE(reg,SS,ss)
+#define BSDREG_Rsp(reg)     BSD_REGS_STYLE(reg,RSP,rsp)
+#define BSDREG_R8(reg)      BSD_REGS_STYLE(reg,R8,r8)
+#define BSDREG_R9(reg)      BSD_REGS_STYLE(reg,R9,r9)
+#define BSDREG_R10(reg)     BSD_REGS_STYLE(reg,R10,r10)
+#define BSDREG_R11(reg)     BSD_REGS_STYLE(reg,R11,r11)
+#define BSDREG_R12(reg)     BSD_REGS_STYLE(reg,R12,r12)
+#define BSDREG_R13(reg)     BSD_REGS_STYLE(reg,R13,r13)
+#define BSDREG_R14(reg)     BSD_REGS_STYLE(reg,R14,r14)
+#define BSDREG_R15(reg)     BSD_REGS_STYLE(reg,R15,r15)
+#define BSDREG_EFlags(reg)  BSD_REGS_STYLE(reg,RFLAGS,rflags)
 
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
+#define BSDREG_Ebx(reg)     BSD_REGS_STYLE(reg,EBX,ebx)
+#define BSDREG_Ecx(reg)     BSD_REGS_STYLE(reg,ECX,ecx)
+#define BSDREG_Edx(reg)     BSD_REGS_STYLE(reg,EDX,edx)
+#define BSDREG_Esi(reg)     BSD_REGS_STYLE(reg,ESI,esi)
+#define BSDREG_Edi(reg)     BSD_REGS_STYLE(reg,EDI,edi)
+#define BSDREG_Ebp(reg)     BSD_REGS_STYLE(reg,EDP,ebp)
+#define BSDREG_Eax(reg)     BSD_REGS_STYLE(reg,EAX,eax)
+#define BSDREG_Eip(reg)     BSD_REGS_STYLE(reg,EIP,eip)
+#define BSDREG_SegCs(reg)   BSD_REGS_STYLE(reg,CS,cs)
+#define BSDREG_EFlags(reg)  BSD_REGS_STYLE(reg,EFLAGS,eflags)
+#define BSDREG_Esp(reg)     BSD_REGS_STYLE(reg,ESP,esp)
+#define BSDREG_SegSs(reg)   BSD_REGS_STYLE(reg,SS,ss)
 
 #endif // BIT64
 
