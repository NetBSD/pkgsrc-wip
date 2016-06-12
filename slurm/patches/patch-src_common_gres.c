$NetBSD$

--- src/common/gres.c.orig	2016-05-31 21:35:09.000000000 +0000
+++ src/common/gres.c
@@ -82,7 +82,8 @@ typedef cpuset_t cpu_set_t;
 #ifdef __NetBSD__
 #define CPU_ZERO(c) cpuset_zero(*(c))
 #define CPU_ISSET(i,c) cpuset_isset((i),*(c))
-#define sched_getaffinity sched_getaffinity_np
+#define sched_getaffinity(p,s,c) \
+        sched_getaffinity_np((p),cpuset_size(*(c)),*(c))
 #define SCHED_GETAFFINITY_THREE_ARGS
 #endif
 
