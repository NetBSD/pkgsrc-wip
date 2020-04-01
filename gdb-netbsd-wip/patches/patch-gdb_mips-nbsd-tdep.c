$NetBSD$

--- gdb/mips-nbsd-tdep.c.orig	2020-03-25 17:24:08.000000000 +0000
+++ gdb/mips-nbsd-tdep.c
@@ -354,6 +354,8 @@ static void
 mipsnbsd_init_abi (struct gdbarch_info info,
                    struct gdbarch *gdbarch)
 {
+  nbsd_init_abi (info, gdbarch)
+
   set_gdbarch_iterate_over_regset_sections
     (gdbarch, mipsnbsd_iterate_over_regset_sections);
 
