$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/renderer/theme_helper_mac.mm.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/renderer/theme_helper_mac.mm
@@ -7,16 +7,28 @@
 #include <Cocoa/Cocoa.h>
 
 #include "base/strings/sys_string_conversions.h"
+#include "electron/mas.h"
 
+#if !IS_MAS_BUILD()
 extern "C" {
 bool CGFontRenderingGetFontSmoothingDisabled(void);
 }
-
+#endif
 namespace content {
 
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
