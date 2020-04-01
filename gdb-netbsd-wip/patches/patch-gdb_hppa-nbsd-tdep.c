$NetBSD$

--- gdb/hppa-nbsd-tdep.c.orig	2020-03-25 17:24:08.000000000 +0000
+++ gdb/hppa-nbsd-tdep.c
@@ -201,6 +201,8 @@ hppanbsd_init_abi (struct gdbarch_info i
   /* Obviously NetBSD is BSD-based.  */
   hppabsd_init_abi (info, gdbarch);
 
+  nbsd_init_abi (info, gdbarch);
+
   /* Core file support.  */
   set_gdbarch_iterate_over_regset_sections
     (gdbarch, hppanbsd_iterate_over_regset_sections);
