$NetBSD$

--- ui/views/style/platform_style.cc.orig	2017-02-02 02:03:13.000000000 +0000
+++ ui/views/style/platform_style.cc
@@ -17,7 +17,7 @@
 #include "ui/views/controls/focusable_border.h"
 #include "ui/views/controls/scrollbar/scroll_bar_views.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #define DESKTOP_LINUX
 #endif
 
