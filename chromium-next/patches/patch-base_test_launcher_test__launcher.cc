$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/test/launcher/test_launcher.cc.orig	2025-03-31 15:23:48.000000000 +0000
+++ base/test/launcher/test_launcher.cc
@@ -73,6 +73,7 @@
 #include "testing/gtest/include/gtest/gtest.h"
 
 #if BUILDFLAG(IS_POSIX)
+#include <signal.h>
 #include <fcntl.h>
 
 #include "base/files/file_descriptor_watcher_posix.h"
@@ -1831,6 +1832,10 @@ bool TestLauncher::Init(CommandLine* com
   results_tracker_.AddGlobalTag("OS_OPENBSD");
 #endif
 
+#if BUILDFLAG(IS_NETBSD)
+  results_tracker_.AddGlobalTag("OS_NETBSD");
+#endif
+
 #if BUILDFLAG(IS_POSIX)
   results_tracker_.AddGlobalTag("OS_POSIX");
 #endif
