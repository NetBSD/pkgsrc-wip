$NetBSD$

--- src/pal/src/thread/context.cpp.orig	2016-02-01 01:55:12.000000000 +0000
+++ src/pal/src/thread/context.cpp
@@ -19,6 +19,8 @@ Abstract:
 
 --*/
 
+#if 0
+
 #include "pal/palinternal.h"
 #include "pal/dbgmsg.h"
 #include "pal/context.h"
@@ -200,7 +202,7 @@ BOOL CONTEXT_GetRegisters(DWORD processI
         if (ptrace((__ptrace_request)PT_GETREGS, processId, (caddr_t) &ptrace_registers, 0) == -1)
 #elif HAVE_BSD_REGS_T
         struct reg ptrace_registers;
-        if (ptrace(PT_GETREGS, processId, (caddr_t) &ptrace_registers, 0) == -1)
+        if (PAL_PTRACE(PT_GETREGS, processId, &ptrace_registers, 0) == -1)
 #endif
         {
             ASSERT("Failed ptrace(PT_GETREGS, processId:%d) errno:%d (%s)\n",
@@ -349,7 +351,7 @@ CONTEXT_SetThreadContext(
 #if HAVE_PT_REGS
         if (ptrace((__ptrace_request)PT_GETREGS, dwProcessId, (caddr_t)&ptrace_registers, 0) == -1)
 #elif HAVE_BSD_REGS_T
-        if (ptrace(PT_GETREGS, dwProcessId, (caddr_t)&ptrace_registers, 0) == -1)
+        if (PAL_PTRACE(PT_GETREGS, dwProcessId, &ptrace_registers, 0) == -1)
 #endif
         {
             ASSERT("Failed ptrace(PT_GETREGS, processId:%d) errno:%d (%s)\n",
@@ -1351,3 +1353,5 @@ DBG_FlushInstructionCache(
 
     return TRUE;
 }
+
+#endif
