$NetBSD$

Add support for UMAPINFO.

--- src/p_info.c.orig	2023-01-10 10:38:38.000000000 +0000
+++ src/p_info.c
@@ -150,13 +150,15 @@ static void P_RemoveEqualses(char *line)
 //  '=' sign is optional: all equals signs are internally turned to spaces
 //
 
-char *info_interpic;
+// [MB] 2023-01-22: Changed to const (used for UMAPINFO too)
+const char *info_creator;
+const char *info_music;
+const char *info_skyname;
+const char *info_interpic;
+const char *info_levelpic;
+
 char *info_levelname;
 int info_partime;
-char *info_music;
-char *info_skyname;
-char *info_creator;
-char *info_levelpic;
 char *info_nextlevel;
 char *info_nextsecret;
 char *info_intertext = NULL;
@@ -295,7 +297,10 @@ not_map:
 
 void P_Clear_LevelVars(void)
 {
-  info_levelname = info_skyname = info_levelpic = info_interpic = "";
+  info_levelname = "";
+  info_skyname = "";
+  info_levelpic = "";
+  info_interpic = "";
   info_music = "";
   info_creator = "unknown";
   info_partime = -1;
@@ -673,7 +678,8 @@ void P_Load_LevelInfo( void )
 
 void COM_MapInfo_f(void)
 {
-  CONS_Printf("Name: %s\n", levelname);
+  // [MB] 2023-02-04: Call P_LevelName() to catch levelname from UMAPINFO
+  CONS_Printf("Name: %s\n", P_LevelName());
   CONS_Printf("Author: %s\n", info_creator);
 }
 
@@ -684,12 +690,48 @@ void P_Register_Info_Commands(void)
 }
 
 
-
 char * P_LevelName(void)
 {
-  return levelname;
+    // [MB] 2023-01-22: Support for UMAPINFO added
+    if (gamemapinfo && gamemapinfo->levelname)
+    {
+        static char newlevelstr[50];
+        size_t      remaining = 50 - 1;  // -1 for NUL-termination
+
+        newlevelstr[0] = 0;
+        if (gamemapinfo && gamemapinfo->label)
+        {
+            // The key 'label' contains a prefix for key 'levelname'
+            size_t len_label = strlen(gamemapinfo->label);
+            size_t len_level = strlen(gamemapinfo->levelname);
+
+            if (remaining < len_label)
+                len_label = remaining;
+            remaining -= len_label;
+            if (remaining < len_level)
+                len_level = remaining;
+
+            memcpy(newlevelstr, gamemapinfo->label, len_label);
+            memcpy(&newlevelstr[len_label], gamemapinfo->levelname, len_level);
+            newlevelstr[len_label + len_level] = 0;
+        }
+        else
+        {
+            size_t len_level = strlen(gamemapinfo->levelname);
+
+            if (remaining < len_level)
+                len_level = remaining;
+
+            memcpy(newlevelstr, gamemapinfo->levelname, len_level);
+            newlevelstr[len_level] = 0;
+        }
+        return newlevelstr;
+    }
+    else
+        return levelname;
 }
 
+
 // todo : make this use mapinfo lump
 // Called by WI_Draw_EL "Entering <LevelName>"
 // Called by IN_Draw_YAH "NOW ENTERING"
