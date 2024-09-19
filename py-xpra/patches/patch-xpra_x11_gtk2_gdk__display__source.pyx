$NetBSD$

Fix path to glib2 headers.

--- xpra/x11/gtk2/gdk_display_source.pyx.orig	2015-12-10 03:35:49.000000000 +0000
+++ xpra/x11/gtk2/gdk_display_source.pyx
@@ -38,7 +38,7 @@ init_pygtk()
 ###################################
 # GObject
 ###################################
-cdef extern from "glib-2.0/glib-object.h":
+cdef extern from "glib-object.h":
     ctypedef struct cGObject "GObject":
         pass
 
