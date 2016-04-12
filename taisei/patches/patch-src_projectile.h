$NetBSD$

Fix build with gcc-5.

--- src/projectile.h.orig	2012-08-10 14:42:54.000000000 +0000
+++ src/projectile.h
@@ -49,7 +49,7 @@ typedef struct Projectile {
 } Projectile;
 
 Color *rgba(float r, float g, float b, float a);
-inline Color *rgb(float r, float g, float b);
+Color *rgb(float r, float g, float b);
 
 #define create_particle3c(n,p,c,d,r,a1,a2,a3) create_particle4c(n,p,c,d,r,a1,a2,a3,0)
 #define create_particle2c(n,p,c,d,r,a1,a2) create_particle4c(n,p,c,d,r,a1,a2,0,0)
