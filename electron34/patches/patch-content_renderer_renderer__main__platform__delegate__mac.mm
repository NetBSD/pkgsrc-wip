$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/renderer/renderer_main_platform_delegate_mac.mm.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/renderer/renderer_main_platform_delegate_mac.mm
@@ -7,12 +7,15 @@
 #import <Cocoa/Cocoa.h>
 
 #include "base/check_op.h"
+#include "electron/mas.h"
 #include "sandbox/mac/seatbelt.h"
 #include "sandbox/mac/system_services.h"
 
+#if !IS_MAS_BUILD()
 extern "C" {
 CGError CGSSetDenyWindowServerConnections(bool);
 }
+#endif
 
 namespace content {
 
@@ -22,6 +25,7 @@ namespace {
 // verifies there are no existing open connections), and then indicates that
 // Chrome should continue execution without access to launchservicesd.
 void DisableSystemServices() {
+#if !IS_MAS_BUILD()
   // Tell the WindowServer that we don't want to make any future connections.
   // This will return Success as long as there are no open connections, which
   // is what we want.
@@ -30,6 +34,7 @@ void DisableSystemServices() {
 
   sandbox::DisableLaunchServices();
   sandbox::DisableCoreServicesCheckFix();
+#endif
 }
 
 }  // namespace
