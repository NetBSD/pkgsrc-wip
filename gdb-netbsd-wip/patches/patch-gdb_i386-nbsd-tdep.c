$NetBSD$

--- gdb/i386-nbsd-tdep.c.orig	2020-03-25 17:24:08.000000000 +0000
+++ gdb/i386-nbsd-tdep.c
@@ -377,6 +377,8 @@ i386nbsd_init_abi (struct gdbarch_info i
   /* Obviously NetBSD is BSD-based.  */
   i386bsd_init_abi (info, gdbarch);
 
+  nbsd_init_abi (info, gdbarch);
+
   /* NetBSD has a different `struct reg'.  */
   tdep->gregset_reg_offset = i386nbsd_r_reg_offset;
   tdep->gregset_num_regs = ARRAY_SIZE (i386nbsd_r_reg_offset);
