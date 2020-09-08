$NetBSD$

--- gdb/nat/fork-inferior.c.orig	2020-09-03 16:35:18.000000000 +0000
+++ gdb/nat/fork-inferior.c
@@ -526,7 +526,10 @@ startup_inferior (process_stratum_target
 
 	  case TARGET_WAITKIND_EXECD:
 	    /* Handle EXEC signals as if they were SIGTRAP signals.  */
-	    xfree (ws.value.execd_pathname);
+	    /* Free the exec'ed pathname, but only if this isn't the
+	       waitstatus we are returning to the caller.  */
+	    if (pending_execs != 1)
+	      xfree (ws.value.execd_pathname);
 	    resume_signal = GDB_SIGNAL_TRAP;
 	    switch_to_thread (proc_target, event_ptid);
 	    break;
