$NetBSD$

Add support for UMAPINFO.

--- src/p_info.c.orig	2023-01-10 10:38:38.000000000 +0000
+++ src/p_info.c
@@ -471,11 +471,50 @@ static char * levelname;
 // Called by P_Load_LevelInfo
 void P_FindLevelName(void)
 {
+  // [MB] 2023-01-22: Common buffer
+  //      Size is unchanged, but only 44 characters are displayed in worst case
+#define P_NEWLEVELSTR_SIZE 50u
+  static char newlevelstr[P_NEWLEVELSTR_SIZE];
+
   // Determine the level name.
   // There are a number of sources from which it can come from,
   // getting the right one is the tricky bit =).
-  
-  if(*info_levelname)
+
+  // [MB] 2023-01-22: Support for UMAPINFO added
+  if (gamemapinfo && gamemapinfo->levelname)
+  {
+      size_t remaining = P_NEWLEVELSTR_SIZE - 1;  // -1 for NUL-termination
+
+      newlevelstr[0] = 0;
+      if (gamemapinfo->label)
+      {
+          // The key 'label' contains a prefix for key 'levelname'
+          size_t len_label = strlen(gamemapinfo->label);
+          size_t len_level = strlen(gamemapinfo->levelname);
+
+          if (remaining < len_label)
+              len_label = remaining;
+          remaining -= len_label;
+          if (remaining < len_level)
+              len_level = remaining;
+
+          memcpy(newlevelstr, gamemapinfo->label, len_label);
+          memcpy(&newlevelstr[len_label], gamemapinfo->levelname, len_level);
+          newlevelstr[len_label + len_level] = 0;
+      }
+      else
+      {
+          size_t len_level = strlen(gamemapinfo->levelname);
+
+          if (remaining < len_level)
+              len_level = remaining;
+
+          memcpy(newlevelstr, gamemapinfo->levelname, len_level);
+          newlevelstr[len_level] = 0;
+      }
+      levelname = newlevelstr;
+  }
+  else if(*info_levelname)
   {
       // info level name from level lump (p_info.c) ?
       levelname = info_levelname;
@@ -516,8 +555,6 @@ void P_FindLevelName(void)
   }
   else        //  otherwise just put "new level"
   {
-      static char newlevelstr[50];
-
       sprintf(newlevelstr, "%s: new level", level_mapname);
       levelname = newlevelstr;
   }
