$NetBSD$

--- gdb/thread.c.orig	2020-03-25 17:24:08.000000000 +0000
+++ gdb/thread.c
@@ -325,6 +325,7 @@ add_thread_with_info (process_stratum_ta
 struct thread_info *
 add_thread (process_stratum_target *targ, ptid_t ptid)
 {
+  fprintf_unfiltered (gdb_stderr, "ADD THREAD: (pid=%d, lwp=%ld, tid=%ld)\n", ptid.pid (), ptid.lwp (), ptid.tid ());
   return add_thread_with_info (targ, ptid, NULL);
 }
 
