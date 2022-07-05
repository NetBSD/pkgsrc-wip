$NetBSD$

As of NetBSD 9.2 pthread_*_setpshared aren't supported. Default them to error
return value.

Upstream: https://github.com/utwente-fmt/ltsmin/issues/203

--- src/hre/hre_pthread.c.orig	2018-07-03 19:28:10.000000000 +0000
+++ src/hre/hre_pthread.c
@@ -17,6 +17,14 @@
 
 #include <hre/provider.h>
 
+#if defined(__NetBSD__)
+#  include <sys/param.h>
+#  if !__NetBSD_Prereq__(11, 0, 0)
+#    define pthread_mutexattr_setpshared(attr, flag) 1
+#    define pthread_condattr_setpshared(attr, flag) 1
+#  endif
+#endif
+
 /**
  * For pthreads we only use a small shared region for the queues.
  * For forks all shared objects are allocated on the region, so we try to claim
