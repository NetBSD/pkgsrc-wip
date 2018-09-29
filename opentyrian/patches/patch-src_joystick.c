$NetBSD: patch-src_joystick.c,v 1.1 2015/08/19 19:36:56 yhardy Exp $

joystick_cfg_version is never used and triggers a warning (an error due to -Werror).
Fix toupper() usage on NetBSD (compiled with -Werror).

--- src/joystick.c.orig	2013-09-07 22:14:32.000000000 +0000
+++ src/joystick.c
@@ -42,7 +42,9 @@ bool ignore_joystick = false;
 int joysticks = 0;
 Joystick *joystick = NULL;
 
+/* not used
 static const char joystick_cfg_version = 1;
+*/
 static const int joystick_analog_max = 32767;
 
 // eliminates axis movement below the threshold
@@ -490,8 +492,8 @@ void code_to_assignment( Joystick_assign
 	else
 		--assignment->num;
 	
-	assignment->x_axis = (toupper(axis) == 'X');
-	assignment->negative_axis = (toupper(direction) == '-');
+	assignment->x_axis = (toupper((int)axis) == 'X');
+	assignment->negative_axis = (toupper((int)direction) == '-');
 }
 
 /* gives the short (6 or less characters) identifier for a joystick assignment
