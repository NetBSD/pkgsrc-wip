$NetBSD$

# No eventfd on NetBSD 7

--- src/plugins/task/cgroup/task_cgroup_memory.c.orig	2018-02-26 19:16:37.000000000 +0000
+++ src/plugins/task/cgroup/task_cgroup_memory.c
@@ -39,7 +39,9 @@
 #include <poll.h>
 #include <signal.h>
 #include <stdlib.h>		/* getenv */
+#ifndef __NetBSD__
 #include <sys/eventfd.h>
+#endif
 #include <sys/types.h>
 #include <unistd.h>
 
