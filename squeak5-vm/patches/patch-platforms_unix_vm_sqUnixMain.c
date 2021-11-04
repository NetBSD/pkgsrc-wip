$NetBSD$

--- platforms/unix/vm/sqUnixMain.c.orig	2020-03-02 17:30:55.000000000 +0000
+++ platforms/unix/vm/sqUnixMain.c
@@ -933,6 +933,9 @@ reportStackState(char *msg, char *date, 
 # elif __FreeBSD__ && __amd64__
 			void *fp = (void *)(uap ? uap->uc_mcontext.mc_rbp : 0);
 			void *sp = (void *)(uap ? uap->uc_mcontext.mc_rsp : 0);
+# elif __NetBSD__ && __x86_64__
+			void *fp = (void *)(uap ? _UC_MACHINE_FP(uap) : 0);
+			void *sp = (void *)(uap ? _UC_MACHINE_SP(uap) : 0);
 # elif __OpenBSD__ && __i386__
 			void *fp = (void *)(uap ? uap->sc_ebp : 0);
 			void *sp = (void *)(uap ? uap->sc_esp : 0);
@@ -1008,6 +1011,19 @@ printRegisterState(ucontext_t *uap)
 			regs->mc_edi, regs->mc_edi, regs->mc_ebp, regs->mc_esp,
 			regs->mc_eip);
 	return regs->mc_eip;
+#elif __NetBSD__ && __x86_64__
+	__greg_t *regs = &uap->uc_mcontext.__gregs;
+	printf(	"\trax 0x%08lx rbx 0x%08lx rcx 0x%08lx rdx 0x%08lx\n"
+			"\trdi 0x%08lx rsi 0x%08lx rbp 0x%08lx rsp 0x%08lx\n"
+			"\tr8  0x%08lx r9  0x%08lx r10 0x%08lx r11 0x%08lx\n"
+			"\tr12 0x%08lx r13 0x%08lx r14 0x%08lx r15 0x%08lx\n"
+			"\trip 0x%08lx\n",
+			regs[_REG_RAX], regs[_REG_RBX], regs[_REG_RCX], regs[_REG_RDX],
+			regs[_REG_RDI], regs[_REG_RSI], regs[_REG_RBP], regs[_REG_RSP],
+			regs[_REG_R8 ], regs[_REG_R9 ], regs[_REG_R10], regs[_REG_R11],
+			regs[_REG_R12], regs[_REG_R13], regs[_REG_R14], regs[_REG_R15],
+			regs[_REG_RIP]);
+	return (void *)regs[_REG_RIP];
 #elif __linux__ && __x86_64__
 	greg_t *regs = (greg_t *)&uap->uc_mcontext.gregs;
 	printf(	"\trax 0x%08lx rbx 0x%08lx rcx 0x%08lx rdx 0x%08lx\n"
