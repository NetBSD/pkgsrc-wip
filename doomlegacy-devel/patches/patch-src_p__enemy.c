$NetBSD$

--- src/p_enemy.c.orig	2023-02-26 17:42:27.000000000 +0000
+++ src/p_enemy.c
@@ -3401,6 +3401,66 @@ static state_t *P_FinalState(statenum_t
     return &states[state];
 }
 
+// [MB] 2023-03-19: Support for UMAPINFO added
+// Helper function for A_Bosstype_Death(), code is now used more than once
+// Returns false if no player is alive
+static boolean A_Player_Alive(void)
+{
+    boolean alive = true;
+    int     i;
+
+    for( i = 0 ; i < MAXPLAYERS ; i++ )
+        if( playeringame[i] && players[i].health > 0 )
+            break;
+
+    if (i == MAXPLAYERS)
+        alive = false;
+
+    return alive;
+}
+
+// [MB] 2023-03-19: Support for UMAPINFO added
+// Helper function for A_Bosstype_Death(), code is now used more than once
+// Parameters are forwarded from A_Bosstype_Death().
+// Returns true if all other bosses (of same type as in parameter mo) are dead
+static boolean A_All_Bosses_Dead(mobj_t* mo, int boss_type)
+{
+    boolean     dead = true;
+    thinker_t*  th;
+    mobj_t*     mo2;
+
+    for( th = thinkercap.next ; th != &thinkercap ; th = th->next )
+    {
+        if( th->function.acp1 != (actionf_p1)P_MobjThinker )
+            continue;
+
+        // Fixes MAP07 bug where if last arachnotron is killed while first
+        // still in death sequence, then both would trigger this code
+        // and the floor would be raised twice (bad).
+        mo2 = (mobj_t *)th;
+        // Check all boss of the same type
+        if ( mo2 != mo
+             && mo2->type == boss_type )
+        {
+            // Check if really dead and finished the death sequence.
+            // [WDJ] Corpse has health < 0.
+            // If two monsters are killed at the same time, this test may occur
+            // while first is corpse and second is not.  But the simple health
+            // test may trigger twice because second monster already has
+            // health < 0 during the first death test.
+            if( mo2->health > 0  // the old test (doom original 1.9)
+                || !(mo2->flags & MF_CORPSE)
+                || mo2->state != P_FinalState(mo2->info->deathstate) )
+            {
+                // other boss not dead
+                dead = false;
+            }
+        }
+    }
+
+    return dead;
+}
+
 //
 // A_BossDeath
 // Possibly trigger special effects
@@ -3412,13 +3472,73 @@ static state_t *P_FinalState(statenum_t
 // [WDJ]  Keen death does not have tests for mo->type and thus allows
 // Dehacked monsters to trigger Keen death and BossDeath effects.
 // Should duplicate that ability in Doom maps.
-void A_Bosstype_Death (mobj_t* mo, int boss_type)
+static void A_Bosstype_Death (mobj_t* mo, int boss_type)
 {
-    thinker_t*  th;
-    mobj_t*     mo2;
-    line_t      lineop;  // operation performed when all bosses are dead.
-    int         i;
-   
+    line_t lineop;  // operation performed when all bosses are dead.
+
+    // [MB] 2023-03-19: Support for UMAPINFO added
+    if( gamemapinfo && gamemapinfo->bossactions )
+    {
+        struct bossaction_t*  umi_ba = gamemapinfo->bossactions;
+        boolean               found  = false;
+
+        do
+        {
+            if( boss_type == umi_ba->thing)
+            {
+                found = true;
+                break;
+            }
+            umi_ba = umi_ba->next;
+        }
+        while( umi_ba );
+
+        if( !found )
+            return;
+
+        // DEHEXTRA is not supported
+        if( boss_type > ENDDOOM_MT )
+        {
+            GenPrintf(EMSG_debug,
+                      "UMAPINFO: Thing for bossaction not supported\n");
+            return;
+        }
+
+        if( ! A_All_Bosses_Dead(mo, boss_type) )
+            return;
+
+        // Execute (potentially multiple) actions defined by UMAPINFO
+        umi_ba = gamemapinfo->bossactions;
+        do
+        {
+            if( boss_type == umi_ba->thing)
+            {
+                // FIXME: Is this allowed for the xxxSoecialLine() functions?
+                memset(&lineop, 0, sizeof(line_t));
+                if (umi_ba->special > (unsigned int)SHRT_MAX)
+                    continue;
+                lineop.special = (short)umi_ba->special;
+                if (umi_ba->tag > (unsigned int)UINT16_MAX)
+                    continue;
+                lineop.tag = (uint16_t)umi_ba->tag;
+
+                // Try to use the line first, cross it if not successful
+                if( ! P_UseSpecialLine(mo, &lineop, 0) )
+                    P_CrossSpecialLine(&lineop, 0, mo);
+            }
+            umi_ba = umi_ba->next;
+        }
+        while( umi_ba );
+        return;
+    }
+
+    if( gamemapinfo && gamemapinfo->bossactions_clear )
+    {
+        // Default handling explicitly cleared by UMAPINFO
+        return;
+    }
+
+    // [MB] Default handling starts here
     if ( gamemode == doom2_commercial)
     {
         // Doom2 MAP07: When last Mancubus is dead,
@@ -3515,45 +3635,14 @@ void A_Bosstype_Death (mobj_t* mo, int b
 
     }
 
-
     // make sure there is a player alive for victory
-    for (i=0 ; i<MAXPLAYERS ; i++)
-        if (playeringame[i] && players[i].health > 0)
-            break;
-
-    if (i==MAXPLAYERS)
+    if( ! A_Player_Alive() )
         return; // no one left alive, so do not end game
 
     // scan the remaining thinkers to see
     // if all bosses are dead
-    for (th = thinkercap.next ; th != &thinkercap ; th=th->next)
-    {
-        if (th->function.acp1 != (actionf_p1)P_MobjThinker)
-            continue;
-
-        // Fixes MAP07 bug where if last arachnotron is killed while first
-        // still in death sequence, then both would trigger this code
-        // and the floor would be raised twice (bad).
-        mo2 = (mobj_t *)th;
-        // Check all boss of the same type
-        if ( mo2 != mo
-            && mo2->type == boss_type )
-        {
-            // Check if really dead and finished the death sequence.
-            // [WDJ] Corpse has health < 0.
-            // If two monsters are killed at the same time, this test may occur
-            // while first is corpse and second is not.  But the simple health
-            // test may trigger twice because second monster already has
-            // health < 0 during the first death test.
-            if( mo2->health > 0  // the old test (doom original 1.9)
-                || !(mo2->flags & MF_CORPSE)
-                || mo2->state != P_FinalState(mo2->info->deathstate) )
-            {
-                // other boss not dead
-                goto no_action;
-            }
-        }
-    }
+    if( ! A_All_Bosses_Dead(mo, boss_type) )
+        goto no_action;
 
     // victory!
     if ( gamemode == doom2_commercial)
