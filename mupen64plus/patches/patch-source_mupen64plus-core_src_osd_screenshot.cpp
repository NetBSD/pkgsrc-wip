$NetBSD: patch-source_mupen64plus-core_src_osd_screenshot.cpp,v 1.2 2013/07/06 23:00:14 othyro Exp $

Fixes "array subscript has type 'char'" warning.

--- source/mupen64plus-core/src/osd/screenshot.cpp.orig	2013-07-04 00:27:56.000000000 +0000
+++ source/mupen64plus-core/src/osd/screenshot.cpp
@@ -143,7 +143,7 @@ static char *GetNextScreenshotPath(void)
     // add the ROM name, convert to lowercase, convert spaces to underscores
     strcpy(ScreenshotFileName, ROM_PARAMS.headername);
     for (char *pch = ScreenshotFileName; *pch != '\0'; pch++)
-        *pch = (*pch == ' ') ? '_' : tolower(*pch);
+        *pch = (*pch == ' ') ? '_' : tolower((unsigned char)*pch);
     strcat(ScreenshotFileName, "-###.png");
     
     // add the base path to the screenshot file name
