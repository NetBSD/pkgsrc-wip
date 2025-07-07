$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/style/platform_style.h.orig	2025-06-30 06:54:11.000000000 +0000
+++ ui/views/style/platform_style.h
@@ -84,7 +84,7 @@ class VIEWS_EXPORT PlatformStyle {
   // Default setting at bubble creation time for whether arrow will be adjusted
   // for bubbles going off-screen to bring more bubble area into view. Linux
   // clips bubble windows that extend outside their parent window bounds.
-  static constexpr bool kAdjustBubbleIfOffscreen = !BUILDFLAG(IS_LINUX);
+  static constexpr bool kAdjustBubbleIfOffscreen = (!BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD));
 
   // Default focus behavior on the platform.
   static constexpr View::FocusBehavior kDefaultFocusBehavior =
