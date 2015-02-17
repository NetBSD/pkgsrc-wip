$NetBSD: patch-lib_pdf_BitmapOutputDev.cc,v 1.1 2015/02/17 10:36:29 fhajny Exp $

Remove ambiguity, fix build on at least SunOS.

--- lib/pdf/BitmapOutputDev.cc.orig	2011-01-02 03:30:29.000000000 +0000
+++ lib/pdf/BitmapOutputDev.cc
@@ -1635,10 +1635,10 @@ static void getGlyphBbox(GfxState*state,
     SplashCoord*matrix = font->getMatrix();
 
     if(font && font->getGlyph(code, xFrac, yFrac, &glyph)) {
-        x1 = floor(x0-glyph.x);
-        y1 = floor(y0-glyph.y);
-        x2 = ceil(x0-glyph.x+glyph.w);
-        y2 = ceil(y0-glyph.y+glyph.h);
+        x1 = floor((double)x0-glyph.x);
+        y1 = floor((double)y0-glyph.y);
+        x2 = ceil((double)x0-glyph.x+glyph.w);
+        y2 = ceil((double)y0-glyph.y+glyph.h);
         if (glyph.freeData) {
           gfree(glyph.data);
         }
