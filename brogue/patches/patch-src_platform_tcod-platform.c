$NetBSD: patch-src_platform_tcod-platform.c,v 1.1 2015/08/18 20:24:52 yhardy Exp $

Find the fonts in the BROGUE_SHARE diretory

--- src/platform/tcod-platform.c.orig	2014-07-03 19:19:10.000000000 +0000
+++ src/platform/tcod-platform.c
@@ -27,7 +27,7 @@ static int desktop_width, desktop_height
 
 static void loadFont(int detectSize)
 {
-	char font[60];
+	char font[256];
 	
 	if (detectSize) {
 		int fontWidths[13] = {112, 128, 144, 160, 176, 192, 208, 224, 240, 256, 272, 288, 304}; // widths of the font graphics (divide by 16 to get individual character width)
@@ -51,7 +51,7 @@ static void loadFont(int detectSize)
 
 	}
 
-	sprintf(font, "fonts/font-%i.png", brogueFontSize);
+	sprintf(font, BROGUE_SHARE "fonts/font-%i.png", brogueFontSize);
 	
 	TCOD_console_set_custom_font(font, (TCOD_FONT_TYPE_GREYSCALE | TCOD_FONT_LAYOUT_ASCII_INROW), 0, 0);
 	TCOD_console_init_root(COLS, ROWS, "Brogue", false, renderer);
