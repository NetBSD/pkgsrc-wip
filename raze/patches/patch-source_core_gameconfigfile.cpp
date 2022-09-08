$NetBSD$

Add the pkgsrc search path for game files.

--- source/core/gameconfigfile.cpp.orig	2022-07-20 13:37:09.000000000 +0000
+++ source/core/gameconfigfile.cpp
@@ -142,6 +142,7 @@ FGameConfigFile::FGameConfigFile ()
 		SetValueForKey ("Path", "/usr/share/games/nblood", true);
 		SetValueForKey ("Path", "/usr/local/share/games/nblood", true);
 #endif
+		SetValueForKey ("Path", PKGSRC_RAZE_PATH, true);
 	}
 
 	// Set default search paths if none present
