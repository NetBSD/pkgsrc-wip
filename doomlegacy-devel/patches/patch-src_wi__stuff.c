$NetBSD$

Add support for UMAPINFO.

--- src/wi_stuff.c.orig	2023-01-29 19:24:45.535984651 +0000
+++ src/wi_stuff.c
@@ -1986,11 +1986,21 @@ void WI_Ticker(void)
 
     if (bcnt == 1)
     {
-        // intermission music
-        if ( gamemode == doom2_commercial )
-          S_ChangeMusic(mus_dm2int, true);
+        // [MB] 2023-01-22: Support for UMAPINFO added
+        if (gamemapinfo && gamemapinfo->intermusic)
+        {
+            const char *mus_umi = UMI_GetMusicLumpName(gamemapinfo->intermusic);
+
+            S_ChangeMusicName(mus_umi, true);
+        }
         else
-          S_ChangeMusic(mus_inter, true);
+        {
+            // intermission music
+            if ( gamemode == doom2_commercial )
+              S_ChangeMusic(mus_dm2int, true);
+            else
+              S_ChangeMusic(mus_inter, true);
+        }
     }
 
     WI_checkForAccelerate();
