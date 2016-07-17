$NetBSD$

--- base/process/launch.cc.orig	2016-06-24 01:02:08.000000000 +0000
+++ base/process/launch.cc
@@ -25,11 +25,11 @@ LaunchOptions::LaunchOptions()
       fds_to_remap(NULL),
       maximize_rlimits(NULL),
       new_process_group(false)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD) || defined(OS_NETBSD)
       , clone_flags(0)
       , allow_new_privs(false)
       , kill_on_parent_death(false)
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_FREEBSD || OS_NETBSD
 #if defined(OS_POSIX)
       , pre_exec_delegate(NULL)
 #endif  // OS_POSIX
