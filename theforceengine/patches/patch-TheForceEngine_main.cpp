$NetBSD$

Search for program files in the install prefix.

--- TheForceEngine/main.cpp.orig	2023-05-27 05:02:04.000000000 +0000
+++ TheForceEngine/main.cpp
@@ -528,6 +528,7 @@ int main(int argc, char* argv[])
 	#endif
 
 	// Paths
+	FileUtil::setCurrentDirectory(PROGDATADIR);
 	bool pathsSet = true;
 	pathsSet &= TFE_Paths::setProgramPath();
 	pathsSet &= TFE_Paths::setProgramDataPath("TheForceEngine");
