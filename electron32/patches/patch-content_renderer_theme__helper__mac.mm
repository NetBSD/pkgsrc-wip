$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/renderer/theme_helper_mac.mm.orig	2024-10-18 12:34:14.630272600 +0000
+++ content/renderer/theme_helper_mac.mm
@@ -8,10 +8,11 @@
 
 #include "base/strings/sys_string_conversions.h"
 
+#if !IS_MAS_BUILD()
 extern "C" {
 bool CGFontRenderingGetFontSmoothingDisabled(void);
 }
-
+#endif
 namespace content {
 
 void SystemColorsDidChange(int aqua_color_variant) {
@@ -24,8 +25,18 @@ void SystemColorsDidChange(int aqua_colo
 }
 
 bool IsSubpixelAntialiasingAvailable() {
+#if !IS_MAS_BUILD()
   // See https://trac.webkit.org/changeset/239306/webkit for more info.
   return !CGFontRenderingGetFontSmoothingDisabled();
+#else
+  NSUserDefaults* defaults = [NSUserDefaults standardUserDefaults];
+  NSString *default_key = @"CGFontRenderingGetFontSmoothingDisabled";
+  // Check that key exists since boolForKey defaults to NO when the
+  // key is missing and this key in fact defaults to YES;
+  if ([defaults objectForKey:default_key] == nil)
+    return false;
+  return ![defaults boolForKey:default_key];
+#endif
 }
 
 }  // namespace content
