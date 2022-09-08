$NetBSD$

Add the pkgsrc search path for game files.

--- src/gameconfigfile.cpp.orig	2022-07-04 08:31:18.000000000 +0000
+++ src/gameconfigfile.cpp
@@ -149,6 +149,7 @@ FGameConfigFile::FGameConfigFile ()
 		SetValueForKey ("Path", "/usr/share/games/doom", true);
 #endif
 		SetValueForKey ("Path", "$DOOMWADDIR", true);
+		SetValueForKey ("Path", PKGSRC_DOOM_PATH, true);
 	}
 
 	// Set default search paths if none present
