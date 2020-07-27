$NetBSD$

--- third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc.orig	2020-07-15 18:56:03.000000000 +0000
+++ third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc
@@ -137,7 +137,7 @@ bool ScrollbarThemeAura::SupportsDragSna
 // Disable snapback on desktop Linux to better integrate with the desktop
 // behavior. Typically, Linux apps do not implement scrollbar snapback (this
 // is true for at least GTK and QT apps).
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   return false;
 #else
   return true;
@@ -301,7 +301,7 @@ ScrollbarPart ScrollbarThemeAura::PartsT
 
 bool ScrollbarThemeAura::ShouldCenterOnThumb(const Scrollbar& scrollbar,
                                              const WebMouseEvent& event) {
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (event.button == WebPointerProperties::Button::kMiddle)
     return true;
 #endif
