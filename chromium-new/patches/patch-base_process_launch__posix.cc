$NetBSD$

--- base/process/launch_posix.cc.orig	2016-06-24 01:02:08.000000000 +0000
+++ base/process/launch_posix.cc
@@ -214,6 +214,8 @@ static const char kFDDir[] = "/dev/fd";
 static const char kFDDir[] = "/dev/fd";
 #elif defined(OS_OPENBSD)
 static const char kFDDir[] = "/dev/fd";
+#elif defined(OS_NETBSD)
+static const char kFDDir[] = "/dev/fd";
 #elif defined(OS_ANDROID)
 static const char kFDDir[] = "/proc/self/fd";
 #endif
