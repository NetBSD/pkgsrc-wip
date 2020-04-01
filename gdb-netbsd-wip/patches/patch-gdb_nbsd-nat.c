$NetBSD$

--- gdb/nbsd-nat.c.orig	2020-03-25 17:24:08.000000000 +0000
+++ gdb/nbsd-nat.c
@@ -20,10 +20,17 @@
 #include "defs.h"
 
 #include "nbsd-nat.h"
+#include "gdbarch.h"
+#include "gdbthread.h"
+#include "inferior.h"
+#include "regcache.h"
 
 #include <sys/types.h>
 #include <sys/ptrace.h>
 #include <sys/sysctl.h>
+#include <sys/wait.h>
+
+#include <forward_list>
 
 /* Return the name of a file that can be opened to get the symbols for
    the child process identified by PID.  */
@@ -39,3 +46,616 @@ nbsd_nat_target::pid_to_exec_file (int p
     return NULL;
   return buf;
 }
+
+/* Generic thread (LWP) lister within a specified process.  The callback
+   parameters is a C++ function that is called for each detected thread.  */
+
+static void
+nbsd_thread_lister (const pid_t pid,
+		    std::function<bool (const struct kinfo_lwp *)> callback)
+{
+  int mib[5] = {CTL_KERN, KERN_LWP, pid, sizeof (struct kinfo_lwp), 0};
+  size_t size;
+
+  if (sysctl (mib, ARRAY_SIZE (mib), NULL, &size, NULL, 0) == -1 || size == 0)
+    perror_with_name (("sysctl"));
+
+  mib[4] = size / sizeof (size_t);
+
+  gdb::unique_xmalloc_ptr<struct kinfo_lwp> kl
+    ((struct kinfo_lwp *) xcalloc (size, 1));
+  if (kl == NULL)
+    perror_with_name (("calloc"));
+
+  if (sysctl (mib, ARRAY_SIZE (mib), kl.get (), &size, NULL, 0) == -1 ||
+      size == 0)
+    perror_with_name (("sysctl"));
+
+  for (size_t i = 0; i < size / sizeof (struct kinfo_lwp); i++)
+    {
+      struct kinfo_lwp *l = &kl.get ()[i];
+
+      /* Return true if the specified thread is alive.  */
+      auto lwp_alive =
+	[&l]()
+	{
+	  switch (l->l_stat)
+	    {
+	    case LSSLEEP:
+	    case LSRUN:
+	    case LSONPROC:
+	    case LSSTOP:
+	    case LSSUSPENDED:
+	      return true;
+	    default:
+	      return false;
+	    }
+	};
+
+      /* Ignore embryonic or demised threads.  */
+      if (!lwp_alive ())
+	continue;
+
+      if (callback (l))
+	break;
+    }
+}
+
+/* Return true if PTID is still active in the inferior.  */
+
+bool
+nbsd_nat_target::thread_alive (ptid_t ptid)
+{
+  pid_t pid = ptid.pid ();
+  int lwp = ptid.lwp ();
+  bool found = false;
+
+  fprintf_unfiltered (gdb_stderr, "THREAD ALIVE: (pid=%d, lwp=%ld, tid=%ld)\n", ptid.pid (), ptid.lwp (), ptid.tid ());
+  
+  auto fn =
+    [&lwp, &found] (const struct kinfo_lwp *kl)
+    {
+      if (kl->l_lid == lwp)
+	{
+	  found = true;
+	  return true;
+	}
+      return false;
+    };
+
+  nbsd_thread_lister (pid, fn);
+
+  return found;
+}
+
+/* Return the name assigned to a thread by an application.  Returns
+   the string in a static buffer.  */
+
+const char *
+nbsd_nat_target::thread_name (struct thread_info *thr)
+{
+  ptid_t ptid = thr->ptid;
+  pid_t pid = ptid.pid ();
+  int lwp = ptid.lwp ();
+
+  fprintf_unfiltered (gdb_stderr, "THREAD NAME: (pid=%d, lwp=%ld, tid=%ld)\n", ptid.pid (), ptid.lwp (), ptid.tid ());
+  
+  static char buf[KI_LNAMELEN] = {};
+
+  auto fn =
+    [&lwp] (const struct kinfo_lwp *kl)
+    {
+      if (kl->l_lid == lwp)
+	{
+	  xsnprintf (buf, sizeof buf, "%s", kl->l_name);
+	  return true;
+	}
+      return false;
+    };
+
+  nbsd_thread_lister (pid, fn);
+
+  return buf;
+}
+
+/* Implement the "post_attach" target_ops method.  */
+
+static void
+nbsd_add_threads (nbsd_nat_target *target, pid_t pid)
+{
+  fprintf_unfiltered (gdb_stderr, "%s() %s:%d NBSD_ADD_THREADS JESTEM TU !!!!!!!!!!!!!\n", __func__, __FILE__, __LINE__);
+  
+  auto fn =
+    [&target, &pid] (const struct kinfo_lwp *kl)
+    {
+      ptid_t ptid = ptid_t (pid, kl->l_lid, 0);
+      if (!in_thread_list (target, ptid))
+	{
+	  if (inferior_ptid.lwp () == 0)
+	    thread_change_ptid (target, inferior_ptid, ptid);
+	  else
+	    add_thread (target, ptid);
+	}
+      return false;
+    };
+
+  
+  nbsd_thread_lister (pid, fn);
+
+  fprintf_unfiltered (gdb_stderr, "%s() %s:%d NBSD_ADD_THREADS JESTEM TU !!!!!!!!!!!!!\n", __func__, __FILE__, __LINE__);
+}
+
+/* Enable additional event reporting on new processes.  */
+
+static void
+nbsd_enable_proc_events (pid_t pid)
+{
+  int events;
+
+  fprintf_unfiltered (gdb_stderr, "ENABLE PROC EVENTS: (pid=%d)\n", pid);
+
+  if (ptrace (PT_GET_EVENT_MASK, pid, &events, sizeof (events)) == -1)
+    perror_with_name (("ptrace"));
+
+  events |= PTRACE_FORK;
+  events |= PTRACE_VFORK;
+  events |= PTRACE_VFORK_DONE;
+  events |= PTRACE_LWP_CREATE;
+  events |= PTRACE_LWP_EXIT;
+
+  if (ptrace (PT_SET_EVENT_MASK, pid, &events, sizeof (events)) == -1)
+    perror_with_name (("ptrace"));
+}
+
+/* Implement the "post_attach" target_ops method.  */
+
+void
+nbsd_nat_target::post_attach (int pid)
+{
+  fprintf_unfiltered (gdb_stderr, "POST ATTACH: (pid=%d)\n", pid);
+    
+  nbsd_enable_proc_events (pid);
+  nbsd_add_threads (this, pid);
+}
+
+/* Implement the "update_thread_list" target_ops method.  */
+
+void
+nbsd_nat_target::update_thread_list ()
+{
+  fprintf_unfiltered (gdb_stderr, "UPDATE THREAD LIST\n");
+    
+  prune_threads ();
+
+  nbsd_add_threads (this, inferior_ptid.pid ());
+}
+
+/* Convert PTID to a string.  */
+
+std::string
+nbsd_nat_target::pid_to_str (ptid_t ptid)
+{
+  int lwp = ptid.lwp ();
+
+  fprintf_unfiltered (gdb_stderr, "PID TO STR: (pid=%d, lwp=%ld, tid=%ld)\n", ptid.pid (), ptid.lwp (), ptid.tid ());
+  
+  if (lwp != 0)
+    {
+      pid_t pid = ptid.pid ();
+
+      return string_printf ("LWP %d of process %d", lwp, pid);
+    }
+
+  return normal_pid_to_str (ptid);
+}
+
+static std::list<ptid_t> nbsd_pending_children;
+
+/* Record a new child process event that is reported before the                                                                                                                                      
+   corresponding fork event in the parent.  */
+
+static void
+nbsd_remember_child (ptid_t pid)
+{
+  nbsd_pending_children.push_front (pid);
+}
+
+/* Check for a previously-recorded new child process event for PID.                                                                                                                                  
+   If one is found, remove it from the list and return the PTID.  */
+
+static ptid_t
+nbsd_is_child_pending (pid_t pid)
+{
+  for (auto it = nbsd_pending_children.begin ();
+       it != nbsd_pending_children.end (); it++)
+    if (it->pid () == pid)
+      {
+        ptid_t ptid = *it;
+        nbsd_pending_children.erase (it);
+        return ptid;
+      }
+  return null_ptid;
+}
+
+/* Wait for the child specified by PTID to do something.  Return the
+   process ID of the child, or MINUS_ONE_PTID in case of error; store
+   the status in *OURSTATUS.  */
+
+ptid_t
+nbsd_nat_target::wait (ptid_t ptid, struct target_waitstatus *ourstatus,
+                       int target_options)
+{
+  ptid_t wptid;
+
+  while (true)
+    {
+      wptid = inf_ptrace_target::wait (ptid, ourstatus, target_options);
+
+      if (ourstatus->kind != TARGET_WAITKIND_STOPPED)
+	return wptid;
+
+      pid_t pid = wptid. pid();
+
+      /* Extract the event and thread that received a signal.  */
+      ptrace_siginfo_t psi;
+      if (ptrace (PT_GET_SIGINFO, pid, &psi, sizeof (psi)) == -1)
+        perror_with_name (("ptrace"));
+
+      /* Pick child's siginfo_t.  */
+      siginfo_t *si = &psi.psi_siginfo;
+
+      int lwp = psi.psi_lwpid;
+
+      /* Construct PTID.  */
+      wptid = ptid_t (pid, lwp, 0);
+
+      int signo = si->si_signo;
+      int code = si->si_code;
+
+      /* Stop examining here uninteresting events.  */
+      if (signo != SIGTRAP || code <= SI_USER || code == SI_NOINFO)
+	return wptid;
+
+      ptrace_state_t pst;
+      if (ptrace (PT_GET_PROCESS_STATE, pid, &pst, sizeof (pst)) == -1)
+	perror_with_name (("ptrace"));
+
+      int event = pst.pe_report_event;
+      
+      if (code == TRAP_LWP && event == PTRACE_LWP_EXIT)
+	{
+	  /* If GDB attaches to a multi-threaded process, exiting
+	     threads might be skipped during post_attach that
+	     have not yet reported their PL_FLAG_EXITED event.
+	     Ignore EXITED events for an unknown LWP.  */
+	  thread_info *thr = find_thread_ptid (this, wptid);
+	  if (thr != nullptr)
+	    {
+	      delete_thread (thr);
+	    }
+	  if (ptrace (PT_CONTINUE, pid, (void *) 1, 0) == -1)
+	    perror_with_name (("ptrace"));
+	  continue;
+	}
+      
+      /* Switch to an LWP PTID on the first stop in a new process.
+	 This is done after handling PL_FLAG_EXITED to avoid
+	 switching to an exited LWP.  It is done before checking
+	 PL_FLAG_BORN in case the first stop reported after
+	 attaching to an existing process is a PL_FLAG_BORN
+	 event.  */
+
+      bool newborn_process = !in_thread_list (this, ptid_t (pid));
+
+      if (!newborn_process)
+	{
+	  thread_change_ptid (this, ptid_t (pid), wptid);
+	}
+
+      if (code == TRAP_LWP && event == PTRACE_LWP_CREATE)
+	{
+	  /* If GDB attaches to a multi-threaded process, newborn
+	     threads might be added by fbsd_add_threads that have
+	     not yet reported their PL_FLAG_BORN event.  Ignore
+	     BORN events for an already-known LWP.  */
+              if (!in_thread_list (this, wptid))
+                {
+                  add_thread (this, wptid);
+                }
+              ourstatus->kind = TARGET_WAITKIND_SPURIOUS;
+              return wptid;
+	}
+      
+      if (code == TRAP_CHLD && (event == PTRACE_FORK || event == PTRACE_VFORK))
+	{
+	  if (newborn_process)
+	    {
+	      nbsd_remember_child (wptid);
+	      continue;
+	    }
+
+	  bool forked = event == PTRACE_FORK;
+	  ourstatus->kind =
+	    forked ? TARGET_WAITKIND_FORKED : TARGET_WAITKIND_VFORKED;
+
+	  pid_t child = pst.pe_other_pid;
+	  ptid_t child_ptid = nbsd_is_child_pending (child);
+	  if (child_ptid == null_ptid)
+	    {
+	      int status;
+	      pid = waitpid (child, &status, 0);
+	      if (pid == -1)
+		perror_with_name (("waitpid"));
+
+	      gdb_assert (pid == child);
+
+	      if (!WIFSTOPPED (status))
+		  {
+		    /* Abnormal situation (process killed?)... bail out.  */
+		    ourstatus->kind = TARGET_WAITKIND_SPURIOUS;
+		    return wptid;
+		  }
+	      
+	      if (ptrace (PT_GET_SIGINFO, child, &psi, sizeof psi) == -1)
+		perror_with_name (("ptrace"));
+
+	      gdb_assert (psi.psi_siginfo.si_signo == SIGTRAP);
+	      gdb_assert (psi.psi_siginfo.si_code == TRAP_CHLD);
+
+	      child_ptid = ptid_t (child, psi.psi_lwpid, 0);
+	    }
+	  
+	  /* Enable additional events on the child process.  */
+	  nbsd_enable_proc_events (child);
+
+	  ourstatus->value.related_pid = child_ptid;
+
+	  return wptid;
+	}
+
+      if (code == TRAP_CHLD && event == PTRACE_VFORK_DONE)
+	{
+	  ourstatus->kind = TARGET_WAITKIND_VFORK_DONE;
+	  return wptid;
+	}
+
+      if (code == TRAP_EXEC)
+	{
+	  ourstatus->kind = TARGET_WAITKIND_EXECD;
+	  ourstatus->value.execd_pathname = xstrdup (pid_to_exec_file (pid));
+	  return wptid;
+	}
+
+      if (code == TRAP_TRACE || code == TRAP_DBREG)
+	{
+	  /* Unhandled at this level.  */
+	  return wptid;
+	}
+
+      if (code == TRAP_SCE || code == TRAP_SCX)
+	{
+	  int sysnum = si->si_sysnum;
+	  
+	  if (!catch_syscall_enabled () || !catching_syscall_number (sysnum))
+	    {
+	      /* If the core isn't interested in this event, just  
+                 continue the process explicitly and wait for another
+                 event.  */
+              if (ptrace (PT_CONTINUE, pid, (void *) 1, 0) == -1)
+                perror_with_name (("ptrace"));
+              continue;
+	    }
+
+	  ourstatus->kind =
+	    (code == TRAP_SCE) ? TARGET_WAITKIND_SYSCALL_ENTRY :
+	    TARGET_WAITKIND_SYSCALL_RETURN;
+	  ourstatus->value.syscall_number = sysnum;
+	  return wptid;
+	}
+      
+      if (code == TRAP_BRKPT)
+	{
+#if 0
+	  struct regcache *regcache = get_thread_regcache (this, ptid);
+	  struct gdbarch *gdbarch = regcache->arch ();
+	  int decr_pc = gdbarch_decr_pc_after_break (gdbarch);
+
+	  if (decr_pc != 0)
+	    {
+	      CORE_ADDR pc;
+
+	      pc = regcache_read_pc (regcache);
+	      regcache_write_pc (regcache, pc - decr_pc);
+	    }
+#endif	  
+	  return wptid;
+	}
+
+      return wptid;
+    }
+
+  __unreachable();
+}
+
+/* Implement the "post_startup_inferior" target_ops method.  */
+
+void
+nbsd_nat_target::post_startup_inferior (ptid_t ptid)
+{
+  fprintf_unfiltered (gdb_stderr, "POST STARTUP INFERIOR: (pid=%d, lwp=%ld, tid=%ld)\n", ptid.pid (), ptid.lwp (), ptid.tid ());
+  
+  nbsd_enable_proc_events (ptid.pid ());
+}
+
+/* Target hook for follow_fork.  On entry and at return inferior_ptid is
+   the ptid of the followed inferior.  */
+
+bool
+nbsd_nat_target::follow_fork (bool follow_child, bool detach_fork)
+{
+  fprintf_unfiltered (gdb_stderr, "FOLLOW FORK\n");
+    
+  if (!follow_child && detach_fork)
+    {
+      struct thread_info *tp = inferior_thread ();
+      pid_t child_pid = tp->pending_follow.value.related_pid.pid ();
+
+      /* Breakpoints have already been detached from the child by
+         infrun.c.  */
+
+      if (ptrace (PT_DETACH, child_pid, (void *)1, 0) == -1)
+        perror_with_name (("ptrace"));
+    }
+
+  return 0;
+}
+
+/* Implement the "insert_fork_catchpoint" target_ops method.  */
+
+int
+nbsd_nat_target::insert_fork_catchpoint (int pid)
+{
+  fprintf_unfiltered (gdb_stderr, "INSERT FORK CATCHPOINT: (pid=%d)\n", pid);
+    
+  return 0;
+}
+
+/* Implement the "remove_fork_catchpoint" target_ops method.  */
+
+int
+nbsd_nat_target::remove_fork_catchpoint (int pid)
+{
+  fprintf_unfiltered (gdb_stderr, "REMOVE FORK CATCHPOINT: (pid=%d)\n", pid);
+  return 0;
+}
+
+/* Implement the "insert_vfork_catchpoint" target_ops method.  */
+
+int
+nbsd_nat_target::insert_vfork_catchpoint (int pid)
+{
+  fprintf_unfiltered (gdb_stderr, "INSERT VFORK CATCHPOINT: (pid=%d)\n", pid);
+  return 0;
+}
+
+/* Implement the "remove_vfork_catchpoint" target_ops method.  */
+
+int
+nbsd_nat_target::remove_vfork_catchpoint (int pid)
+{
+  fprintf_unfiltered (gdb_stderr, "REMOVE VFORK CATCHPOINT: (pid=%d)\n", pid);
+  return 0;
+}
+
+/* Implement the "insert_exec_catchpoint" target_ops method.  */
+
+int
+nbsd_nat_target::insert_exec_catchpoint (int pid)
+{
+  fprintf_unfiltered (gdb_stderr, "INSERT EXEC CATCHPOINT: (pid=%d)\n", pid);
+  return 0;
+}
+
+/* Implement the "" target_ops method.  */
+
+int
+nbsd_nat_target::remove_exec_catchpoint (int pid)
+{
+  fprintf_unfiltered (gdb_stderr, "REMOVE EXEC CATCHPOINT: (pid=%d)\n", pid);
+  return 0;
+}
+
+/* Implement the "" target_ops method.  */
+
+int
+nbsd_nat_target::set_syscall_catchpoint (int pid, bool needed,
+                                         int any_count,
+                                         gdb::array_view<const int> syscall_counts)
+{
+  fprintf_unfiltered (gdb_stderr, "SET SYSCALL CATCHPOINT: (pid=%d)\n", pid);
+  /* Ignore the arguments.  inf-ptrace.c will use PT_SYSCALL which
+     will catch all system call entries and exits.  The system calls
+     are filtered by GDB rather than the kernel.  */
+  return 0;
+}
+
+/* Implement the "stopped_by_sw_breakpoint" target_ops method.  */
+#if 0
+bool
+nbsd_nat_target::stopped_by_sw_breakpoint ()
+{
+  pid_t pid = inferior_ptid.pid ();
+  ptrace_siginfo_t psi;
+
+  fprintf_unfiltered (gdb_stderr, "STOPPED BY SW BREAKPOINT\n");
+  
+  if (ptrace (PT_GET_SIGINFO, pid, &psi, sizeof (psi)) == -1)
+    return false;
+
+  siginfo_t *si = &psi.psi_siginfo;
+  return si->si_signo == SIGTRAP && si->si_code == TRAP_BRKPT;
+}
+
+/* Implement the "supports_stopped_by_sw_breakpoint" target_ops method.  */
+
+bool
+nbsd_nat_target::supports_stopped_by_sw_breakpoint ()
+{
+  fprintf_unfiltered (gdb_stderr, "SUPPORTS STOPPED BY SW BREAKPOINT\n");
+  return true;
+}
+#endif
+
+/* Implement the "resume" target_ops method.  */
+
+void
+nbsd_nat_target::resume (ptid_t ptid, int step, enum gdb_signal signo)
+{
+  fprintf_unfiltered (gdb_stderr, "RESUME: (pid=%d, lwp=%ld, tid=%ld)\n", ptid.pid (), ptid.lwp (), ptid.tid ());
+
+  if (ptid.lwp_p ())
+    {
+      /* If ptid is a specific LWP, suspend all other LWPs in the process.  */
+      inferior *inf = find_inferior_ptid (this, ptid);
+
+      for (thread_info *tp : inf->non_exited_threads ())
+        {
+          int request;
+
+          if (tp->ptid.lwp () == ptid.lwp ())
+            request = PT_RESUME;
+          else
+            request = PT_SUSPEND;
+
+          if (ptrace (request, tp->ptid.pid (), NULL, tp->ptid.lwp ()) == -1)
+            perror_with_name (("ptrace"));
+        }
+    }
+  else
+    {
+      /* If ptid is a wildcard, resume all matching threads (they won't run
+         until the process is continued however).  */
+      for (thread_info *tp : all_non_exited_threads (this, ptid))
+        if (ptrace (PT_RESUME, tp->ptid.pid (), NULL, tp->ptid.lwp ()) == -1)
+          perror_with_name (("ptrace"));
+      ptid = inferior_ptid;
+    }
+
+  if (step)
+    {
+      for (thread_info *tp : all_non_exited_threads (this, ptid))
+	if (ptrace (PT_SETSTEP, tp->ptid.pid (), NULL, tp->ptid.lwp ()) == -1)
+	  perror_with_name (("ptrace"));
+      step = 0;
+    }
+  else
+    {
+      for (thread_info *tp : all_non_exited_threads (this, ptid))
+	if (ptrace (PT_CLEARSTEP, tp->ptid.pid (), NULL, tp->ptid.lwp ()) == -1)
+	  perror_with_name (("ptrace"));
+    }
+
+  ptid = ptid_t (ptid.pid ());
+
+  inf_ptrace_target::resume (ptid, step, signo);
+}
