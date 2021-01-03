$NetBSD$

enable glx when xcb-glx is found not just on linux

--- src/gui/kernel/qopenglcontext_platform.h.orig	2020-12-04 10:14:27.000000000 +0000
+++ src/gui/kernel/qopenglcontext_platform.h
@@ -50,7 +50,7 @@
 Q_FORWARD_DECLARE_OBJC_CLASS(NSOpenGLContext);
 #endif
 
-#if defined(Q_OS_LINUX)
+#if QT_CONFIG(xcb_glx)
 struct __GLXcontextRec; typedef struct __GLXcontextRec *GLXContext;
 #endif
 #if QT_CONFIG(egl)
@@ -85,7 +85,7 @@ struct Q_GUI_EXPORT QWGLContext
 };
 #endif
 
-#if defined(Q_OS_LINUX) || defined(Q_CLANG_QDOC)
+#if QT_CONFIG(xcb_glx) || defined(Q_CLANG_QDOC)
 struct Q_GUI_EXPORT QGLXContext
 {
     QT_DECLARE_NATIVE_INTERFACE(QGLXContext)
