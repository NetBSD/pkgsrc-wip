$NetBSD$

Add the pkgsrc search path for game files.

--- source/core/gameconfigfile.cpp.orig	2023-11-12 13:35:34.000000000 +0000
+++ source/core/gameconfigfile.cpp
@@ -157,6 +157,8 @@ FGameConfigFile::FGameConfigFile ()
 		SetValueForKey ("Path", "/usr/local/share/games/eduke32", true);
 		SetValueForKey ("Path", "/usr/local/share/games/nblood", true);
 #endif
+		// Section "FileSearch.Directories"
+		SetValueForKey ("Path", PKGSRC_RAZE_PATH, true);
 	}
 
 	// Set default search paths if none present
