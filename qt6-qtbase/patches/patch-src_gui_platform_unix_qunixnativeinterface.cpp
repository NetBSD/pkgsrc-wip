$NetBSD$

enable glx when xcb_glx is available not just on linux

--- src/gui/platform/unix/qunixnativeinterface.cpp.orig	2020-12-30 22:09:23.903201486 +0000
+++ src/gui/platform/unix/qunixnativeinterface.cpp
@@ -55,7 +55,7 @@ using namespace QNativeInterface::Privat
 
 #ifndef QT_NO_OPENGL
 
-#if defined(Q_OS_LINUX)
+#if QT_CONFIG(xcb_glx)
 
 /*!
     \class QNativeInterface::QGLXContext
