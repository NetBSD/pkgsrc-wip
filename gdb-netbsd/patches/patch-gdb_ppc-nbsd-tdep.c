$NetBSD$

--- gdb/ppc-nbsd-tdep.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/ppc-nbsd-tdep.c
@@ -195,7 +195,7 @@ _initialize_ppcnbsd_tdep (void)
 			  ppcnbsd_init_abi);
 
   /* Avoid initializing the register offsets again if they were
-     already initialized by ppcnbsd-nat.c.  */
+     already initailized by ppcnbsd-nat.c.  */
   if (ppcnbsd_reg_offsets.pc_offset == 0)
     {
       /* General-purpose registers.  */
