$NetBSD$

--- src/libbiji/editor/biji-editor-utils.h.orig	2014-10-18 21:26:34.000000000 +0000
+++ src/libbiji/editor/biji-editor-utils.h
@@ -19,7 +19,7 @@
 #ifndef E_EDITOR_UTILS_H
 #define E_EDITOR_UTILS_H
 
-#include <webkit/webkitdom.h>
+#include <webkitdom/webkitdom.h>
 
 WebKitDOMElement * e_editor_dom_node_find_parent_element (WebKitDOMNode *node, const gchar *tagname);
 
