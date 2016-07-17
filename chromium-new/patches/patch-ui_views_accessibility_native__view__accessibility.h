$NetBSD$

--- ui/views/accessibility/native_view_accessibility.h.orig	2016-06-24 01:02:53.000000000 +0000
+++ ui/views/accessibility/native_view_accessibility.h
@@ -22,7 +22,7 @@
 #define PLATFORM_HAS_NATIVE_VIEW_ACCESSIBILITY_IMPL 1
 #endif
 
-#if defined(OS_LINUX) && defined(USE_X11) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_X11) && !defined(OS_CHROMEOS)
 #define PLATFORM_HAS_NATIVE_VIEW_ACCESSIBILITY_IMPL 1
 #endif
 
