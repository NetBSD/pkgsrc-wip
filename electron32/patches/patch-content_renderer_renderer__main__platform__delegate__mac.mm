$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/renderer/renderer_main_platform_delegate_mac.mm.orig	2024-10-18 12:34:14.626274800 +0000
+++ content/renderer/renderer_main_platform_delegate_mac.mm
@@ -10,9 +10,11 @@
 #include "sandbox/mac/seatbelt.h"
 #include "sandbox/mac/system_services.h"
 
+#if !IS_MAS_BUILD()
 extern "C" {
 CGError CGSSetDenyWindowServerConnections(bool);
 }
+#endif
 
 namespace content {
 
@@ -22,6 +24,7 @@ namespace {
 // verifies there are no existing open connections), and then indicates that
 // Chrome should continue execution without access to launchservicesd.
 void DisableSystemServices() {
+#if !IS_MAS_BUILD()
   // Tell the WindowServer that we don't want to make any future connections.
   // This will return Success as long as there are no open connections, which
   // is what we want.
@@ -30,6 +33,7 @@ void DisableSystemServices() {
 
   sandbox::DisableLaunchServices();
   sandbox::DisableCoreServicesCheckFix();
+#endif
 }
 
 }  // namespace
