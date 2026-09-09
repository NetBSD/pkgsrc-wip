$NetBSD$

Add the pkgsrc search path for game files.

--- src/gameconfigfile.cpp.orig	2026-08-28 22:25:23.000000000 +0000
+++ src/gameconfigfile.cpp
@@ -146,6 +146,7 @@ static void CollectDefaultSearchPaths()
 	for (unsigned int i = 0; i < std::size(GameDirs); i++)
 	{
 		DefaultSearchPaths.Push(dataDir + GameDirs[i]);
+		DefaultSearchPaths.Push(PKGSRC_DATA_PATH + GameDirs[i]);
 		DefaultSearchPaths.Push(SHARE_DIR + GameDirs[i]);
 
 		if (shareDirChanged)
@@ -236,6 +237,7 @@ FGameConfigFile::FGameConfigFile ()
 		SetSection ("IWADSearch.Directories", true);
 		SetValueForKey ("Path", ".", true);
 		SetValueForKey ("Path", "$DOOMWADDIR", true);
+		SetValueForKey ("Path", PKGSRC_DOOM_PATH, true);
 		SetValueForKey ("PathList", "$DOOMWADPATH", true);
 		for (unsigned int i = 0; i < DefaultSearchPaths.Size(); i++)
 		{
