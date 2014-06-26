$NetBSD: patch-src_download.c,v 1.1 2014/06/26 15:44:09 khorben Exp $

Fix building with Gtk+ 3.0

--- src/download.c.orig	2012-10-06 01:34:55.000000000 +0000
+++ src/download.c
@@ -30,6 +30,9 @@
 #include <locale.h>
 #include <libintl.h>
 #include <gtk/gtk.h>
+#if GTK_CHECK_VERSION(3, 0, 0)
+# include <gtk/gtkx.h>
+#endif
 #include <System.h>
 #ifdef WITH_WEBKIT
 # include <webkit/webkit.h>
