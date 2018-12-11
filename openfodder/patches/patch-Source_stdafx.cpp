$NetBSD$

Use PREFIX when searching for data.

--- Source/stdafx.cpp.orig	2018-12-11 09:43:06.000000000 +0000
+++ Source/stdafx.cpp
@@ -245,14 +245,19 @@ void local_BasePathGenerate() {
         if (path) {
             FinalPath = path;
             FinalPath.append("/.local/share/");
+            filePathFinal << FinalPath << "OpenFodder/";
+            if (!local_FileExists(filePathFinal.str())) {
+                FinalPath = "";
+                filePathFinal.str("");
+            }
         }
     }
 
     // Fall back just incase
-    if (!FinalPath.size())
-        FinalPath = "/usr/local/share/";
-
-    filePathFinal << FinalPath << "OpenFodder/";
+    if (!FinalPath.size()) {
+        FinalPath = OPENFODDER_DATADIR;
+        filePathFinal << FinalPath << "OpenFodder/";
+    }
 
 #endif
 
