$NetBSD$

--- src/libbiji/editor/biji-editor-selection.h.orig	2014-10-18 21:26:34.000000000 +0000
+++ src/libbiji/editor/biji-editor-selection.h
@@ -20,7 +20,7 @@
 #define E_EDITOR_SELECTION_H
 
 #include <glib-object.h>
-#include <webkit/webkit.h>
+#include <webkit2/webkit2.h>
 
 /* Standard GObject macros */
 #define E_TYPE_EDITOR_SELECTION \
@@ -204,4 +204,4 @@ void			e_editor_selection_wrap_lines	(EE
 
 G_END_DECLS
 
-#endif /* E_EDITOR_SELECTION_H */
\ No newline at end of file
+#endif /* E_EDITOR_SELECTION_H */
