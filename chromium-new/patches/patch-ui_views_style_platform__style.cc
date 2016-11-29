$NetBSD$

--- ui/views/style/platform_style.cc.orig	2016-11-10 20:02:30.000000000 +0000
+++ ui/views/style/platform_style.cc
@@ -17,7 +17,7 @@
 #include "ui/views/controls/focusable_border.h"
 #include "ui/views/controls/scrollbar/native_scroll_bar.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #define DESKTOP_LINUX
 #endif
 
