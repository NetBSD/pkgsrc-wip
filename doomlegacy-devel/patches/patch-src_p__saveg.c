$NetBSD$

SAVEGAME FILE CORRUPTED
"Legacy save game sync error"
<https://sourceforge.net/p/doomlegacy/bugs/696/>

--- src/p_saveg.c.orig	2024-12-22 00:28:16.000000000 +0000
+++ src/p_saveg.c
@@ -714,6 +714,10 @@ void P_ArchivePlayers(void)
         }
         WRITEU16(save_p, flags);
 
+        // [MB] 2024-12-26: Added for 1.49 savegame format
+        WRITEBYTE(save_p, ply->GB_flags);
+        WRITEU16(save_p, ply->GF_flags);
+
         if (EN_inventory)
         {
             WRITEBYTE(save_p, ply->inventorySlotNum);
