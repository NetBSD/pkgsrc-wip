$NetBSD$

--- content/browser/devtools/protocol/color_picker.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ content/browser/devtools/protocol/color_picker.cc
@@ -151,7 +151,7 @@ void ColorPicker::UpdateCursor() {
   // magnified projection only with centered hotspot.
   // Mac Retina requires cursor to be > 120px in order to render smoothly.
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   const float kCursorSize = 63;
   const float kDiameter = 63;
   const float kHotspotOffset = 32;
