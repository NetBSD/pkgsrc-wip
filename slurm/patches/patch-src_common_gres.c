$NetBSD$

--- gres.c.orig	2016-05-03 22:41:59.000000000 +0000
+++ gres.c
@@ -79,6 +79,14 @@ typedef cpuset_t cpu_set_t;
 #include <sys/stat.h>
 #include <math.h>
 
+#ifdef __NetBSD__
+typedef cpuset_t cpu_set_t;
+#define	CPU_ZERO(p) cpuset_zero((p))
+#define CPU_ISSET(i,c) cpuset_isset((i),(c))
+#define sched_getaffinity sched_getaffinity_np
+#define SCHED_GETAFFINITY_THREE_ARGS
+#endif
+
 #include "slurm/slurm.h"
 #include "slurm/slurm_errno.h"
 #include "src/common/bitstring.h"
