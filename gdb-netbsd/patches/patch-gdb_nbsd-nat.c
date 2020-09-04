$NetBSD$

--- gdb/nbsd-nat.c.orig	2020-09-03 16:35:18.000000000 +0000
+++ gdb/nbsd-nat.c
@@ -20,6 +20,7 @@
 #include "defs.h"
 
 #include "nbsd-nat.h"
+#include "nat/netbsd-nat.h"
 #include "gdbthread.h"
 #include "nbsd-tdep.h"
 #include "inferior.h"
@@ -36,13 +37,7 @@
 char *
 nbsd_nat_target::pid_to_exec_file (int pid)
 {
-  static char buf[PATH_MAX];
-  size_t buflen;
-  int mib[4] = {CTL_KERN, KERN_PROC_ARGS, pid, KERN_PROC_PATHNAME};
-  buflen = sizeof (buf);
-  if (sysctl (mib, ARRAY_SIZE (mib), buf, &buflen, NULL, 0))
-    return NULL;
-  return buf;
+  return netbsd_nat::pid_to_exec_file (pid);
 }
 
 /* Return the current directory for the process identified by PID.  */
@@ -80,12 +75,12 @@ nbsd_pid_to_cmdline (int pid)
   int mib[4] = {CTL_KERN, KERN_PROC_ARGS, pid, KERN_PROC_ARGV};
 
   size_t size = 0;
-  if (sysctl (mib, ARRAY_SIZE (mib), NULL, &size, NULL, 0) == -1 || size == 0)
+  if (::sysctl (mib, ARRAY_SIZE (mib), NULL, &size, NULL, 0) == -1 || size == 0)
     return nullptr;
 
   gdb::unique_xmalloc_ptr<char[]> args (XNEWVAR (char, size));
 
-  if (sysctl (mib, ARRAY_SIZE (mib), args.get (), &size, NULL, 0) == -1
+  if (::sysctl (mib, ARRAY_SIZE (mib), args.get (), &size, NULL, 0) == -1
       || size == 0)
     return nullptr;
 
@@ -99,76 +94,12 @@ nbsd_pid_to_cmdline (int pid)
   return args;
 }
 
-/* Generic thread (LWP) lister within a specified process.  The callback
-   parameters is a C++ function that is called for each detected thread.  */
-
-static bool
-nbsd_thread_lister (const pid_t pid,
-		    gdb::function_view<bool (const struct kinfo_lwp *)>
-		    callback)
-{
-  int mib[5] = {CTL_KERN, KERN_LWP, pid, sizeof (struct kinfo_lwp), 0};
-  size_t size;
-
-  if (sysctl (mib, ARRAY_SIZE (mib), NULL, &size, NULL, 0) == -1 || size == 0)
-    perror_with_name (("sysctl"));
-
-  mib[4] = size / sizeof (size_t);
-
-  gdb::unique_xmalloc_ptr<struct kinfo_lwp[]> kl
-    ((struct kinfo_lwp *) xcalloc (size, 1));
-
-  if (sysctl (mib, ARRAY_SIZE (mib), kl.get (), &size, NULL, 0) == -1
-      || size == 0)
-    perror_with_name (("sysctl"));
-
-  for (size_t i = 0; i < size / sizeof (struct kinfo_lwp); i++)
-    {
-      struct kinfo_lwp *l = &kl[i];
-
-      /* Return true if the specified thread is alive.  */
-      auto lwp_alive
-	= [] (struct kinfo_lwp *lwp)
-	  {
-	    switch (lwp->l_stat)
-	      {
-	      case LSSLEEP:
-	      case LSRUN:
-	      case LSONPROC:
-	      case LSSTOP:
-	      case LSSUSPENDED:
-		return true;
-	      default:
-		return false;
-	      }
-	  };
-
-      /* Ignore embryonic or demised threads.  */
-      if (!lwp_alive (l))
-	continue;
-
-      if (callback (l))
-	return true;
-    }
-
-  return false;
-}
-
 /* Return true if PTID is still active in the inferior.  */
 
 bool
 nbsd_nat_target::thread_alive (ptid_t ptid)
 {
-  pid_t pid = ptid.pid ();
-  int lwp = ptid.lwp ();
-
-  auto fn
-    = [&lwp] (const struct kinfo_lwp *kl)
-      {
-        return kl->l_lid == lwp;
-      };
-
-  return nbsd_thread_lister (pid, fn);
+  return netbsd_nat::thread_alive (ptid);
 }
 
 /* Return the name assigned to a thread by an application.  Returns
@@ -178,26 +109,7 @@ const char *
 nbsd_nat_target::thread_name (struct thread_info *thr)
 {
   ptid_t ptid = thr->ptid;
-  pid_t pid = ptid.pid ();
-  int lwp = ptid.lwp ();
-
-  static char buf[KI_LNAMELEN] = {};
-
-  auto fn
-    = [&lwp] (const struct kinfo_lwp *kl)
-      {
-	if (kl->l_lid == lwp)
-	  {
-	    xsnprintf (buf, sizeof buf, "%s", kl->l_name);
-	    return true;
-	  }
-	return false;
-      };
-
-  if (nbsd_thread_lister (pid, fn))
-    return buf;
-  else
-    return NULL;
+  return netbsd_nat::thread_name (ptid);
 }
 
 /* Implement the "post_attach" target_ops method.  */
