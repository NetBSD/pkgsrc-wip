$NetBSD$

Add pkgsrc paths to WAD/game/soundfont file search paths.

--- src/gameconfigfile.cpp.orig	2020-06-16 17:19:13.000000000 +0000
+++ src/gameconfigfile.cpp
@@ -96,6 +96,9 @@ FGameConfigFile::FGameConfigFile ()
 		SetSection ("IWADSearch.Directories", true);
 		SetValueForKey ("Path", ".", true);
 		SetValueForKey ("Path", "$DOOMWADDIR", true);
+		// For pkgsrc
+		SetValueForKey ("Path", "PKGSRC_PREFIX/PKGSRC_DOOMWADDIR/qzdoom", true);
+		SetValueForKey ("Path", "PKGSRC_PREFIX/PKGSRC_DOOMWADDIR", true);
 #ifdef __APPLE__
 		SetValueForKey ("Path", user_docs, true);
 		SetValueForKey ("Path", user_app_support, true);
@@ -120,6 +123,9 @@ FGameConfigFile::FGameConfigFile ()
 	if (!SetSection ("FileSearch.Directories"))
 	{
 		SetSection ("FileSearch.Directories", true);
+		// For pkgsrc
+		SetValueForKey ("Path", "PKGSRC_PREFIX/PKGSRC_DOOMWADDIR/qzdoom", true);
+		SetValueForKey ("Path", "PKGSRC_PREFIX/PKGSRC_DOOMWADDIR", true);
 #ifdef __APPLE__
 		SetValueForKey ("Path", user_docs, true);
 		SetValueForKey ("Path", user_app_support, true);
@@ -142,6 +148,8 @@ FGameConfigFile::FGameConfigFile ()
 	if (!SetSection("SoundfontSearch.Directories"))
 	{
 		SetSection("SoundfontSearch.Directories", true);
+		// For pkgsrc
+		SetValueForKey("Path", "PKGSRC_PREFIX/PKGSRC_DOOMWADDIR/soundfonts", true);
 #ifdef __APPLE__
 		SetValueForKey("Path", user_docs + "/soundfonts", true);
 		SetValueForKey("Path", user_docs + "/fm_banks", true);
