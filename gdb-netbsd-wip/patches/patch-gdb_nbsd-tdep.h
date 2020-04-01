$NetBSD$

--- gdb/nbsd-tdep.h.orig	2020-03-25 17:24:08.000000000 +0000
+++ gdb/nbsd-tdep.h
@@ -25,4 +25,8 @@ struct link_map_offsets *nbsd_lp64_solib
 
 int nbsd_pc_in_sigtramp (CORE_ADDR, const char *);
 
+/* NetBSD specific set of ABI-related routines.  */
+
+void nbsd_init_abi (struct gdbarch_info, struct gdbarch *);
+
 #endif /* NBSD_TDEP_H */
