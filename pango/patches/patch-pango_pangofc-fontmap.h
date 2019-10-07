$NetBSD$

Search Harfbuzz headerfile in "harfbuzz" subdirectory.

--- pango/pangofc-fontmap.h.orig	2019-09-03 12:11:42.000000000 +0000
+++ pango/pangofc-fontmap.h
@@ -26,7 +26,7 @@
 #include <fontconfig/fontconfig.h>
 #include <pango/pangofc-decoder.h>
 #include <pango/pangofc-font.h>
-#include <hb.h>
+#include <harfbuzz/hb.h>
 
 G_BEGIN_DECLS
 
