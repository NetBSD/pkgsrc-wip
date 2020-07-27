$NetBSD$

--- ui/gfx/font_fallback_linux.cc.orig	2020-07-15 18:56:34.000000000 +0000
+++ ui/gfx/font_fallback_linux.cc
@@ -24,6 +24,10 @@
 #include "ui/gfx/linux/fontconfig_util.h"
 #include "ui/gfx/platform_font.h"
 
+#if defined(OS_BSD)
+#include <unistd.h>
+#endif
+
 namespace gfx {
 
 namespace {
