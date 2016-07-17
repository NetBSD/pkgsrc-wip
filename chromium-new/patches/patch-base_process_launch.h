$NetBSD$

--- base/process/launch.h.orig	2016-06-24 01:02:08.000000000 +0000
+++ base/process/launch.h
@@ -138,7 +138,7 @@ struct BASE_EXPORT LaunchOptions {
   // will be the same as its pid.
   bool new_process_group;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD) || defined(OS_NETBSD)
   // If non-zero, start the process using clone(), using flags as provided.
   // Unlike in clone, clone_flags may not contain a custom termination signal
   // that is sent to the parent when the child dies. The termination signal will
@@ -151,7 +151,7 @@ struct BASE_EXPORT LaunchOptions {
 
   // Sets parent process death signal to SIGKILL.
   bool kill_on_parent_death;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_FREEBSD) || defined(OS_NETBSD)
 
 #if defined(OS_POSIX)
   // If non-null, a delegate to be run immediately prior to executing the new
