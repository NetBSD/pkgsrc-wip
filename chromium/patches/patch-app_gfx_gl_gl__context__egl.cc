$NetBSD: patch-app_gfx_gl_gl__context__egl.cc,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- app/gfx/gl/gl_context_egl.cc.orig	2011-05-24 08:01:03.000000000 +0000
+++ app/gfx/gl/gl_context_egl.cc
@@ -13,7 +13,7 @@
 // it brings in #defines that cause conflicts.
 #include "app/gfx/gl/gl_bindings.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 extern "C" {
 #include <X11/Xlib.h>
 }
