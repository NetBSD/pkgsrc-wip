$NetBSD$

A fix for mac os x
--- src/main.cpp.orig	2013-10-10 18:50:15.000000000 +0000
+++ src/main.cpp
@@ -100,7 +100,7 @@ int main(int argc, char *argv[])
 
 #ifdef Q_OS_MACX
   // connect to plugins directory
-  app.setLibraryPaths(app.applicationDirPath() + "/../PlugIns");
+  app.addLibraryPath(app.applicationDirPath() + "/../PlugIns");
 #endif
 
   parseCmdLine(argc, argv);
