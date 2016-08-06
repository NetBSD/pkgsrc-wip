$NetBSD$

--- base/process/process_posix.cc.orig	2016-08-05 17:13:37.000000000 +0000
+++ base/process/process_posix.cc
@@ -8,6 +8,9 @@
 #include <stdint.h>
 #include <sys/resource.h>
 #include <sys/wait.h>
+#if defined(OS_POSIX)
+#include <signal.h>
+#endif
 
 #include "base/files/scoped_file.h"
 #include "base/logging.h"
@@ -16,7 +19,7 @@
 #include "base/third_party/dynamic_annotations/dynamic_annotations.h"
 #include "build/build_config.h"
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 #include <sys/event.h>
 #endif
 
@@ -86,7 +89,7 @@ bool WaitpidWithTimeout(base::ProcessHan
   return ret_pid > 0;
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 // Using kqueue on Mac so that we can wait on non-child processes.
 // We can't use kqueues on child processes because we need to reap
 // our own children using wait.
@@ -183,7 +186,7 @@ bool WaitForExitWithTimeoutImpl(base::Pr
   base::ProcessHandle parent_pid = base::GetParentProcessId(handle);
   base::ProcessHandle our_pid = base::GetCurrentProcessHandle();
   if (parent_pid != our_pid) {
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
     // On Mac we can wait on non child processes.
     return WaitForSingleNonChildProcess(handle, timeout);
 #else
