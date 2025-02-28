$NetBSD$

--- src/Main/MainCmd.cpp.orig	2016-04-07 01:39:34.000000000 +0000
+++ src/Main/MainCmd.cpp
@@ -69,6 +69,13 @@ int main( int argc, char ** argv )
     // Make sure that we use '.' as decimal point
     setlocale(LC_ALL, "");
     setlocale(LC_NUMERIC, "C");
+
+#if defined(HOMEDIR)
+    App::Application::Config()["AppHomePath"] = HOMEDIR;
+    argv[0] = (char*)malloc(PATH_MAX);
+    strncpy(argv[0], HOMEDIR, PATH_MAX);
+    argv[0][PATH_MAX-1] = '\0'; // ensure null termination
+#endif
 
     // Name and Version of the Application
     App::Application::Config()["ExeName"] = "FreeCAD";
