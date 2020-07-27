$NetBSD$

--- base/test/launcher/test_launcher.cc.orig	2020-07-08 21:41:45.000000000 +0000
+++ base/test/launcher/test_launcher.cc
@@ -56,6 +56,7 @@
 #include "testing/gtest/include/gtest/gtest.h"
 
 #if defined(OS_POSIX)
+#include <signal.h>
 #include <fcntl.h>
 
 #include "base/files/file_descriptor_watcher_posix.h"
@@ -582,7 +583,7 @@ ChildProcessResults DoLaunchChildTestPro
 #if !defined(OS_FUCHSIA)
   options.new_process_group = true;
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   options.kill_on_parent_death = true;
 #endif
 
@@ -1497,6 +1498,10 @@ bool TestLauncher::Init(CommandLine* com
   results_tracker_.AddGlobalTag("OS_OPENBSD");
 #endif
 
+#if defined(OS_NETBSD)
+  results_tracker_.AddGlobalTag("OS_NETBSD");
+#endif
+
 #if defined(OS_POSIX)
   results_tracker_.AddGlobalTag("OS_POSIX");
 #endif
