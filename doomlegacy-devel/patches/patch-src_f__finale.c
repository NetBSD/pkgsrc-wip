$NetBSD$

Add support for UMAPINFO.

--- src/f_finale.c.orig	2023-02-26 17:42:28.000000000 +0000
+++ src/f_finale.c
@@ -75,8 +75,8 @@ int             finalecount;
 #define TEXTSPEED       3
 #define TEXTWAIT        250
 
-char*   finaletext;
-char*   finaleflat;
+const char*   finaletext;  // [MB] 2023-01-29: Changed to const
+const char*   finaleflat;  // [MB] 2023-01-29: Changed to const
 static boolean keypressed=false;
 static byte    finale_palette = 0;  // [WDJ] 0 is PLAYPAL
 
@@ -84,27 +84,45 @@ void    F_StartCast (void);
 void    F_CastTicker (void);
 boolean F_CastResponder (event_t *ev);
 void    F_CastDrawer (void);
-void    F_Draw_interpic_Name( char * name );
+// [MB] 2023-02-05: Changed to static and parameter to const for UMAPINFO
+static void F_Draw_interpic_Name( const char * name );
+
 
 //
 // F_StartFinale
 //
-void F_StartFinale (void)
+void F_StartFinale (boolean secretexit)
 {
     gamestate = GS_FINALE;
 
+    // [MB] 2023-01-29: Provide defaults for flat and text
+    finaleflat = text[BGFLATE1_NUM];  // Doom E1, FLOOR4_8
+    finaletext = "";  // Skip text screen
+
+    // [MB] 2023-01-29: Support for UMAPINFO added
+    if(gamemapinfo)
+    {
+        if(!secretexit && gamemapinfo->intertext)
+        {
+            // An empty string is set for 'clear' identifier
+            finaletext = gamemapinfo->intertext;
+            goto beyond_default_setup;
+        }
+        else if(secretexit && gamemapinfo->intertextsecret)
+        {
+            // An empty string is set for 'clear' identifier
+            finaletext = gamemapinfo->intertextsecret;
+            goto beyond_default_setup;
+        }
+    }
+
     if(info_intertext)
     {
-      //SoM: Use FS level info intermission.
-      finaletext = info_intertext;
-      if(info_backdrop)
-        finaleflat = info_backdrop;
-      else
-        finaleflat = text[BGFLATE1_NUM]; // Doom E1, FLOOR4_8
-
-      finalestage = 0;
-      finalecount = 0;
-      return;
+        //SoM: Use FS level info intermission.
+        finaletext = info_intertext;
+        if(info_backdrop)
+            finaleflat = info_backdrop;
+        goto beyond_default_setup;
     }
 
     // Okay - IWAD dependent stuff.
@@ -139,7 +157,7 @@ void F_StartFinale (void)
             finaletext = text[E4TEXT_NUM];
             break;
           default:
-            // Ouch.
+            // [MB] Use defaults
             break;
         }
         break;
@@ -181,8 +199,8 @@ void F_StartFinale (void)
               textnum = 5; // text[C6TEXT_NUM];
               break;
             default:
-              // Ouch.
-              break;
+              // [MB] With UMAPINFO game can end after arbitrary level
+              goto use_defaults;
           }
           switch( gamedesc_id )
           {
@@ -200,6 +218,7 @@ void F_StartFinale (void)
              break;
           }
           finaletext = text[textnum];
+use_defaults:
           break;
       }
 
@@ -248,9 +267,31 @@ void F_StartFinale (void)
         break;
     }
 
+beyond_default_setup:
+    // [MB] 2023-01-29: Skip text screen for empty string
+    if (finaletext[0] == 0)
+    {
+        // Fake state when text screen terminates
+        // Use logic in F_Ticker() to decide what to do next
+        // FIXME: Screen wipe does not work correctly
+        finalestage = 0;
+        finalecount = INT_MAX - 1;
+        keypressed  = true;
+        return;
+    }
+
+    // [MB] 2023-01-29: Support for UMAPINFO added
+    if (gamemapinfo && gamemapinfo->interbackdrop)
+        finaleflat = gamemapinfo->interbackdrop;
+    if (gamemapinfo && gamemapinfo->intermusic)
+    {
+        const char *mus_umi = UMI_GetMusicLumpName(gamemapinfo->intermusic);
+
+        S_ChangeMusicName(mus_umi, true);
+    }
+
     finalestage = 0;
     finalecount = 0;
