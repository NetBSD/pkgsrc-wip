$NetBSD$

--- base/process/launch_posix.cc.orig	2016-11-16 08:03:06.053219341 +0000
+++ base/process/launch_posix.cc
@@ -215,6 +215,8 @@ static const char kFDDir[] = "/dev/fd";
 static const char kFDDir[] = "/dev/fd";
 #elif defined(OS_OPENBSD)
 static const char kFDDir[] = "/dev/fd";
+#elif defined(OS_NETBSD)
+static const char kFDDir[] = "/dev/fd";
 #elif defined(OS_ANDROID)
 static const char kFDDir[] = "/proc/self/fd";
 #endif
