$NetBSD$

Include additional headerfiles.

--- images/fl_png.cxx.orig	2012-03-23 05:49:17.000000000 +0000
+++ images/fl_png.cxx
@@ -40,7 +40,8 @@ extern "C"
 #endif
 }
 
-# include <stdlib.h>
+#include <stdlib.h>
+#include <string.h>
 
 static png_bytep cur_datas;
 
