$NetBSD$

--- src/util-affinity.c.orig	2025-09-16 02:07:13.000000000 +0000
+++ src/util-affinity.c
@@ -35,6 +35,37 @@
 #include "util-dpdk.h"
 #include "util-unittest.h"
 
+#ifdef __NetBSD__
+
+#include "util-debug.h"
+
+void cpuZero(cpu_set_t *cset) {
+  if(*cset == NULL) {
+    // if the cpu set inst crated yet - create it
+    cpuset_t *new_cset = cpuset_create();
+    if(new_cset == NULL) {
+      FatalError("Error creating cpu set in cpuZero");
+      //      warnc(EXIT_FAILURE, "cpuset_create");
+      return;
+    }
+    *cset = new_cset;
+  }
+  cpuset_zero(*cset);
+}
+
+#ifdef UNITTESTS
+int cpuCount(cpu_set_t *cset) {
+  int c = 0;
+  for (int i = 0; i < MAX_CPU_SET; i++) {
+    if(cpuset_isset(0, *cset) > 0) c++;
+  }
+  return c;
+}
+
+#define CPU_COUNT(cset) (cpuCount(cset))
+#endif /* UNITTESTS */
+#endif /* __NetBSD__ */
+
 ThreadsAffinityType thread_affinity[MAX_CPU_SET] = {
     {
             .name = "receive-cpu-set",
