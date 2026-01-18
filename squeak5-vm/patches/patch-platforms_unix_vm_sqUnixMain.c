$NetBSD$

--- platforms/unix/vm/sqUnixMain.c.orig	2025-12-16 16:09:40.000000000 +0000
+++ platforms/unix/vm/sqUnixMain.c
@@ -1042,6 +1042,19 @@ printRegisterState(FILE *file,ucontext_t
 			v(regs[REG_R12]),v(regs[REG_R13]),v(regs[REG_R14]),v(regs[REG_R15]),
 			v(regs[REG_RIP]));
 	return v(regs[REG_RIP]);
+#elif __NetBSD__ && __x86_64__
+	__gregset_t *regs = &uap->uc_mcontext.__gregs;
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
 # elif __OpenBSD__ && __x86_64__
 	fprintf(file,
 			"    rax %14p rbx %14p rcx %14p rdx %14p\n"
