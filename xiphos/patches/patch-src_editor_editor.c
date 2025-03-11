$NetBSD$

Disable the study pad. It only compiles with webkitgtk 1.x

--- src/editor/editor.c.orig	2025-03-11 17:18:16.782287101 +0000
+++ src/editor/editor.c
@@ -23,7 +23,7 @@
 #include <config.h>
 #endif
 
-#ifdef USE_WEBKIT_EDITOR
+#ifndef USE_WEBKIT_EDITOR
 
 /* X keyboard #definitions, to handle shortcuts */
 /* we must define the categories of #definitions we need. */
