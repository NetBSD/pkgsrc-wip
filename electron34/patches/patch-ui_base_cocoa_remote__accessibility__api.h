$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/base/cocoa/remote_accessibility_api.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/base/cocoa/remote_accessibility_api.h
@@ -10,9 +10,12 @@
 #include <vector>
 
 #include "base/component_export.h"
+#include "electron/mas.h"
 
 // NSAccessibilityRemoteUIElement is a private class in AppKit.
 
+#if !IS_MAS_BUILD()
+
 @interface NSAccessibilityRemoteUIElement : NSObject
 + (void)setRemoteUIApp:(BOOL)flag;
 + (BOOL)isRemoteUIApp;
@@ -38,4 +41,6 @@ class COMPONENT_EXPORT(UI_BASE) RemoteAc
 
 }  // namespace ui
 
+#endif  // MAS_BUILD
+
 #endif  // UI_BASE_COCOA_REMOTE_ACCESSIBILITY_API_H_
