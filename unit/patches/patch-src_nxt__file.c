$NetBSD$

Use fcntl on Solaris

--- src/nxt_file.c.orig	2020-11-19 18:12:30.000000000 +0000
+++ src/nxt_file.c
@@ -312,7 +312,7 @@ nxt_file_rename(nxt_file_name_t *old_nam
  * Linux 2.6 does not use BKL.
  */
 
-#if (NXT_HAVE_FIONBIO)
+#if (NXT_HAVE_FIONBIO) && !(NXT_SOLARIS)
 
 nxt_int_t
 nxt_fd_nonblocking(nxt_task_t *task, nxt_fd_t fd)
