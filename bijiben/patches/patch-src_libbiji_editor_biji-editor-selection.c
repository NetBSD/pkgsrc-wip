$NetBSD$

--- src/libbiji/editor/biji-editor-selection.c.orig	2014-10-18 21:26:34.000000000 +0000
+++ src/libbiji/editor/biji-editor-selection.c
@@ -23,8 +23,8 @@
 #include "biji-editor-selection.h"
 #include "biji-editor-utils.h"
  
-#include <webkit/webkit.h>
-#include <webkit/webkitdom.h>
+#include <webkit2/webkit2.h>
+#include <webkitdom/webkitdom.h>
 
 #include <string.h>
 #include <stdlib.h>
