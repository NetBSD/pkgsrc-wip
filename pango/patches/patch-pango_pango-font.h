$NetBSD$

Search Harfbuzz headerfile in "harfbuzz" subdirectory.

--- pango/pango-font.h.orig	2019-09-03 12:11:42.000000000 +0000
+++ pango/pango-font.h
@@ -26,7 +26,7 @@
 #include <pango/pango-types.h>
 
 #include <glib-object.h>
-#include <hb.h>
+#include <harfbuzz/hb.h>
 
 G_BEGIN_DECLS
 
