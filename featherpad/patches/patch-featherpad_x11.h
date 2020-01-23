$NetBSD$

Allow building on NetBSD

--- featherpad/x11.h.orig	2019-12-26 23:10:16.000000000 +0000
+++ featherpad/x11.h
@@ -20,7 +20,7 @@
 #ifndef X11_H
 #define X11_H
 
-#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_OPENBSD || defined Q_OS_HURD
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_OPENBSD || defined Q_OS_NETBSD || defined Q_OS_HURD
 #include <X11/Xlib.h>
 #endif
 
