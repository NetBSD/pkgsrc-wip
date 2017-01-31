$NetBSD$

--- source/Host/common/Host.cpp.orig	2017-01-31 17:20:57.000000000 +0000
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
@@ -623,7 +625,7 @@ Error Host::RunShellCommand(const Args &
   return error;
 }
 
-// LaunchProcessPosixSpawn for Apple, Linux, FreeBSD and other GLIBC
+// LaunchProcessPosixSpawn for Apple, Linux, FreeBSD, NetBSD and other GLIBC
 // systems
 
 #if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__) ||        \
@@ -700,7 +702,7 @@ Error Host::LaunchProcessPosixSpawn(cons
   sigemptyset(&no_signals);
   sigfillset(&all_signals);
   ::posix_spawnattr_setsigmask(&attr, &no_signals);
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
   ::posix_spawnattr_setsigdefault(&attr, &no_signals);
 #else
   ::posix_spawnattr_setsigdefault(&attr, &all_signals);
@@ -977,6 +979,8 @@ Error Host::LaunchProcess(ProcessLaunchI
   delegate_launcher.reset(new ProcessLauncherWindows());
 #elif defined(__linux__)
   delegate_launcher.reset(new ProcessLauncherLinux());
+#elif defined(__NetBSD__)
+  delegate_launcher.reset(new ProcessLauncherNetBSD());
 #else
   delegate_launcher.reset(new ProcessLauncherPosix());
 #endif
