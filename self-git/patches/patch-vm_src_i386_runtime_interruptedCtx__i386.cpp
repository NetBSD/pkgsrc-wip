$NetBSD$

--- vm/src/i386/runtime/interruptedCtx_i386.cpp.orig	2019-07-22 01:11:46.000000000 +0000
+++ vm/src/i386/runtime/interruptedCtx_i386.cpp
@@ -101,6 +101,18 @@ int* InterruptedContext::ebp_addr() {
   return (int*) &((ucontext_t*) scp)->uc_mcontext.gregs[REG_FP];
 }
 
+# elif TARGET_OS_VERSION == NETBSD_VERSION
+
+  char** InterruptedContext::pc_addr() {
+    return  (char**) &scp->uc_mcontext.__gregs[_REG_EIP]; // see /usr/include/asm-i386/sigcontext.h
+  }
+  int* InterruptedContext::sp_addr() {
+    return  (int*) &scp->uc_mcontext.__gregs[_REG_ESP];
+  }
+  int* InterruptedContext::ebp_addr() {
+    return  (int*) &scp->uc_mcontext.__gregs[_REG_EBP];
+  }
+
 # else
   # error What OS version?
 # endif
@@ -180,6 +192,29 @@ void InterruptedContext::print_registers
   lprintf("err       = 0x%x\n", gregs[ERR]);
   lprintf("uesp      = 0x%x\n", gregs[UESP]);
 
+  # elif TARGET_OS_VERSION == NETBSD_VERSION
+
+    __greg_t *gregs = ic->scp->uc_mcontext.__gregs;
+    lprintf("eax       = 0x%x\n", gregs[_REG_EAX]);
+    lprintf("ebx       = 0x%x\n", gregs[_REG_EBX]);
+    lprintf("ecx       = 0x%x\n", gregs[_REG_ECX]);
+    lprintf("edx       = 0x%x\n", gregs[_REG_EDX]);
+    lprintf("esi       = 0x%x\n", gregs[_REG_ESI]);
+    lprintf("edi       = 0x%x\n", gregs[_REG_EDI]);
+    lprintf("ebp       = 0x%x\n", gregs[_REG_EBP]);
+    lprintf("esp       = 0x%x\n", gregs[_REG_ESP]);
+    lprintf("ss        = 0x%x\n", gregs[_REG_SS]);
+    lprintf("efl       = 0x%x\n", gregs[_REG_EFL]);
+    lprintf("eip       = 0x%x\n", gregs[_REG_EIP]);
+    lprintf("cs        = 0x%x\n", gregs[_REG_CS]);
+    lprintf("ds        = 0x%x\n", gregs[_REG_DS]);
+    lprintf("es        = 0x%x\n", gregs[_REG_ES]);
+    lprintf("fs        = 0x%x\n", gregs[_REG_FS]);
+    lprintf("gs        = 0x%x\n", gregs[_REG_GS]);
+    lprintf("trapno    = 0x%x\n", gregs[_REG_TRAPNO]);
+    lprintf("err       = 0x%x\n", gregs[_REG_ERR]);
+    lprintf("uesp      = 0x%x\n", gregs[_REG_UESP]);
+
   # else
 	# error What OS?
   # endif
