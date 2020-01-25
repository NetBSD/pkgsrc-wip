$NetBSD$

Define NetBSD

--- feathernotes/x11.h.orig	2020-01-06 06:05:04.000000000 +0000
+++ feathernotes/x11.h
@@ -18,13 +18,13 @@
 #ifndef X11_H
 #define X11_H
 
-#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_OPENBSD || defined Q_OS_HURD
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_OPENBSD || defined Q_OS_NETBSD || defined Q_OS_HURD
 #include <X11/Xlib.h>
 #endif
 
 namespace FeatherNotes {
 
-#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_OPENBSD || defined Q_OS_HURD
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_OPENBSD || defined Q_OS_NETBSD || defined Q_OS_HURD
 long fromDesktop();
 #endif
 
