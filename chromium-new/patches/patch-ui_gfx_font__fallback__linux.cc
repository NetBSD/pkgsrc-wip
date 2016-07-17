$NetBSD$

--- ui/gfx/font_fallback_linux.cc.orig	2016-06-24 01:02:53.000000000 +0000
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
