$NetBSD$

Add support for UMAPINFO.

--- src/g_game.c.orig	2023-01-10 10:38:23.000000000 +0000
+++ src/g_game.c
@@ -225,6 +225,7 @@ uint16_t        demoversion_rev;  // dem
 skill_e         gameskill;
 byte            gameepisode;  // current game episode number  1..4
 byte            gamemap;      // current game map number 1..31
+mapentry_t    * gamemapinfo;  // [MB] 2023-01-22: Support for UMAPINFO added
 char            game_map_filename[MAX_WADPATH];      // an external wad filename
 
 
@@ -2384,10 +2385,69 @@ void G_DoCompleted (void)
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
+    wminfo.lastmapinfo = gamemapinfo;
+    wminfo.nextmapinfo = NULL;
+
+    if (gamemapinfo)
+    {
+        const char *mapname = NULL;
+
+        // 'nextmap' or 'nextsecret' key overrides default behaviour
+        if (secretexit && gamemapinfo->nextsecret)
+            mapname = gamemapinfo->nextsecret;
+        else if (gamemapinfo->nextmap)
+            mapname = gamemapinfo->nextmap;
+
+        if (mapname)
+        {
+            result = true;
+
+            {
+                byte e = 0;
+                byte m = 0;
+
+                UMI_ParseMapName(mapname, &e, &m);
+                wminfo.epsd_next = e;
+                wminfo.lev_next = m;
+            }
+            wminfo.epsd_next--;
+            wminfo.lev_next--;
+
+            if (wminfo.epsd_next != wminfo.epsd)
+            {
+                // Jump to different episode
+                int  i;
+
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
@@ -2436,7 +2496,7 @@ void G_Start_Intermission( void )
     // go to next level
     // wminfo.lev_next is 0 biased, unlike gamemap
     wminfo.lev_next = gamemap;
-    
+
     // overwrite next level in some cases
     if (gamemode == doom2_commercial)
     {
@@ -2490,6 +2550,21 @@ void G_Start_Intermission( void )
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
+        if (0 <= e && 256 > e && 0 < m && 256 > m)
+        {
+            byte epsd = e;
+            byte map  = m;
+
+            wminfo.nextmapinfo = UMI_LookupUMapInfo(epsd, map);
+        }
+    }
 
     wminfo.maxkills = totalkills;
     wminfo.maxitems = totalitems;
@@ -2566,6 +2641,22 @@ void G_NextLevel (void)
 
 void G_DoWorldDone (void)
 {
+    // [MB] 2023-01-22: Support for UMAPINFO added
+    {
+        int e = wminfo.epsd_next + 1;
+        int m = wminfo.lev_next + 1;
+
+        if (0 <= e && 256 > e && 0 < m && 256 > m)
+        {
+            byte epsd = e;
+            byte map  = m;
+
+            gameepisode = epsd;
+            gamemap     = map;
+            gamemapinfo = UMI_LookupUMapInfo(gameepisode, gamemap);
+        }
+    }
+
     if( demoversion<129 )
     {
         gamemap = wminfo.lev_next+1;
@@ -2880,6 +2971,9 @@ void G_InitNew (skill_e skill, const cha
     playerdeadview = false;
     automapactive  = false;
 
+    // [MB] 2023-01-22: Support for UMAPINFO added
+    gamemapinfo    = UMI_LookupUMapInfo(gameepisode, gamemap);
+
     G_DoLoadLevel (resetplayer);
 }
 
