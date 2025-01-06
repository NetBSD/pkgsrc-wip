$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/ozone/public/ozone_platform.h.orig	2024-10-18 12:35:12.776249600 +0000
+++ ui/ozone/public/ozone_platform.h
@@ -128,6 +128,10 @@ class COMPONENT_EXPORT(OZONE) OzonePlatf
     // Linux only: determines if Skia can fall back to the X11 output device.
     bool skia_can_fall_back_to_x11 = false;
 
+    // Linux only: determines is Electron can call selected X11 functions while
+    // it migrates to pure ozone abstractions.
+    bool electron_can_call_x11 = false;
+
     // Wayland only: determines whether windows which are not top level ones
     // should be given parents explicitly.
     bool set_parent_for_non_top_level_windows = false;
