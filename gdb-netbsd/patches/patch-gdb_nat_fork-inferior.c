$NetBSD$

--- gdb/nat/fork-inferior.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/nat/fork-inferior.c
@@ -525,7 +525,7 @@ startup_inferior (pid_t pid, int ntraps,
 
 	  case TARGET_WAITKIND_EXECD:
 	    /* Handle EXEC signals as if they were SIGTRAP signals.  */
-	    xfree (ws.value.execd_pathname);
+//	    xfree (ws.value.execd_pathname);
 	    resume_signal = GDB_SIGNAL_TRAP;
 	    switch_to_thread (event_ptid);
 	    break;
