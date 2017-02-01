$NetBSD$

--- source/Host/common/Host.cpp.orig	2017-02-01 14:45:44.000000000 +0000
+++ source/Host/common/Host.cpp
@@ -700,7 +700,7 @@ Error Host::LaunchProcessPosixSpawn(cons
   sigemptyset(&no_signals);
   sigfillset(&all_signals);
   ::posix_spawnattr_setsigmask(&attr, &no_signals);
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
   ::posix_spawnattr_setsigdefault(&attr, &no_signals);
 #else
   ::posix_spawnattr_setsigdefault(&attr, &all_signals);
