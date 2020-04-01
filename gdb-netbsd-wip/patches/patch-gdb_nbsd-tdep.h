$NetBSD$

--- gdb/nbsd-tdep.h.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/nbsd-tdep.h
@@ -25,4 +25,6 @@ struct link_map_offsets *nbsd_lp64_solib
 
 int nbsd_pc_in_sigtramp (CORE_ADDR, const char *);
 
+CORE_ADDR nbsd_skip_solib_resolver (struct gdbarch *gdbarch,
+				    CORE_ADDR pc);
 #endif /* NBSD_TDEP_H */
