$NetBSD$

Add support for UMAPINFO.

--- src/wi_stuff.c.orig	2023-02-26 17:42:27.000000000 +0000
+++ src/wi_stuff.c
@@ -481,6 +481,28 @@ void detect_range_violation( int item, i
 // CODE
 //
 
+
+// [MB] 2023-03-19: Support for UMAPINFO added
+// Moved out of WI_Load_Data() into separate function because with UMAPINFO
+// the LF and EL screens can use different background pictures.
+static void WI_Prepare_Background(void)
+{
+    // Prepare new background from bgname for software renderer
+    if (rendermode == render_soft)
+    {
+        memset(screens[0], 0, vid.screen_size);
+
+        // clear backbuffer from status bar stuff and borders
+        memset(screens[1], 0, vid.screen_size);
+
+        // Draw background on screen1
+        V_SetupDraw(1 | V_SCALESTART | V_SCALEPATCH | V_CENTERHORZ); // screen 1
+        V_DrawScaledPatch(0, 0, W_CachePatchName(bgname, PU_CACHE));
+        V_SetupDraw(drawinfo.prev_screenflags);  // restore
+    }
+}
+
+
 // slam background
 // UNUSED static unsigned char *background=0;
 
@@ -523,25 +545,79 @@ static void WI_Draw_LF(void)
 {
     // Hardware or software render.
     patch_t * pp, * pf;
+    int x = 0;
     int y = WI_TITLEY;
 
-    // draw <LevelName>
-    if( FontBBaseLump )
+    // [MB] 2023-03-12: Support for UMAPINFO added
+    //
+    // Quoted from UMAPINFO specification Rev 2.2 definition of levelpic:
+    // Specifies the patch that is used on the status screen for 'entering' and
+    // 'finished'. [...]
+    // If not given, the status screen will instead print the map's name with a
+    // suitable font (PrBoom uses STFxxx) to ensure that the proper name is
+    // used. If the author field is set, it will also be shown.
+    if (wbs->lastmapinfo && wbs->lastmapinfo->levelpic)
     {
-        V_DrawTextB(P_LevelName(), (BASEVIDWIDTH - V_TextBWidth(P_LevelName()))/2, y);
-        y += (5*V_TextBHeight(P_LevelName()))/4;
-        V_DrawTextB("Finished", (BASEVIDWIDTH - V_TextBWidth("Finished"))/2, y);
+        pp = W_CachePatchName(wbs->lastmapinfo->levelpic, PU_CACHE);
+        pf = V_patch(pp);  // access patch fields
+        x = (BASEVIDWIDTH - pf->width) / 2;
+        V_DrawScaledPatch(x, y, pp);
+
+        y += (5 * pf->height) / 4;
+
+        x = (BASEVIDWIDTH - (V_patch(finished)->width)) / 2;
+        V_DrawScaledPatch(x, y, finished);
     }
+    else if (wbs->lastmapinfo && wbs->lastmapinfo->levelname)
+    {
+        const char * level_string = wbs->lastmapinfo->levelname;
+
+        x = (BASEVIDWIDTH - V_StringWidth(level_string)) / 2;
+        V_DrawString(x, y, V_WHITEMAP, level_string);
+
+        if (wbs->lastmapinfo && wbs->lastmapinfo->author)
+        {
+            const char * author_string = wbs->lastmapinfo->author;
+
+            y += (5 * V_FontInfo()->height) / 4;
+
+            x = (BASEVIDWIDTH - V_StringWidth(author_string)) / 2;
+            V_DrawString(x, y, V_WHITEMAP, author_string);
+        }
+
+        y += 2 * V_FontInfo()->height;
+
+        x = (BASEVIDWIDTH - (V_patch(finished)->width)) / 2;
+        V_DrawScaledPatch(x, y, finished);
+    }
+    // Normal behaviour without UMAPINFO
     else
     {
-        //[segabor]: 'SHORT' BUG !  [WDJ] Patch read does endian conversion
-        pp = lnames[wbs->lev_prev];
-        pf = V_patch( pp );  // access patch fields
-        V_DrawScaledPatch ((BASEVIDWIDTH - pf->width)/2, y, pp);
-        y += (5 * pf->height)/4;
-        // draw "Finished!"
-        V_DrawScaledPatch ((BASEVIDWIDTH - (V_patch(finished)->width))/2,
-                            y, finished);
+        // draw <LevelName>
+        if (FontBBaseLump)
+        {
+            x = (BASEVIDWIDTH - V_TextBWidth(P_LevelName())) / 2;
+            V_DrawTextB(P_LevelName(), x, y);
+
+            y += (5 * V_TextBHeight(P_LevelName())) / 4;
+
+            x = (BASEVIDWIDTH - V_TextBWidth("Finished")) / 2;
+            V_DrawTextB("Finished", x, y);
+        }
+        else
+        {
+            //[segabor]: 'SHORT' BUG !  [WDJ] Patch read does endian conversion
+            pp = lnames[wbs->lev_prev];
+            pf = V_patch( pp );  // access patch fields
+            x = (BASEVIDWIDTH - pf->width) / 2;
+            V_DrawScaledPatch(x, y, pp);
+
+            y += (5 * pf->height) / 4;
+
+            x = (BASEVIDWIDTH - (V_patch(finished)->width)) / 2;
+            // draw "Finished!"
+            V_DrawScaledPatch(x, y, finished);
+        }
     }
 }
 
@@ -552,31 +628,81 @@ static void WI_Draw_EL(void)
 {
     // Hardware or software render.
     patch_t * pp, * pf;
+    int x = 0;
     int y = WI_TITLEY;
 
-    // draw "Entering"
-    if( FontBBaseLump )
+    // [MB] 2023-03-12: Support for UMAPINFO added
+    // See WI_Draw_LF() for additional notes about levelpic
+    if (wbs->nextmapinfo && wbs->nextmapinfo->levelpic)
     {
-        const char * levname = P_LevelNameByNum(wbs->epsd+1, wbs->lev_next+1);
-        V_DrawTextB("Entering", (BASEVIDWIDTH - V_TextBWidth("Entering"))/2, y);
-        y += (5*V_TextBHeight("Entering"))/4;
-        V_DrawTextB( levname, (BASEVIDWIDTH - V_TextBWidth(levname))/2, y);
+        x = (BASEVIDWIDTH - (V_patch(entering)->width)) / 2;
+        V_DrawScaledPatch(x, y, entering);
+
+        y += (5 * V_patch(entering)->height) / 4;
+
+        pp = W_CachePatchName(wbs->nextmapinfo->levelpic, PU_CACHE);
+        pf = V_patch(pp);  // access patch fields
+        x = (BASEVIDWIDTH - pf->width) / 2;
+        V_DrawScaledPatch(x, y, pp);
     }
-    else
+    else if (wbs->nextmapinfo && wbs->nextmapinfo->levelname)
     {
-        //[segabor]: 'SHORT' BUG !    [WDJ] Patch read does endian conversion
-        V_DrawScaledPatch((BASEVIDWIDTH - (V_patch(entering)->width))/2,
-                          y, entering);
-        // draw level
-        pp = lnames[wbs->lev_next];
-        pf = V_patch( pp );  // access patch fields
-        y += (5 * pf->height)/4;
+        const char * level_string = wbs->nextmapinfo->levelname;
+
+        x = (BASEVIDWIDTH - (V_patch(entering)->width)) / 2;
+        V_DrawScaledPatch(x, y, entering);
+
+        y += V_patch(entering)->height + V_FontInfo()->height;
+
+        x = (BASEVIDWIDTH - V_StringWidth(level_string)) / 2;
+        V_DrawString(x, y, V_WHITEMAP, level_string);
 
-        V_DrawScaledPatch((BASEVIDWIDTH - pf->width)/2, y, pp);
+        if (wbs->nextmapinfo && wbs->nextmapinfo->author)
+        {
+            const char * author_string = wbs->nextmapinfo->author;
+
+            y += (5 * V_FontInfo()->height) / 4;
+
+            x = (BASEVIDWIDTH - V_StringWidth(author_string)) / 2;
+            V_DrawString(x, y, V_WHITEMAP, author_string);
+        }
     }
+    // Normal behaviour without UMAPINFO
+    else
+    {
+        // draw "Entering"
+        if (FontBBaseLump)
+        {
+            const char * level_string = P_LevelNameByNum(wbs->epsd + 1,
+                                                         wbs->lev_next + 1);
+
+            x = (BASEVIDWIDTH - V_TextBWidth("Entering")) / 2;
+            V_DrawTextB("Entering", x, y);
+
+            y += (5 * V_TextBHeight("Entering")) / 4;
+
+            x = (BASEVIDWIDTH - V_TextBWidth(level_string)) / 2;
+            V_DrawTextB(level_string, x, y);
+        }
+        else
+        {
+            //[segabor]: 'SHORT' BUG !  [WDJ] Patch read does endian conversion
+            x = (BASEVIDWIDTH - (V_patch(entering)->width)) / 2;
+            V_DrawScaledPatch(x, y, entering);
+
+            // draw level
+            pp = lnames[wbs->lev_next];
+            pf = V_patch(pp);  // access patch fields
 
+            y += (5 * pf->height) / 4;
+
+            x = (BASEVIDWIDTH - pf->width) / 2;
+            V_DrawScaledPatch(x, y, pp);
+        }
+    }
 }
 
+
 // [WDJ] Made more resistent to segfault.
 // Doom YAH draw
 //  n : YAH index
@@ -958,6 +1084,20 @@ static void WI_Draw_ShowNextLoc(void)
     if (cnt<=0)  // all removed no draw !!!
         return;
 
+    // [MB] 2023-04-01: Support for UMAPINFO added
+    if (wbs->lastmapinfo)
+    {
+        if ( (wbs->lastmapinfo->endgame == enabled) ||
+             (wbs->lastmapinfo->endbunny) ||
+             (wbs->lastmapinfo->endcast) )
+            return;
+    }
+    if (wbs->nextmapinfo && wbs->nextmapinfo->enterpic)
+    {
+        strcpy(bgname, wbs->nextmapinfo->enterpic);
+        WI_Prepare_Background();
+    }
+
     WI_Slam_Background();
 
     // draw animated background
@@ -990,10 +1130,16 @@ static void WI_Draw_ShowNextLoc(void)
     }
 
     // draws which level you are entering..
