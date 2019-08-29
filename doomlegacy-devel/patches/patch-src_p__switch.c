$NetBSD$

Typecast signed result from LE_SWAP16 macro to unsigned where required.
Only relevant for big endian machines.
Proposed by upstream for test.

--- src/p_switch.c.orig	2019-08-21 09:16:55.000000000 +0000
+++ src/p_switch.c
@@ -190,7 +190,7 @@ void P_Init_SwitchList(void)
     {
       // endian conversion only when loading from extra lump
       for (i=0;alphSwitchList[i].episode!=0;i++)
-        alphSwitchList[i].episode = LE_SWAP16(alphSwitchList[i].episode);
+        alphSwitchList[i].episode = (uint16_t)( LE_SWAP16(alphSwitchList[i].episode) );
     }
 #endif
   }
