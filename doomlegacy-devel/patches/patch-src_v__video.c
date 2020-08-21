$NetBSD$

Support for DeePsea tall patches:
https://doomwiki.org/wiki/Picture_format#Tall_patches

This patch is for the software renderer.

--- src/v_video.c.orig	2020-07-07 09:01:36.000000000 +0000
+++ src/v_video.c
@@ -1422,12 +1422,24 @@ void V_DrawMappedPatch(int x, int y, pat
 
     for (col=0; col < wf; col += drawinfo.x_unitfrac)
     {
+        int  top = -1;  // [MB] 2020-08-21: Support for DeePsea tall patches
+
         column = (column_t *) ((byte *) patch + patch->columnofs[col >> FRACBITS]);
 
         while (column->topdelta != 0xff)
         {
+            // [MB] 2020-08-21: Support for DeePsea tall patches
+            if (column->topdelta <= top)
+            {
+                top += column->topdelta;
+            }
+            else
+            {
+                top = column->topdelta;
+            }
             source = (byte *) column + 3;
-            dest = desttop + (column->topdelta * drawinfo.ybytes);
+            dest = desttop + (top * drawinfo.ybytes);
+            //dest = desttop + (column->topdelta * drawinfo.ybytes);
             count = column->length * drawinfo.dupy;
 
             ofs = 0;
@@ -1511,12 +1523,24 @@ void V_DrawMappedPatch_Box(int x, int y,
 
     for ( ; col < wf; col += drawinfo.x_unitfrac)
     {
+        int  top = -1;  // [MB] 2020-08-21: Support for DeePsea tall patches
+
         column = (column_t *) ((byte *) patch + patch->columnofs[col >> FRACBITS]);
 
         while (column->topdelta != 0xff)
         {
+            // [MB] 2020-08-21: Support for DeePsea tall patches
+            if (column->topdelta <= top)
+            {
+                top += column->topdelta;
+            }
+            else
+            {
+                top = column->topdelta;
+            }
             source = (byte *) column + 3;
-            draw_y = draw_y1 + (column->topdelta * drawinfo.ybytes);
+            draw_y = draw_y1 + (top * drawinfo.ybytes);
+            //draw_y = draw_y1 + (column->topdelta * drawinfo.ybytes);
             count = column->length * drawinfo.dupy;
             column = (column_t *) ((byte *) column + column->length + 4);  // next column in patch
             ofs = 0;
@@ -1661,13 +1685,25 @@ void V_DrawScaledPatch(int x, int y, pat
 
     while( desttop < destend )
     {
+        int  top = -1;  // [MB] 2020-08-21: Support for DeePsea tall patches
+
         column = (column_t *) ((byte *) patch + patch->columnofs[col >> FRACBITS]);
         col += colfrac;
 
         while (column->topdelta != 0xff)
         {
+            // [MB] 2020-08-21: Support for DeePsea tall patches
+            if (column->topdelta <= top)
+            {
+                top += column->topdelta;
+            }
+            else
+            {
+                top = column->topdelta;
+            }
             source = (byte *) column + 3;
-            dest = desttop + (column->topdelta * drawinfo.ybytes);
+            dest = desttop + (top * drawinfo.ybytes);
+            //dest = desttop + (column->topdelta * drawinfo.ybytes);
             count = column->length * drawinfo.dupy;
 
             ofs = 0;
@@ -1794,12 +1830,24 @@ void V_DrawSmallScaledPatch(int x, int y
     // [WDJ] Use same loop for normal and skippixels, with some predefined inc
     for (  ; desttop < destend; desttop+=vid.bytepp)
     {
+        int  top = -1;  // [MB] 2020-08-21: Support for DeePsea tall patches
+
         column = (column_t *) ((byte *) patch + patch->columnofs[col >> FRACBITS]);
         col += colfrac_inc;
         while (column->topdelta != 0xff)
         {
+            // [MB] 2020-08-21: Support for DeePsea tall patches
+            if (column->topdelta <= top)
+            {
+                top += column->topdelta;
+            }
+            else
+            {
+                top = column->topdelta;
+            }
             source = (byte *) column + 3;
-            dest = desttop + (column->topdelta * dup_ybytes);
+            dest = desttop + (top * dup_ybytes);
+            //dest = desttop + (column->topdelta * dup_ybytes);
             count = (column->length * count_dupy) >> 1;  // dupy or dupy/2
             ofs = 0;
             while (count--)
@@ -1860,12 +1908,24 @@ void V_DrawTranslucentPatch(int x, int y
 
     for ( col=0; col < wf; col += drawinfo.x_unitfrac)
     {
+        int  top = -1;  // [MB] 2020-08-21: Support for DeePsea tall patches
+
         column = (column_t *) ((byte *) patch + patch->columnofs[col >> FRACBITS]);
 
         while (column->topdelta != 0xff)
         {
+            // [MB] 2020-08-21: Support for DeePsea tall patches
+            if (column->topdelta <= top)
+            {
+                top += column->topdelta;
+            }
+            else
+            {
+                top = column->topdelta;
+            }
             source = (byte *) column + 3;
-            dest = desttop + (column->topdelta * drawinfo.ybytes);
+            dest = desttop + (top * drawinfo.ybytes);
+            //dest = desttop + (column->topdelta * drawinfo.ybytes);
             count = column->length * drawinfo.dupy;
 
             ofs = 0;
@@ -1992,13 +2052,25 @@ void V_DrawPatch(int x, int y, int scrn,
 
     for ( col=0; col < wi; col++)
     {
+        int  top = -1;  // [MB] 2020-08-21: Support for DeePsea tall patches
+
         column = (column_t *) ((byte *) patch + patch->columnofs[col]);
 
         // step through the posts in a column
         while (column->topdelta != 0xff)
         {
+            // [MB] 2020-08-21: Support for DeePsea tall patches
+            if (column->topdelta <= top)
+            {
+                top += column->topdelta;
+            }
+            else
+            {
+                top = column->topdelta;
+            }
             source = (byte *) column + 3;
-            dest = desttop + (column->topdelta * vid.ybytes);
+            dest = desttop + (top * vid.ybytes);
+            //dest = desttop + (column->topdelta * vid.ybytes);
             count = column->length;
 
             while (count--)
