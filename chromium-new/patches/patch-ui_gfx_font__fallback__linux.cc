$NetBSD$

--- ui/gfx/font_fallback_linux.cc.orig	2016-11-10 20:02:30.000000000 +0000
+++ ui/gfx/font_fallback_linux.cc
@@ -15,6 +15,10 @@
 #include "base/memory/ptr_util.h"
 #include "ui/gfx/font.h"
 
+#if defined(OS_BSD)
+#  include <unistd.h>
+#endif
+
 namespace gfx {
 
 namespace {
