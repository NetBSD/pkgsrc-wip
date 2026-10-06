$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/base/cocoa/remote_layer_api.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/base/cocoa/remote_layer_api.h
@@ -9,6 +9,7 @@
 
 #include "base/component_export.h"
 #include "build/build_config.h"
+#include "electron/mas.h"
 
 #if defined(__OBJC__)
 #import <Foundation/Foundation.h>
@@ -17,6 +18,7 @@
 
 #if BUILDFLAG(IS_MAC)
 
+#if !IS_MAS_BUILD()
 // The CGSConnectionID is used to create the CAContext in the process that is
 // going to share the CALayers that it is rendering to another process to
 // display.
@@ -68,6 +70,8 @@ extern NSString* const kCAContextIgnores
 
 #endif  // __OBJC__
 
+#endif // MAS_BUILD
+
 namespace ui {
 
 // This function will check if all of the interfaces listed above are supported
