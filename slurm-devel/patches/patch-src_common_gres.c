$NetBSD$

# Linux compatiblity
--- src/common/gres.c.orig	2016-05-03 22:41:59.000000000 +0000
+++ src/common/gres.c
@@ -79,6 +79,14 @@ typedef cpuset_t cpu_set_t;
 #include <sys/stat.h>
 #include <math.h>
 
+// Linux compat layer for _get_usable_gres()
+#ifdef __NetBSD__
+#define CPU_ZERO(c) cpuset_zero(*(c))
+#define CPU_ISSET(i,c) cpuset_isset((i),*(c))
+#define sched_getaffinity sched_getaffinity_np
+#define SCHED_GETAFFINITY_THREE_ARGS
+#endif
+
 #include "slurm/slurm.h"
 #include "slurm/slurm_errno.h"
 #include "src/common/bitstring.h"
@@ -5591,7 +5599,12 @@ extern uint64_t gres_plugin_step_count(L
  * which are available from the CPUs current allocated to this process */
 static bitstr_t * _get_usable_gres(int context_inx)
 {
+#ifdef __NetBSD__
+	// On NetBSD, cpuset_t is an opaque data type
+	cpuset_t *mask = cpuset_create();
+#else
 	cpu_set_t mask;
+#endif
 	bitstr_t *usable_gres = NULL;
 	int i, i_last, rc;
 	ListIterator iter;
