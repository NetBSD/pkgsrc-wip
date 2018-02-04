$NetBSD$

Check argc before accessing argv.

Use PREFIX when searching for data.

--- Source/stdafx.cpp.orig	2018-02-01 19:54:26.000000000 +0000
+++ Source/stdafx.cpp
@@ -39,7 +39,7 @@ int main(int argc, char *args[]) {
 		if (strcmp( args[1], "skipintro" ) == 0)
 			SkipIntro = true;
 
-		if (strcmp( args[2], "map" ) == 0) {
+		if ((argc > 3) && strcmp( args[2], "map" ) == 0) {
 			MapNumber = atoi( args[3] );
 		}
 	}
@@ -110,14 +110,19 @@ std::string local_PathGenerate( const st
             if (path) {
                 FinalPath = path;
                 FinalPath.append("/.local/share/");
+                filePathFinal << FinalPath << "OpenFodder/";
+                if (!local_FileExists(filePathFinal.str())) {
+                    FinalPath = "";
+                    filePathFinal.str("");
+                }
             }
         }
 
         // Fall back just incase
-        if(!FinalPath.size())
-            FinalPath = "/usr/local/share/";
-
-        filePathFinal << FinalPath << "OpenFodder/";
+        if(!FinalPath.size()) {
+            FinalPath = OPENFODDER_DATADIR;
+            filePathFinal << FinalPath << "OpenFodder/";
+        }
 
     #endif
 
