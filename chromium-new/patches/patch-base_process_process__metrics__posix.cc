$NetBSD$

--- base/process/process_metrics_posix.cc.orig	2016-06-24 01:02:08.000000000 +0000
+++ base/process/process_metrics_posix.cc
@@ -35,6 +35,8 @@ static const rlim_t kSystemDefaultMaxFds
 static const rlim_t kSystemDefaultMaxFds = 8192;
 #elif defined(OS_OPENBSD)
 static const rlim_t kSystemDefaultMaxFds = 256;
+#elif defined(OS_NETBSD)
+static const rlim_t kSystemDefaultMaxFds = 1024;
 #elif defined(OS_ANDROID)
 static const rlim_t kSystemDefaultMaxFds = 1024;
 #endif
