$NetBSD$

--- src/pal/src/thread/context.cpp.orig	2016-02-01 01:55:12.000000000 +0000
+++ src/pal/src/thread/context.cpp
@@ -200,7 +200,7 @@ BOOL CONTEXT_GetRegisters(DWORD processI
         if (ptrace((__ptrace_request)PT_GETREGS, processId, (caddr_t) &ptrace_registers, 0) == -1)
 #elif HAVE_BSD_REGS_T
         struct reg ptrace_registers;
-        if (ptrace(PT_GETREGS, processId, (caddr_t) &ptrace_registers, 0) == -1)
+        if (PAL_PTRACE(PT_GETREGS, processId, &ptrace_registers, 0) == -1)
 #endif
         {
             ASSERT("Failed ptrace(PT_GETREGS, processId:%d) errno:%d (%s)\n",
@@ -349,7 +349,7 @@ CONTEXT_SetThreadContext(
 #if HAVE_PT_REGS
         if (ptrace((__ptrace_request)PT_GETREGS, dwProcessId, (caddr_t)&ptrace_registers, 0) == -1)
 #elif HAVE_BSD_REGS_T
-        if (ptrace(PT_GETREGS, dwProcessId, (caddr_t)&ptrace_registers, 0) == -1)
+        if (PAL_PTRACE(PT_GETREGS, dwProcessId, &ptrace_registers, 0) == -1)
 #endif
         {
             ASSERT("Failed ptrace(PT_GETREGS, processId:%d) errno:%d (%s)\n",
