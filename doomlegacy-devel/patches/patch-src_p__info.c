$NetBSD$

Add support for UMAPINFO.

--- src/p_info.c.orig	2023-02-26 17:42:27.000000000 +0000
+++ src/p_info.c
@@ -79,6 +79,9 @@
 #include "z_zone.h"
 #include "p_local.h"
 
+// [MB] 2023-03-12: Size of static buffers used for names of levels, etc.
+#define NAME_BUFSIZE  50
+
 //----------------------------------------------------------------------------
 //
 // Helper functions
@@ -150,13 +153,15 @@ static void P_RemoveEqualses(char *line)
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
@@ -295,7 +300,10 @@ not_map:
 
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
@@ -673,7 +681,8 @@ void P_Load_LevelInfo( void )
 
 void COM_MapInfo_f(void)
 {
-  CONS_Printf("Name: %s\n", levelname);
+  // [MB] 2023-02-04: Call P_LevelName() to catch levelname from UMAPINFO
+  CONS_Printf("Name: %s\n", P_LevelName());
   CONS_Printf("Author: %s\n", info_creator);
 }
 
@@ -684,12 +693,81 @@ void P_Register_Info_Commands(void)
 }
 
 
+// [MB] 2023-03-12: Get label (prefix) for UMAPINFO levelname
+// Helper function for P_LevelName()
+//
+// Returns the length of the label, even if larger than buffer size
+// (but does not write beyond end of buffer).
+static size_t P_LevelName_GetLabel(char * buffer, size_t size)
+{
+    size_t len_label = 0;
+
+    if (size > 0)
+    {
+        int len = -1;
+
+        if(gamemapinfo && gamemapinfo->label)
+        {
+            // Empty string, if "clear" was specified in UMAPINFO
+            const char * label = gamemapinfo->label;
+
+            len = snprintf(buffer, size, "%s", label);
+        }
+        else
+        {
+            // Quoted from UMAPINFO specification Rev 2.2 definition of map
+            // entry:
+            // The [episode and map] numbers [...] can exceed their original
+            // limits, though, so MAP50, E5M6 or even MAP100 or E1M10 are valid
+            // map names for their respective game.
+            //
+            // Quoted from UMAPINFO specification Rev 2.2 definition of label:
+            // If not specified the mapname will be used by default followed by
+            // a colon and a space character (e.g. "E1M1: ").
+            unsigned char e = gameepisode;
+            unsigned char m = gamemap;
+
+            if(gamemode == doom2_commercial)
+                len = snprintf(buffer, size, "level %u: ", m);
+            else
+                len = snprintf(buffer, size, "E%uM%u: ", e, m);
+
+        }
+
+        if(len > 0)
+           len_label = len;
+    }
+
+    return len_label;
+}
+
 
 char * P_LevelName(void)
 {
-  return levelname;
+    // [MB] 2023-01-22: Support for UMAPINFO added
+    if(gamemapinfo && gamemapinfo->levelname)
+    {
+        static char  newlevelstr[NAME_BUFSIZE];
+        size_t       remaining = NAME_BUFSIZE - 1;  // -1 for NUL-termination
+
+        size_t len_label = P_LevelName_GetLabel(newlevelstr, NAME_BUFSIZE);
+        size_t len_level = strlen(gamemapinfo->levelname);
+
+        if(len_label > remaining)
+            len_label = remaining;
+        remaining -= len_label;
+        if(len_level > remaining)
+            len_level = remaining;
+
+        memcpy(&newlevelstr[len_label], gamemapinfo->levelname, len_level);
+        newlevelstr[len_label + len_level] = 0;
+        return newlevelstr;
+    }
+    else
+        return levelname;
 }
 
+
 // todo : make this use mapinfo lump
 // Called by WI_Draw_EL "Entering <LevelName>"
 // Called by IN_Draw_YAH "NOW ENTERING"
