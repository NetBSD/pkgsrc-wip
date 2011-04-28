$NetBSD: patch-app_gfx_gl_gl__context__egl.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- app/gfx/gl/gl_context_egl.cc.orig	2011-04-13 08:01:07.000000000 +0000
+++ app/gfx/gl/gl_context_egl.cc
@@ -4,7 +4,7 @@
 
 #include <EGL/egl.h>
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 extern "C" {
 #include <X11/Xlib.h>
 }
