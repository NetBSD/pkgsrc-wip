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
 
@@ -84,16 +84,39 @@ void    F_StartCast (void);
 void    F_CastTicker (void);
 boolean F_CastResponder (event_t *ev);
 void    F_CastDrawer (void);
-void    F_Draw_interpic_Name( char * name );
+// [MB] 2023-02-05: Changed to static and parameter to const for UMAPINFO
+static void F_Draw_interpic_Name( const char * name );
 
 //
 // F_StartFinale
 //
-void F_StartFinale (void)
+void F_StartFinale (boolean secretexit)
 {
     gamestate = GS_FINALE;
 
-    if(info_intertext)
+    if (gamemapinfo)
+    {
+        // [MB] 2023-01-29: Support for UMAPINFO added
+        if (!secretexit && gamemapinfo->intertext)
+        {
+            finaletext = gamemapinfo->intertext;
+            if (gamemapinfo->interbackdrop)
+              finaleflat = gamemapinfo->interbackdrop;
+            else
+              finaleflat = text[BGFLATE1_NUM]; // Doom E1, FLOOR4_8
+            goto umapinfo_used;
+        }
+        else if (secretexit && gamemapinfo->intertextsecret)
+        {
+            finaletext = gamemapinfo->intertextsecret;
+            if (gamemapinfo->interbackdrop)
+              finaleflat = gamemapinfo->interbackdrop;
+            else
+              finaleflat = text[BGFLATE1_NUM]; // Doom E1, FLOOR4_8
+            goto umapinfo_used;
+        }
+    }
+    else if(info_intertext)
     {
       //SoM: Use FS level info intermission.
       finaletext = info_intertext;
@@ -248,6 +271,7 @@ void F_StartFinale (void)
         break;
     }
 
+umapinfo_used:
     finalestage = 0;
     finalecount = 0;
 
@@ -363,7 +387,7 @@ void F_TextWrite (void)
     // vid : from video setup
     int         w;
     int         count;
-    char*       ch;
+    const char* ch;  // [MB] 2023-01-29: Changed to const
     int         c;
     int         cx, cy;
 
@@ -840,7 +864,8 @@ credit_page:
 
 
 // Called from F_Drawer, to draw full screen
-void F_Draw_interpic_Name( char * name )
+// [MB] 2023-02-05: Changed to static and parameter to const for UMAPINFO
+static void F_Draw_interpic_Name( const char * name )
 {
    patch_t*  pic = W_CachePatchName( name, PU_CACHE );  // endian fix
    // Intercept some doom pictures that chex.wad left in (a young kids game).
@@ -858,14 +883,14 @@ void F_Drawer (void)
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
+        F_TextWrite();
     else
     {
         if( gamemode == heretic )
@@ -874,10 +899,13 @@ void F_Drawer (void)
         }
         else
         {
-           switch (gameepisode)
+           // [MB] 2023-02-05: Support for UMAPINFO added
+           if( gamemapinfo && gamemapinfo->endpic )
+              F_Draw_interpic_Name( gamemapinfo->endpic );
+           else switch( gameepisode )
            {
             case 1:
-              if ( gamemode == ultdoom_retail || gamemode == chexquest1 )
+              if( gamemode == ultdoom_retail || gamemode == chexquest1 )
                 F_Draw_interpic_Name( text[CREDIT_NUM] );
               else
                 F_Draw_interpic_Name( text[HELP2_NUM] );
@@ -894,5 +922,4 @@ void F_Drawer (void)
            }
         }
     }
-
 }
