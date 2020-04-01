$NetBSD$

--- gdb/sparc-nbsd-tdep.c.orig	2020-03-25 17:24:08.000000000 +0000
+++ gdb/sparc-nbsd-tdep.c
@@ -296,6 +296,8 @@ sparc32nbsd_init_abi (struct gdbarch_inf
 {
   struct gdbarch_tdep *tdep = gdbarch_tdep (gdbarch);
 
+  nbsd_init_abi (info, gdbarch);
+
   /* NetBSD doesn't support the 128-bit `long double' from the psABI.  */
   set_gdbarch_long_double_bit (gdbarch, 64);
   set_gdbarch_long_double_format (gdbarch, floatformats_ieee_double);
