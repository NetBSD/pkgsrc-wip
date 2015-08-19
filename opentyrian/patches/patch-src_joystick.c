$NetBSD: patch-src_joystick.c,v 1.1 2015/08/19 19:36:56 yhardy Exp $

Fix toupper() usage on NetBSD (compiled with -Werror).

--- src/joystick.c.orig	2013-09-07 22:14:32.000000000 +0000
+++ src/joystick.c
@@ -490,8 +490,8 @@ void code_to_assignment( Joystick_assign
 	else
 		--assignment->num;
 	
-	assignment->x_axis = (toupper(axis) == 'X');
-	assignment->negative_axis = (toupper(direction) == '-');
+	assignment->x_axis = (toupper((int)axis) == 'X');
+	assignment->negative_axis = (toupper((int)direction) == '-');
 }
 
 /* gives the short (6 or less characters) identifier for a joystick assignment
