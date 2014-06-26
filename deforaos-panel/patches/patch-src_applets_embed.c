$NetBSD: patch-src_applets_embed.c,v 1.1 2014/06/26 12:02:20 khorben Exp $

Build fix for Gtk+ 3.0

--- src/applets/embed.c.orig	2013-04-13 20:30:34.000000000 +0000
+++ src/applets/embed.c
@@ -24,6 +24,9 @@
 #include <string.h>
 #include <System.h>
 #include <Desktop.h>
+#if GTK_CHECK_VERSION(3, 0, 0)
+# include <gtk/gtkx.h>
+#endif
 #include "Panel.h"
 
 
@@ -33,7 +36,11 @@
 typedef struct _EmbedWidget
 {
 	GtkWidget * socket;
+#if GTK_CHECK_VERSION(3, 0, 0)
+	unsigned long id;
+#else
 	GdkNativeWindow id;
+#endif
 } EmbedWidget;
 
 typedef struct _PanelApplet
