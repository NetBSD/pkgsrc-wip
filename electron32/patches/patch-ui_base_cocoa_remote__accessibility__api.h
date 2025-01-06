$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/base/cocoa/remote_accessibility_api.h.orig	2024-10-18 12:35:12.352418700 +0000
+++ ui/base/cocoa/remote_accessibility_api.h
@@ -13,6 +13,8 @@
 
 // NSAccessibilityRemoteUIElement is a private class in AppKit.
 
+#if !IS_MAS_BUILD()
+
 @interface NSAccessibilityRemoteUIElement : NSObject
 + (void)setRemoteUIApp:(BOOL)flag;
 + (BOOL)isRemoteUIApp;
@@ -38,4 +40,6 @@ class COMPONENT_EXPORT(UI_BASE) RemoteAc
 
 }  // namespace ui
 
+#endif  // MAS_BUILD
+
 #endif  // UI_BASE_COCOA_REMOTE_ACCESSIBILITY_API_H_
