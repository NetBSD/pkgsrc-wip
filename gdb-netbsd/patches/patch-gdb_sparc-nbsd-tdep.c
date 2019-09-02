$NetBSD$

--- gdb/sparc-nbsd-tdep.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/sparc-nbsd-tdep.c
@@ -32,6 +32,7 @@
 #include "gdbarch.h"
 
 #include "sparc-tdep.h"
+#include "sparc-nbsd-tdep.h"
 #include "nbsd-tdep.h"
 
 /* Macros to extract fields from SPARC instructions.  */
@@ -291,7 +292,7 @@ static const struct regset sparc32nbsd_f
     NULL, sparc32nbsd_supply_fpregset, NULL
   };
 
-void
+static void
 sparc32nbsd_init_abi (struct gdbarch_info info, struct gdbarch *gdbarch)
 {
   struct gdbarch_tdep *tdep = gdbarch_tdep (gdbarch);
@@ -310,6 +311,12 @@ sparc32nbsd_init_abi (struct gdbarch_inf
   tdep->step_trap = sparcnbsd_step_trap;
 
   frame_unwind_append_unwinder (gdbarch, &sparc32nbsd_sigcontext_frame_unwind);
+}
+
+void
+sparc32nbsd_elf_init_abi (struct gdbarch_info info, struct gdbarch *gdbarch)
+{
+  sparc32nbsd_init_abi (info, gdbarch);
 
   set_solib_svr4_fetch_link_map_offsets
     (gdbarch, svr4_ilp32_fetch_link_map_offsets);
@@ -319,5 +326,5 @@ void
 _initialize_sparcnbsd_tdep (void)
 {
   gdbarch_register_osabi (bfd_arch_sparc, 0, GDB_OSABI_NETBSD,
-			  sparc32nbsd_init_abi);
+			  sparc32nbsd_elf_init_abi);
 }
