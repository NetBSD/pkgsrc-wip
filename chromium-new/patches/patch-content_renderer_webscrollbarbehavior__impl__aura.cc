$NetBSD$

--- content/renderer/webscrollbarbehavior_impl_aura.cc.orig	2017-02-02 02:02:54.000000000 +0000
+++ content/renderer/webscrollbarbehavior_impl_aura.cc
@@ -14,7 +14,7 @@ bool WebScrollbarBehaviorImpl::shouldCen
       blink::WebPointerProperties::Button mouseButton,
       bool shiftKeyPressed,
       bool altKeyPressed) {
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (mouseButton == blink::WebPointerProperties::Button::Middle)
     return true;
 #endif
@@ -29,7 +29,7 @@ bool WebScrollbarBehaviorImpl::shouldSna
 // Disable snapback on desktop Linux to better integrate with the desktop
 // behavior.  Typically, Linux apps do not implement scrollbar snapback (this is
 // true for at least GTK and QT apps).
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   return false;
 #endif
 
