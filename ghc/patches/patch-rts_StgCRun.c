$NetBSD: patch-rts_StgCRun.c,v 1.1 2012/03/22 23:24:58 phonohawk Exp $

We have to make the visiblity of StgRun and StgReturn to "hidden" not
to trigger a bug in old binutils which results in:

   ld: rts/dist/build/RtsStartup.dyn_o: relocation R_X86_64_PC32
   against `StgRun' can not be used when making a shared object;
   recompile with -fPIC

With this workaround we can no longer override those two symbols using
LD_PRELOAD, but I think there is no reason to do so anyway.

--- rts/StgCRun.c.orig	2012-03-21 03:41:49.000000000 +0000
+++ rts/StgCRun.c
@@ -238,6 +238,7 @@ StgRunIsImplementedInAssembler(void)
          * save callee-saves registers on behalf of the STG code.
          */
         ".globl " STG_RUN "\n"
+        ".hidden " STG_RUN "\n"
         STG_RUN ":\n\t"
         "subq %0, %%rsp\n\t"
         "movq %%rsp, %%rax\n\t"
@@ -259,6 +260,7 @@ StgRunIsImplementedInAssembler(void)
         "jmp *%%rax\n\t"
 
         ".globl " STG_RETURN "\n"
+        ".hidden " STG_RETURN "\n"
          STG_RETURN ":\n\t"
 
         "movq %%rbx, %%rax\n\t"   /* Return value in R1  */
