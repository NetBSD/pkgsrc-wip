$NetBSD$

--- gdb/alpha-nbsd-tdep.c.orig	2020-03-25 17:24:08.000000000 +0000
+++ gdb/alpha-nbsd-tdep.c
@@ -258,6 +258,8 @@ alphanbsd_init_abi (struct gdbarch_info 
   /* Hook into the MDEBUG frame unwinder.  */
   alpha_mdebug_init_abi (info, gdbarch);
 
+  nbsd_init_abi (info, gdbarch);
+
   /* NetBSD/alpha does not provide single step support via ptrace(2); we
      must use software single-stepping.  */
   set_gdbarch_software_single_step (gdbarch, alpha_software_single_step);
