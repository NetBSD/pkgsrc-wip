$NetBSD$

Add support for UMAPINFO.

--- src/g_game.c.orig	2023-02-26 17:42:09.000000000 +0000
+++ src/g_game.c
@@ -225,6 +225,7 @@ uint16_t        demoversion_rev;  // dem
 skill_e         gameskill;
 byte            gameepisode;  // current game episode number  1..4
 byte            gamemap;      // current game map number 1..31
+mapentry_t    * gamemapinfo;  // [MB] 2023-01-22: Support for UMAPINFO added
 char            game_map_filename[MAX_WADPATH];      // an external wad filename
 
 
@@ -2384,10 +2385,80 @@ void G_DoCompleted (void)
     automapactive = false;
 }
 
+
+// [MB] 2023-01-22: Support for UMAPINFO added
+// Returns true if default setup should be skipped
+static boolean G_DoUMapInfo(void)
+{
+    boolean result = false;
+
+    wminfo.epsd_next   = wminfo.epsd;
+    wminfo.lev_next    = wminfo.lev_prev + 1;
+    wminfo.lastmapinfo = gamemapinfo;
+    wminfo.nextmapinfo = NULL;
+
+    if (gamemapinfo)
+    {
+        const char *mapname = NULL;
+        int         i = 0;
+
+        // Keys nextmap and nextsecret overrides default setup
+        if (secretexit && gamemapinfo->nextsecret)
+        {
+            mapname = gamemapinfo->nextsecret;
+            for (i = 0; MAXPLAYERS > i; ++i)
+                players[i].didsecret = true;
+        }
+        else if (gamemapinfo->nextmap)
+            mapname = gamemapinfo->nextmap;
+
+        if (mapname)
+        {
+            result = true;  // UMAPINFO overrides default setup
+
+            {
+                byte e = 0;
+                byte m = 0;
+
+                UMI_ParseMapName(mapname, &e, &m);
+                wminfo.epsd_next = e;
+                wminfo.lev_next = m;
+                GenPrintf(EMSG_info, "UMAPINFO: Go to Episode %d, Map %d\n",
+                          wminfo.epsd_next, wminfo.lev_next);
+            }
+            wminfo.epsd_next--;
+            wminfo.lev_next--;
+
+            if (wminfo.epsd_next != wminfo.epsd)
+            {
+                // Jump to different episode
+                for (i = 0; MAXPLAYERS > i; ++i)
+                    players[i].didsecret = false;
+            }
+        }
+    }
+
+    return result;
+}
+
+
 void G_Start_Intermission( void )
 {
     int  i;
 
+    // [MB] 2023-01-22: Moved to beginning for G_DoUMapInfo()
+    // 0 based
+    wminfo.epsd     = gameepisode - 1;
+    wminfo.lev_prev = gamemap - 1;
+
+    // [MB] 2023-01-22: Support for UMAPINFO added
+    {
+        boolean skip = G_DoUMapInfo();
+
+        if (skip)
+            goto beyond_default_setup;
+    }
+
     if (gamemode != doom2_commercial)
     {
         switch(gamemap)
@@ -2401,7 +2472,7 @@ void G_Start_Intermission( void )
                 // also for heretic
                 // disconnect from network
                 CL_Reset();
-                F_StartFinale();
+                F_StartFinale(secretexit);  // [MB] 2023-03-04: Parameter added
                 return;
             }
             break; // [WDJ] 4/11/2012  map 8 is not secret level, and prboom and boom do not fall thru here.
@@ -2421,7 +2492,7 @@ void G_Start_Intermission( void )
             else
             {
                 CL_Reset();
-                F_StartFinale();
+                F_StartFinale(secretexit);  // [MB] 2023-03-04: Parameter added
                 return;
             }
         }
@@ -2429,14 +2500,11 @@ void G_Start_Intermission( void )
 
     if(!dedicated)
         wminfo.didsecret = consoleplayer_ptr->didsecret;
-    // 0 based
-    wminfo.epsd = gameepisode -1;
-    wminfo.lev_prev = gamemap -1;
 
     // go to next level
     // wminfo.lev_next is 0 biased, unlike gamemap
     wminfo.lev_next = gamemap;
-    
+
     // overwrite next level in some cases
     if (gamemode == doom2_commercial)
     {
@@ -2490,6 +2558,21 @@ void G_Start_Intermission( void )
                 wminfo.lev_next = 0; // wrap around in deathmatch
         }
     }
+beyond_default_setup:
+
+    // [MB] 2023-01-22: Support for UMAPINFO added
+    {
+        int e = wminfo.epsd_next + 1;
+        int m = wminfo.lev_next + 1;
+
+        if (0 <= e && 255u >= e && 0 < m && 255u >= m)
+        {
+            byte epsd = e;
+            byte map  = m;
+
+            wminfo.nextmapinfo = UMI_LookupUMapInfo(epsd, map);
+        }
+    }
 
     wminfo.maxkills = totalkills;
     wminfo.maxitems = totalitems;
@@ -2542,6 +2625,16 @@ void G_NextLevel (void)
             if( gamemap == 30 )
                 wminfo.lev_next = 0; // wrap around in deathmatch
         }
+        // [MB] 2023-01-29: Support for UMAPINFO added
+        else if (gamemapinfo && gamemapinfo->endgame)
+        {
+            tristate_t end = gamemapinfo->endgame;
+
+            if( (end == unchanged && gamemap == 30) || end == enabled )
+                CL_Reset(); // end of game disconnect from server
+            gameaction = ga_nothing;
+            F_StartFinale(secretexit);  // [MB] 2023-03-04: Parameter added
+        }
         else
         {
             switch (gamemap)
@@ -2557,7 +2650,7 @@ void G_NextLevel (void)
                 if( gamemap == 30 )
                     CL_Reset(); // end of game disconnect from server
                 gameaction = ga_nothing;
-                F_StartFinale ();
+                F_StartFinale (secretexit);  // [MB] 2023-03-04: Parameter added
                 break;
             }
         }
