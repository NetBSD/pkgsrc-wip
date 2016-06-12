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
@@ -149,19 +149,19 @@ biji_webkit_editor_apply_format (BijiWeb
 void
 biji_webkit_editor_cut (BijiWebkitEditor *self)
 {
-  webkit_web_view_cut_clipboard (WEBKIT_WEB_VIEW (self));
+  webkit_web_view_execute_editing_command (WEBKIT_WEB_VIEW (embed), WEBKIT_EDITING_COMMAND_CUT);
 }
 
 void
 biji_webkit_editor_copy (BijiWebkitEditor *self)
 {
-  webkit_web_view_copy_clipboard (WEBKIT_WEB_VIEW (self));
+  webkit_web_view_execute_editing_command (WEBKIT_WEB_VIEW (embed), WEBKIT_EDITING_COMMAND_COPY);
 }
 
 void
 biji_webkit_editor_paste (BijiWebkitEditor *self)
 {
-  webkit_web_view_paste_clipboard (WEBKIT_WEB_VIEW (self));
+  webkit_web_view_execute_editing_command (WEBKIT_WEB_VIEW (embed), WEBKIT_EDITING_COMMAND_PASTE);
 }
 
 static void