-    if ( EN_doom_etc
-         && !((gamemode == doom2_commercial) && (wbs->lev_next == 30)) )
-        WI_Draw_EL();
-
+    if (EN_doom_etc)
+    {
+        boolean map30 = (gamemode == doom2_commercial) && (wbs->lev_next == 30);
+        boolean do_el = wbs->lastmapinfo
+                        && (wbs->lastmapinfo->endgame == disabled);
+
+        // [MB] 2023-04-02: Draw EL if UMAPINFO has disabled endgame
+        if (!map30 || do_el)
+            WI_Draw_EL();
+    }
 }
 
 // Called by WI_Drawer
@@ -1977,7 +2123,6 @@ static void WI_checkForAccelerate(void)
 }
 
 
-
 // Updates stuff each client tick.
 void WI_Ticker(void)
 {
@@ -2097,20 +2242,8 @@ void WI_Load_Data(void)
         if (wb_epsd == 3)
             strcpy(bgname,"INTERPIC");
     }
-    
-    
-    if( rendermode == render_soft )
-    {
-        memset(screens[0], 0, vid.screen_size);
 
-        // clear backbuffer from status bar stuff and borders
-        memset(screens[1], 0, vid.screen_size);
-  
-        // Draw background on screen1
-        V_SetupDraw( 1 | V_SCALESTART | V_SCALEPATCH | V_CENTERHORZ ); // screen 1
-        V_DrawScaledPatch(0, 0, W_CachePatchName(bgname, PU_CACHE));
-        V_SetupDraw( drawinfo.prev_screenflags );  // restore
-    }
+    WI_Prepare_Background();
 
     // UNUSED unsigned char *pic = screens[1];
     // if (gamemode == doom2_commercial)
@@ -2333,6 +2466,14 @@ void WI_Start(wb_start_t * wb_start)
         WI_Init_NetgameStats();
         // wait_game_start_timer will be set by network
     }
+    // [MB] 2023-03-29: Support for UMAPINFO added
+    else if( gamemapinfo && gamemapinfo->nointermission )
+    {
+        if ( gamemode == doom2_commercial )
+            WI_Init_NoState();
+        else
+            WI_Init_ShowNextLoc();
+    }
     else
         WI_Init_Stats();
 }
