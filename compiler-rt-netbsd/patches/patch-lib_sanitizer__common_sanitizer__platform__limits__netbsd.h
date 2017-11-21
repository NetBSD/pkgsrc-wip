$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_limits_netbsd.h.orig	2017-11-16 17:55:37.000000000 +0000
+++ lib/sanitizer_common/sanitizer_platform_limits_netbsd.h
@@ -38,6 +38,7 @@ extern unsigned struct_rusage_sz;
 extern unsigned siginfo_t_sz;
 extern unsigned struct_itimerval_sz;
 extern unsigned pthread_t_sz;
+extern unsigned pthread_mutex_t_sz;
 extern unsigned pthread_cond_t_sz;
 extern unsigned pid_t_sz;
 extern unsigned timeval_sz;
