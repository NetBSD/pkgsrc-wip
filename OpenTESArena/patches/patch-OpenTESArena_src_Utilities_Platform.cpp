$NetBSD$

Return the pkgsrc data directory as the base path to search for files.
Use XDG directories on the BSDs as well.

It does not look like SDL2 reports the DragonFlyBSD platform?

--- OpenTESArena/src/Utilities/Platform.cpp.orig	2018-09-23 18:19:37.000000000 +0000
+++ OpenTESArena/src/Utilities/Platform.cpp
@@ -45,6 +45,8 @@ std::string Platform::getPlatform()
 
 std::string Platform::getBasePath()
 {
+	return "@@PKGSRC_DATA_DIR@@";
+
 	// Allocate the base path from SDL.
 	char *basePathPtr = SDL_GetBasePath();
 
@@ -82,7 +84,8 @@ std::string Platform::getOptionsPath()
 		// Convert Windows backslashes to forward slashes.
 		return String::replace(optionsPathString, '\\', '/');
 	}
-	else if (platform == "Linux")
+	/* DragonFlyBSD ? */
+	else if (platform == "Linux" || platform == "FreeBSD" || platform == "NetBSD" || platform == "OpenBSD")
 	{
 		return Platform::getXDGConfigHomeEnv() + "/OpenTESArena/options/";
 	}
