$NetBSD$

--- gdb/nat/netbsd-nat.c.orig	2020-09-02 16:10:13.481373355 +0000
+++ gdb/nat/netbsd-nat.c
@@ -0,0 +1,211 @@
+/* Internal interfaces for the NetBSD code.
+
+   Copyright (C) 2006-2020 Free Software Foundation, Inc.
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
+#include "gdbsupport/common-defs.h"
+#include "nat/netbsd-nat.h"
+#include "gdbsupport/common-debug.h"
+
+#include <sys/types.h>
+#include <sys/ptrace.h>
+#include <sys/sysctl.h>
+
+#include "gdbsupport/function-view.h"
+
+namespace netbsd_nat
+{
+
+/* Return the executable file name of a process specified by PID.  Returns the
+   string in a static buffer.  */
+
+char *
+pid_to_exec_file (pid_t pid)
+{
+  static char buf[PATH_MAX];
+  int mib[4] = {CTL_KERN, KERN_PROC_ARGS, pid, KERN_PROC_PATHNAME};
+  size_t buflen = sizeof (buf);
+  if (::sysctl (mib, ARRAY_SIZE (mib), buf, &buflen, NULL, 0))
+    return NULL;
+  return buf;
+}
+
+/* Generic thread (LWP) lister within a specified process.  The callback
+   parameters is a C++ function that is called for each detected thread.  */
+
+static bool
+netbsd_thread_lister (const pid_t pid,
+		      gdb::function_view<bool (const struct kinfo_lwp *)>
+		      callback)
+{
+  int mib[5] = {CTL_KERN, KERN_LWP, pid, sizeof (struct kinfo_lwp), 0};
+  size_t size;
+
+  if (sysctl (mib, ARRAY_SIZE (mib), NULL, &size, NULL, 0) == -1 || size == 0)
+    perror_with_name (("sysctl"));
+
+  mib[4] = size / sizeof (size_t);
+
+  gdb::unique_xmalloc_ptr<struct kinfo_lwp[]> kl
+    ((struct kinfo_lwp *) xcalloc (size, 1));
+
+  if (sysctl (mib, ARRAY_SIZE (mib), kl.get (), &size, NULL, 0) == -1
+      || size == 0)
+    perror_with_name (("sysctl"));
+
+  for (size_t i = 0; i < size / sizeof (struct kinfo_lwp); i++)
+    {
+      struct kinfo_lwp *l = &kl[i];
+
+      /* Return true if the specified thread is alive.  */
+      auto lwp_alive
+	= [] (struct kinfo_lwp *lwp)
+	  {
+	    switch (lwp->l_stat)
+	      {
+	      case LSSLEEP:
+	      case LSRUN:
+	      case LSONPROC:
+	      case LSSTOP:
+	      case LSSUSPENDED:
+		return true;
+	      default:
+		return false;
+	      }
+	  };
+
+      /* Ignore embryonic or demised threads.  */
+      if (!lwp_alive (l))
+	continue;
+
+      if (callback (l))
+	return true;
+    }
+
+  return false;
+}
+
+/* Return true if PTID is still active in the inferior.  */
+
+bool
+thread_alive (ptid_t ptid)
+{
+  pid_t pid = ptid.pid ();
+  lwpid_t lwp = ptid.lwp ();
+
+  auto fn
+    = [&lwp] (const struct kinfo_lwp *kl)
+      {
+        return kl->l_lid == lwp;
+      };
+
+  return netbsd_thread_lister (pid, fn);
+}
+
+/* Return the name assigned to a thread by an application.  Returns
+   the string in a static buffer.  */
+
+const char *
+thread_name (ptid_t ptid)
+{
+  pid_t pid = ptid.pid ();
+  lwpid_t lwp = ptid.lwp ();
+
+  static char buf[KI_LNAMELEN] = {};
+
+  auto fn
+    = [&lwp] (const struct kinfo_lwp *kl)
+      {
+	if (kl->l_lid == lwp)
+	  {
+	    xsnprintf (buf, sizeof buf, "%s", kl->l_name);
+	    return true;
+	  }
+	return false;
+      };
+
+  if (netbsd_thread_lister (pid, fn))
+    return buf;
+  else
+    return NULL;
+}
+
+/* A generic thread lister within a specific PID.  The CALLBACK parameter
+   is a C++ function that is called for each detected thread.  */
+
+void
+list_threads (pid_t pid, gdb::function_view<void (ptid_t)> callback)
+{
+  auto fn
+    = [&callback, &pid] (const struct kinfo_lwp *kl)
+      {
+	ptid_t ptid = ptid_t (pid, kl->l_lid, 0);
+	callback (ptid);
+	return false;
+      };
+
+  netbsd_thread_lister (pid, fn);
+}
+
+/* Enable additional event reporting in a new process specified by PID.  */
+
+void
+enable_proc_events (pid_t pid)
+{
+  int events;
+
+  if (ptrace (PT_GET_EVENT_MASK, pid, &events, sizeof (events)) == -1)
+    perror_with_name (("ptrace"));
+
+  events |= PTRACE_LWP_CREATE;
+  events |= PTRACE_LWP_EXIT;
+
+  if (ptrace (PT_SET_EVENT_MASK, pid, &events, sizeof (events)) == -1)
+    perror_with_name (("ptrace"));
+}
+
+/* Implement reading and writing of inferior's siginfo_t specified by PID.
+   Returns -1 on failure and the number of bytes on a successful transfer.  */
+
+int
+qxfer_siginfo (pid_t pid, const char *annex, unsigned char *readbuf,
+	       unsigned const char *writebuf, CORE_ADDR offset, int len)
+{
+  ptrace_siginfo_t psi;
+
+  if (offset > sizeof (siginfo_t))
+    return -1;
+
+  if (ptrace (PT_GET_SIGINFO, pid, &psi, sizeof (psi)) == -1)
+    return -1;
+
+  if (offset + len > sizeof (siginfo_t))
+    len = sizeof (siginfo_t) - offset;
+
+  if (readbuf != NULL)
+    memcpy (readbuf, ((gdb_byte *) &psi.psi_siginfo) + offset, len);
+  else
+    {
+      memcpy (((gdb_byte *) &psi.psi_siginfo) + offset, writebuf, len);
+
+      if (ptrace (PT_SET_SIGINFO, pid, &psi, sizeof (psi)) == -1)
+	return -1;
+    }
+  return len;
+}
+
+}
