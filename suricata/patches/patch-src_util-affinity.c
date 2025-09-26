$NetBSD$

--- src/util-affinity.c.orig	2025-09-16 02:07:13.000000000 +0000
+++ src/util-affinity.c
@@ -35,6 +35,18 @@
 #include "util-dpdk.h"
 #include "util-unittest.h"
 
+#if defined __NetBSD_ && defined UNITTESTS
+int cpuCount(cpu_set_t *cset) {
+  int c = 0;
+  for (int i = 0; i < MAX_CPU_SET; i++) {
+    if(cpuset_isset(0, *cset) > 0) c++;
+  }
+  return c;
+}
+
+#define CPU_COUNT(cset) (cpuCount(cset))
+#endif
+
 ThreadsAffinityType thread_affinity[MAX_CPU_SET] = {
     {
             .name = "receive-cpu-set",
