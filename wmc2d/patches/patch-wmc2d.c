$NetBSD: patch-wmc2d.c,v 1.1 2012/11/15 21:20:04 othyro Exp $

Fixes "array has subscript type char" warning.

--- wmc2d.c.orig	2011-04-29 15:14:12.000000000 +0000
+++ wmc2d.c
@@ -613,7 +613,7 @@ void DrawString(const char *s, int x, in
 
     dx = x;
     while (*s) {
-	c = toupper(*s);
+	c = toupper((int)*s);
 	if (c == ' ') {
 	    xcb_copy_area(Connection, Image, Pixmap, NormalGC, 0, 65, dx, y, 6,
 		7);
