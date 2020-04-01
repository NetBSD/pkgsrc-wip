$NetBSD$

--- gdb/arm-nbsd-tdep.c.orig	2020-03-25 17:24:08.000000000 +0000
+++ gdb/arm-nbsd-tdep.c
@@ -150,6 +150,9 @@ arm_netbsd_elf_init_abi (struct gdbarch_
   struct gdbarch_tdep *tdep = gdbarch_tdep (gdbarch);
 
   arm_netbsd_init_abi_common (info, gdbarch);
+
+  nbsd_init_abi (info, gdbarch);
+
   if (tdep->fp_model == ARM_FLOAT_AUTO)
     tdep->fp_model = ARM_FLOAT_SOFT_VFP;
 
