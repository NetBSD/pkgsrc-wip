$NetBSD$

--- gdb/arm-nbsd-tdep.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/arm-nbsd-tdep.c
@@ -22,6 +22,7 @@
 
 #include "arch/arm.h"
 #include "arm-tdep.h"
+#include "nbsd-tdep.h"
 #include "solib-svr4.h"
 
 /* Description of the longjmp buffer.  */
@@ -42,7 +43,7 @@ arm_netbsd_init_abi_common (struct gdbar
   struct gdbarch_tdep *tdep = gdbarch_tdep (gdbarch);
 
   tdep->lowest_pc = 0x8000;
-  switch (info.byte_order)
+  switch (info.byte_order_for_code)
     {
     case BFD_ENDIAN_LITTLE:
       tdep->arm_breakpoint = arm_nbsd_arm_le_breakpoint;
@@ -68,8 +69,23 @@ arm_netbsd_init_abi_common (struct gdbar
 
   /* Single stepping.  */
   set_gdbarch_software_single_step (gdbarch, arm_software_single_step);
+  /* Core support */
+  set_gdbarch_iterate_over_regset_sections
+    (gdbarch, armbsd_iterate_over_regset_sections);
+
 }
-  
+
+static void
+arm_netbsd_aout_init_abi (struct gdbarch_info info,
+			  struct gdbarch *gdbarch)
+{
+  struct gdbarch_tdep *tdep = gdbarch_tdep (gdbarch);
+
+  arm_netbsd_init_abi_common (info, gdbarch);
+  if (tdep->fp_model == ARM_FLOAT_AUTO)
+    tdep->fp_model = ARM_FLOAT_SOFT_FPA;
+}
+
 static void
 arm_netbsd_elf_init_abi (struct gdbarch_info info,
 			 struct gdbarch *gdbarch)
@@ -83,6 +99,9 @@ arm_netbsd_elf_init_abi (struct gdbarch_
   /* NetBSD ELF uses SVR4-style shared libraries.  */
   set_solib_svr4_fetch_link_map_offsets
     (gdbarch, svr4_ilp32_fetch_link_map_offsets);
+
+  /* for single stepping; see PR/50773 */
+  set_gdbarch_skip_solib_resolver (gdbarch, nbsd_skip_solib_resolver);
 }
 
 void
