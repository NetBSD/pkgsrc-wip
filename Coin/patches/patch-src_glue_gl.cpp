$NetBSD$

Work around EGL detection failure needing COIN_EGL=1 set.
https://github.com/FreeCAD/FreeCAD/issues/22695

--- src/glue/gl.cpp.orig	2026-04-27 07:21:23.559091032 +0000
+++ src/glue/gl.cpp
@@ -2215,10 +2215,12 @@ static void check_egl()
     }
 
     // Detect EGL
-    EGLContext eglContext = eglGetCurrentContext();
-    if (eglContext != EGL_NO_CONTEXT) {
-      COIN_USE_EGL = 1;
-      return;
+    EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
+    if (display != nullptr) {
+      if (eglInitialize(display, nullptr, nullptr)) {
+        COIN_USE_EGL = 1;
+        return;
+      }
     }
 
     // Detect GLX
