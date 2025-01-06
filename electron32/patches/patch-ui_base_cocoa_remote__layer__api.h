$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/base/cocoa/remote_layer_api.h.orig	2024-10-18 12:35:12.352418700 +0000
+++ ui/base/cocoa/remote_layer_api.h
@@ -17,6 +17,7 @@
 
 #if BUILDFLAG(IS_MAC)
 
+#if !IS_MAS_BUILD()
 // The CGSConnectionID is used to create the CAContext in the process that is
 // going to share the CALayers that it is rendering to another process to
 // display.
@@ -68,6 +69,8 @@ extern NSString* const kCAContextIgnores
 
 #endif  // __OBJC__
 
+#endif // MAS_BUILD
+
 namespace ui {
 
 // This function will check if all of the interfaces listed above are supported
