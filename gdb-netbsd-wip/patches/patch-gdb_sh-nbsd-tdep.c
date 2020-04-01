$NetBSD$

--- gdb/sh-nbsd-tdep.c.orig	2020-03-25 17:24:08.000000000 +0000
+++ gdb/sh-nbsd-tdep.c
@@ -63,6 +63,7 @@ shnbsd_init_abi (struct gdbarch_info inf
                   struct gdbarch *gdbarch)
 {
   struct gdbarch_tdep *tdep = gdbarch_tdep (gdbarch);
+  nbsd_init_abi (info, gdbarch);
 
   tdep->core_gregmap = (struct sh_corefile_regmap *)regmap;
   tdep->sizeof_gregset = 84;
