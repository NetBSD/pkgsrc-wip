$NetBSD$

Check argc before accessing argv.

Use PREFIX when searching for data.

--- ./Source/stdafx.cpp.orig	2015-11-08 06:10:34.000000000 +0000
+++ ./Source/stdafx.cpp
@@ -32,7 +32,7 @@ int main(int argc, char *args[]) {
 		if (strcmp( args[1], "skipintro" ) == 0)
 			SkipIntro = true;
 
-		if (strcmp( args[2], "map" ) == 0) {
+		if ((argc > 3) && strcmp( args[2], "map" ) == 0) {
 			MapNumber = atoi( args[3] );
 		}
 	}
@@ -51,6 +51,8 @@ int main(int argc, char *args[]) {
 std::string local_PathGenerate( const std::string& pFile, const std::string& pPath, bool pData = true ) {
 	std::stringstream	 filePathFinal;
 
+	filePathFinal << OPENFODDER_DATADIR << "/";
+
 	if (pData)
 		filePathFinal << "Data/";
 	else
