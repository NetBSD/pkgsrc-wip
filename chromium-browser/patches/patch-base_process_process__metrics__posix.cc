$NetBSD$

--- base/process/process_metrics_posix.cc.orig	2016-08-05 17:13:37.000000000 +0000
+++ base/process/process_metrics_posix.cc
@@ -33,6 +33,8 @@ static const rlim_t kSystemDefaultMaxFds
 static const rlim_t kSystemDefaultMaxFds = 8192;
 #elif defined(OS_FREEBSD)
 static const rlim_t kSystemDefaultMaxFds = 8192;
+#elif defined(OS_NETBSD)
+static const rlim_t kSystemDefaultMaxFds = 1024;
 #elif defined(OS_OPENBSD)
 static const rlim_t kSystemDefaultMaxFds = 256;
 #elif defined(OS_ANDROID)
