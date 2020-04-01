$NetBSD$

--- gdb/nbsd-nat.h.orig	2020-03-25 17:24:08.000000000 +0000
+++ gdb/nbsd-nat.h
@@ -22,11 +22,37 @@
 
 #include "inf-ptrace.h"
 
+struct thread_info;
+
 /* A prototype NetBSD target.  */
 
 struct nbsd_nat_target : public inf_ptrace_target
 {
   char *pid_to_exec_file (int pid) override;
+
+  bool thread_alive (ptid_t ptid) override;
+  const char *thread_name (struct thread_info *thr) override;
+  void post_attach (int pid) override;
+  void update_thread_list () override;
+  std::string pid_to_str (ptid_t ptid) override;
+  ptid_t wait (ptid_t ptid, struct target_waitstatus *ourstatus,
+	       int target_options) override;
+  void post_startup_inferior (ptid_t ptid) override;
+  bool follow_fork (bool follow_child, bool detach_fork) override;
+  int insert_fork_catchpoint (int pid) override;
+  int remove_fork_catchpoint (int pid) override;
+  int insert_vfork_catchpoint (int pid) override;
+  int remove_vfork_catchpoint (int pid) override;
+  int insert_exec_catchpoint (int pid) override;
+  int remove_exec_catchpoint (int pid) override;
+  int set_syscall_catchpoint (int pid, bool needed, int any_count,
+			      gdb::array_view<const int> syscall_counts)
+    override;
+#if 0
+  bool stopped_by_sw_breakpoint () override;
+  bool supports_stopped_by_sw_breakpoint () override;
+#endif
+  void resume (ptid_t ptid, int step, enum gdb_signal signo) override;
 };
 
 #endif /* nbsd-nat.h */
