$NetBSD: patch-src_terminal.c,v 1.1 2013/03/05 01:07:05 khorben Exp $

Fixes build with Gtk+ 3

--- src/terminal.c.orig	2013-02-24 03:45:06.000000000 +0000
+++ src/terminal.c
@@ -26,6 +26,9 @@ char const _license[] =
 #include <libintl.h>
 #include <gtk/gtk.h>
 #include <gdk/gdkkeysyms.h>
+#if GTK_CHECK_VERSION(3, 0, 0)
+# include <gtk/gtkx.h>
+#endif
 #include <System.h>
 #include <Desktop.h>
 #include "terminal.h"
