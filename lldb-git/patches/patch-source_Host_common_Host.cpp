$NetBSD$

--- source/Host/common/Host.cpp.orig	2017-01-31 20:59:30.000000000 +0000
+++ source/Host/common/Host.cpp
@@ -73,6 +73,8 @@
 #include "lldb/Host/windows/ProcessLauncherWindows.h"
 #elif defined(__linux__)
 #include "lldb/Host/linux/ProcessLauncherLinux.h"
+#elif defined(__NetBSD__)
+#include "lldb/Host/netbsd/ProcessLauncherNetBSD.h"
 #else
 #include "lldb/Host/posix/ProcessLauncherPosix.h"
 #endif
@@ -977,6 +979,8 @@ Error Host::LaunchProcess(ProcessLaunchI
   delegate_launcher.reset(new ProcessLauncherWindows());
 #elif defined(__linux__)
   delegate_launcher.reset(new ProcessLauncherLinux());
+#elif defined(__NetBSD__)
+  delegate_launcher.reset(new ProcessLauncherNetBSD());
 #else
   delegate_launcher.reset(new ProcessLauncherPosix());
 #endif
