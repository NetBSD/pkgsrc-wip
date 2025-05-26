$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/process/process_info_mac.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ base/process/process_info_mac.cc
@@ -4,19 +4,27 @@
 
 #include "base/process/process_info.h"
 
+#include "electron/mas.h"
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 
+#if !IS_MAS_BUILD()
 extern "C" {
 pid_t responsibility_get_pid_responsible_for_pid(pid_t);
 }
+#endif
 
 namespace base {
 
 bool IsProcessSelfResponsible() {
+#if !IS_MAS_BUILD()
   const pid_t pid = getpid();
   return responsibility_get_pid_responsible_for_pid(pid) == pid;
+#else
+  return true;
+#endif
 }
 
 }  // namespace base
