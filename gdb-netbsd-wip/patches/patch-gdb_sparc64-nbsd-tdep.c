$NetBSD$

--- gdb/sparc64-nbsd-tdep.c.orig	2020-03-25 17:24:08.000000000 +0000
+++ gdb/sparc64-nbsd-tdep.c
@@ -249,6 +249,8 @@ sparc64nbsd_init_abi (struct gdbarch_inf
 {
   struct gdbarch_tdep *tdep = gdbarch_tdep (gdbarch);
 
+  nbsd_init_abi (info, gdbarch);
+
   tdep->gregset = &sparc64nbsd_gregset;
   tdep->sizeof_gregset = 160;
 
