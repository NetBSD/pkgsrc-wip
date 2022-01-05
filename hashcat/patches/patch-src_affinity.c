$NetBSD$

Tentatively fix the build for NetBSD

--- src/affinity.c.orig	2022-01-05 22:06:04.906472892 +0000
+++ src/affinity.c
@@ -45,6 +45,11 @@ static int pthread_setaffinity_np (pthre
 typedef cpuset_t cpu_set_t;
 #endif
 
+#if defined(__NetBSD__)
+#include <sys/intrio.h>
+typedef cpuset_t cpu_set_t;
+#endif
+
 int set_cpu_affinity (MAYBE_UNUSED hashcat_ctx_t *hashcat_ctx)
 {
 #if defined (__CYGWIN__)
