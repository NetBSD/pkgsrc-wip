$NetBSD: patch-libcaja-private_caja-undostack-manager.c,v 1.3 2015/04/09 03:07:39 krytarowski Exp $

* stdlib.h is required for malloc(3)

--- libcaja-private/caja-undostack-manager.c.orig	2014-02-16 22:01:21.000000000 +0000
+++ libcaja-private/caja-undostack-manager.c
@@ -33,6 +33,7 @@
 #include <glib/gi18n.h>
 #include <locale.h>
 #include <gdk/gdk.h>
+#include <stdlib.h>
 
 #include <src/glibcompat.h> /* for g_list_free_full */
 
