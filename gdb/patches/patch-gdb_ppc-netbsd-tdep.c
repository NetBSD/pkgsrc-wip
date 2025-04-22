$NetBSD$

Blindly adapted for renamed sources on a Linux host. Someone
please verify on NetBSD/PPC.

Original patch:
NetBSD: patch-gdb_ppc-nbsd-tdep.c,v 1.2 2022/12/11 03:51:55 mef Exp

Incorporate changes from r1.7 to r1.9 of in-tree gdb:

1.9:
PR port-powerpc/56899

Disable 128-bit long double for NetBSD/powerpc.

1.8:
PR port-powerpc/56899

In addition to ``powerpc'', register NetBSD OS ABI also for ``rs6000'',
which is default target for powerpc.

1.7:
fix powerpc (by including ppc-nbsd-tdep.h)




--- gdb/ppc-netbsd-tdep.c.orig	2024-12-29 02:50:07.000000000 +0000
+++ gdb/ppc-netbsd-tdep.c
@@ -174,6 +174,10 @@ ppcnbsd_init_abi (struct gdbarch_info in
 {
   nbsd_init_abi (info, gdbarch);
 
+  /* NetBSD doesn't support the 128-bit `long double' from the psABI.  */
+  set_gdbarch_long_double_bit (gdbarch, 64);
+  set_gdbarch_long_double_format (gdbarch, floatformats_ieee_double);
+  
   /* For NetBSD, this is an on again, off again thing.  Some systems
      do use the broken struct convention, and some don't.  */
   set_gdbarch_return_value (gdbarch, ppcnbsd_return_value);
@@ -195,6 +199,8 @@ _initialize_ppcnbsd_tdep ()
 {
   gdbarch_register_osabi (bfd_arch_powerpc, 0, GDB_OSABI_NETBSD,
 			  ppcnbsd_init_abi);
+  gdbarch_register_osabi (bfd_arch_rs6000, 0, GDB_OSABI_NETBSD,
+                         ppcnbsd_init_abi);
 
   /* Avoid initializing the register offsets again if they were
      already initialized by ppc-netbsd-nat.c.  */
