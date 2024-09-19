$NetBSD: patch-nautilus-gksu_libnautilus-gksu.c,v 1.1 2013/01/21 00:38:46 othyro Exp $

Only glib.h can be included directly.

--- nautilus-gksu/libnautilus-gksu.c.orig	2009-02-23 02:03:37.000000000 +0000
+++ nautilus-gksu/libnautilus-gksu.c
@@ -5,7 +5,7 @@
 #include <string.h>
 #include <pthread.h>
 
-#include <glib/gkeyfile.h>
+#include <glib.h>
 #include <gtk/gtk.h>
 #include <gio/gio.h>
 #include <libnautilus-extension/nautilus-extension-types.h>
