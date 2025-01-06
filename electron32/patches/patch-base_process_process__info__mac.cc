$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/process/process_info_mac.cc.orig	2024-10-18 12:33:59.794258600 +0000
+++ base/process/process_info_mac.cc
@@ -8,15 +8,21 @@
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
