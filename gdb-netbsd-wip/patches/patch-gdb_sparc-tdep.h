$NetBSD$

--- gdb/sparc-tdep.h.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/sparc-tdep.h
@@ -252,20 +252,4 @@ extern const char *sparc_sol2_static_tra
 extern void sparc32_sol2_init_abi (struct gdbarch_info info,
 				   struct gdbarch *gdbarch);
 
-/* Functions and variables exported from sparcnbsd-tdep.c.  */
-
-/* Register offsets for NetBSD.  */
-extern const struct sparc_gregmap sparc32nbsd_gregmap;
-
-/* Return the address of a system call's alternative return
-   address.  */
-extern CORE_ADDR sparcnbsd_step_trap (struct frame_info *frame,
-				      unsigned long insn);
-
-extern void sparc32nbsd_init_abi (struct gdbarch_info info,
-				  struct gdbarch *gdbarch);
-
-extern struct trad_frame_saved_reg *
-  sparc32nbsd_sigcontext_saved_regs (struct frame_info *next_frame);
-
 #endif /* sparc-tdep.h */
