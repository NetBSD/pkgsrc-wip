$NetBSD$

--- src/libbiji/editor/biji-webkit-editor.c.orig	2014-10-26 21:06:45.000000000 +0000
+++ src/libbiji/editor/biji-webkit-editor.c
@@ -47,7 +47,7 @@ struct _BijiWebkitEditorPrivate
   gulong color_changed;
   gchar *font_color;
 
-  WebKitWebSettings *settings;
+  WebKitSettings *settings;
   EEditorSelection *sel;
   GObject *spell_check;
 };
