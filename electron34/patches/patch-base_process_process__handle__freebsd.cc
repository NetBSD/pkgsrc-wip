$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/process/process_handle_freebsd.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ base/process/process_handle_freebsd.cc
@@ -3,6 +3,7 @@
 // found in the LICENSE file.
 
 #include "base/process/process_handle.h"
+#include "base/files/file_util.h"
 
 #include <limits.h>
 #include <stddef.h>
@@ -20,12 +21,15 @@ namespace base {
 
 ProcessId GetParentProcessId(ProcessHandle process) {
   struct kinfo_proc info;
-  size_t length;
+  size_t length = sizeof(struct kinfo_proc);
   int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, process };
 
   if (sysctl(mib, std::size(mib), &info, &length, NULL, 0) < 0)
     return -1;
 
+  if (length < sizeof(struct kinfo_proc))
+    return -1;
+
   return info.ki_ppid;
 }
 
