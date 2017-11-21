$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_limits_posix.cc.orig	2017-11-16 17:55:37.000000000 +0000
+++ lib/sanitizer_common/sanitizer_platform_limits_posix.cc
@@ -210,6 +210,7 @@ namespace __sanitizer {
   unsigned struct_sigaction_sz = sizeof(struct sigaction);
   unsigned struct_itimerval_sz = sizeof(struct itimerval);
   unsigned pthread_t_sz = sizeof(pthread_t);
+  unsigned pthread_mutex_t_sz = sizeof(pthread_mutex_t);
   unsigned pthread_cond_t_sz = sizeof(pthread_cond_t);
   unsigned pid_t_sz = sizeof(pid_t);
   unsigned timeval_sz = sizeof(timeval);
