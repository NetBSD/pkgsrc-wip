$NetBSD$

# Portability

--- src/plugins/task/affinity/affinity.h.orig	2020-01-26 20:44:58.750715619 +0000
+++ src/plugins/task/affinity/affinity.h
@@ -52,6 +52,10 @@
    typedef cpuset_t cpu_set_t;
 #endif
 
+#ifdef __NetBSD__
+#define	CPU_SETSIZE	MAXCPUS
+#endif
+
 #ifdef HAVE_SYS_PRCTL_H
 #  include <sys/prctl.h>
 #endif
