$NetBSD$

--- gdb/amd64-nbsd-tdep.c.orig	2020-03-25 17:24:08.000000000 +0000
+++ gdb/amd64-nbsd-tdep.c
@@ -106,6 +106,7 @@ amd64nbsd_init_abi (struct gdbarch_info 
 
   amd64_init_abi (info, gdbarch,
 		  amd64_target_description (X86_XSTATE_SSE_MASK, true));
+  nbsd_init_abi (info, gdbarch);
 
   tdep->jb_pc_offset = 7 * 8;
 
