$NetBSD$

--- gdb/inf-ptrace.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/inf-ptrace.c
@@ -322,10 +322,12 @@ get_ptrace_pid (ptid_t ptid)
 {
   pid_t pid;
 
+#ifndef __NetBSD__
   /* If we have an LWPID to work with, use it.  Otherwise, we're
      dealing with a non-threaded program/target.  */
   pid = ptid.lwp ();
   if (pid == 0)
+#endif
     pid = ptid.pid ();
   return pid;
 }
@@ -338,7 +340,7 @@ void
 inf_ptrace_target::resume (ptid_t ptid, int step, enum gdb_signal signal)
 {
   pid_t pid;
-  int request;
+  int request, sig;
 
   if (minus_one_ptid == ptid)
     /* Resume all threads.  Traditionally ptrace() only supports
@@ -360,13 +362,23 @@ inf_ptrace_target::resume (ptid_t ptid, 
          all possible successor instructions), so we don't have to
          worry about that here.  */
       request = PT_STEP;
-    }
+#if __NetBSD__
+      /*
+       * On NetBSD the data field of PT_STEP contains the thread
+       * to be stepped; all other threads are continued if this value is > 0
+       */
+      sig = ptid.lwp ();
+#else
+      sig = 0;
+#endif
+    } else
+      sig = gdb_signal_to_host (signal);
 
   /* An address of (PTRACE_TYPE_ARG3)1 tells ptrace to continue from
      where it was.  If GDB wanted it to start some other way, we have
      already written a new program counter value to the child.  */
   errno = 0;
-  ptrace (request, pid, (PTRACE_TYPE_ARG3)1, gdb_signal_to_host (signal));
+  ptrace (request, pid, (PTRACE_TYPE_ARG3)1, sig);
   if (errno != 0)
     perror_with_name (("ptrace"));
 }
@@ -562,6 +574,15 @@ inf_ptrace_target::xfer_partial (enum ta
 	/* If the PT_IO request is somehow not supported, fallback on
 	   using PT_WRITE_D/PT_READ_D.  Otherwise we will return zero
 	   to indicate failure.  */
+	if (errno == EACCES)
+	  {
+	    fprintf_unfiltered (gdb_stderr, "Cannot %s process at %p (%s). "
+				"Is PaX MPROTECT active? See security(7), "
+				"sysctl(7), paxctl(8)\n", writebuf ? "write to" :
+				"read from", piod.piod_offs,
+				strerror(errno));
+	    return TARGET_XFER_E_IO;	/* Some other error perhaps? */
+	  }
 	if (errno != EINVAL)
 	  return TARGET_XFER_EOF;
       }
