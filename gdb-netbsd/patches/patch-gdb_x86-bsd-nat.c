$NetBSD$

--- gdb/x86-bsd-nat.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/x86-bsd-nat.c
@@ -58,7 +58,7 @@ x86bsd_dr_get (ptid_t ptid, int regnum)
   struct dbreg dbregs;
 
   if (ptrace (PT_GETDBREGS, get_ptrace_pid (inferior_ptid),
-	      (PTRACE_TYPE_ARG3) &dbregs, 0) == -1)
+	      (PTRACE_TYPE_ARG3) &dbregs, inferior_ptid.lwp ()) == -1)
     perror_with_name (_("Couldn't read debug registers"));
 
   return DBREG_DRX ((&dbregs), regnum);
@@ -70,7 +70,7 @@ x86bsd_dr_set (int regnum, unsigned long
   struct dbreg dbregs;
 
   if (ptrace (PT_GETDBREGS, get_ptrace_pid (inferior_ptid),
-              (PTRACE_TYPE_ARG3) &dbregs, 0) == -1)
+              (PTRACE_TYPE_ARG3) &dbregs, inferior_ptid.lwp ()) == -1)
     perror_with_name (_("Couldn't get debug registers"));
 
   /* For some mysterious reason, some of the reserved bits in the
@@ -83,7 +83,7 @@ x86bsd_dr_set (int regnum, unsigned long
   for (thread_info *thread : current_inferior ()->non_exited_threads ())
     {
       if (ptrace (PT_SETDBREGS, get_ptrace_pid (thread->ptid),
-		  (PTRACE_TYPE_ARG3) &dbregs, 0) == -1)
+		  (PTRACE_TYPE_ARG3) &dbregs, thread->ptid.lwp ()) == -1)
 	perror_with_name (_("Couldn't write debug registers"));
     }
 }
