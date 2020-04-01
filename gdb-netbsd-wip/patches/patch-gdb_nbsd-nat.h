$NetBSD$

--- gdb/nbsd-nat.h.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/nbsd-nat.h
@@ -27,6 +27,27 @@
 struct nbsd_nat_target : public inf_ptrace_target
 {
   char *pid_to_exec_file (int pid) override;
+  int find_memory_regions (find_memory_region_ftype func, void *data) override;
+
+  bool thread_alive (ptid_t ptid) override;
+  std::string pid_to_str (ptid_t) override;
+
+  const char *thread_name (struct thread_info *) override;
+
+  void update_thread_list () override;
+
+  thread_control_capabilities get_thread_control_capabilities () override
+  { return tc_schedlock; }
+
+  void resume (ptid_t, int, enum gdb_signal) override;
+
+  ptid_t wait (ptid_t, struct target_waitstatus *, int) override;
+
+  void post_startup_inferior (ptid_t) override;
+  void post_attach (int) override;
+
+  int follow_fork (int, int) override;
+
 };
 
 #endif /* nbsd-nat.h */
