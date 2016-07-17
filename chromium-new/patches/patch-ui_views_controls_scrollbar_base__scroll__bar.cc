$NetBSD$

--- ui/views/controls/scrollbar/base_scroll_bar.cc.orig	2016-06-24 01:02:53.000000000 +0000
+++ ui/views/controls/scrollbar/base_scroll_bar.cc
@@ -24,7 +24,7 @@
 #include "ui/views/controls/scrollbar/base_scroll_bar_thumb.h"
 #include "ui/views/widget/widget.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/gfx/screen.h"
 #endif
 