-
 }
 
 
@@ -314,7 +355,14 @@ void F_Ticker (void)
                 {
                     if (gamemode == doom2_commercial)
                     {
-                        if (gamemap == 30)
+                        // [MB] 2023-03-26: Support for UMAPINFO added
+                        tristate_t endgame = gamemapinfo ? gamemapinfo->endgame
+                                                         : unchanged;
+
+                        if (endgame == enabled
+                            || (gamemapinfo && gamemapinfo->endcast))
+                            F_StartCast ();
+                        else if (gamemap == 30 && endgame != disabled)
                             F_StartCast ();
                         else
                         {
@@ -328,7 +376,7 @@ void F_Ticker (void)
                 }
             }
 
-            if( gamemode != doom2_commercial)
+            if( gamemode != doom2_commercial )
             {
                 uint32_t  f = finalecount;
                 if( f >= INT_MAX/2 )
@@ -339,7 +387,8 @@ void F_Ticker (void)
                     finalecount = 0;
                     finalestage = 1;
                     wipegamestate = GS_FORCEWIPE;             // force a wipe
-                    if (EN_doom_etc && gameepisode == 3)
+                    if ( (EN_doom_etc && gameepisode == 3)
+                         || (gamemapinfo && gamemapinfo->endbunny) )
                         S_StartMusic (mus_bunny);
                 }
             }
@@ -363,7 +412,7 @@ void F_TextWrite (void)
     // vid : from video setup
     int         w;
     int         count;
-    char*       ch;
+    const char* ch;  // [MB] 2023-01-29: Changed to const
     int         c;
     int         cx, cy;
 
@@ -840,7 +889,8 @@ credit_page:
 
 
 // Called from F_Drawer, to draw full screen
-void F_Draw_interpic_Name( char * name )
+// [MB] 2023-02-05: Changed to static and parameter to const for UMAPINFO
+static void F_Draw_interpic_Name( const char * name )
 {
    patch_t*  pic = W_CachePatchName( name, PU_CACHE );  // endian fix
    // Intercept some doom pictures that chex.wad left in (a young kids game).
@@ -858,14 +908,18 @@ void F_Drawer (void)
     // Draw to screen0, scaled
     V_SetupDraw( 0 | V_SCALESTART | V_SCALEPATCH | V_CENTERHORZ );
 
-    if (finalestage == 2)
+    if( finalestage == 2 )
     {
-        F_CastDrawer ();
+        F_CastDrawer();
         return;
     }
 
-    if (!finalestage)
-        F_TextWrite ();
+    if( !finalestage )
+    {
+        // [MB] 2023-03-29: Skip for empty string
+        if( finaletext[0] )
+            F_TextWrite();
+    }
     else
     {
         if( gamemode == heretic )
@@ -874,10 +928,15 @@ void F_Drawer (void)
         }
         else
         {
-           switch (gameepisode)
+           // [MB] 2023-03-29: Support for UMAPINFO added
+           if( gamemapinfo && gamemapinfo->endbunny )
+               F_BunnyScroll();
+           else if( gamemapinfo && gamemapinfo->endpic )
+               F_Draw_interpic_Name( gamemapinfo->endpic );
+           else switch( gameepisode )
            {
             case 1:
-              if ( gamemode == ultdoom_retail || gamemode == chexquest1 )
+              if( gamemode == ultdoom_retail || gamemode == chexquest1 )
                 F_Draw_interpic_Name( text[CREDIT_NUM] );
               else
                 F_Draw_interpic_Name( text[HELP2_NUM] );
@@ -894,5 +953,4 @@ void F_Drawer (void)
            }
         }
     }
-
 }
