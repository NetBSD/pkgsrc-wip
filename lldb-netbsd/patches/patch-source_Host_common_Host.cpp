$NetBSD$

--- source/Host/common/Host.cpp.orig	2017-01-31 17:20:57.000000000 +0000
+++ source/Host/common/Host.cpp
@@ -71,8 +71,8 @@
 
 #if defined(_WIN32)
 #include "lldb/Host/windows/ProcessLauncherWindows.h"
-#elif defined(__linux__)
-#include "lldb/Host/linux/ProcessLauncherLinux.h"
+#elif defined(__linux__) || defined(__NetBSD__)
+#include "lldb/Host/posix/ProcessLauncherPosixFork.h"
 #else
 #include "lldb/Host/posix/ProcessLauncherPosix.h"
 #endif
@@ -623,7 +623,7 @@ Error Host::RunShellCommand(const Args &
   return error;
 }
 
-// LaunchProcessPosixSpawn for Apple, Linux, FreeBSD and other GLIBC
+// LaunchProcessPosixSpawn for Apple, Linux, FreeBSD, NetBSD and other GLIBC
 // systems
 
 #if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__) ||        \
@@ -700,7 +700,7 @@ Error Host::LaunchProcessPosixSpawn(cons
   sigemptyset(&no_signals);
   sigfillset(&all_signals);
   ::posix_spawnattr_setsigmask(&attr, &no_signals);
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
   ::posix_spawnattr_setsigdefault(&attr, &no_signals);
 #else
   ::posix_spawnattr_setsigdefault(&attr, &all_signals);
@@ -975,8 +975,8 @@ Error Host::LaunchProcess(ProcessLaunchI
   std::unique_ptr<ProcessLauncher> delegate_launcher;
 #if defined(_WIN32)
   delegate_launcher.reset(new ProcessLauncherWindows());
-#elif defined(__linux__)
-  delegate_launcher.reset(new ProcessLauncherLinux());
+#elif defined(__linux__) || defined(__NetBSD__)
+  delegate_launcher.reset(new ProcessLauncherPosixFork());
 #else
   delegate_launcher.reset(new ProcessLauncherPosix());
 #endif
