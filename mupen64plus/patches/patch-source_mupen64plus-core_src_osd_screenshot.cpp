$NetBSD: patch-source_mupen64plus-core_src_osd_screenshot.cpp,v 1.1 2012/11/11 02:30:48 othyro Exp $

Fixes "array subscript has type 'char'" warning.

--- source/mupen64plus-core/src/osd/screenshot.cpp.orig	2012-03-10 18:31:29.000000000 +0000
+++ source/mupen64plus-core/src/osd/screenshot.cpp
@@ -173,7 +173,7 @@ static void GetBaseFilepath(char *filepa
         if (ch == ' ')
             *pch++ = '_';
         else
-            *pch++ = tolower(ch);
+            *pch++ = tolower((unsigned char)ch);
     } while (ch != 0);
 
     return;
