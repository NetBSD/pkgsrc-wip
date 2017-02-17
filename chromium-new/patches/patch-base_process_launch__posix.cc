$NetBSD$

--- base/process/launch_posix.cc.orig	2017-02-02 02:02:47.000000000 +0000
+++ base/process/launch_posix.cc
@@ -64,6 +64,7 @@
 #include "base/feature_list.h"
 #else
 extern char** environ;
+#pragma weak environ
 #endif
 
 namespace base {
@@ -219,6 +220,8 @@ static const char kFDDir[] = "/dev/fd";
 static const char kFDDir[] = "/dev/fd";
 #elif defined(OS_FREEBSD)
 static const char kFDDir[] = "/dev/fd";
+#elif defined(OS_NETBSD)
+static const char kFDDir[] = "/dev/fd";
 #elif defined(OS_OPENBSD)
 static const char kFDDir[] = "/dev/fd";
 #elif defined(OS_ANDROID)
