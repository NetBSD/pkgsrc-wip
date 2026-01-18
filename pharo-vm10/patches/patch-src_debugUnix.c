$NetBSD$

support NetBSD/amd64

--- src/debugUnix.c.orig	2025-11-17 14:10:09.000000000 +0000
+++ src/debugUnix.c
@@ -23,6 +23,12 @@
 
 #endif
 
+#if __NetBSD__
+
+#include <ucontext.h>
+
+#endif
+
 #ifdef HAVE_EXECINFO_H
 # include <execinfo.h>
 #endif
@@ -279,6 +285,20 @@ void * printRegisterState(ucontext_t *ua
 			regs->mc_edi, regs->mc_edi, regs->mc_ebp, regs->mc_esp,
 			regs->mc_eip);
 	return regs->mc_eip;
+#elif __NetBSD__ && __x86_64__
+	__gregset_t *regs = &uap->uc_mcontext.__gregs;
+	fprintf_impl(output,
+			"\trax 0x%08llx rbx 0x%08llx rcx 0x%08llx rdx 0x%08llx\n"
+			"\trdi 0x%08llx rsi 0x%08llx rbp 0x%08llx rsp 0x%08llx\n"
+			"\tr8  0x%08llx r9  0x%08llx r10 0x%08llx r11 0x%08llx\n"
+			"\tr12 0x%08llx r13 0x%08llx r14 0x%08llx r15 0x%08llx\n"
+			"\trip 0x%08llx\n",
+			regs[_REG_RAX], regs[_REG_RBX], regs[_REG_RCX], regs[_REG_RDX],
+			regs[_REG_RDI], regs[_REG_RSI], regs[_REG_RBP], regs[_REG_RSP],
+			regs[_REG_R8 ], regs[_REG_R9 ], regs[_REG_R10], regs[_REG_R11],
+			regs[_REG_R12], regs[_REG_R13], regs[_REG_R14], regs[_REG_R15],
+			regs[_REG_RIP]);
+	return (void *)regs[_REG_RIP];
 #elif __linux__ && __x86_64__
 	greg_t *regs = uap->uc_mcontext.gregs;
 	fprintf_impl(output,
@@ -442,6 +462,9 @@ void reportStackState(const char *msg, c
 # elif __FreeBSD__ && __x86_64__
 			void *fp = (void *)(uap ? uap->uc_mcontext.mc_rbp: 0);
 			void *sp = (void *)(uap ? uap->uc_mcontext.mc_rsp: 0);
+#elif __NetBSD__
+			void *fp = (void *)(uap ? _UC_MACHINE_FP(uap) : 0);
+			void *sp = (void *)(uap ? _UC_MACHINE_SP(uap) : 0);
 # elif __OpenBSD__
 			void *fp = (void *)(uap ? uap->sc_rbp: 0);
 			void *sp = (void *)(uap ? uap->sc_rsp: 0);
