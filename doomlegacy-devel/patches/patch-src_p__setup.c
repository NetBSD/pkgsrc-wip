$NetBSD$

Add support for UMAPINFO.

--- src/p_setup.c.orig	2023-01-10 10:38:38.000000000 +0000
+++ src/p_setup.c
@@ -2087,7 +2087,7 @@ fail:
 // The sky texture to be used instead of the F_SKY1 dummy.
 void P_Setup_LevelSky (void)
 {
-    char * sn = "SKY1";
+    const char * sn = "SKY1";
     char   skytexname[12];
 
     // DOOM determines the sky texture to be used
@@ -2282,6 +2282,8 @@ boolean P_SetupLevel (int      to_episod
     // Dependent upon level_mapname, level_lumpnum.
     P_Load_LevelInfo();
 #endif
+    // [MB] 2023-01-22: Support for UMAPINFO added
+    UMI_Load_LevelInfo();
 
     //SoM: We've loaded the music lump, start the music.
     S_Start_LevelSound();
