$NetBSD$

Patch for NO_AFFINITY=1. Sent upstream as issue #979.

--- driver/others/memory.c.orig	2016-10-11 14:00:54.030387184 +0000
+++ driver/others/memory.c
@@ -169,7 +169,7 @@ void goto_set_num_threads(int num_thread
 
 #else
 
-#if defined(OS_LINUX) || defined(OS_SUNOS)
+#if defined(OS_LINUX) || defined(OS_SUNOS) || defined(OS_NETBSD)
 #ifndef NO_AFFINITY
 int get_num_procs(void);
 #else
