$NetBSD$

--- gdb/gdbserver/netbsd-low.c.orig	2019-09-02 20:02:23.503085722 +0000
+++ gdb/gdbserver/netbsd-low.c
@@ -0,0 +1,2084 @@
+/* Copyright (C) 2019 Free Software Foundation, Inc.
+
+   This file is part of GDB.
+
+   This program is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 3 of the License, or
+   (at your option) any later version.
+
+   This program is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
+
+   You should have received a copy of the GNU General Public License
+   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
+
+#include "server.h"
+#include "target.h"
+#include "netbsd-low.h"
+
+#include <sys/param.h>
+#include <sys/types.h>
+
+#include <sys/ptrace.h>
+#include <sys/sysctl.h>
+
+#include <limits.h>
+#include <unistd.h>
+#include <signal.h>
+
+#include <elf.h>
+
+#include "gdbsupport/gdb_wait.h"
+#include "gdbsupport/filestuff.h"
+#include "gdbsupport/common-inferior.h"
+#include "nat/fork-inferior.h"
+#include "hostio.h"
+
+int using_threads = 1;
+
+const struct target_desc *netbsd_tdesc;
+
+/* Per-process private data.  */
+
+struct process_info_private
+{
+  /* The PTID obtained from the last wait performed on this process.
+     Initialized to null_ptid until the first wait is performed.  */
+  ptid_t last_wait_event_ptid;
+
+  /* &_r_debug.  0 if not yet determined.  -1 if no PT_DYNAMIC in Phdrs.  */
+  CORE_ADDR r_debug;
+};
+
+/* Print a debug trace on standard output if debug_threads is set.  */
+
+static void
+netbsd_debug (const char *string, ...)
+{
+  va_list args;
+
+  if (!debug_threads)
+    return;
+
+  va_start (args, string);
+  fprintf (stderr, "[pid=%d] DEBUG(netbsd): ", getpid());
+  vfprintf (stderr, string, args);
+  va_end (args);
+}
+
+/* Build a ptid_t given a PID and a NetBSD TID.  */
+
+static ptid_t
+netbsd_ptid_t (pid_t pid, lwpid_t tid)
+{
+  return ptid_t (pid, tid, 0);
+}
+
+/* Return a string image of the ptrace REQUEST number.  */
+
+static const char *
+ptrace_request_to_str (int request)
+{
+#define CASE(X) case X: return #X
+  switch (request)
+    {
+      CASE(PT_TRACE_ME);
+      CASE(PT_READ_I);
+      CASE(PT_READ_D);
+      CASE(PT_WRITE_I);
+      CASE(PT_WRITE_D);
+      CASE(PT_CONTINUE);
+      CASE(PT_KILL);
+      CASE(PT_ATTACH);
+      CASE(PT_DETACH);
+      CASE(PT_IO);
+      CASE(PT_DUMPCORE);
+      CASE(PT_LWPINFO);
+      CASE(PT_SYSCALL);
+      CASE(PT_SYSCALLEMU);
+      CASE(PT_SET_EVENT_MASK);
+      CASE(PT_GET_EVENT_MASK);
+      CASE(PT_GET_PROCESS_STATE);
+      CASE(PT_SET_SIGINFO);
+      CASE(PT_GET_SIGINFO);
+      CASE(PT_RESUME);
+      CASE(PT_SUSPEND);
+
+#ifdef PT_STEP
+      CASE(PT_STEP);
+#endif
+#ifdef PT_GETREGS
+      CASE(PT_GETREGS);
+#endif
+#ifdef PT_SETREGS
+      CASE(PT_SETREGS);
+#endif
+#ifdef PT_GETFPREGS
+      CASE(PT_GETFPREGS);
+#endif
+#ifdef PT_SETFPREGS
+      CASE(PT_SETFPREGS);
+#endif
+#ifdef PT_GETDBREGS
+      CASE(PT_GETDBREGS);
+#endif
+#ifdef PT_SETDBREGS
+      CASE(PT_SETDBREGS);
+#endif
+#ifdef PT_SETSTEP
+      CASE(PT_SETSTEP);
+#endif
+#ifdef PT_CLEARSTEP
+      CASE(PT_CLEARSTEP);
+#endif
+#ifdef PT_GETXSTATE
+      CASE(PT_GETXSTATE);
+#endif
+#ifdef PT_SETXSTATE
+      CASE(PT_SETXSTATE);
+#endif
+#ifdef PT_GETXMMREGS
+      CASE(PT_GETXMMREGS);
+#endif
+#ifdef PT_SETXMMREGS
+      CASE(PT_SETXMMREGS);
+#endif
+#ifdef PT_GETVECREGS
+      CASE(PT_GETVECREGS);
+#endif
+#ifdef PT_SETVECREGS
+      CASE(PT_SETVECREGS);
+#endif
+    }
+#undef CASE
+
+  return "<unknown-request>";
+}
+
+static const char *
+ptrace_ptio_request_to_str (int request)
+{
+#define CASE(X) case X: return #X
+  switch (request)
+    {
+      CASE(PIOD_READ_D);
+      CASE(PIOD_WRITE_D);
+      CASE(PIOD_READ_I);
+      CASE(PIOD_WRITE_I);
+      CASE(PIOD_READ_AUXV);
+    }
+#undef CASE
+
+  return "<unknown-request>";
+}
+
+/* Return a string image of the ptrace REQUEST number.  */
+
+static const char *
+sigcode_to_str (int signo, int sigcode)
+{
+#define CASE(X) case X: return #X
+  switch (signo)
+    {
+      case SIGILL:
+      switch (sigcode)
+        {
+          CASE(ILL_ILLOPC);
+          CASE(ILL_ILLOPN);
+          CASE(ILL_ILLADR);
+          CASE(ILL_ILLTRP);
+          CASE(ILL_PRVOPC);
+          CASE(ILL_PRVREG);
+          CASE(ILL_COPROC);
+          CASE(ILL_BADSTK);
+        }
+        break;
+
+      case SIGFPE:
+      switch (sigcode)
+        {
+          CASE(FPE_INTDIV);
+          CASE(FPE_INTOVF);
+          CASE(FPE_FLTDIV);
+          CASE(FPE_FLTOVF);
+          CASE(FPE_FLTUND);
+          CASE(FPE_FLTRES);
+          CASE(FPE_FLTINV);
+          CASE(FPE_FLTSUB);
+        }
+        break;
+
+      case SIGSEGV:
+      switch (sigcode)
+        {
+          CASE(SEGV_MAPERR);
+          CASE(SEGV_ACCERR);
+        }
+        break;
+
+      case SIGBUS:
+      switch (sigcode)
+        {
+          CASE(BUS_ADRALN);
+          CASE(BUS_ADRERR);
+          CASE(BUS_OBJERR);
+        }
+        break;
+
+      case SIGTRAP:
+      switch (sigcode)
+        {
+          CASE(TRAP_BRKPT);
+          CASE(TRAP_TRACE);
+          CASE(TRAP_EXEC);
+          CASE(TRAP_CHLD);
+          CASE(TRAP_LWP);
+          CASE(TRAP_DBREG);
+          CASE(TRAP_SCE);
+          CASE(TRAP_SCX);
+        }
+        break;
+
+      case SIGCHLD:
+      switch (sigcode)
+        {
+          CASE(CLD_EXITED);
+          CASE(CLD_KILLED);
+          CASE(CLD_DUMPED);
+          CASE(CLD_TRAPPED);
+          CASE(CLD_STOPPED);
+          CASE(CLD_CONTINUED);
+        }
+        break;
+
+      case SIGIO:
+      switch (sigcode)
+        {
+          CASE(POLL_IN);
+          CASE(POLL_OUT);
+          CASE(POLL_MSG);
+          CASE(POLL_ERR);
+          CASE(POLL_PRI);
+          CASE(POLL_HUP);
+        }
+        break;
+    }
+
+  switch (sigcode)
+    {
+      CASE(SI_USER);
+      CASE(SI_QUEUE);
+      CASE(SI_TIMER);
+      CASE(SI_ASYNCIO);
+      CASE(SI_MESGQ);
+      CASE(SI_LWP);
+      CASE(SI_NOINFO);
+    }
+#undef CASE
+
+  return "<unknown-sigcode>";
+}
+
+/* A wrapper around waitpid that handles the various idiosyncrasies
+   of NetBSD waitpid.  */
+
+static int
+netbsd_waitpid (int pid, int *stat_loc, int options)
+{
+  int ret;
+
+  do
+    {
+      ret = waitpid (pid, stat_loc, options);
+    }
+  while (ret == -1 && errno == EINTR);
+
+  return ret;
+}
+
+static const char *
+netbsd_wait_kind_to_str (int kind)
+{
+#define CASE(X) case X: return #X
+  switch (kind)
+    {
+      CASE(TARGET_WAITKIND_EXITED);
+      CASE(TARGET_WAITKIND_STOPPED);
+      CASE(TARGET_WAITKIND_SIGNALLED);
+      CASE(TARGET_WAITKIND_LOADED);
+      CASE(TARGET_WAITKIND_FORKED);
+      CASE(TARGET_WAITKIND_VFORKED);
+      CASE(TARGET_WAITKIND_EXECD);
+      CASE(TARGET_WAITKIND_VFORK_DONE);
+      CASE(TARGET_WAITKIND_SYSCALL_ENTRY);
+      CASE(TARGET_WAITKIND_SYSCALL_RETURN);
+      CASE(TARGET_WAITKIND_IGNORE);
+      CASE(TARGET_WAITKIND_NO_HISTORY);
+      CASE(TARGET_WAITKIND_NO_RESUMED);
+      CASE(TARGET_WAITKIND_THREAD_CREATED);
+      CASE(TARGET_WAITKIND_THREAD_EXITED);
+    }
+#undef CASE
+
+  return "<unknown-request>";
+}
+
+/* A wrapper around ptrace that allows us to print debug traces of
+   ptrace calls if debug traces are activated.  */
+
+static int
+netbsd_ptrace (int request, pid_t pid, void *addr, int data)
+{
+  int result;
+  int saved_errno;
+
+  netbsd_debug ("PTRACE (%s, pid=%d, addr=%p, data=%#x)\n",
+              ptrace_request_to_str (request), pid, addr, data);
+
+  if (request == PT_IO)
+    {
+      struct ptrace_io_desc *pio = (struct ptrace_io_desc *)addr;
+      netbsd_debug (":: { .piod_op=%s, .piod_offs=%p, .piod_addr=%p, "
+                    ".piod_len=%zu }\n",
+                    ptrace_ptio_request_to_str (pio->piod_op),
+                    pio->piod_offs, pio->piod_addr, pio->piod_len);
+      if (pio->piod_op == PT_WRITE_I || pio->piod_op == PT_WRITE_D)
+        {
+          for (size_t i = 0; i < pio->piod_len; i++)
+            netbsd_debug (" :: [%02zu] = %#02x\n", i, (unsigned char)((char *)pio->piod_addr)[i]);
+        }
+    }
+
+  saved_errno = errno;
+  errno = 0;
+  result = ptrace (request, pid, addr, data);
+
+  netbsd_debug (" -> %d (=%#x errno=%d)\n", result, result, errno);
+  if (request == PT_IO)
+    {
+      struct ptrace_io_desc *pio = (struct ptrace_io_desc *)addr;
+      netbsd_debug (" -> :: { .piod_op=%s, .piod_offs=%p, .piod_addr=%p, "
+                    ".piod_len=%zu }\n",
+                    ptrace_ptio_request_to_str (pio->piod_op),
+                    pio->piod_offs, pio->piod_addr, pio->piod_len);
+      if (pio->piod_op == PT_READ_I || pio->piod_op == PT_READ_D)
+        {
+          for (size_t i = 0; i < pio->piod_len; i++)
+            netbsd_debug (" :: [%02zu] = %#02x\n", i, (unsigned char)((char *)pio->piod_addr)[i]);
+        }
+    }
+
+  errno = saved_errno;
+  return result;
+}
+
+/* A wrapper around ptrace that allows us to print debug traces of
+   ptrace calls if debug traces are activated.  */
+
+static int
+netbsd_sysctl (const int *name, u_int namelen, void *oldp, size_t *oldlenp,
+  const void *newp, size_t newlen)
+{
+  int result;
+
+  gdb_assert(name);
+  gdb_assert(namelen > 0);
+
+  std::string str = "[" + std::to_string(name[0]);
+  for (u_int i = 1; i < namelen; i++)
+    str += ", " + std::to_string(name[i]);
+  str += "]";
+
+  netbsd_debug ("SYSCTL (name=%s, namelen=%u, oldp=%p, oldlenp=%p, newp=%p, "
+                "newlen=%zu)\n",
+                str.c_str(), namelen, oldp, oldlenp, newp, newlen);
+  result = sysctl(name, namelen, oldp, oldlenp, newp, newlen);
+
+  netbsd_debug (" -> %d (=%#x errno=%d)\n", result, result, errno);
+
+  return result;
+}
+
+/* Call add_process with the given parameters, and initializes
+   the process' private data.  */
+
+static struct process_info *
+netbsd_add_process (int pid, int attached)
+{
+  struct process_info *proc;
+
+  proc = add_process (pid, attached);
+  proc->tdesc = netbsd_tdesc;
+  proc->priv = XCNEW (struct process_info_private);
+  proc->priv->last_wait_event_ptid = null_ptid;
+
+  return proc;
+}
+
+/* Callback used by fork_inferior to start tracing the inferior.  */
+
+static void
+netbsd_ptrace_fun ()
+{
+  /* Switch child to its own process group so that signals won't
+     directly affect GDBserver. */
+  if (setpgid (0, 0) < 0)
+    trace_start_error_with_name ("setpgid");
+
+  if (netbsd_ptrace (PT_TRACE_ME, 0, NULL, 0) < 0)
+    trace_start_error_with_name ("netbsd_ptrace");
+
+  /* If GDBserver is connected to gdb via stdio, redirect the inferior's
+     stdout to stderr so that inferior i/o doesn't corrupt the connection.
+     Also, redirect stdin to /dev/null.  */
+  if (remote_connection_is_stdio ())
+    {
+      if (close (0) < 0)
+        trace_start_error_with_name ("close");
+      if (open ("/dev/null", O_RDONLY) < 0)
+        trace_start_error_with_name ("open");
+      if (dup2 (2, 1) < 0)
+        trace_start_error_with_name ("dup2");
+      if (write (2, "stdin/stdout redirected\n",
+                 sizeof ("stdin/stdout redirected\n") - 1) < 0)
+        {
+          /* Errors ignored.  */;
+        }
+    }
+}
+
+static void
+netbsd_add_threads_sysctl (pid_t pid)
+{
+  struct kinfo_lwp *kl;
+  int mib[5];
+  size_t i, nlwps;
+  size_t size;
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_LWP;
+  mib[2] = pid;
+  mib[3] = sizeof(struct kinfo_lwp);
+  mib[4] = 0;
+
+  if (netbsd_sysctl (mib, 5, NULL, &size, NULL, 0) == -1 || size == 0)
+    trace_start_error_with_name ("sysctl");
+
+  mib[4] = size / sizeof(size_t);
+
+  kl = (struct kinfo_lwp *) xmalloc (size);
+  if (kl == NULL)
+    trace_start_error_with_name ("malloc");
+
+  if (netbsd_sysctl (mib, 5, kl, &size, NULL, 0) == -1 || size == 0)
+    trace_start_error_with_name ("sysctl");
+
+  nlwps = size / sizeof(struct kinfo_lwp);
+
+  for (i = 0; i < nlwps; i++) {
+    ptid_t ptid = netbsd_ptid_t (pid, kl[i].l_lid);
+    netbsd_debug ("Registering thread (pid=%d, lwpid=%d)\n", pid, kl[i].l_lid);
+    add_thread (ptid, NULL);
+  }
+
+  xfree(kl);
+}
+
+static void
+netbsd_wait_stopped_noreap (pid_t pid)
+{
+  int status;
+
+  gdb_assert (pid > 0);
+
+repeat:
+  pid_t wpid = netbsd_waitpid (pid, &status, WNOWAIT);
+
+  if (wpid == -1 || wpid != pid)
+    internal_error (__FILE__, __LINE__, _("unexpected waitpid return value %d"), wpid);
+
+  if (WIFSTOPPED (status))
+    return;
+
+  if (WIFSIGNALED (status) || WIFEXITED (status))
+    internal_error (__FILE__, __LINE__, _("tracee died"));
+
+  // Should not happen
+  if (WIFCONTINUED (status))
+    goto repeat;
+
+  __unreachable();
+}
+
+/* Assuming we've just attached to a stopped and waited inferior whose pid is PID */
+
+static void
+netbsd_add_threads_after_attach (pid_t pid)
+{
+  struct ptrace_lwpinfo pl;
+
+  pl.pl_lwpid = 0;
+  while (netbsd_ptrace(PT_LWPINFO, pid, (void *)&pl, sizeof(pl)) != -1 &&
+    pl.pl_lwpid != 0)
+    {
+      ptid_t thread_ptid = netbsd_ptid_t (pid, pl.pl_lwpid);
+
+      if (!find_thread_ptid (thread_ptid))
+	{
+	  netbsd_debug ("New thread: (pid = %d, tid = %d)\n",
+		      pid, pl.pl_lwpid);
+	  add_thread (thread_ptid, NULL);
+	}
+    }
+}
+
+/* Implement the create_inferior method of the target_ops vector.  */
+
+static int
+netbsd_create_inferior (const char *program,
+		      const std::vector<char *> &program_args)
+{
+  pid_t pid;
+  std::string str_program_args = stringify_argv (program_args);
+
+  netbsd_debug ("%s(program='%s', args=%s)\n",
+                __func__, program, str_program_args.c_str());
+
+  pid = fork_inferior (program,
+		       str_program_args.c_str (),
+		       get_environ ()->envp (), netbsd_ptrace_fun,
+		       NULL, NULL, NULL, NULL);
+
+  netbsd_add_process (pid, 0);
+
+  netbsd_wait_stopped_noreap (pid);
+
+  netbsd_add_threads_sysctl (pid);
+
+  post_fork_inferior (pid, program);
+
+  return pid;
+}
+
+/* Implement the attach target_ops method.  */
+
+static int
+netbsd_attach (unsigned long pid)
+{
+
+  netbsd_debug ("%s(pid=%d)\n", __func__, pid);
+
+  if (netbsd_ptrace (PT_ATTACH, pid, NULL, 0) != 0)
+    error ("Cannot attach to process %lu: %s (%d)\n", pid,
+	   strerror (errno), errno);
+
+  netbsd_add_process (pid, 1);
+  netbsd_add_threads_after_attach (pid);
+
+  return 0;
+}
+
+#if 0
+/* Resume the execution of the given PTID.  */
+
+static void
+netbsd_continue (ptid_t ptid)
+{
+  struct thread_resume resume_info;
+
+  resume_info.thread = ptid;
+  resume_info.kind = resume_continue;
+  resume_info.sig = 0;
+
+  netbsd_resume (&resume_info, 1);
+}
+#endif
+
+/* Implement the resume target_ops method.  */
+
+static void
+netbsd_resume (struct thread_resume *resume_info, size_t n)
+{
+
+  netbsd_debug ("%s()\n", __func__);
+
+  ptid_t ptid = resume_info[0].thread;
+  const int signal = resume_info[0].sig;
+
+  if (ptid == minus_one_ptid)
+    ptid = ptid_of (current_thread);
+
+  regcache_invalidate_pid (ptid.pid ());
+
+  if (resume_info[0].kind == resume_step)
+    {
+      if (n == 1)
+        {
+          struct ptrace_lwpinfo pl;
+          int val;
+          pl.pl_lwpid = 0;
+          while ((val = netbsd_ptrace(PT_LWPINFO, ptid.pid(), (void *)&pl,
+            sizeof(pl))) != -1 && pl.pl_lwpid != 0)
+           {
+              if (pl.pl_lwpid == ptid.lwp())
+                {
+                  netbsd_ptrace (PT_SETSTEP, ptid.pid(), NULL, pl.pl_lwpid);
+                  netbsd_ptrace (PT_RESUME, ptid.pid(), NULL, pl.pl_lwpid);
+                }
+              else
+                {
+                  netbsd_ptrace (PT_CLEARSTEP, ptid.pid(), NULL, pl.pl_lwpid);
+                  netbsd_ptrace (PT_SUSPEND, ptid.pid(), NULL, pl.pl_lwpid);
+                }
+           }
+        }
+      else
+        {
+          struct ptrace_lwpinfo pl;
+          int val;
+          pl.pl_lwpid = 0;
+          while ((val = netbsd_ptrace(PT_LWPINFO, ptid.pid(), (void *)&pl,
+            sizeof(pl))) != -1 && pl.pl_lwpid != 0)
+           {
+              netbsd_ptrace (PT_SETSTEP, ptid.pid(), NULL, pl.pl_lwpid);
+              netbsd_ptrace (PT_RESUME, ptid.pid(), NULL, pl.pl_lwpid);
+           }
+        }
+    }
+  else
+    {
+      struct ptrace_lwpinfo pl;
+      int val;
+      pl.pl_lwpid = 0;
+      while ((val = netbsd_ptrace(PT_LWPINFO, ptid.pid(), (void *)&pl, sizeof(pl))) != -1 &&
+        pl.pl_lwpid != 0)
+        {
+          netbsd_ptrace (PT_CLEARSTEP, ptid.pid(), NULL, pl.pl_lwpid);
+          netbsd_ptrace (PT_RESUME, ptid.pid(), NULL, pl.pl_lwpid);
+        }
+    }
+
+  errno = 0;
+  netbsd_ptrace (PT_CONTINUE, ptid.pid(), (void *)1, signal);
+  if (errno)
+    perror_with_name ("ptrace");
+}
+
+static char *
+pid_to_exec_file (pid_t pid)
+{
+  static const int name[] = {
+    CTL_KERN, KERN_PROC_ARGS, pid, KERN_PROC_PATHNAME,
+  };
+  static char path[MAXPATHLEN];
+  size_t len;
+
+  len = sizeof(path);
+  if (netbsd_sysctl (name, __arraycount(name), path, &len, NULL, 0) == -1)
+    return NULL;
+
+  return path;
+}
+
+static void
+netbsd_enable_event_reporting (pid_t pid)
+{
+  ptrace_event_t event;
+
+  ptrace (PT_GET_EVENT_MASK, pid, &event, sizeof(event));
+
+  event.pe_set_event |= PTRACE_FORK;
+  event.pe_set_event |= PTRACE_VFORK;
+  event.pe_set_event |= PTRACE_VFORK_DONE;
+  event.pe_set_event |= PTRACE_LWP_CREATE;
+  event.pe_set_event |= PTRACE_LWP_EXIT;
+  event.pe_set_event |= PTRACE_POSIX_SPAWN;
+
+  netbsd_ptrace (PT_SET_EVENT_MASK, pid, &event, sizeof(event));
+}
+
+/* Implement the wait target_ops method.  */
+
+static ptid_t
+netbsd_wait_1 (ptid_t ptid, struct target_waitstatus *ourstatus, int target_options)
+{
+  pid_t pid;
+  int status;
+
+  if (ptid == minus_one_ptid)
+    ptid = ptid_of (current_thread);
+
+  pid = ptid.pid();
+
+  int options = 0;
+  if (target_options & TARGET_WNOHANG)
+    options |= WNOHANG;
+
+  pid_t wpid = netbsd_waitpid (pid, &status, options);
+
+  if (wpid == 0)
+    {
+      gdb_assert (target_options & TARGET_WNOHANG);
+      ourstatus->kind = TARGET_WAITKIND_IGNORE;
+      return null_ptid;
+    }
+
+  gdb_assert (wpid != -1);
+
+  if (WIFEXITED (status))
+    {
+      ourstatus->kind = TARGET_WAITKIND_EXITED;
+      ourstatus->value.integer = WEXITSTATUS (status);
+      return ptid;
+    }
+
+  if (WIFSIGNALED (status))
+    {
+      ourstatus->kind = TARGET_WAITKIND_SIGNALLED;
+      ourstatus->value.sig = gdb_signal_from_host (WTERMSIG (status));
+      return ptid;
+    }
+
+  if (WIFCONTINUED(status))
+    {
+      ourstatus->kind = TARGET_WAITKIND_IGNORE;
+      return null_ptid;
+    }
+
+
+  if (WIFSTOPPED (status))
+    {
+      ptrace_state_t pst;
+      ptrace_siginfo_t psi, child_psi;
+      pid_t child, wchild;
+      ptid_t child_ptid;
+      lwpid_t lwp;
+
+      {
+        struct process_info *proc;
+
+      /* Architecture-specific setup after inferior is running.  */
+      proc = find_process_pid (wpid);
+      if (proc->tdesc == NULL)
+        {
+              /* This needs to happen after we have attached to the
+                 inferior and it is stopped for the first time, but
+                 before we access any inferior registers.  */
+              the_low_target.arch_setup ();
+        }
+      }
+
+      ourstatus->kind = TARGET_WAITKIND_STOPPED;
+      ourstatus->value.sig = gdb_signal_from_host (WSTOPSIG (status));
+
+      // Find the lwp that caused the wait status change
+      if (netbsd_ptrace (PT_GET_SIGINFO, wpid, &psi, sizeof(psi)) == -1)
+        perror_with_name (("ptrace"));
+
+      /* For whole-process signals pick random thread */
+      if (psi.psi_lwpid == 0)
+        {
+          // XXX: Is this always valid?
+          lwp = lwpid_of (current_thread);
+        }
+      else
+        {
+          lwp = psi.psi_lwpid;
+        }
+
+      ptid_t wptid = netbsd_ptid_t (wpid, lwp);
+
+      if (!find_thread_ptid (wptid))
+        {
+          add_thread (wptid, NULL);
+        }
+
+      switch (psi.psi_siginfo.si_signo)
+        {
+        case SIGTRAP:
+          switch (psi.psi_siginfo.si_code)
+            {
+            case TRAP_BRKPT:
+#ifdef PTRACE_BREAKPOINT_ADJ
+              {
+                CORE_ADDR pc;
+                struct reg r;
+                netbsd_ptrace (PT_GETREGS, wpid, &r, psi.psi_lwpid);
+                pc = PTRACE_REG_PC (&r);
+                PTRACE_REG_SET_PC (&r, pc - PTRACE_BREAKPOINT_ADJ);
+                netbsd_ptrace (PT_SETREGS, wpid, &r, psi.psi_lwpid);
+              }
+#endif
+            case TRAP_DBREG:
+            case TRAP_TRACE:
+              /* These stop reasons return STOPPED and are distinguished later */
+              break;
+            case TRAP_SCE:
+              ourstatus->kind = TARGET_WAITKIND_SYSCALL_ENTRY;
+              ourstatus->value.syscall_number = psi.psi_siginfo.si_sysnum;
+              break;
+            case TRAP_SCX:
+              ourstatus->kind = TARGET_WAITKIND_SYSCALL_RETURN;
+              ourstatus->value.syscall_number = psi.psi_siginfo.si_sysnum;
+              break;
+#if 0
+            case TRAP_EXEC:
+              ourstatus->kind = TARGET_WAITKIND_EXECD;
+              ourstatus->value.execd_pathname = xstrdup(pid_to_exec_file (wpid));
+              break;
+#endif
+            case TRAP_LWP:
+            case TRAP_CHLD:
+              if (netbsd_ptrace (PT_GET_PROCESS_STATE, wpid, &pst, sizeof(pst)) == -1)
+                perror_with_name (("ptrace"));
+              switch (pst.pe_report_event)
+                {
+                case PTRACE_FORK:
+                case PTRACE_VFORK:
+                  if (pst.pe_report_event == PTRACE_FORK)
+                    ourstatus->kind = TARGET_WAITKIND_FORKED;
+                  else
+                    ourstatus->kind = TARGET_WAITKIND_VFORKED;
+                  child = pst.pe_other_pid;
+
+                  wchild = netbsd_waitpid (child, &status, 0);
+
+                  if (wchild == -1)
+                    perror_with_name (("waitpid"));
+
+                  gdb_assert (wchild == child);
+
+                  if (!WIFSTOPPED(status))
+                    {
+                      /* Abnormal situation (SIGKILLed?).. bail out */
+                      ourstatus->kind = TARGET_WAITKIND_SPURIOUS;
+                      return wptid;
+                    }
+
+                  if (netbsd_ptrace (PT_GET_SIGINFO, child, &child_psi, sizeof(child_psi)) == -1)
+                    perror_with_name (("ptrace"));
+
+                  if (child_psi.psi_siginfo.si_signo != SIGTRAP)
+                    {
+                      /* Abnormal situation.. bail out */
+                      ourstatus->kind = TARGET_WAITKIND_SPURIOUS;
+                      return wptid;
+                    }
+
+                  if (child_psi.psi_siginfo.si_code != TRAP_CHLD)
+                    {
+                      /* Abnormal situation.. bail out */
+                      ourstatus->kind = TARGET_WAITKIND_SPURIOUS;
+                      return wptid;
+                    }
+
+                  child_ptid = netbsd_ptid_t (child, child_psi.psi_lwpid);
+                  netbsd_enable_event_reporting (child_ptid.pid ());
+                  ourstatus->value.related_pid = child_ptid;
+                  break;
+                case PTRACE_VFORK_DONE:
+                  ourstatus->kind = TARGET_WAITKIND_VFORK_DONE;
+                  break;
+                case PTRACE_LWP_CREATE:
+                  wptid = netbsd_ptid_t (wpid, pst.pe_lwp);
+                  if (!find_thread_ptid (wptid))
+                    {
+                      add_thread (wptid, NULL);
+                    }
+                  ourstatus->kind = TARGET_WAITKIND_THREAD_CREATED;
+                  break;
+                case PTRACE_LWP_EXIT:
+                  wptid = netbsd_ptid_t (wpid, pst.pe_lwp);
+                  thread_info *thread = find_thread_ptid (wptid);
+                  if (!thread)
+                    {
+                      /* Dead child reported after attach? */
+                      ourstatus->kind = TARGET_WAITKIND_SPURIOUS;
+                      return wptid;
+                    }
+                  remove_thread (thread);
+                  ourstatus->kind = TARGET_WAITKIND_THREAD_EXITED;
+
+#if 0
+                  if (netbsd_ptrace (PT_CONTINUE, pid, (void *)1, 0) == -1)
+                    perror_with_name (("ptrace"));
+#endif
+                  break;
+                }
+              break;
+            }
+          break;
+        }
+      return wptid;
+    }
+
+  return null_ptid;
+}
+
+/* A wrapper around netbsd_wait_1 that also prints debug traces when
+   such debug traces have been activated.  */
+
+static ptid_t
+netbsd_wait (ptid_t ptid, struct target_waitstatus *status, int options)
+{
+  ptid_t new_ptid;
+
+  netbsd_debug ("%s (pid = %d, options=%s)\n", __func__,
+                ptid.pid(), options & TARGET_WNOHANG ? "WNOHANG" : "0" );
+  new_ptid = netbsd_wait_1 (ptid, status, options);
+  netbsd_debug ("          -> (pid=%d, status->kind = %s)\n",
+	        new_ptid.pid(), netbsd_wait_kind_to_str(status->kind));
+  if (status->kind == TARGET_WAITKIND_EXECD)
+    {
+        netbsd_debug ("          -> (execd_pathname='%s')\n",
+                      status->value.execd_pathname);
+    }
+
+  return new_ptid;
+}
+
+/* Implement the kill target_ops method.  */
+
+static int
+netbsd_kill (process_info *process)
+{
+  netbsd_debug ("%s()\n", __func__);
+
+  pid_t pid = process->pid;
+  ptid_t ptid = netbsd_ptid_t (pid, 0);
+  struct target_waitstatus status;
+
+  netbsd_ptrace (PT_KILL, pid, NULL, 0);
+  netbsd_wait (ptid, &status, 0);
+  the_target->mourn (process);
+  return 0;
+}
+
+/* Implement the detach target_ops method.  */
+
+static int
+netbsd_detach (process_info *process)
+{
+  netbsd_debug ("%s()\n", __func__);
+
+  pid_t pid = process->pid;
+
+  netbsd_ptrace (PT_DETACH, pid, (void *)1, 0);
+  the_target->mourn (process);
+  return 0;
+}
+
+/* Implement the mourn target_ops method.  */
+
+static void
+netbsd_mourn (struct process_info *proc)
+{
+  netbsd_debug ("%s()\n", __func__);
+
+  for_each_thread (proc->pid, remove_thread);
+
+  /* Free our private data.  */
+  free (proc->priv);
+  proc->priv = NULL;
+
+  remove_process (proc);
+}
+
+/* Implement the join target_ops method.  */
+
+static void
+netbsd_join (int pid)
+{
+  netbsd_debug ("%s()\n", __func__);
+
+  /* The PTRACE_DETACH is sufficient to detach from the process.
+     So no need to do anything extra.  */
+}
+
+/* Implement the thread_alive target_ops method.  */
+
+static int
+netbsd_thread_alive (ptid_t ptid)
+{
+  netbsd_debug ("%s()\n", __func__);
+
+  /* The list of threads is updated at the end of each wait, so it
+     should be up to date.  No need to re-fetch it.  */
+  return (find_thread_ptid (ptid) != NULL);
+}
+
+/* Implement the fetch_registers target_ops method.  */
+
+static void
+netbsd_fetch_registers (struct regcache *regcache, int regno)
+{
+  netbsd_debug ("%s(regno=%d)\n", __func__, regno);
+
+  struct netbsd_regset_info *regset = netbsd_target_regsets;
+  ptid_t inferior_ptid = ptid_of (current_thread);
+
+  while (regset->size >= 0)
+    {
+      char *buf;
+      int res;
+
+      buf = (char *)xmalloc (regset->size);
+      res = netbsd_ptrace (regset->get_request, inferior_ptid.pid(), buf, inferior_ptid.lwp());
+      if (res < 0)
+        perror ("ptrace");
+      regset->store_function (regcache, buf);
+      free (buf);
+      regset++;
+    }
+}
+
+/* Implement the store_registers target_ops method.  */
+
+static void
+netbsd_store_registers (struct regcache *regcache, int regno)
+{
+  netbsd_debug ("%s(regno=%d)\n", __func__, regno);
+
+  struct netbsd_regset_info *regset = netbsd_target_regsets;
+  ptid_t inferior_ptid = ptid_of (current_thread);
+
+  while (regset->size >= 0)
+    {
+      char *buf;
+      int res;
+
+      buf = (char *)xmalloc (regset->size);
+      res = netbsd_ptrace (regset->get_request, inferior_ptid.pid(), buf, inferior_ptid.lwp());
+      if (res == 0)
+        {
+	  /* Then overlay our cached registers on that.  */
+	  regset->fill_function (regcache, buf);
+	  /* Only now do we write the register set.  */
+	  res = netbsd_ptrace (regset->set_request, inferior_ptid.pid(), buf, inferior_ptid.lwp());
+        }
+      if (res < 0)
+        perror ("ptrace");
+      free (buf);
+      regset++;
+    }
+}
+
+/* Implement the read_memory target_ops method.  */
+
+static int
+netbsd_read_memory (CORE_ADDR memaddr, unsigned char *myaddr, int size)
+{
+  netbsd_debug ("%s(memaddr=%p, myaddr=%p, size=%d)\n",
+                __func__, memaddr, myaddr, size);
+
+  struct ptrace_io_desc io;
+  io.piod_op = PIOD_READ_D;
+  io.piod_len = size;
+
+  ptid_t inferior_ptid = ptid_of (current_thread);
+
+  int bytes_read = 0;
+
+  if (size == 0)
+    {
+      /* Zero length write always succeeds.  */
+      return 0;
+    }
+  do
+    {
+      io.piod_offs = (void *)(memaddr + bytes_read);
+      io.piod_addr = myaddr + bytes_read;
+
+      int rv = netbsd_ptrace (PT_IO, inferior_ptid.pid(), &io, 0);
+      if (rv == -1)
+        return errno;
+      if (io.piod_len == 0)
+        return 0;
+
+      bytes_read += io.piod_len;
+      io.piod_len = size - bytes_read;
+    }
+  while (bytes_read < size);
+
+  return 0;
+}
+
+/* Implement the write_memory target_ops method.  */
+
+static int
+netbsd_write_memory (CORE_ADDR memaddr, const unsigned char *myaddr, int size)
+{
+  netbsd_debug ("%s(memaddr=%p, myaddr=%p, size=%d)\n",
+                __func__, memaddr, myaddr, size);
+
+  struct ptrace_io_desc io;
+  io.piod_op = PIOD_WRITE_D;
+  io.piod_len = size;
+
+  ptid_t inferior_ptid = ptid_of (current_thread);
+
+  int bytes_written = 0;
+
+  if (size == 0)
+    {
+      /* Zero length write always succeeds.  */
+      return 0;
+    }
+
+  do
+    {
+      io.piod_addr = (void *)(myaddr + bytes_written);
+      io.piod_offs = (void *)(memaddr + bytes_written);
+
+      int rv = netbsd_ptrace (PT_IO, inferior_ptid.pid(), &io, 0);
+      if (rv == -1)
+        return errno;
+      if (io.piod_len == 0)
+        return 0;
+
+      bytes_written += io.piod_len;
+      io.piod_len = size - bytes_written;
+    }
+  while (bytes_written < size);
+
+  return 0;
+}
+
+/* Implement the kill_request target_ops method.  */
+
+static void
+netbsd_request_interrupt (void)
+{
+  netbsd_debug ("%s()\n", __func__);
+
+  ptid_t inferior_ptid = ptid_of (get_first_thread ());
+
+  kill (inferior_ptid.pid(), SIGINT);
+}
+
+/* Copy LEN bytes from inferior's auxiliary vector starting at OFFSET
+   to debugger memory starting at MYADDR.  */
+
+static int
+netbsd_read_auxv (CORE_ADDR offset, unsigned char *myaddr, unsigned int len)
+{
+  netbsd_debug ("%s(offset=%p, myaddr=%p, size=%u)\n",
+                __func__, offset, myaddr, len);
+
+  struct ptrace_io_desc pio;
+  pid_t pid = pid_of (current_thread);
+
+  pio.piod_op = PIOD_READ_AUXV;
+  pio.piod_offs = (void *)(intptr_t)offset;
+  pio.piod_addr = myaddr;
+  pio.piod_len = len;
+
+  if (netbsd_ptrace (PT_IO, pid, &pio, 0) == -1)
+    return 0;
+
+  return pio.piod_len;
+}
+
+static int
+netbsd_supports_z_point_type (char z_type)
+{
+  netbsd_debug ("%s(z_type='%c')\n", __func__, z_type);
+
+  switch (z_type)
+    {
+    case Z_PACKET_SW_BP:
+#if 0
+    case Z_PACKET_HW_BP:
+    case Z_PACKET_WRITE_WP:
+    case Z_PACKET_READ_WP:
+    case Z_PACKET_ACCESS_WP:
+#endif
+      return 1;
+    default:
+      return 0;
+    }
+}
+
+/* Insert {break/watch}point at address ADDR.  SIZE is not used.  */
+
+static int
+netbsd_insert_point (enum raw_bkpt_type type, CORE_ADDR addr,
+                     int size, struct raw_breakpoint *bp)
+{
+  netbsd_debug ("%s type:%#x addr: 0x%08lx len:%d\n", __func__, (int)type, addr, size);
+
+  switch (type)
+    {
+    case raw_bkpt_type_sw:
+      return insert_memory_breakpoint (bp);
+    case raw_bkpt_type_hw:
+    case raw_bkpt_type_write_wp:
+    case raw_bkpt_type_read_wp:
+    case raw_bkpt_type_access_wp:
+    default:
+      return 1; /* Not supported.  */
+    }
+}
+
+/* Remove {break/watch}point at address ADDR.  SIZE is not used.  */
+
+static int
+netbsd_remove_point (enum raw_bkpt_type type, CORE_ADDR addr,
+                     int size, struct raw_breakpoint *bp)
+{
+  netbsd_debug ("%s type:%c addr: 0x%08lx len:%d\n", __func__, (int)type, addr, size);
+
+  switch (type)
+    {
+    case raw_bkpt_type_sw:
+      return remove_memory_breakpoint (bp);
+    case raw_bkpt_type_hw:
+    case raw_bkpt_type_write_wp:
+    case raw_bkpt_type_read_wp:
+    case raw_bkpt_type_access_wp:
+    default:
+      return 1; /* Not supported.  */
+    }
+}
+
+/* Implement the to_stopped_by_sw_breakpoint target_ops
+   method.  */
+
+static int
+netbsd_stopped_by_sw_breakpoint (void)
+{
+  netbsd_debug ("%s()\n", __func__);
+
+  ptrace_siginfo_t psi;
+  pid_t pid = pid_of (current_thread);
+
+  if (netbsd_ptrace (PT_GET_SIGINFO, pid, &psi, sizeof(psi)) == -1)
+    return -1; // XXX
+
+  netbsd_debug (" -> psi_lwpid = %d, psi_siginfo.si_signo=SIG%s, "
+                "psi_siginfo.si_code=%s\n", psi.psi_lwpid,
+                signalname(psi.psi_siginfo.si_signo),
+                sigcode_to_str(psi.psi_siginfo.si_signo, psi.psi_siginfo.si_code));
+
+  return psi.psi_siginfo.si_signo == SIGTRAP &&
+         psi.psi_siginfo.si_code == TRAP_BRKPT;
+}
+
+/* Implement the to_supports_stopped_by_sw_breakpoint target_ops
+   method.  */
+
+static int
+netbsd_supports_stopped_by_sw_breakpoint (void)
+{
+  netbsd_debug ("%s()\n", __func__);
+
+  return 1;
+}
+
+static int
+netbsd_qxfer_siginfo (const char *annex, unsigned char *readbuf,
+                     unsigned const char *writebuf, CORE_ADDR offset, int len)
+{
+  netbsd_debug ("%s(annex=%p, readbuf=%p, writebuf=%p, offset=%p len=%d)\n",
+                __func__, annex, readbuf, writebuf, offset, len);
+
+  if (current_thread == NULL)
+    return -1;
+
+  pid_t pid = pid_of (current_thread);
+
+  netbsd_debug ("%s siginfo for lwp %d.\n",
+                readbuf != NULL ? "Reading" : "Writing",
+                pid);
+
+  if (offset >= sizeof (siginfo))
+    return -1;
+
+  struct ptrace_siginfo psi;
+  if (ptrace (PT_GET_SIGINFO, pid, &psi, sizeof(psi)) != 0)
+    return -1;
+
+  if (offset + len > sizeof (siginfo))
+    len = sizeof (siginfo) - offset;
+
+  if (readbuf != NULL)
+    memcpy (readbuf, (char *)&psi.psi_siginfo + offset, len);
+  else
+    {
+      memcpy ((char *)&psi.psi_siginfo + offset, writebuf, len);
+
+      if (ptrace (PT_SET_SIGINFO, pid, &psi, sizeof(psi)) != 0)
+        return -1;
+    }
+
+  return len;
+}
+
+static int
+netbsd_supports_non_stop (void)
+{
+  netbsd_debug ("%s()\n", __func__);
+
+  return 0;
+}
+
+static int
+netbsd_supports_multi_process (void)
+{
+  netbsd_debug ("%s()\n", __func__);
+
+  return 0; /* XXX */
+}
+
+/* Check if fork events are supported.  */
+
+static int
+netbsd_supports_fork_events (void)
+{
+  netbsd_debug ("%s()\n", __func__);
+
+  return 1;
+}
+
+/* Check if vfork events are supported.  */
+
+static int
+netbsd_supports_vfork_events (void)
+{
+  netbsd_debug ("%s()\n", __func__);
+
+  return 1;
+}
+
+/* Check if exec events are supported.  */
+
+static int
+netbsd_supports_exec_events (void)
+{
+  netbsd_debug ("%s()\n", __func__);
+
+  return 1;
+}
+
+static int
+netbsd_supports_disable_randomization (void)
+{
+  netbsd_debug ("%s()\n", __func__);
+
+  return 0;
+}
+
+/* Extract &phdr and num_phdr in the inferior.  Return 0 on success.  */
+
+static int
+get_phdr_phnum_from_proc_auxv (const int pid, const int is_elf64,
+                               CORE_ADDR *phdr_memaddr, int *num_phdr)
+{
+  struct ptrace_io_desc pio;
+  const int auxv_size = is_elf64
+    ? sizeof (Aux64Info) : sizeof (Aux32Info);
+  char *auxv_buf;
+  char *buf;
+  const size_t auxv_buf_size = 100 * sizeof(Aux64Info);
+
+  auxv_buf = (char *)xmalloc(auxv_buf_size);
+
+  pio.piod_op = PIOD_READ_AUXV;
+  pio.piod_offs = 0;
+  pio.piod_addr = auxv_buf;
+  pio.piod_len = auxv_buf_size;
+
+  netbsd_ptrace (PT_IO, pid, &pio, 0);
+
+  *phdr_memaddr = 0;
+  *num_phdr = 0;
+
+  for (buf = auxv_buf; buf < (auxv_buf + auxv_buf_size); buf += auxv_size)
+    {
+      if (is_elf64)
+        {
+          Aux64Info *const aux = (Aux64Info *) buf;
+
+          switch (aux->a_type)
+            {
+            case AT_PHDR:
+              *phdr_memaddr = aux->a_v;
+              break;
+            case AT_PHNUM:
+              *num_phdr = aux->a_v;
+              break;
+            }
+        }
+      else
+        {
+          Aux32Info *const aux = (Aux32Info *) buf;
+
+          switch (aux->a_type)
+            {
+            case AT_PHDR:
+              *phdr_memaddr = aux->a_v;
+              break;
+            case AT_PHNUM:
+              *num_phdr = aux->a_v;
+              break;
+            }
+        }
+
+      if (*phdr_memaddr != 0 && *num_phdr != 0)
+        break;
+    }
+
+  xfree (auxv_buf);
+
+  if (*phdr_memaddr == 0 || *num_phdr == 0)
+    {
+      warning ("Unexpected missing AT_PHDR and/or AT_PHNUM: "
+               "phdr_memaddr = %ld, phdr_num = %d",
+               (long) *phdr_memaddr, *num_phdr);
+      return 2;
+    }
+
+  return 0;
+}
+
+/* Return &_DYNAMIC (via PT_DYNAMIC) in the inferior, or 0 if not present.  */
+
+static CORE_ADDR
+get_dynamic (const int pid, const int is_elf64)
+{
+  CORE_ADDR phdr_memaddr, relocation;
+  int num_phdr, i;
+  unsigned char *phdr_buf;
+  const int phdr_size = is_elf64 ? sizeof (Elf64_Phdr) : sizeof (Elf32_Phdr);
+
+  if (get_phdr_phnum_from_proc_auxv (pid, is_elf64, &phdr_memaddr, &num_phdr))
+    return 0;
+
+  gdb_assert (num_phdr < 100);  /* Basic sanity check.  */
+  phdr_buf = (unsigned char *) alloca (num_phdr * phdr_size);
+
+  if (netbsd_read_memory (phdr_memaddr, phdr_buf, num_phdr * phdr_size))
+    return 0;
+
+  /* Compute relocation: it is expected to be 0 for "regular" executables,
+     non-zero for PIE ones.  */
+  relocation = -1;
+  for (i = 0; relocation == -1 && i < num_phdr; i++)
+    if (is_elf64)
+      {
+        Elf64_Phdr *const p = (Elf64_Phdr *) (phdr_buf + i * phdr_size);
+
+        if (p->p_type == PT_PHDR)
+          relocation = phdr_memaddr - p->p_vaddr;
+      }
+    else
+      {
+        Elf32_Phdr *const p = (Elf32_Phdr *) (phdr_buf + i * phdr_size);
+
+        if (p->p_type == PT_PHDR)
+          relocation = phdr_memaddr - p->p_vaddr;
+      }
+
+  if (relocation == -1)
+    {
+      /* PT_PHDR is optional, but necessary for PIE in general.  Fortunately
+         any real world executables, including PIE executables, have always
+         PT_PHDR present.  PT_PHDR is not present in some shared libraries or
+         in fpc (Free Pascal 2.4) binaries but neither of those have a need for
+         or present DT_DEBUG anyway (fpc binaries are statically linked).
+
+         Therefore if there exists DT_DEBUG there is always also PT_PHDR.
+
+         GDB could find RELOCATION also from AT_ENTRY - e_entry.  */
+
+      return 0;
+    }
+
+  for (i = 0; i < num_phdr; i++)
+    {
+      if (is_elf64)
+        {
+          Elf64_Phdr *const p = (Elf64_Phdr *) (phdr_buf + i * phdr_size);
+
+          if (p->p_type == PT_DYNAMIC)
+            return p->p_vaddr + relocation;
+        }
+      else
+        {
+          Elf32_Phdr *const p = (Elf32_Phdr *) (phdr_buf + i * phdr_size);
+
+          if (p->p_type == PT_DYNAMIC)
+            return p->p_vaddr + relocation;
+        }
+    }
+
+  return 0;
+}
+
+/* Return &_r_debug in the inferior, or -1 if not present.  Return value
+   can be 0 if the inferior does not yet have the library list initialized.
+   We look for DT_MIPS_RLD_MAP first.  MIPS executables use this instead of
+   DT_DEBUG, although they sometimes contain an unused DT_DEBUG entry too.  */
+
+static CORE_ADDR
+get_r_debug (const int pid, const int is_elf64)
+{
+  CORE_ADDR dynamic_memaddr;
+  const int dyn_size = is_elf64 ? sizeof (Elf64_Dyn) : sizeof (Elf32_Dyn);
+  unsigned char buf[sizeof (Elf64_Dyn)];  /* The larger of the two.  */
+  CORE_ADDR map = -1;
+
+  dynamic_memaddr = get_dynamic (pid, is_elf64);
+  if (dynamic_memaddr == 0)
+    return map;
+
+  while (netbsd_read_memory (dynamic_memaddr, buf, dyn_size) == 0)
+    {
+      if (is_elf64)
+        {
+          Elf64_Dyn *const dyn = (Elf64_Dyn *) buf;
+#if defined DT_MIPS_RLD_MAP || defined DT_MIPS_RLD_MAP_REL
+          union
+            {
+              Elf64_Xword map;
+              unsigned char buf[sizeof (Elf64_Xword)];
+            }
+          rld_map;
+#endif
+#ifdef DT_MIPS_RLD_MAP
+          if (dyn->d_tag == DT_MIPS_RLD_MAP)
+            {
+              if (netbsd_read_memory (dyn->d_un.d_val,
+                                     rld_map.buf, sizeof (rld_map.buf)) == 0)
+                return rld_map.map;
+              else
+                break;
+            }
+#endif  /* DT_MIPS_RLD_MAP */
+#ifdef DT_MIPS_RLD_MAP_REL
+          if (dyn->d_tag == DT_MIPS_RLD_MAP_REL)
+            {
+              if (netbsd_read_memory (dyn->d_un.d_val + dynamic_memaddr,
+                                     rld_map.buf, sizeof (rld_map.buf)) == 0)
+                return rld_map.map;
+              else
+                break;
+            }
+#endif  /* DT_MIPS_RLD_MAP_REL */
+
+          if (dyn->d_tag == DT_DEBUG && map == -1)
+            map = dyn->d_un.d_val;
+
+          if (dyn->d_tag == DT_NULL)
+            break;
+        }
+      else
+        {
+          Elf32_Dyn *const dyn = (Elf32_Dyn *) buf;
+#if defined DT_MIPS_RLD_MAP || defined DT_MIPS_RLD_MAP_REL
+          union
+            {
+              Elf32_Word map;
+              unsigned char buf[sizeof (Elf32_Word)];
+            }
+          rld_map;
+#endif
+#ifdef DT_MIPS_RLD_MAP
+          if (dyn->d_tag == DT_MIPS_RLD_MAP)
+            {
+              if (netbsd_read_memory (dyn->d_un.d_val,
+                                     rld_map.buf, sizeof (rld_map.buf)) == 0)
+                return rld_map.map;
+              else
+                break;
+            }
+#endif  /* DT_MIPS_RLD_MAP */
+#ifdef DT_MIPS_RLD_MAP_REL
+          if (dyn->d_tag == DT_MIPS_RLD_MAP_REL)
+            {
+              if (netbsd_read_memory (dyn->d_un.d_val + dynamic_memaddr,
+                                     rld_map.buf, sizeof (rld_map.buf)) == 0)
+                return rld_map.map;
+              else
+                break;
+            }
+#endif  /* DT_MIPS_RLD_MAP_REL */
+
+          if (dyn->d_tag == DT_DEBUG && map == -1)
+            map = dyn->d_un.d_val;
+
+          if (dyn->d_tag == DT_NULL)
+            break;
+        }
+
+      dynamic_memaddr += dyn_size;
+    }
+
+  return map;
+}
+
+/* Read one pointer from MEMADDR in the inferior.  */
+
+static int
+read_one_ptr (CORE_ADDR memaddr, CORE_ADDR *ptr, int ptr_size)
+{
+  int ret;
+
+  /* Go through a union so this works on either big or little endian
+     hosts, when the inferior's pointer size is smaller than the size
+     of CORE_ADDR.  It is assumed the inferior's endianness is the
+     same of the superior's.  */
+
+  union
+  {
+    CORE_ADDR core_addr;
+    unsigned int ui;
+    unsigned char uc;
+  } addr;
+
+  ret = netbsd_read_memory (memaddr, &addr.uc, ptr_size);
+  if (ret == 0)
+    {
+      if (ptr_size == sizeof (CORE_ADDR))
+        *ptr = addr.core_addr;
+      else if (ptr_size == sizeof (unsigned int))
+        *ptr = addr.ui;
+      else
+        gdb_assert_not_reached ("unhandled pointer size");
+    }
+  return ret;
+}
+
+struct link_map_offsets
+  {
+    /* Offset and size of r_debug.r_version.  */
+    int r_version_offset;
+
+    /* Offset and size of r_debug.r_map.  */
+    int r_map_offset;
+
+    /* Offset to l_addr field in struct link_map.  */
+    int l_addr_offset;
+
+    /* Offset to l_name field in struct link_map.  */
+    int l_name_offset;
+
+    /* Offset to l_ld field in struct link_map.  */
+    int l_ld_offset;
+
+    /* Offset to l_next field in struct link_map.  */
+    int l_next_offset;
+
+    /* Offset to l_prev field in struct link_map.  */
+    int l_prev_offset;
+  };
+
+/* Return non-zero if HEADER is a 64-bit ELF file.  */
+
+static int
+elf_64_header_p (const Elf64_Ehdr *header, unsigned int *machine)
+{
+  if (header->e_ident[EI_MAG0] == ELFMAG0
+      && header->e_ident[EI_MAG1] == ELFMAG1
+      && header->e_ident[EI_MAG2] == ELFMAG2
+      && header->e_ident[EI_MAG3] == ELFMAG3)
+    {
+      *machine = header->e_machine;
+      return header->e_ident[EI_CLASS] == ELFCLASS64;
+
+    }
+  *machine = EM_NONE;
+  return -1;
+}
+
+/* Return non-zero if FILE is a 64-bit ELF file,
+   zero if the file is not a 64-bit ELF file,
+   and -1 if the file is not accessible or doesn't exist.  */
+
+static int
+elf_64_file_p (const char *file, unsigned int *machine)
+{
+  Elf64_Ehdr header;
+  int fd;
+
+  fd = open (file, O_RDONLY);
+  if (fd < 0)
+    return -1;
+
+  if (read (fd, &header, sizeof (header)) != sizeof (header))
+    {
+      close (fd);
+      return 0;
+    }
+  close (fd);
+
+  int is64 = elf_64_header_p (&header, machine);
+
+  netbsd_debug ("%s(): file='%s' is64=%d\n", __func__, file, is64);
+
+  return is64;
+}
+
+/* Construct qXfer:libraries-svr4:read reply.  */
+
+static int
+netbsd_qxfer_libraries_svr4 (const char *annex, unsigned char *readbuf,
+                            unsigned const char *writebuf,
+                            CORE_ADDR offset, int len)
+{
+  netbsd_debug ("%s(annex=%s, readbuf=%p, writebuf=%p, offset=%p, len=%d)\n",
+                __func__, annex, readbuf, writebuf, offset, len);
+
+  struct process_info_private *const priv = current_process ()->priv;
+  int pid, is_elf64;
+
+  static const struct link_map_offsets lmo_32bit_offsets =
+    {
+      0,     /* r_version offset. */
+      4,     /* r_debug.r_map offset.  */
+      0,     /* l_addr offset in link_map.  */
+      4,     /* l_name offset in link_map.  */
+      8,     /* l_ld offset in link_map.  */
+      12,    /* l_next offset in link_map.  */
+      16     /* l_prev offset in link_map.  */
+    };
+
+  static const struct link_map_offsets lmo_64bit_offsets =
+    {
+      0,     /* r_version offset. */
+      8,     /* r_debug.r_map offset.  */
+      0,     /* l_addr offset in link_map.  */
+      8,     /* l_name offset in link_map.  */
+      16,    /* l_ld offset in link_map.  */
+      24,    /* l_next offset in link_map.  */
+      32     /* l_prev offset in link_map.  */
+    };
+  const struct link_map_offsets *lmo;
+  unsigned int machine;
+  int ptr_size;
+  CORE_ADDR lm_addr = 0, lm_prev = 0;
+  CORE_ADDR l_name, l_addr, l_ld, l_next, l_prev;
+  int header_done = 0;
+
+  if (writebuf != NULL)
+    return -2;
+  if (readbuf == NULL)
+    return -1;
+
+  pid = pid_of (current_thread);
+  is_elf64 = elf_64_file_p (pid_to_exec_file(pid), &machine);
+  lmo = is_elf64 ? &lmo_64bit_offsets : &lmo_32bit_offsets;
+  ptr_size = is_elf64 ? 8 : 4;
+
+  while (annex[0] != '\0')
+    {
+      const char *sep;
+      CORE_ADDR *addrp;
+      int name_len;
+
+      sep = strchr (annex, '=');
+      if (sep == NULL)
+        break;
+
+      name_len = sep - annex;
+      if (name_len == 5 && startswith (annex, "start"))
+        addrp = &lm_addr;
+      else if (name_len == 4 && startswith (annex, "prev"))
+        addrp = &lm_prev;
+      else
+        {
+          annex = strchr (sep, ';');
+          if (annex == NULL)
+            break;
+          annex++;
+          continue;
+        }
+
+      annex = decode_address_to_semicolon (addrp, sep + 1);
+    }
+
+  if (lm_addr == 0)
+    {
+      int r_version = 0;
+
+      if (priv->r_debug == 0)
+        priv->r_debug = get_r_debug (pid, is_elf64);
+
+      /* We failed to find DT_DEBUG.  Such situation will not change
+         for this inferior - do not retry it.  Report it to GDB as
+         E01, see for the reasons at the GDB solib-svr4.c side.  */
+      if (priv->r_debug == (CORE_ADDR) -1)
+        return -1;
+
+      if (priv->r_debug != 0)
+        {
+          if (netbsd_read_memory (priv->r_debug + lmo->r_version_offset,
+                                 (unsigned char *) &r_version,
+                                 sizeof (r_version)) != 0
+              || r_version != 1)
+            {
+              warning ("unexpected r_debug version %d", r_version);
+            }
+          else if (read_one_ptr (priv->r_debug + lmo->r_map_offset,
+                                 &lm_addr, ptr_size) != 0)
+            {
+              warning ("unable to read r_map from 0x%lx",
+                       (long) priv->r_debug + lmo->r_map_offset);
+            }
+        }
+    }
+
+  std::string document = "<library-list-svr4 version=\"1.0\"";
+
+  while (lm_addr
+         && read_one_ptr (lm_addr + lmo->l_name_offset,
+                          &l_name, ptr_size) == 0
+         && read_one_ptr (lm_addr + lmo->l_addr_offset,
+                          &l_addr, ptr_size) == 0
+         && read_one_ptr (lm_addr + lmo->l_ld_offset,
+                          &l_ld, ptr_size) == 0
+         && read_one_ptr (lm_addr + lmo->l_prev_offset,
+                          &l_prev, ptr_size) == 0
+         && read_one_ptr (lm_addr + lmo->l_next_offset,
+                          &l_next, ptr_size) == 0)
+    {
+      unsigned char libname[PATH_MAX];
+
+      if (lm_prev != l_prev)
+        {
+          warning ("Corrupted shared library list: 0x%lx != 0x%lx",
+                   (long) lm_prev, (long) l_prev);
+          break;
+        }
+
+      /* Ignore the first entry even if it has valid name as the first entry
+         corresponds to the main executable.  The first entry should not be
+         skipped if the dynamic loader was loaded late by a static executable
+         (see solib-svr4.c parameter ignore_first).  But in such case the main
+         executable does not have PT_DYNAMIC present and this function already
+         exited above due to failed get_r_debug.  */
+      if (lm_prev == 0)
+        string_appendf (document, " main-lm=\"0x%lx\"", (unsigned long) lm_addr);
+      else
+        {
+          /* Not checking for error because reading may stop before
+             we've got PATH_MAX worth of characters.  */
+          libname[0] = '\0';
+          netbsd_read_memory (l_name, libname, sizeof (libname) - 1);
+          libname[sizeof (libname) - 1] = '\0';
+          if (libname[0] != '\0')
+            {
+              if (!header_done)
+                {
+                  /* Terminate `<library-list-svr4'.  */
+                  document += '>';
+                  header_done = 1;
+                }
+
+              string_appendf (document, "<library name=\"");
+              xml_escape_text_append (&document, (char *) libname);
+              string_appendf (document, "\" lm=\"0x%lx\" "
+                              "l_addr=\"0x%lx\" l_ld=\"0x%lx\"/>",
+                              (unsigned long) lm_addr, (unsigned long) l_addr,
+                              (unsigned long) l_ld);
+            }
+        }
+
+      lm_prev = lm_addr;
+      lm_addr = l_next;
+    }
+
+  if (!header_done)
+    {
+      /* Empty list; terminate `<library-list-svr4'.  */
+      document += "/>";
+    }
+  else
+    document += "</library-list-svr4>";
+
+  int document_len = document.length ();
+  if (offset < document_len)
+    document_len -= offset;
+  else
+    document_len = 0;
+  if (len > document_len)
+    len = document_len;
+
+  memcpy (readbuf, document.data () + offset, len);
+
+  return len;
+}
+
+/* Return the name of a file that can be opened to get the symbols for
+   the child process identified by PID.  */
+
+static char *
+netbsd_pid_to_exec_file (pid_t pid)
+{
+  netbsd_debug ("%s(pid=%d)\n", __func__, pid);
+
+  return pid_to_exec_file(pid);
+}
+
+
+/* Implementation of the target_ops method "sw_breakpoint_from_kind".  */
+
+static const gdb_byte *
+netbsd_sw_breakpoint_from_kind (int kind, int *size)
+{
+  netbsd_debug ("%s(kind=%d)\n", __func__, kind);
+
+  static gdb_byte brkpt[PTRACE_BREAKPOINT_SIZE];
+
+  *size = PTRACE_BREAKPOINT_SIZE;
+
+  memcpy(brkpt, PTRACE_BREAKPOINT, PTRACE_BREAKPOINT_SIZE);
+
+  return brkpt;
+}
+
+const char *
+netbsd_thread_name (ptid_t ptid)
+{
+  netbsd_debug ("%s(ptid=(%d, %d, %d))\n",
+                __func__, ptid.pid(), ptid.lwp(), ptid.tid());
+
+  struct kinfo_lwp *kl;
+  pid_t pid = ptid.pid ();
+  lwpid_t lwp = ptid.lwp ();
+  static char buf[KI_LNAMELEN];
+  int mib[5];
+  size_t i, nlwps;
+  size_t size;
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_LWP;
+  mib[2] = pid;
+  mib[3] = sizeof(struct kinfo_lwp);
+  mib[4] = 0;
+
+  if (netbsd_sysctl (mib, 5, NULL, &size, NULL, 0) == -1 || size == 0)
+    perror_with_name (("sysctl"));
+
+  mib[4] = size / sizeof(size_t);
+
+  kl = (struct kinfo_lwp *) xmalloc (size);
+  if (kl == NULL)
+    perror_with_name (("malloc"));
+
+  if (netbsd_sysctl (mib, 5, kl, &size, NULL, 0) == -1 || size == 0)
+    perror_with_name (("sysctl"));
+
+  nlwps = size / sizeof(struct kinfo_lwp);
+  buf[0] = '\0';
+  for (i = 0; i < nlwps; i++) {
+    if (kl[i].l_lid == lwp) {
+      xsnprintf (buf, sizeof buf, "%s", kl[i].l_name);
+      break;
+    }
+  }
+  xfree(kl);
+
+  return buf;
+}
+
+static int
+netbsd_supports_catch_syscall (void)
+{
+  netbsd_debug ("%s()\n", __func__);
+
+  return 1;
+}
+
+/* The NetBSD target_ops vector.  */
+
+static struct target_ops netbsd_target_ops = {
+  netbsd_create_inferior,
+  NULL,  /* post_create_inferior */
+  netbsd_attach,
+  netbsd_kill,
+  netbsd_detach,
+  netbsd_mourn,
+  netbsd_join,
+  netbsd_thread_alive,
+  netbsd_resume,
+  netbsd_wait,
+  netbsd_fetch_registers,
+  netbsd_store_registers,
+  NULL,  /* prepare_to_access_memory */
+  NULL,  /* done_accessing_memory */
+  netbsd_read_memory,
+  netbsd_write_memory,
+  NULL,  /* look_up_symbols */
+  netbsd_request_interrupt,
+  netbsd_read_auxv,
+  netbsd_supports_z_point_type,
+  netbsd_insert_point,
+  netbsd_remove_point,
+  netbsd_stopped_by_sw_breakpoint,
+  netbsd_supports_stopped_by_sw_breakpoint,
+  NULL,  /* stopped_by_hw_breakpoint */
+  NULL,  /* supports_stopped_by_hw_breakpoint */
+  target_can_do_hardware_single_step,
+  NULL,  /* stopped_by_watchpoint */
+  NULL,  /* stopped_data_address */
+  NULL,  /* read_offsets */
+  NULL,  /* get_tls_address */
+  NULL,  /* qxfer_spu */
+  hostio_last_error_from_errno,
+  NULL,  /* qxfer_osdata */
+  netbsd_qxfer_siginfo,
+  netbsd_supports_non_stop,
+  NULL,  /* async */
+  NULL,  /* start_non_stop */
+  netbsd_supports_multi_process,
+  netbsd_supports_fork_events,
+  netbsd_supports_vfork_events,
+  netbsd_supports_exec_events,
+  NULL,  /* handle_new_gdb_connection */
+  NULL,  /* handle_monitor_command */
+  NULL,  /* core_of_thread */
+  NULL,  /* read_loadmap */
+  NULL,  /* process_qsupported */
+  NULL,  /* supports_tracepoints */
+  NULL,  /* read_pc */
+  NULL,  /* write_pc */
+  NULL,  /* thread_stopped */
+  NULL,  /* get_tib_address */
+  NULL,  /* pause_all */
+  NULL,  /* unpause_all */
+  NULL,  /* stabilize_threads */
+  NULL,  /* install_fast_tracepoint_jump_pad */
+  NULL,  /* emit_ops */
+  netbsd_supports_disable_randomization,
+  NULL,  /* get_min_fast_tracepoint_insn_len */
+  netbsd_qxfer_libraries_svr4,
+  NULL,  /* supports_agent */
+  NULL,  /* enable_btrace */
+  NULL,  /* disable_btrace */
+  NULL,  /* read_btrace */
+  NULL,  /* read_btrace_conf */
+  NULL,  /* supports_range_stepping */
+  netbsd_pid_to_exec_file,
+  NULL,  /* multifs_open */
+  NULL,  /* multifs_unlink */
+  NULL,  /* multifs_readlink */
+  NULL,  /* breakpoint_kind_from_pc */
+  netbsd_sw_breakpoint_from_kind,
+  netbsd_thread_name,
+  NULL,  /* breakpoint_kind_from_current_state */
+  NULL,  /* supports_software_single_step */
+  netbsd_supports_catch_syscall,
+  NULL,  /* get_ipa_tdesc_idx */
+  NULL,  /* thread_handle */
+};
+
+void
+initialize_low (void)
+{
+  set_target_ops (&netbsd_target_ops);
+  the_low_target.arch_setup ();
+}
