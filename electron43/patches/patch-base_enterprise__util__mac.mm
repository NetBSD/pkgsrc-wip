$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/enterprise_util_mac.mm.orig	2025-02-24 19:59:26.000000000 +0000
+++ base/enterprise_util_mac.mm
@@ -16,6 +16,7 @@
 #include "base/strings/string_split.h"
 #include "base/strings/string_util.h"
 #include "base/strings/sys_string_conversions.h"
+#include "electron/mas.h"
 
 namespace base {
 
@@ -116,6 +117,14 @@ DeviceUserDomainJoinState AreDeviceAndUs
     DeviceUserDomainJoinState state{.device_joined = false,
                                     .user_joined = false};
 
+#if IS_MAS_BUILD()
+    return state;
+  }();
+
+  return state;
+}
+#else
+
     @autoreleasepool {
       ODSession* session = [ODSession defaultSession];
       if (session == nil) {
@@ -219,5 +228,6 @@ DeviceUserDomainJoinState AreDeviceAndUs
 
   return state;
 }
+#endif
 
 }  // namespace base
