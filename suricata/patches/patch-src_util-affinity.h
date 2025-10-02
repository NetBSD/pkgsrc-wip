$NetBSD$

--- src/util-affinity.h.orig	2025-09-16 02:07:13.000000000 +0000
+++ src/util-affinity.h
@@ -43,6 +43,14 @@
 #include <sched.h>
 #include <sys/param.h>
 #include <sys/resource.h>
+#elif defined __NetBSD__
+#include <pthread.h>
+#include <sched.h>
+#define cpu_set_t cpuset_t *
+#define CPU_SET(cpu_id, cset) (cpuset_set(cpu_id, *cset))
+#define CPU_ISSET(cpu_id, cset) (cpuset_isset(cpu_id, *cset) > 0)
+void cpuZero(cpu_set_t *cset);
+#define CPU_ZERO(cset) (cpuZero(cset))
 #elif defined OS_DARWIN
 #include <mach/mach.h>
 #include <mach/mach_init.h>
