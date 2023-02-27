$NetBSD$

Add support for UMAPINFO.

--- src/p_info.h.orig	2023-01-10 10:38:38.000000000 +0000
+++ src/p_info.h
@@ -50,14 +50,16 @@ void P_Load_LevelInfo(void);
 
 void P_CleanLine(char *line);
 
-extern char *info_interpic;
+// [MB] 2023-01-22: Changed to const (used for UMAPINFO too)
+extern const char *info_creator;
+extern const char *info_music;
+extern const char *info_skyname;
+extern const char *info_interpic;
+extern const char *info_levelpic;
+
 extern char *info_levelname;
-extern char *info_levelpic;
-extern char *info_music;
 extern int info_partime;
 extern char *info_levelcmd[128];
-extern char *info_skyname;
-extern char *info_creator;
 extern char *info_nextlevel;
 extern char *info_nextsecret;
 extern char *info_intertext;
