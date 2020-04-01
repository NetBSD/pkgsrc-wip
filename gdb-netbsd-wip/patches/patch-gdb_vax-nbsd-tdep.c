$NetBSD$

--- gdb/vax-nbsd-tdep.c.orig	2020-03-25 17:24:08.000000000 +0000
+++ gdb/vax-nbsd-tdep.c
@@ -29,6 +29,8 @@
 static void
 vaxnbsd_elf_init_abi (struct gdbarch_info info, struct gdbarch *gdbarch)
 {
+  nbsd_init_abi (info, gdbarch);
+
   /* NetBSD ELF uses SVR4-style shared libraries.  */
   set_solib_svr4_fetch_link_map_offsets
     (gdbarch, svr4_ilp32_fetch_link_map_offsets);
