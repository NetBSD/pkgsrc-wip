$NetBSD$

Fix absolute value for floating point values.

--- src/game_menu.c.orig	2013-09-07 22:14:32.000000000 +0000
+++ src/game_menu.c
@@ -1992,9 +1992,9 @@ void JE_updateNavScreen( void )
 	navX = navX + (newNavX - navX) / 2.0f;
 	navY = navY + (newNavY - navY) / 2.0f;
 
-	if (abs(newNavX - navX) < 1)
+	if (fabs(newNavX - navX) < 1)
 		navX = newNavX;
-	if (abs(newNavY - navY) < 1)
+	if (fabs(newNavY - navY) < 1)
 		navY = newNavY;
 
 	fill_rectangle_xy(VGAScreen, 314, 0, 319, 199, 230);
