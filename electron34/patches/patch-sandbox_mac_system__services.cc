$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- sandbox/mac/system_services.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ sandbox/mac/system_services.cc
@@ -8,7 +8,9 @@
 #include <CoreFoundation/CoreFoundation.h>
 
 #include "base/apple/osstatus_logging.h"
+#include "electron/mas.h"
 
+#if !IS_MAS_BUILD()
 extern "C" {
 OSStatus SetApplicationIsDaemon(Boolean isDaemon);
 void _LSSetApplicationLaunchServicesServerConnectionStatus(
@@ -19,10 +21,12 @@ void _LSSetApplicationLaunchServicesServ
 // https://github.com/WebKit/WebKit/blob/24aaedc770d192d03a07ba4a71727274aaa8fc07/Source/WebKit/WebProcess/cocoa/WebProcessCocoa.mm#L840
 void _CSCheckFixDisable();
 }  // extern "C"
+#endif
 
 namespace sandbox {
 
 void DisableLaunchServices() {
+  #if !IS_MAS_BUILD()
   // Allow the process to continue without a LaunchServices ASN. The
   // INIT_Process function in HIServices will abort if it cannot connect to
   // launchservicesd to get an ASN. By setting this flag, HIServices skips
@@ -36,10 +40,13 @@ void DisableLaunchServices() {
       0, ^bool(CFDictionaryRef options) {
         return false;
       });
+  #endif
 }
 
 void DisableCoreServicesCheckFix() {
+#if !IS_MAS_BUILD()
   _CSCheckFixDisable();
+#endif
 }
 
 }  // namespace sandbox
