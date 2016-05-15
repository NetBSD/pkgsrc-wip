$NetBSD$

# Linux compatibility
--- src/common/gres.c.orig	2016-05-03 22:41:59.000000000 +0000
+++ src/common/gres.c
@@ -79,6 +79,21 @@ typedef cpuset_t cpu_set_t;
 #include <sys/stat.h>
 #include <math.h>
 
+#ifdef __NetBSD__
+#define CPU_ZERO(p) cpuset_zero((p))
+#define CPU_ISSET(i,c) cpuset_isset((i),(c))
+#define sched_getaffinity sched_getaffinity_np
+#define SCHED_GETAFFINITY_THREE_ARGS
+
+// From /usr/src/common/lib/libc/sys/cpuset.c
+struct _cpuset {
+       uint32_t        bits[0];
+};
+
+// Must come after #include <sched.h>
+typedef cpuset_t cpu_set_t;
+#endif
+
 #include "slurm/slurm.h"
 #include "slurm/slurm_errno.h"
 #include "src/common/bitstring.h"
