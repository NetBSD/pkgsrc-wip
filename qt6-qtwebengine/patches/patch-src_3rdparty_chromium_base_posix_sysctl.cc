$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/posix/sysctl.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/base/posix/sysctl.cc
@@ -4,6 +4,7 @@
 
 #include "base/posix/sysctl.h"
 
+#include <sys/types.h>
 #include <sys/sysctl.h>
 
 #include <initializer_list>
@@ -16,17 +17,17 @@
 #include "third_party/abseil-cpp/absl/types/optional.h"
 
 namespace {
-
+// NetBSD has sysctl_func macro in sys/sysctl.h, workaround: sysctl_func -> sysctl_func2
 absl::optional<std::string> StringSysctlImpl(
-    base::FunctionRef<int(char* /*out*/, size_t* /*out_len*/)> sysctl_func) {
+    base::FunctionRef<int(char* /*out*/, size_t* /*out_len*/)> sysctl_func2) {
   size_t buf_len;
-  int result = sysctl_func(nullptr, &buf_len);
+  int result = sysctl_func2(nullptr, &buf_len);
   if (result < 0 || buf_len < 1) {
     return absl::nullopt;
   }
 
   std::string value(buf_len - 1, '\0');
-  result = sysctl_func(&value[0], &buf_len);
+  result = sysctl_func2(&value[0], &buf_len);
   if (result < 0) {
     return absl::nullopt;
   }
