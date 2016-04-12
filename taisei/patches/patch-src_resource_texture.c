$NetBSD$

Fix build with gcc-5.

--- src/resource/texture.c.orig	2012-08-10 14:42:54.000000000 +0000
+++ src/resource/texture.c
@@ -25,7 +25,7 @@ Color *rgba(float r, float g, float b, f
 	return clr;
 }
 
-inline Color *rgb(float r, float g, float b) {
+Color *rgb(float r, float g, float b) {
 	return rgba(r, g, b, 1.0);
 }
 
