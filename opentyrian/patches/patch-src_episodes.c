$NetBSD$

Use snprintf instead of sprintf (work around errors when compiling with -Werror).

--- src/episodes.c.orig	2013-09-07 22:14:32.000000000 +0000
+++ src/episodes.c
@@ -258,9 +258,9 @@ void JE_initEpisode( JE_byte newEpisode 
 	
 	episodeNum = newEpisode;
 	
-	sprintf(levelFile,    "tyrian%d.lvl",  episodeNum);
-	sprintf(cube_file,    "cubetxt%d.dat", episodeNum);
-	sprintf(episode_file, "levels%d.dat",  episodeNum);
+	snprintf(levelFile, sizeof(levelFile),       "tyrian%d.lvl",  episodeNum);
+	snprintf(cube_file, sizeof(cube_file),       "cubetxt%d.dat", episodeNum);
+	snprintf(episode_file, sizeof(episode_file), "levels%d.dat",  episodeNum);
 	
 	JE_analyzeLevel();
 	JE_loadItemDat();
