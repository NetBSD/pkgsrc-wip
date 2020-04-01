$NetBSD$

--- gdb/ppc-nbsd-tdep.c.orig	2020-03-25 17:24:08.000000000 +0000
+++ gdb/ppc-nbsd-tdep.c
@@ -173,6 +173,8 @@ static void
 ppcnbsd_init_abi (struct gdbarch_info info,
                   struct gdbarch *gdbarch)
 {
+  nbsd_init_abi (info, gdbarch);
+
   /* For NetBSD, this is an on again, off again thing.  Some systems
      do use the broken struct convention, and some don't.  */
   set_gdbarch_return_value (gdbarch, ppcnbsd_return_value);
