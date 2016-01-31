$NetBSD$

--- src/pal/src/thread/context.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/thread/context.cpp
@@ -51,9 +51,14 @@ extern void CONTEXT_CaptureContext(LPCON
 #if !HAVE_MACH_EXCEPTIONS
 
 #if HAVE_BSD_REGS_T
+#if HAVE_MACHINE_REG_H
 #include <machine/reg.h>
+#endif
+#if HAVE_MACHINE_NPX_H
 #include <machine/npx.h>
+#endif
 #endif  // HAVE_BSD_REGS_T
+
 #if HAVE_PT_REGS
 #include <asm/ptrace.h>
 #endif  // HAVE_PT_REGS
