$NetBSD: patch-src_lib_engines_common_evas__font__load.c,v 1.1 2014/05/19 17:41:22 rsmarples Exp $

--- src/lib/engines/common/evas_font_load.c.orig	2014-05-19 17:22:38.000000000 +0000
+++ src/lib/engines/common/evas_font_load.c
@@ -5,7 +5,7 @@
 
 #include "evas_font_private.h" /* for Frame-Queuing support */
 #include "evas_font_ot.h"
-#include <freetype/tttables.h> /* Freetype2 OS/2 font table. */
+#include FT_TRUETYPE_TABLES_H  /* Freeetype2 True Type table. */
 
 #ifdef EVAS_CSERVE2
 # include "../../cserve2/evas_cs2_private.h"
