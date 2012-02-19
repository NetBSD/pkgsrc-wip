$NetBSD: patch-src_switchpanel.c,v 1.1.1.1 2012/02/19 19:25:49 khorben Exp $

--- src/switchpanel.c.orig	2012-02-14 19:36:01.000000000 +0000
+++ src/switchpanel.c
@@ -36,6 +36,8 @@
 extern Atom _XA_WM_IGNORE_FOCUS_EVENTS;
 
 #ifdef SHAPE
+#include <X11/Xlib.h>
+#include <X11/Xutil.h>
 #include <X11/extensions/shape.h>
 
 extern Bool wShapeSupported;
