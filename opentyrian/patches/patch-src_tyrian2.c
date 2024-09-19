$NetBSD: patch-src_tyrian2.c,v 1.1 2015/08/19 19:36:56 yhardy Exp $

Use snprintf instead of sprintf (work around errors when compiling with -Werror).
Initialize variables (compiled with -Werror).

--- src/tyrian2.c.orig	2013-09-07 22:14:33.000000000 +0000
+++ src/tyrian2.c
@@ -2090,7 +2090,7 @@ draw_player_shot_loop_end:
 		strcpy(tempStr, "");
 		for (temp = 0; temp < 9; temp++)
 		{
-			sprintf(tempStr, "%s%c", tempStr,  smoothies[temp] + 48);
+			snprintf(tempStr, sizeof(tempStr), "%s%c", tempStr,  smoothies[temp] + 48);
 		}
 		sprintf(buffer, "SM = %s", tempStr);
 		JE_outText(VGAScreen, 30, 70, buffer, 4, 0);
@@ -4325,8 +4325,8 @@ void JE_eventSystem( void )
 
 	case 19: /* Enemy Global Move */
 	{
-		int initial_i, max_i;
-		bool all_enemies;
+		int initial_i = 0, max_i = 0;
+		bool all_enemies = false;
 
 		if (eventRec[eventLoc-1].eventdat3 > 79 && eventRec[eventLoc-1].eventdat3 < 90)
 		{
