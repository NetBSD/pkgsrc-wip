$NetBSD$

--- gdb/hppa-tdep.h.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/hppa-tdep.h
@@ -215,4 +215,6 @@ extern int hppa_in_solib_call_trampoline
 					  CORE_ADDR pc);
 extern CORE_ADDR hppa_skip_trampoline_code (struct frame_info *, CORE_ADDR pc);
 
+void _initialize_hppabsd_tdep (void);
+
 #endif  /* hppa-tdep.h */