@@ -206,9 +118,8 @@ static void
 nbsd_add_threads (nbsd_nat_target *target, pid_t pid)
 {
   auto fn
-    = [&target, &pid] (const struct kinfo_lwp *kl)
+    = [&target] (ptid_t ptid)
       {
-	ptid_t ptid = ptid_t (pid, kl->l_lid, 0);
 	if (!in_thread_list (target, ptid))
 	  {
 	    if (inferior_ptid.lwp () == 0)
@@ -216,27 +127,9 @@ nbsd_add_threads (nbsd_nat_target *targe
 	    else
 	      add_thread (target, ptid);
 	  }
-	return false;
       };
 
-  nbsd_thread_lister (pid, fn);
-}
-
-/* Enable additional event reporting on new processes.  */
-
-static void
-nbsd_enable_proc_events (pid_t pid)
-{
-  int events;
-
-  if (ptrace (PT_GET_EVENT_MASK, pid, &events, sizeof (events)) == -1)
-    perror_with_name (("ptrace"));
-
-  events |= PTRACE_LWP_CREATE;
-  events |= PTRACE_LWP_EXIT;
-
-  if (ptrace (PT_SET_EVENT_MASK, pid, &events, sizeof (events)) == -1)
-    perror_with_name (("ptrace"));
+  netbsd_nat::for_each_thread (pid, fn);
 }
 
 /* Implement the "post_startup_inferior" target_ops method.  */
@@ -244,7 +137,7 @@ nbsd_enable_proc_events (pid_t pid)
 void
 nbsd_nat_target::post_startup_inferior (ptid_t ptid)
 {
-  nbsd_enable_proc_events (ptid.pid ());
+  netbsd_nat::enable_proc_events (ptid.pid ());
 }
 
 /* Implement the "post_attach" target_ops method.  */
@@ -252,7 +145,7 @@ nbsd_nat_target::post_startup_inferior (
 void
 nbsd_nat_target::post_attach (int pid)
 {
-  nbsd_enable_proc_events (pid);
+  netbsd_nat::enable_proc_events (pid);
   nbsd_add_threads (this, pid);
 }
 
@@ -861,26 +754,12 @@ nbsd_nat_target::xfer_partial (enum targ
     {
     case TARGET_OBJECT_SIGNAL_INFO:
       {
-	ptrace_siginfo_t psi;
-
-	if (offset > sizeof (siginfo_t))
-	  return TARGET_XFER_E_IO;
+	len = netbsd_nat::qxfer_siginfo(pid, annex, readbuf, writebuf, offset,
+					len);
 
-	if (ptrace (PT_GET_SIGINFO, pid, &psi, sizeof (psi)) == -1)
+	if (len == -1)
 	  return TARGET_XFER_E_IO;
 
-	if (offset + len > sizeof (siginfo_t))
-	  len = sizeof (siginfo_t) - offset;
-
-	if (readbuf != NULL)
-	  memcpy (readbuf, ((gdb_byte *) &psi.psi_siginfo) + offset, len);
-	else
-	  {
-	    memcpy (((gdb_byte *) &psi.psi_siginfo) + offset, writebuf, len);
-
-	    if (ptrace (PT_SET_SIGINFO, pid, &psi, sizeof (psi)) == -1)
-	      return TARGET_XFER_E_IO;
-	  }
 	*xfered_len = len;
 	return TARGET_XFER_OK;
       }
