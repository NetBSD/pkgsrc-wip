$NetBSD: patch-src_swft_swft__import__ttf.cpp,v 1.1 2014/04/12 17:54:47 thomasklausner Exp $

Fix build with freetype-2.5.1.

--- src/swft/swft_import_ttf.cpp.orig	2013-10-30 17:33:35.000000000 +0000
+++ src/swft/swft_import_ttf.cpp
@@ -14,7 +14,7 @@
 #include FT_OUTLINE_H
 #include "SWFShapeMaker.h"
 
-#include <freetype/tttables.h>
+#include FT_TRUETYPE_TABLES_H
 
 using namespace SWF;
 
