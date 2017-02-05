$NetBSD$

--- source/Host/linux/HostInfoLinux.cpp.orig	2016-12-17 10:30:35.000000000 +0000
+++ source/Host/linux/HostInfoLinux.cpp
@@ -10,6 +10,8 @@
 #include "lldb/Host/linux/HostInfoLinux.h"
 #include "lldb/Core/Log.h"
 
+#include "llvm/Support/Threading.h"
+
 #include <limits.h>
 #include <stdio.h>
 #include <string.h>
@@ -44,7 +46,7 @@ uint32_t HostInfoLinux::GetMaxThreadName
 bool HostInfoLinux::GetOSVersion(uint32_t &major, uint32_t &minor,
                                  uint32_t &update) {
   static bool success = false;
-  static std::once_flag g_once_flag;
+  static llvm::once_flag g_once_flag;
   std::call_once(g_once_flag, []() {
 
     struct utsname un;
@@ -100,7 +102,7 @@ bool HostInfoLinux::GetOSKernelDescripti
 llvm::StringRef HostInfoLinux::GetDistributionId() {
   // Try to run 'lbs_release -i', and use that response
   // for the distribution id.
-  static std::once_flag g_once_flag;
+  static llvm::once_flag g_once_flag;
   std::call_once(g_once_flag, []() {
 
     Log *log(lldb_private::GetLogIfAllCategoriesSet(LIBLLDB_LOG_HOST));
