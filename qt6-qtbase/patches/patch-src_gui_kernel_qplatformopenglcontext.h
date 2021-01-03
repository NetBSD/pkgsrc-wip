$NetBSD$

enable glx when xcb-glx is found not just on linux

--- src/gui/kernel/qplatformopenglcontext.h.orig	2020-12-04 10:14:27.000000000 +0000
+++ src/gui/kernel/qplatformopenglcontext.h
@@ -127,7 +127,7 @@ struct Q_GUI_EXPORT QWindowsGLIntegratio
 };
 #endif
 
-#if defined(Q_OS_LINUX)
+#if QT_CONFIG(xcb_glx)
 struct Q_GUI_EXPORT QGLXIntegration
 {
     QT_DECLARE_NATIVE_INTERFACE(QGLXIntegration)
