$NetBSD$

--- src/pal/src/thread/context.cpp.orig	2016-01-31 18:28:53.000000000 +0000
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
@@ -634,6 +634,7 @@ DWORD CONTEXTGetExceptionCodeForSignal(c
                 case SEGV_MAPERR:   // Address not mapped to object
                 case SEGV_ACCERR:   // Invalid permissions for mapped object
                     return EXCEPTION_ACCESS_VIOLATION;
+#ifdef SI_KERNEL
                 case SI_KERNEL:
                 {
                     // Identify privileged instructions that are not identified as such by the system
@@ -647,6 +648,7 @@ DWORD CONTEXTGetExceptionCodeForSignal(c
                     }
                     // fall through
                 }
+#endif
                 default:
                     break;
             }
@@ -665,7 +667,9 @@ DWORD CONTEXTGetExceptionCodeForSignal(c
         case SIGTRAP:
             switch (siginfo->si_code)
             {
+#ifdef SI_KERNEL
                 case SI_KERNEL:
+#endif
                 case SI_USER:
                 case TRAP_BRKPT:    // Process breakpoint
                     return EXCEPTION_BREAKPOINT;
