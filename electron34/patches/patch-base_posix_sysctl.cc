$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/posix/sysctl.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ base/posix/sysctl.cc
@@ -4,6 +4,7 @@
 
 #include "base/posix/sysctl.h"
 
+#include <sys/types.h>
 #include <sys/sysctl.h>
 
 #include <initializer_list>
@@ -16,17 +17,17 @@
 #include "build/build_config.h"
 
 namespace {
-
+// NetBSD has sysctl_func macro in sys/sysctl.h, workaround: sysctl_func -> sysctl_func2
 std::optional<std::string> StringSysctlImpl(
-    base::FunctionRef<int(char* /*out*/, size_t* /*out_len*/)> sysctl_func) {
+    base::FunctionRef<int(char* /*out*/, size_t* /*out_len*/)> sysctl_func2) {
   size_t buf_len;
-  int result = sysctl_func(nullptr, &buf_len);
+  int result = sysctl_func2(nullptr, &buf_len);
   if (result < 0 || buf_len < 1) {
     return std::nullopt;
   }
 
   std::string value(buf_len - 1, '\0');
-  result = sysctl_func(&value[0], &buf_len);
+  result = sysctl_func2(&value[0], &buf_len);
   if (result < 0) {
     return std::nullopt;
   }
