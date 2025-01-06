$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/enterprise_util_mac.mm.orig	2024-10-18 12:33:59.758278800 +0000
+++ base/enterprise_util_mac.mm
@@ -116,6 +116,14 @@ DeviceUserDomainJoinState AreDeviceAndUs
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
@@ -219,5 +227,6 @@ DeviceUserDomainJoinState AreDeviceAndUs
 
   return state;
 }
+#endif
 
 }  // namespace base
